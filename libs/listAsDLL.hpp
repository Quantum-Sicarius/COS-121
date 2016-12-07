/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T22:41:58+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:26+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef LISTASDLL_H
#define LISTASDLL_H

#include "listAsSLL.hpp"

class ListAsDLL : public ListAsSLL {
private:
  int listSize = 0;

  struct Node {
    std::shared_ptr<Object> value;
    std::unique_ptr<Node> next;
    Node *prev;

    Node(std::shared_ptr<Object> v, std::unique_ptr<Node> n, Node *p) {
      value = v;
      next = std::move(n);
      prev = p;
    }

    ~Node() {}
  };

protected:
  int compareTo(Object const &) const;
  std::unique_ptr<Node> head;
  // std::unique_ptr<Node> tail;

public:
  ListAsDLL();
  ~ListAsDLL();
  void insert(std::shared_ptr<Object> o);

  void remove(std::shared_ptr<Object> o);

  void grow(int);

  void shrink(int);
  int size();

  std::shared_ptr<Object> &operator[](int i);
  void print(std::ostream &o) const;
};
#endif
