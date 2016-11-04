#include "../libs/auditoriumList.hpp"
#include "../libs/catch.hpp"
#include "../libs/developer.hpp"
#include "../libs/dynamicArrayList.hpp"
#include "../libs/dynamicSizedMatrix.hpp"
#include "../libs/fixedSizedMatrix.hpp"
#include "../libs/integer.hpp"
#include "../libs/listAsDLL.hpp"
#include "../libs/listAsSLL.hpp"
#include "../libs/listAsVector.hpp"
#include "../libs/nullObject.hpp"
#include "../libs/variable.hpp"

#include <memory>
#include <sstream> // std::stringstream

TEST_CASE("Integer object should be same as actual integer", "[integer]") {
  std::unique_ptr<Integer> o(new Integer(3));
  REQUIRE((int)*o == 3);
  o.reset();
}

TEST_CASE("Integer object should not be NULL", "[integer]") {
  std::unique_ptr<Integer> o(new Integer(3));
  REQUIRE(o->isNull() == false);
  o.reset();
}

TEST_CASE("NULL object is NULL", "[nullObject]") {
  std::unique_ptr<Object> o(new NullObject());
  REQUIRE(o->isNull() == true);
  o.reset();
}

TEST_CASE("List as vector tests", "[ListAsVector]") {
  std::shared_ptr<Object> o1 = std::make_shared<NullObject>(NullObject());
  std::shared_ptr<Object> o2 = std::make_shared<NullObject>(NullObject());
  std::shared_ptr<Object> o3 = std::make_shared<NullObject>(NullObject());

  std::unique_ptr<List> l(new ListAsVector());

  l->insert(o1);
  l->insert(o2);
  l->insert(o3);

  std::stringstream ss;

  (*l)[0]->print(ss);
  (*l)[1]->print(ss);
  (*l)[2]->print(ss);

  std::string result = "NullObject\nNullObject\nNullObject\n";

  REQUIRE(ss.str() == result);

  SECTION("Removing an object should should cause it not to be listed") {
    l->remove((o2));
    ss.str("");

    bool error = false;

    try {
      (*l)[0]->print(ss);
      (*l)[1]->print(ss);
      (*l)[2]->print(ss);
      (*l)[3]->print(ss);
    } catch (...) {
      error = true;
    }

    result = "NullObject\nNullObject\n";

    REQUIRE(error == true);
    REQUIRE(ss.str() == result);
  }

  SECTION("Shrinking list should cause objects not to be listed") {
    l->shrink();
    l->shrink();

    ss.str("");

    bool error = false;

    try {
      (*l)[0]->print(ss);
      (*l)[1]->print(ss);
      (*l)[2]->print(ss);
      (*l)[3]->print(ss);
    } catch (...) {
      error = true;
    }

    result = "NullObject\n";

    REQUIRE(error == true);
    REQUIRE(ss.str() == result);
  }

  SECTION("Shrinking list that is empty should work") {
    l->shrink();
    l->shrink();
    l->shrink();
    l->shrink();

    ss.str("");

    bool error = false;

    try {
      (*l)[0]->print(ss);
      (*l)[1]->print(ss);
      (*l)[2]->print(ss);
      (*l)[3]->print(ss);
    } catch (...) {
      error = true;
    }

    result = "";

    REQUIRE(error == true);
    REQUIRE(ss.str() == result);
  }

  o1.reset();
  o2.reset();
  o3.reset();
}

TEST_CASE("List as dynamic array list tests", "[dynamicArrayList]") {
  std::shared_ptr<Object> o1 = std::make_shared<NullObject>(NullObject());
  std::shared_ptr<Object> o2 = std::make_shared<NullObject>(NullObject());
  std::shared_ptr<Object> o3 = std::make_shared<NullObject>(NullObject());

  std::unique_ptr<List> l(new DynamicArrayList());

  l->insert((o1));
  l->insert((o2));
  l->insert((o3));

  std::stringstream ss;

  (*l)[0]->print(ss);
  (*l)[1]->print(ss);
  (*l)[2]->print(ss);

  std::string result = "NullObject\nNullObject\nNullObject\n";

  REQUIRE(ss.str() == result);

  SECTION("Removing an object should should cause it not to be listed") {
    l->remove((o2));
    ss.str("");

    bool error = false;

    try {
      (*l)[0]->print(ss);
      (*l)[1]->print(ss);
      (*l)[2]->print(ss);
      (*l)[3]->print(ss);
    } catch (...) {
      error = true;
    }

    result = "NullObject\nNullObject\n";

    REQUIRE(error == true);
    REQUIRE(ss.str() == result);
  }

  SECTION("Shrinking list should cause objects not to be listed") {
    l->shrink();
    l->shrink();

    ss.str("");

    bool error = false;

    try {
      (*l)[0]->print(ss);
      (*l)[1]->print(ss);
      (*l)[2]->print(ss);
      (*l)[3]->print(ss);
    } catch (...) {
      error = true;
    }

    result = "NullObject\n";

    REQUIRE(error == true);
    REQUIRE(ss.str() == result);
  }

  SECTION("Shrinking list that is empty should work") {
    l->shrink();
    l->shrink();
    l->shrink();
    l->shrink();

    ss.str("");

    bool error = false;

    try {
      (*l)[0]->print(ss);
      (*l)[1]->print(ss);
      (*l)[2]->print(ss);
      (*l)[3]->print(ss);
    } catch (...) {
      error = true;
    }

    result = "";

    REQUIRE(error == true);
    REQUIRE(ss.str() == result);
  }
}

TEST_CASE("List as single linked list tests", "[listAsSLL]") {
  std::shared_ptr<Object> o1 = std::make_shared<NullObject>(NullObject());
  std::shared_ptr<Object> o2 = std::make_shared<NullObject>(NullObject());
  std::shared_ptr<Object> o3 = std::make_shared<NullObject>(NullObject());

  std::unique_ptr<List> l(new ListAsSLL());

  l->insert((o1));
  l->insert((o2));
  l->insert((o3));

  std::stringstream ss;

  (*l)[0]->print(ss);
  (*l)[1]->print(ss);
  (*l)[2]->print(ss);

  std::string result = "NullObject\nNullObject\nNullObject\n";

  REQUIRE(ss.str() == result);

  SECTION("Removing an object should should cause it not to be listed") {
    l->remove(o2);
    ss.str("");

    bool error = false;

    try {
      (*l)[0]->print(ss);
      (*l)[1]->print(ss);
      (*l)[2]->print(ss);
      (*l)[3]->print(ss);
    } catch (...) {
      error = true;
    }

    result = "NullObject\nNullObject\n";

    REQUIRE(error == true);
    REQUIRE(ss.str() == result);
  }

  SECTION("Shrinking list should cause objects not to be listed") {
    l->shrink();
    l->shrink();

    ss.str("");

    bool error = false;

    try {
      (*l)[0]->print(ss);
      (*l)[1]->print(ss);
      (*l)[2]->print(ss);
      (*l)[3]->print(ss);
    } catch (...) {
      error = true;
    }

    result = "";

    REQUIRE(error == true);
    REQUIRE(ss.str() == result);
  }
  SECTION("Shrinking list that is empty should work") {
    l->shrink();
    l->shrink();
    l->shrink();
    l->shrink();

    ss.str("");

    bool error = false;

    try {
      (*l)[0]->print(ss);
      (*l)[1]->print(ss);
      (*l)[2]->print(ss);
      (*l)[3]->print(ss);
    } catch (...) {
      error = true;
    }

    result = "";

    REQUIRE(error == true);
    REQUIRE(ss.str() == result);
  }

  o1.reset();
  o2.reset();
  o3.reset();
}

TEST_CASE("List as doubly linked list tests", "[listAsDLL]") {
  std::shared_ptr<Object> o1 = std::make_shared<NullObject>(NullObject());
  std::shared_ptr<Object> o2 = std::make_shared<NullObject>(NullObject());
  std::shared_ptr<Object> o3 = std::make_shared<NullObject>(NullObject());

  std::unique_ptr<List> l(new ListAsDLL());

  l->insert(o1);
  l->insert(o2);
  l->insert(o3);

  std::stringstream ss;

  (*l)[0]->print(ss);
  (*l)[1]->print(ss);
  (*l)[2]->print(ss);

  std::string result = "NullObject\nNullObject\nNullObject\n";

  REQUIRE(ss.str() == result);

  SECTION("Removing an object should should cause it not to be listed") {
    l->remove(o2);
    ss.str("");

    bool error = false;

    try {
      (*l)[0]->print(ss);
      (*l)[1]->print(ss);
      (*l)[2]->print(ss);
      (*l)[3]->print(ss);
    } catch (...) {
      error = true;
    }

    result = "NullObject\nNullObject\n";

    REQUIRE(error == true);
    REQUIRE(ss.str() == result);
  }

  SECTION("Shrinking list should cause objects not to be listed") {
    l->shrink();
    l->shrink();

    ss.str("");

    bool error = false;

    try {
      (*l)[0]->print(ss);
      (*l)[1]->print(ss);
      (*l)[2]->print(ss);
      (*l)[3]->print(ss);
    } catch (...) {
      error = true;
    }

    result = "";

    REQUIRE(error == true);
    REQUIRE(ss.str() == result);
  }

  SECTION("Shrinking list that is empty should work") {
    l->shrink();
    l->shrink();
    l->shrink();
    l->shrink();

    ss.str("");

    bool error = false;

    try {
      (*l)[0]->print(ss);
      (*l)[1]->print(ss);
      (*l)[2]->print(ss);
      (*l)[3]->print(ss);
    } catch (...) {
      error = true;
    }

    result = "";

    REQUIRE(error == true);
    REQUIRE(ss.str() == result);
  }

  o1.reset();
  o2.reset();
  o3.reset();
}

TEST_CASE("Fixed sized matrix (Vector) tests", "[fixedSizedMatrix]") {
  std::unique_ptr<FixedSizedMatrix> m(new FixedSizedMatrix());

  SECTION("Growing a row should should work") {
    m->growRow(1);
    REQUIRE(m->size() == 1);
  }
  SECTION("Growing a row should grow a column") {
    m->growRow(1);
    int size = (*m)[0]->size();
    // Column size.
    REQUIRE(size == 1);

    m->growRow(1);
    size = (*m)[0]->size();
    // Column size.
    REQUIRE(size == 2);
    size = (*m)[1]->size();
    REQUIRE(size == 2);
  }
  SECTION("Mass grow rows") {
    m->growRow(5);
    int size = (*m)[0]->size();
    // Column size.
    REQUIRE(size == 5);
    size = (*m)[1]->size();
    // Column size.
    REQUIRE(size == 5);
    size = (*m)[2]->size();
    // Column size.
    REQUIRE(size == 5);
    size = (*m)[3]->size();
    // Column size.
    REQUIRE(size == 5);
    size = (*m)[4]->size();
    // Column size.
    REQUIRE(size == 5);
  }
  SECTION("Growing a column should grow a row") {
    m->growColumn(1);
    int size = (*m)[0]->size();

    REQUIRE(size == 1);
    m->growColumn(1);
    size = (*m)[0]->size();
    REQUIRE(size == 2);
    size = (*m)[1]->size();
    REQUIRE(size == 2);
  }
  SECTION("Shrinking a row should shrink both rows and columns") {
    m->growRow(2);
    int size = (*m)[0]->size();
    REQUIRE(size == 2);
    size = (*m)[1]->size();
    REQUIRE(size == 2);

    m->shrinkRow(1);
    size = (*m)[0]->size();
    REQUIRE(size == 1);

    bool thrown = false;

    try {
      size = (*m)[1]->size();
    } catch (...) {
      thrown = true;
    }
    REQUIRE(thrown == true);
  }
  SECTION("Shrinking a column should shrink both rows and columns") {
    m->growColumn(0, 2);
    int size = (*m)[0]->size();
    REQUIRE(size == 2);
    size = (*m)[1]->size();
    REQUIRE(size == 2);

    m->shrinkColumn(0, 1);
    size = (*m)[0]->size();
    REQUIRE(size == 1);

    bool thrown = false;

    try {
      size = (*m)[1]->size();
    } catch (...) {
      thrown = true;
    }
    REQUIRE(thrown == true);
  }
}

TEST_CASE("Fixed sized matrix (DynamicArray) tests", "[fixedSizedMatrix]") {
  std::unique_ptr<FixedSizedMatrix> m(new FixedSizedMatrix(1));

  SECTION("Growing a row should should work") {
    m->growRow();
    REQUIRE(m->size() == 1);
  }
  SECTION("Growing a row should grow a column") {
    m->growRow(1);
    int size = (*m)[0]->size();
    // Column size.
    REQUIRE(size == 1);

    m->growRow(1);
    size = (*m)[0]->size();
    // Column size.
    REQUIRE(size == 2);
    size = (*m)[1]->size();
    REQUIRE(size == 2);
  }
  SECTION("Mass grow rows") {
    m->growRow(5);
    int size = (*m)[0]->size();
    // Column size.
    REQUIRE(size == 5);
    size = (*m)[1]->size();
    // Column size.
    REQUIRE(size == 5);
    size = (*m)[2]->size();
    // Column size.
    REQUIRE(size == 5);
    size = (*m)[3]->size();
    // Column size.
    REQUIRE(size == 5);
    size = (*m)[4]->size();
    // Column size.
    REQUIRE(size == 5);
  }
  SECTION("Growing a column should grow a row") {
    m->growColumn(0, 1);
    int size = (*m)[0]->size();

    REQUIRE(size == 1);
    m->growColumn(0, 1);
    size = (*m)[0]->size();
    REQUIRE(size == 2);
    size = (*m)[1]->size();
    REQUIRE(size == 2);
  }
  SECTION("Shrinking a row should shrink both rows and columns") {
    m->growRow(2);
    int size = (*m)[0]->size();
    REQUIRE(size == 2);
    size = (*m)[1]->size();
    REQUIRE(size == 2);

    m->shrinkRow();
    size = (*m)[0]->size();
    REQUIRE(size == 1);

    bool thrown = false;

    try {
      size = (*m)[1]->size();
    } catch (...) {
      thrown = true;
    }
    REQUIRE(thrown == true);
  }
  SECTION("Shrinking a column should shrink both rows and columns") {
    m->growColumn(0, 2);
    int size = (*m)[0]->size();
    REQUIRE(size == 2);
    size = (*m)[1]->size();
    REQUIRE(size == 2);

    m->shrinkColumn(0, 1);
    size = (*m)[0]->size();
    REQUIRE(size == 1);

    bool thrown = false;

    try {
      size = (*m)[1]->size();
    } catch (...) {
      thrown = true;
    }
    REQUIRE(thrown == true);
  }
}

TEST_CASE("Dynamic sized matrix tests (SLL)", "[fixedSizedMatrix]") {
  std::unique_ptr<DynamicSizedMatrix> m(new DynamicSizedMatrix(0));

  SECTION("Growing a row should should work") {
    m->growRow(1);
    REQUIRE(m->size() == 1);
  }
  SECTION("Growing a row should not grow a column") {
    m->growRow(1);
    int size = (*m)[0]->size();
    // Column size.
    REQUIRE(size == 0);

    m->growRow(1);
    size = (*m)[0]->size();
    // Column size.
    REQUIRE(size == 0);
    size = (*m)[1]->size();
    REQUIRE(size == 0);
  }
  SECTION("Growing a column should not grow a row") {
    m->growRow(1);
    m->growColumn(0, 1);
    int size = (*m)[0]->size();
    REQUIRE(size == 1);

    m->growColumn(0, 1);
    size = (*m)[0]->size();
    REQUIRE(size == 2);

    bool thrown = false;

    try {
      size = (*m)[1]->size();
    } catch (...) {
      thrown = true;
    }
    REQUIRE(thrown == true);
  }
  SECTION("Shrinking a row should not shrink both rows and columns") {
    m->growRow(2);

    int size = (*m)[0]->size();
    REQUIRE(size == 0);
    size = (*m)[1]->size();
    REQUIRE(size == 0);
  }
  SECTION("Shrinking a column should not shrink both rows and columns") {
    m->growRow(1);
    m->growColumn(0, 2);
    int size = (*m)[0]->size();
    REQUIRE(size == 2);

    m->shrinkColumn(0, 1);
    size = (*m)[0]->size();
    REQUIRE(size == 1);

    bool thrown = false;

    try {
      size = (*m)[1]->size();
    } catch (...) {
      thrown = true;
    }
    REQUIRE(thrown == true);
  }
}

TEST_CASE("Auditorium tests (Fixed)", "[auditorium]") {
  std::unique_ptr<Auditorium> a(new Fixed("Fixed Auditorium 1"));

  REQUIRE(a->getName() == "Fixed Auditorium 1");

  SECTION("Give a fixed auditorium we should be able to add rows") {
    // Add 5 rows.
    a->addRow(5);

    SECTION("All seats should be empty.") {
      // Row 1, Column 3.
      for (size_t i = 0; i < 5; i++) {
        for (size_t x = 0; x < 5; x++) {
          std::shared_ptr<Seat> s = a->getSeat(i, x);
          REQUIRE(s->isTaken() == false);
        }
      }
    }

    SECTION("We should not be able to ask for a seat that doesn't exit") {
      REQUIRE_THROWS(a->getSeat(100, 1));
    }
  }
}

TEST_CASE("Auditorium tests (Variable)", "[auditorium]") {
  std::unique_ptr<Variable> a(new Variable("Variable Auditorium 1"));

  REQUIRE(a->getName() == "Variable Auditorium 1");

  SECTION("Given a Variable auditorium we should be able to add rows") {
    // Add 5 rows.
    a->addRow(5);

    SECTION("In a variable auditorium the columns should not have grown") {
      REQUIRE_THROWS(a->getSeat(0, 0));
    }

    SECTION("A variable auditorium should have modifiable rows") {
      a->addSeatsInRow(0, 2);
      a->addSeatsInRow(1, 1);
      a->addSeatsInRow(2, 0);
      a->addSeatsInRow(3, 6);
      a->addSeatsInRow(4, 0);

      REQUIRE(a->getSeat(0, 0)->isTaken() == false);
      REQUIRE(a->getSeat(0, 1)->isTaken() == false);
      REQUIRE(a->getSeat(1, 0)->isTaken() == false);
      REQUIRE_THROWS(a->getSeat(2, 0));
      REQUIRE_THROWS(a->getSeat(4, 0));
    }

    SECTION("A variable auditorium can have seats in the middle of no where") {
      a->addSeat(3, 3);
      REQUIRE(a->getSeat(3, 3)->isTaken() == false);
      REQUIRE_THROWS(a->getSeat(3, 2));
    }

    SECTION("We should not be able to ask for a seat that doesn't exit") {
      REQUIRE_THROWS(a->getSeat(100, 1));
    }
  }
}

TEST_CASE("Auditorium developer tests", "[developer]") {
  std::shared_ptr<AuditoriumList> list(new AuditoriumList());
  std::unique_ptr<Developer> d(new Developer(list));

  d->newFixedAuditorium(5, "Fixed Auditorium 1");

  REQUIRE(list->at(0)->getName() == "Fixed Auditorium 1");

  d->newVariableAuditorium(5, "Variable Auditorium 1");

  REQUIRE(list->at(1)->getName() == "Variable Auditorium 1");
}
