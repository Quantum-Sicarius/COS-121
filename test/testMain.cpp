#include "../libs/catch.hpp"
#include "../libs/dynamicArrayList.hpp"
#include "../libs/dynamicSizedMatrix.hpp"
#include "../libs/fixedSizedMatrix.hpp"
#include "../libs/flexiMatrix.hpp"
#include "../libs/integer.hpp"
#include "../libs/listAsDLL.hpp"
#include "../libs/listAsSLL.hpp"
#include "../libs/listAsVector.hpp"
#include "../libs/nullObject.hpp"

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

  std::unique_ptr<List<std::shared_ptr<Object>>> l(
      new ListAsVector<std::shared_ptr<Object>>());

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

  std::unique_ptr<List<std::shared_ptr<Object>>> l(
      new DynamicArrayList<std::shared_ptr<Object>>());

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

  std::unique_ptr<List<std::shared_ptr<Object>>> l(
      new ListAsSLL<std::shared_ptr<Object>>());

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

  std::unique_ptr<List<std::shared_ptr<Object>>> l(
      new ListAsDLL<std::shared_ptr<Object>>());

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

TEST_CASE("Fixed sized matrix tests", "[fixedSizedMatrix]") {
  std::unique_ptr<FixedSizedMatrix<std::shared_ptr<Object>>> m(
      new FixedSizedMatrix<std::shared_ptr<Object>>());

  SECTION("Growing a row should should work") {
    m->growRow(1);
    REQUIRE(m->size() == 1);
  }
  SECTION("Growing a row should grow a column") {
    m->growRow(1);
    int size = (*m)[0].size();
    // Column size.
    REQUIRE(size == 1);

    m->growRow(1);
    size = (*m)[0].size();
    // Column size.
    REQUIRE(size == 2);
    size = (*m)[1].size();
    REQUIRE(size == 2);
  }
  SECTION("Growing a column should grow a row") {
    m->growColumn(1);
    int size = (*m)[0].size();
    REQUIRE(size == 1);
    m->growColumn(1);
    size = (*m)[1].size();
    REQUIRE(size == 2);
  }
  SECTION("Shrinking a row should shrink both rows and columns") {
    m->growRow(2);
    int size = (*m)[0].size();
    REQUIRE(size == 2);
    size = (*m)[1].size();
    REQUIRE(size == 2);

    m->shrinkRow(1);
    size = (*m)[0].size();
    REQUIRE(size == 1);

    bool thrown = false;

    try {
      size = (*m)[1].size();
    } catch (...) {
      thrown = true;
    }
    REQUIRE(thrown == true);
  }
  SECTION("Shrinking a column should shrink both rows and columns") {
    m->growColumn(2);
    int size = (*m)[0].size();
    REQUIRE(size == 2);
    size = (*m)[1].size();
    REQUIRE(size == 2);

    m->shrinkColumn(1);
    size = (*m)[0].size();
    REQUIRE(size == 1);

    bool thrown = false;

    try {
      size = (*m)[1].size();
    } catch (...) {
      thrown = true;
    }
    REQUIRE(thrown == true);
  }
}
