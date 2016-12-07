/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-06T22:39:34+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:17:27+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#ifndef LISTASSLL_H
#define LISTASSLL_H

#include "list.hpp"
#include "nullObject.hpp"

class ListAsSLL : public List {
private:
  int listSize = 0;

  struct Node {
    std::shared_ptr<Object> value;
    std::unique_ptr<Node> next;

    Node(std::shared_ptr<Object> v, std::unique_ptr<Node> n) {
      value = v;
      next = std::move(n);
    }
  };

  void shrinkList();

protected:
  int compareTo(Object const &) const;
  std::unique_ptr<Node> head;

public:
  ListAsSLL();

  ~ListAsSLL();

  void insert(std::shared_ptr<Object> o);

  void remove(std::shared_ptr<Object> o);

  void grow(int);

  void shrink(int);

  int size();

  std::shared_ptr<Object> &operator[](int i);

  void print(std::ostream &o) const;
};
#endif
