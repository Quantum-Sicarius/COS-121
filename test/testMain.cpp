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

  // Object o1 = new NullObject();
  // Object o2 = new NullObject();
  // Object o3 = new NullObject();

  std::unique_ptr<List<std::shared_ptr<Object>>> l(
      new ListAsVector<std::shared_ptr<Object>>());

  // std::unique_ptr<List<Object>> l(new ListAsVector<Object>());

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

TEST_CASE("Fiex sized matrix tests", "[fixedSizedMatrix]") {
  // Matrix *m = new FixedSizedMatrix();
  //
  // delete m;
}
