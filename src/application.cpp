/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-12-07T19:15:39+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:16:12+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#include "../libs/application.hpp"
#include <curses.h>
#include <form.h>
#include <menu.h>
#include <panel.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

char *choices1[] = {
    "", "", "", "", "", (char *)NULL,
};
char *choices[] = {
    "New Complex", "Make Reservation", "List Complexes", "List Reservations",
    "Exit",        (char *)NULL,
};
void print_in_middle(WINDOW *win, int starty, int startx, int width,
                     char *string, chtype color);

void print_in_middle(WINDOW *win, int starty, int startx, int width,
                     char *string, chtype color) {
  int length, x, y;
  float temp;

  if (win == NULL)
    win = stdscr;
  getyx(win, y, x);
  if (startx != 0)
    x = startx;
  if (starty != 0)
    y = starty;
  if (width == 0)
    width = 80;

  length = strlen(string);
  temp = (width - length) / 2;
  x = startx + (int)temp;
  wattron(win, color);
  mvwprintw(win, y, x, "%s", string);
  wattroff(win, color);
  refresh();
}

void Application::start() {
  ITEM **my_items;
  int c;
  MENU *my_menu;
  WINDOW *my_menu_win;
  int n_choices, i;

  /* Initialize curses */
  initscr();
  start_color();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  init_pair(1, COLOR_RED, COLOR_BLACK);

  /* Create items */
  n_choices = ARRAY_SIZE(choices);
  my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
  for (i = 0; i < n_choices; ++i)
    my_items[i] = new_item(choices[i], choices1[i]);

  /* Crate menu */
  my_menu = new_menu((ITEM **)my_items);

  /* Create the window to be associated with the menu */
  my_menu_win = newwin(10, 40, 4, 4);
  keypad(my_menu_win, TRUE);

  /* Set main window and sub window */
  set_menu_win(my_menu, my_menu_win);
  set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));

  /* Set menu mark to the string " * " */
  set_menu_mark(my_menu, " * ");

  /* Print a border around the main window and print a title */
  box(my_menu_win, 0, 0);
  print_in_middle(my_menu_win, 1, 0, 40, "Main Menu", COLOR_PAIR(1));
  mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
  mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
  mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
  refresh();

  /* Post the menu */
  post_menu(my_menu);
  wrefresh(my_menu_win);

  bool quit = false;

  while ((c = wgetch(my_menu_win))) {
    switch (c) {
    case KEY_DOWN:
      menu_driver(my_menu, REQ_DOWN_ITEM);
      break;
    case KEY_UP:
      menu_driver(my_menu, REQ_UP_ITEM);
      break;
    case 10:
      move(20, 0);
      clrtoeol();
      std::string itemName = item_name(current_item(my_menu));
      if (itemName == "New Complex") {
        clear();
        newComplexForm();
        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, "Main Menu", COLOR_PAIR(1));
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
        refresh();
        /* Post the menu */
        post_menu(my_menu);
        wrefresh(my_menu_win);
      } else if (itemName == "Make Reservation") {

      } else if (itemName == "List Complexes") {
        clear();
        listComplexes();
        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, "Main Menu", COLOR_PAIR(1));
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
        refresh();
        /* Post the menu */
        post_menu(my_menu);
        wrefresh(my_menu_win);
      } else if (itemName == "List Reservations") {
        clear();
        listReservations();
        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, "Main Menu", COLOR_PAIR(1));
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
        refresh();
        /* Post the menu */
        post_menu(my_menu);
        wrefresh(my_menu_win);
      } else if (itemName == "Exit") {
        quit = true;
      }
      pos_menu_cursor(my_menu);
      break;
    }
    if (quit) {
      break;
    }
    wrefresh(my_menu_win);
  }

  /* Unpost and free all the memory taken up */
  unpost_menu(my_menu);
  free_menu(my_menu);
  for (i = 0; i < n_choices; ++i)
    free_item(my_items[i]);
  endwin();
}

void Application::viewComplex(std::shared_ptr<Complex> complex) {
  ITEM **my_items;
  int c;
  MENU *my_menu;
  WINDOW *my_menu_win;
  int n_choices, i;

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);

  char *view_complex_choices[] = {
      "Add Auditorium", "Remove Auditorium", "List Auditoriums",
      "Back",           (char *)NULL,
  };

  /* Create items */
  n_choices = 5;
  my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
  for (i = 0; i < n_choices; ++i) {
    my_items[i] = new_item(view_complex_choices[i], "");
  }

  /* Create menu */
  my_menu = new_menu((ITEM **)my_items);

  /* Create the window to be associated with the menu */
  my_menu_win = newwin(10, 40, 4, 4);
  keypad(my_menu_win, TRUE);

  /* Set main window and sub window */
  set_menu_win(my_menu, my_menu_win);
  set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
  set_menu_format(my_menu, 5, 1);

  /* Set menu mark to the string " * " */
  set_menu_mark(my_menu, " * ");

  /* Print a border around the main window and print a title */
  box(my_menu_win, 0, 0);
  std::string title = ("Listing Complex: " + complex->getName());
  print_in_middle(my_menu_win, 1, 0, 40, strdup((title).c_str()),
                  COLOR_PAIR(1));
  mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
  mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
  mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

  /* Post the menu */
  post_menu(my_menu);
  wrefresh(my_menu_win);

  attron(COLOR_PAIR(2));
  mvprintw(LINES - 2, 0,
           "Use PageUp and PageDown to scoll down or up a page of items");
  mvprintw(LINES - 1, 0, "Arrow Keys to navigate (ESC to Exit)");
  attroff(COLOR_PAIR(2));
  refresh();

  bool quit = false;

  while (!quit && (c = wgetch(my_menu_win))) {
    switch (c) {
    case KEY_DOWN:
      menu_driver(my_menu, REQ_DOWN_ITEM);
      break;
    case KEY_UP:
      menu_driver(my_menu, REQ_UP_ITEM);
      break;
    case KEY_NPAGE:
      menu_driver(my_menu, REQ_SCR_DPAGE);
      break;
    case KEY_PPAGE:
      menu_driver(my_menu, REQ_SCR_UPAGE);
      break;
    case 27:
      quit = true;
      break;
    case 10:
      std::string itemName = item_name(current_item(my_menu));
      if (itemName == "New Complex") {
        clear();
        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, strdup((title).c_str()),
                        COLOR_PAIR(1));
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
        refresh();
        /* Post the menu */
        post_menu(my_menu);
        wrefresh(my_menu_win);
      } else if (itemName == "List Auditoriums") {
        clear();

        listAuditoriums(complex);

        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, strdup((title).c_str()),
                        COLOR_PAIR(1));
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
        refresh();
        /* Post the menu */
        post_menu(my_menu);
        wrefresh(my_menu_win);
      } else if (itemName == "Back") {
        quit = true;
      }
    }

    if (quit) {
      break;
    }
    wrefresh(my_menu_win);
  }

  /* Unpost and free all the memory taken up */
  unpost_menu(my_menu);
  free_menu(my_menu);
  for (i = 0; i < n_choices; ++i)
    free_item(my_items[i]);
  endwin();
}

void Application::viewAuditorium(std::shared_ptr<Auditorium> auditorium) {
  ITEM **my_items;
  int c;
  MENU *my_menu;
  WINDOW *my_menu_win;
  int n_choices, i;

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);

  char *view_auditorium_choices[] = {
      "Add Seat", "View Seats", "Back", (char *)NULL,
  };

  /* Create items */
  n_choices = 4;
  my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
  for (i = 0; i < n_choices; ++i) {
    my_items[i] = new_item(view_auditorium_choices[i], "");
  }

  /* Create menu */
  my_menu = new_menu((ITEM **)my_items);

  /* Create the window to be associated with the menu */
  my_menu_win = newwin(10, 40, 4, 4);
  keypad(my_menu_win, TRUE);

  /* Set main window and sub window */
  set_menu_win(my_menu, my_menu_win);
  set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
  set_menu_format(my_menu, 5, 1);

  /* Set menu mark to the string " * " */
  set_menu_mark(my_menu, " * ");

  /* Print a border around the main window and print a title */
  box(my_menu_win, 0, 0);
  std::string title = ("Listing Auditorium: " + auditorium->getName());
  print_in_middle(my_menu_win, 1, 0, 40, strdup((title).c_str()),
                  COLOR_PAIR(1));
  mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
  mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
  mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

  /* Post the menu */
  post_menu(my_menu);
  wrefresh(my_menu_win);

  attron(COLOR_PAIR(2));
  mvprintw(LINES - 2, 0,
           "Use PageUp and PageDown to scoll down or up a page of items");
  mvprintw(LINES - 1, 0, "Arrow Keys to navigate (ESC to Exit)");
  attroff(COLOR_PAIR(2));
  refresh();

  bool quit = false;

  while (!quit && (c = wgetch(my_menu_win))) {
    switch (c) {
    case KEY_DOWN:
      menu_driver(my_menu, REQ_DOWN_ITEM);
      break;
    case KEY_UP:
      menu_driver(my_menu, REQ_UP_ITEM);
      break;
    case KEY_NPAGE:
      menu_driver(my_menu, REQ_SCR_DPAGE);
      break;
    case KEY_PPAGE:
      menu_driver(my_menu, REQ_SCR_UPAGE);
      break;
    case 27:
      quit = true;
      break;
    case 10:
      std::string itemName = item_name(current_item(my_menu));
      if (itemName == "Back") {
        quit = true;
      } else if (itemName == "View Seats") {
        clear();
        viewSeats(auditorium);
        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, strdup((title).c_str()),
                        COLOR_PAIR(1));
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
        refresh();
        /* Post the menu */
        post_menu(my_menu);
        wrefresh(my_menu_win);
      }
    }

    if (quit) {
      break;
    }
    wrefresh(my_menu_win);
  }

  /* Unpost and free all the memory taken up */
  unpost_menu(my_menu);
  free_menu(my_menu);
  for (i = 0; i < n_choices; ++i)
    free_item(my_items[i]);
  endwin();
}

void Application::viewSeats(std::shared_ptr<Auditorium> auditorium) {
  ITEM **my_items;
  int c;
  MENU *my_menu;
  WINDOW *my_menu_win;
  int n_choices, i;

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);

  char *view_complex_choices[] = {
      "Back", (char *)NULL,
  };

  /* Create items */
  n_choices = 2;
  my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
  for (i = 0; i < n_choices; ++i) {
    my_items[i] = new_item(view_complex_choices[i], "");
  }

  /* Create menu */
  my_menu = new_menu((ITEM **)my_items);

  /* Create the window to be associated with the menu */
  my_menu_win = newwin(10, 40, 4, 4);
  keypad(my_menu_win, TRUE);

  /* Set main window and sub window */
  set_menu_win(my_menu, my_menu_win);
  set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
  set_menu_format(my_menu, 5, 1);

  /* Set menu mark to the string " * " */
  set_menu_mark(my_menu, " * ");

  /* Print a border around the main window and print a title */
  box(my_menu_win, 0, 0);
  std::string title = ("Viewing Seats of: " + auditorium->getName());
  print_in_middle(my_menu_win, 1, 0, 40, strdup((title).c_str()),
                  COLOR_PAIR(1));

  int base_x = 4;
  int base_y = 2;

  for (size_t row = 0; row < auditorium->getRows(); row++) {
    for (size_t col = 0; col < auditorium->getColSize(row); col++) {
      try {
        if (auditorium->getSeat(row, col)->isTaken()) {
          mvwprintw(my_menu_win, base_x + col, base_y + row, "%s", "X,");
        } else {
          mvwprintw(my_menu_win, base_x + col, base_y + row, "%s", "_,");
        }
      } catch (...) {
        mvwprintw(my_menu_win, base_x + col, base_y + row, "%s", " ");
      }
    }
  }

  mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
  mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
  mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

  /* Post the menu */
  post_menu(my_menu);
  wrefresh(my_menu_win);

  attron(COLOR_PAIR(2));
  mvprintw(LINES - 2, 0,
           "Use PageUp and PageDown to scoll down or up a page of items");
  mvprintw(LINES - 1, 0, "Arrow Keys to navigate (ESC to Exit)");
  attroff(COLOR_PAIR(2));
  refresh();

  bool quit = false;

  while (!quit && (c = wgetch(my_menu_win))) {
    switch (c) {
    case KEY_DOWN:
      menu_driver(my_menu, REQ_DOWN_ITEM);
      break;
    case KEY_UP:
      menu_driver(my_menu, REQ_UP_ITEM);
      break;
    case KEY_NPAGE:
      menu_driver(my_menu, REQ_SCR_DPAGE);
      break;
    case KEY_PPAGE:
      menu_driver(my_menu, REQ_SCR_UPAGE);
      break;
    case 27:
      quit = true;
      break;
    case 10:
      std::string itemName = item_name(current_item(my_menu));
      if (itemName == "New Complex") {
        clear();
        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, strdup((title).c_str()),
                        COLOR_PAIR(1));
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
        refresh();
        /* Post the menu */
        post_menu(my_menu);
        wrefresh(my_menu_win);
      } else if (itemName == "List Auditoriums") {
        clear();

        box(my_menu_win, 0, 0);
        print_in_middle(my_menu_win, 1, 0, 40, strdup((title).c_str()),
                        COLOR_PAIR(1));
        mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
        mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
        mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
        refresh();
        /* Post the menu */
        post_menu(my_menu);
        wrefresh(my_menu_win);
      } else if (itemName == "Back") {
        quit = true;
      }
    }

    if (quit) {
      break;
    }
    wrefresh(my_menu_win);
  }

  /* Unpost and free all the memory taken up */
  unpost_menu(my_menu);
  free_menu(my_menu);
  for (i = 0; i < n_choices; ++i)
    free_item(my_items[i]);
  endwin();
}

void Application::listAuditoriums(std::shared_ptr<Complex> complex) {
  ITEM **my_items;
  int c;
  MENU *my_menu;
  WINDOW *my_menu_win;
  int n_choices, i;

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);

  /* Create items */
  n_choices = complex->getSize() + 2;
  my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
  for (i = 0; i < complex->getSize(); ++i)
    my_items[i] = new_item(strdup(complex->at(i)->getName().c_str()), "");

  my_items[complex->getSize()] = new_item("Back", "");

  /* Crate menu */
  my_menu = new_menu((ITEM **)my_items);

  /* Create the window to be associated with the menu */
  my_menu_win = newwin(10, 40, 4, 4);
  keypad(my_menu_win, TRUE);

  /* Set main window and sub window */
  set_menu_win(my_menu, my_menu_win);
  set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
  set_menu_format(my_menu, 5, 1);

  /* Set menu mark to the string " * " */
  set_menu_mark(my_menu, " * ");

  /* Print a border around the main window and print a title */
  box(my_menu_win, 0, 0);
  print_in_middle(my_menu_win, 1, 0, 40, "Listing Auditoriums", COLOR_PAIR(1));
  mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
  mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
  mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

  /* Post the menu */
  post_menu(my_menu);
  wrefresh(my_menu_win);

  attron(COLOR_PAIR(2));
  mvprintw(LINES - 2, 0,
           "Use PageUp and PageDown to scoll down or up a page of items");
  mvprintw(LINES - 1, 0, "Arrow Keys to navigate (ESC to Exit)");
  attroff(COLOR_PAIR(2));
  refresh();

  bool quit = false;

  while (!quit && (c = wgetch(my_menu_win))) {
    switch (c) {
    case KEY_DOWN:
      menu_driver(my_menu, REQ_DOWN_ITEM);
      break;
    case KEY_UP:
      menu_driver(my_menu, REQ_UP_ITEM);
      break;
    case KEY_NPAGE:
      menu_driver(my_menu, REQ_SCR_DPAGE);
      break;
    case KEY_PPAGE:
      menu_driver(my_menu, REQ_SCR_UPAGE);
      break;
    case 27:
      quit = true;
      break;
    case 10:
      std::string itemName = item_name(current_item(my_menu));
      std::shared_ptr<Auditorium> auditorium;
      for (size_t i = 0; i < complex->getSize(); i++) {
        if (itemName == complex->at(i)->getName()) {
          auditorium = complex->at(i);
          clear();
          viewAuditorium(auditorium);
          box(my_menu_win, 0, 0);
          print_in_middle(my_menu_win, 1, 0, 40, ("Listing Auditoriums"),
                          COLOR_PAIR(1));
          mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
          mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
          mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
          refresh();
          /* Post the menu */
          post_menu(my_menu);
          wrefresh(my_menu_win);
          break;
        }
      }

      if (itemName == "Back") {
        quit = true;
      }
      break;
    }

    if (quit) {
      break;
    }
    wrefresh(my_menu_win);
  }

  /* Unpost and free all the memory taken up */
  unpost_menu(my_menu);
  free_menu(my_menu);
  for (i = 0; i < n_choices; ++i)
    free_item(my_items[i]);
  endwin();
}

void Application::listComplexes() {
  ITEM **my_items;
  int c;
  MENU *my_menu;
  WINDOW *my_menu_win;
  int n_choices, i;

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);

  char *list_complexes_choices[] = {
      "Back", (char *)NULL,
  };

  /* Create items */
  n_choices = this->_complexes->size() + 2;
  my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
  for (i = 0; i < this->_complexes->size(); ++i)
    my_items[i] =
        new_item(strdup(this->_complexes->at(i)->getName().c_str()), "");

  my_items[this->_complexes->size()] = new_item(list_complexes_choices[0], "");

  /* Crate menu */
  my_menu = new_menu((ITEM **)my_items);

  /* Create the window to be associated with the menu */
  my_menu_win = newwin(10, 40, 4, 4);
  keypad(my_menu_win, TRUE);

  /* Set main window and sub window */
  set_menu_win(my_menu, my_menu_win);
  set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
  set_menu_format(my_menu, 5, 1);

  /* Set menu mark to the string " * " */
  set_menu_mark(my_menu, " * ");

  /* Print a border around the main window and print a title */
  box(my_menu_win, 0, 0);
  print_in_middle(my_menu_win, 1, 0, 40, "Listing Complexes", COLOR_PAIR(1));
  mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
  mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
  mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

  /* Post the menu */
  post_menu(my_menu);
  wrefresh(my_menu_win);

  attron(COLOR_PAIR(2));
  mvprintw(LINES - 2, 0,
           "Use PageUp and PageDown to scoll down or up a page of items");
  mvprintw(LINES - 1, 0, "Arrow Keys to navigate (ESC to Exit)");
  attroff(COLOR_PAIR(2));
  refresh();

  bool quit = false;

  while (!quit && (c = wgetch(my_menu_win))) {
    switch (c) {
    case KEY_DOWN:
      menu_driver(my_menu, REQ_DOWN_ITEM);
      break;
    case KEY_UP:
      menu_driver(my_menu, REQ_UP_ITEM);
      break;
    case KEY_NPAGE:
      menu_driver(my_menu, REQ_SCR_DPAGE);
      break;
    case KEY_PPAGE:
      menu_driver(my_menu, REQ_SCR_UPAGE);
      break;
    case 27:
      quit = true;
      break;
    case 10:
      std::string itemName = item_name(current_item(my_menu));
      std::shared_ptr<Complex> complex;
      for (size_t i = 0; i < this->_complexes->size(); i++) {
        if (itemName == this->_complexes->at(i)->getName()) {
          complex = this->_complexes->at(i);
          clear();
          viewComplex(complex);
          box(my_menu_win, 0, 0);
          print_in_middle(my_menu_win, 1, 0, 40, ("Listing Complexes"),
                          COLOR_PAIR(1));
          mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
          mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
          mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
          refresh();
          /* Post the menu */
          post_menu(my_menu);
          wrefresh(my_menu_win);
          break;
        }
      }
      if (itemName == "Back") {
        quit = true;
        break;
      }
      break;
    }

    if (quit) {
      break;
    }
    wrefresh(my_menu_win);
  }

  /* Unpost and free all the memory taken up */
  unpost_menu(my_menu);
  free_menu(my_menu);
  for (i = 0; i < n_choices; ++i)
    free_item(my_items[i]);
  endwin();
}

void Application::listReservations() {
  ITEM **my_items;
  int c;
  MENU *my_menu;
  WINDOW *my_menu_win;
  int n_choices, i;

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);

  char *list_reservations_choices[] = {
      "Back", (char *)NULL,
  };

  /* Create items */
  n_choices = this->_reservations->size() + 2;
  my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
  for (i = 0; i < this->_reservations->size(); ++i)
    my_items[i] =
        new_item(strdup(this->_reservations->at(i)->getName().c_str()), "");

  my_items[this->_reservations->size()] =
      new_item(list_reservations_choices[0], "");

  /* Crate menu */
  my_menu = new_menu((ITEM **)my_items);

  /* Create the window to be associated with the menu */
  my_menu_win = newwin(10, 40, 4, 4);
  keypad(my_menu_win, TRUE);

  /* Set main window and sub window */
  set_menu_win(my_menu, my_menu_win);
  set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
  set_menu_format(my_menu, 5, 1);

  /* Set menu mark to the string " * " */
  set_menu_mark(my_menu, " * ");

  /* Print a border around the main window and print a title */
  box(my_menu_win, 0, 0);
  print_in_middle(my_menu_win, 1, 0, 40, "Listing Reservations", COLOR_PAIR(1));
  mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
  mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
  mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

  /* Post the menu */
  post_menu(my_menu);
  wrefresh(my_menu_win);

  attron(COLOR_PAIR(2));
  mvprintw(LINES - 2, 0,
           "Use PageUp and PageDown to scoll down or up a page of items");
  mvprintw(LINES - 1, 0, "Arrow Keys to navigate (ESC to Exit)");
  attroff(COLOR_PAIR(2));
  refresh();

  bool quit = false;

  while (!quit && (c = wgetch(my_menu_win))) {
    switch (c) {
    case KEY_DOWN:
      menu_driver(my_menu, REQ_DOWN_ITEM);
      break;
    case KEY_UP:
      menu_driver(my_menu, REQ_UP_ITEM);
      break;
    case KEY_NPAGE:
      menu_driver(my_menu, REQ_SCR_DPAGE);
      break;
    case KEY_PPAGE:
      menu_driver(my_menu, REQ_SCR_UPAGE);
      break;
    case 27:
      quit = true;
      break;
    case 10:
      std::string itemName = item_name(current_item(my_menu));
      std::shared_ptr<Reservation> reservation;
      for (size_t i = 0; i < this->_reservations->size(); i++) {
        if (itemName == this->_reservations->at(i)->getName()) {
          reservation = this->_reservations->at(i);
          clear();
          box(my_menu_win, 0, 0);
          print_in_middle(my_menu_win, 1, 0, 40, ("Listing Reservations"),
                          COLOR_PAIR(1));
          mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
          mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
          mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
          refresh();
          /* Post the menu */
          post_menu(my_menu);
          wrefresh(my_menu_win);
          break;
        }
      }
      if (itemName == "Back") {
        quit = true;
      }
      break;
    }

    if (quit) {
      break;
    }
    wrefresh(my_menu_win);
  }

  /* Unpost and free all the memory taken up */
  unpost_menu(my_menu);
  free_menu(my_menu);
  for (i = 0; i < n_choices; ++i)
    free_item(my_items[i]);
  endwin();
}

void Application::newComplexForm() {
  FIELD *field[3];
  FORM *my_form;
  WINDOW *my_form_win;
  int ch, rows, cols;

  /* Initialize few color pairs */
  init_pair(1, COLOR_RED, COLOR_BLACK);

  /* Initialize the fields */
  field[0] = new_field(1, 10, 6, 1, 0, 0);
  field[1] = new_field(1, 10, 8, 1, 0, 0);
  field[2] = NULL;

  /* Set field options */
  set_field_back(field[0], A_UNDERLINE);
  field_opts_off(field[0], O_AUTOSKIP); /* Don't go to next field when this */
                                        /* Field is filled up 		*/
  set_field_back(field[1], A_UNDERLINE);
  field_opts_off(field[1], O_AUTOSKIP);

  /* Create the form and post it */
  my_form = new_form(field);

  /* Calculate the area required for the form */
  scale_form(my_form, &rows, &cols);

  /* Create the window to be associated with the form */
  my_form_win = newwin(rows + 4, cols + 4, 4, 4);
  keypad(my_form_win, TRUE);

  /* Set main window and sub window */
  set_form_win(my_form, my_form_win);
  set_form_sub(my_form, derwin(my_form_win, rows, cols, 2, 2));

  /* Print a border around the main window and print a title */
  box(my_form_win, 0, 0);
  print_in_middle(my_form_win, 1, 0, cols + 4, "Create new complex",
                  COLOR_PAIR(1));

  post_form(my_form);
  wrefresh(my_form_win);

  mvprintw(LINES - 2, 0, "Use UP, DOWN arrow keys to switch between fields");
  refresh();

  bool quit = false;

  /* Loop through to get user requests */
  while ((ch = wgetch(my_form_win))) {
    switch (ch) {
    case KEY_DOWN:
      /* Go to next field */
      form_driver(my_form, REQ_NEXT_FIELD);
      /* Go to the end of the present buffer */
      /* Leaves nicely at the last character */
      form_driver(my_form, REQ_END_LINE);
      break;
    case KEY_UP:
      /* Go to previous field */
      form_driver(my_form, REQ_PREV_FIELD);
      form_driver(my_form, REQ_END_LINE);
      break;
    case 27:
      quit = true;
      break;
    default:
      /* If this is a normal character, it gets */
      /* Printed				  */
      form_driver(my_form, ch);
      break;
    }

    if (quit) {
      break;
    }
  }

  /* Un post form and free the memory */
  unpost_form(my_form);
  free_form(my_form);
  free_field(field[0]);
  free_field(field[1]);

  endwin();
}

void Subject::notify() {
  for (int i = 0; i < views.size(); i++)
    this->views[i]->update();
}
