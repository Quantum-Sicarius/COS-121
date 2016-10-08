#include "../libs/catch.hpp"
#include "../libs/nullObject.hpp"
#include "../libs/integer.hpp"
#include "../libs/listAsVector.hpp"
#include "../libs/dynamicArrayList.hpp"
#include "../libs/listAsSLL.hpp"
#include "../libs/listAsDLL.hpp"

#include <sstream>      // std::stringstream

TEST_CASE( "Integer object should be same as actual integer", "[integer]" ) {
        Integer* o = new Integer(3);

        REQUIRE((int)*o == 3);
}

TEST_CASE( "Integer object should not be NULL", "[integer]" ) {
        Integer* o = new Integer(3);
        REQUIRE(o->isNull() == false);
}

TEST_CASE( "NULL object is NULL", "[nullObject]" ) {
        Object* o = new NullObject();

        REQUIRE(o->isNull() == true);
}

TEST_CASE( "List as vector tests", "[ListAsVector]" ) {
        Object* o1 = new NullObject();
        Object* o2 = new NullObject();
        Object* o3 = new NullObject();

        List* l = new ListAsVector();

        l->insert(o1);
        l->insert(o2);
        l->insert(o3);

        std::stringstream ss;

        (*l)[0].print(ss);
        (*l)[1].print(ss);
        (*l)[2].print(ss);

        std::string result = "NullObject\nNullObject\nNullObject\n";

        REQUIRE(ss.str() == result);

        SECTION( "Removing an object should should cause it not to be listed" ) {
                l->remove(o2);
                ss.str("");

                bool error = false;

                try {
                        (*l)[0].print(ss);
                        (*l)[1].print(ss);
                        (*l)[2].print(ss);
                        (*l)[3].print(ss);
                } catch(...) {
                        error = true;
                }

                result = "NullObject\nNullObject\n";

                REQUIRE(error == true);
                REQUIRE(ss.str() == result);
        }

        SECTION( "Shrinking list should cause objects not to be listed" ) {
                l->shrink();
                l->shrink();

                ss.str("");

                bool error = false;

                try {
                        (*l)[0].print(ss);
                        (*l)[1].print(ss);
                        (*l)[2].print(ss);
                        (*l)[3].print(ss);
                } catch(...) {
                        error = true;
                }

                result = "NullObject\n";

                REQUIRE(error == true);
                REQUIRE(ss.str() == result);
        }

        SECTION( "Shrinking list that is empty should work" ) {
                l->shrink();
                l->shrink();
                l->shrink();
                l->shrink();

                ss.str("");

                bool error = false;

                try {
                        (*l)[0].print(ss);
                        (*l)[1].print(ss);
                        (*l)[2].print(ss);
                        (*l)[3].print(ss);
                } catch(...) {
                        error = true;
                }

                result = "";

                REQUIRE(error == true);
                REQUIRE(ss.str() == result);
        }
}

TEST_CASE( "List as dynamic array list tests", "[dynamicArrayList]" ) {
        Object* o1 = new NullObject();
        Object* o2 = new NullObject();
        Object* o3 = new NullObject();

        List* l = new DynamicArrayList();

        l->insert(o1);
        l->insert(o2);
        l->insert(o3);

        std::stringstream ss;

        (*l)[0].print(ss);
        (*l)[1].print(ss);
        (*l)[2].print(ss);

        std::string result = "NullObject\nNullObject\nNullObject\n";

        REQUIRE(ss.str() == result);

        SECTION( "Removing an object should should cause it not to be listed" ) {
                l->remove(o2);
                ss.str("");

                bool error = false;

                try {
                        (*l)[0].print(ss);
                        (*l)[1].print(ss);
                        (*l)[2].print(ss);
                        (*l)[3].print(ss);
                } catch(...) {
                        error = true;
                }

                result = "NullObject\nNullObject\n";

                REQUIRE(error == true);
                REQUIRE(ss.str() == result);
        }

        SECTION( "Shrinking list should cause objects not to be listed" ) {
                l->shrink();
                l->shrink();

                ss.str("");

                bool error = false;

                try {
                        (*l)[0].print(ss);
                        (*l)[1].print(ss);
                        (*l)[2].print(ss);
                        (*l)[3].print(ss);
                } catch(...) {
                        error = true;
                }

                result = "NullObject\n";

                REQUIRE(error == true);
                REQUIRE(ss.str() == result);
        }

        SECTION( "Shrinking list that is empty should work" ) {
                l->shrink();
                l->shrink();
                l->shrink();
                l->shrink();

                ss.str("");

                bool error = false;

                try {
                        (*l)[0].print(ss);
                        (*l)[1].print(ss);
                        (*l)[2].print(ss);
                        (*l)[3].print(ss);
                } catch(...) {
                        error = true;
                }

                result = "";

                REQUIRE(error == true);
                REQUIRE(ss.str() == result);
        }
}

TEST_CASE( "List as single linked list tests", "[listAsSLL]" ) {
        Object* o1 = new NullObject();
        Object* o2 = new NullObject();
        Object* o3 = new NullObject();

        List* l = new ListAsSLL();

        l->insert(o1);
        l->insert(o2);
        l->insert(o3);

        std::stringstream ss;

        (*l)[0].print(ss);
        (*l)[1].print(ss);
        (*l)[2].print(ss);

        std::string result = "NullObject\nNullObject\nNullObject\n";

        REQUIRE(ss.str() == result);

        SECTION( "Removing an object should should cause it not to be listed" ) {
                l->remove(o2);
                ss.str("");

                bool error = false;

                try {
                        (*l)[0].print(ss);
                        (*l)[1].print(ss);
                        (*l)[2].print(ss);
                        (*l)[3].print(ss);
                } catch(...) {
                        error = true;
                }

                result = "NullObject\nNullObject\n";

                REQUIRE(error == true);
                REQUIRE(ss.str() == result);
        }

        SECTION( "Shrinking list should cause objects not to be listed" ) {
                l->shrink();
                l->shrink();

                ss.str("");

                bool error = false;

                try {
                        (*l)[0].print(ss);
                        (*l)[1].print(ss);
                        (*l)[2].print(ss);
                        (*l)[3].print(ss);
                } catch(...) {
                        error = true;
                }

                result = "NullObject\n";

                REQUIRE(error == true);
                REQUIRE(ss.str() == result);
        }
        SECTION( "Shrinking list that is empty should work" ) {
                l->shrink();
                l->shrink();
                l->shrink();
                l->shrink();

                ss.str("");

                bool error = false;

                try {
                        (*l)[0].print(ss);
                        (*l)[1].print(ss);
                        (*l)[2].print(ss);
                        (*l)[3].print(ss);
                } catch(...) {
                        error = true;
                }

                result = "";

                REQUIRE(error == true);
                REQUIRE(ss.str() == result);
        }
}

TEST_CASE( "List as doubly linked list tests", "[listAsDLL]" ) {
        Object* o1 = new NullObject();
        Object* o2 = new NullObject();
        Object* o3 = new NullObject();

        List* l = new ListAsDLL();

        l->insert(o1);
        l->insert(o2);
        l->insert(o3);

        std::stringstream ss;

        (*l)[0].print(ss);
        (*l)[1].print(ss);
        (*l)[2].print(ss);

        std::string result = "NullObject\nNullObject\nNullObject\n";

        REQUIRE(ss.str() == result);

        SECTION( "Removing an object should should cause it not to be listed" ) {
                l->remove(o2);
                ss.str("");

                bool error = false;

                try {
                        (*l)[0].print(ss);
                        (*l)[1].print(ss);
                        (*l)[2].print(ss);
                        (*l)[3].print(ss);
                } catch(...) {
                        error = true;
                }

                result = "NullObject\nNullObject\n";

                REQUIRE(error == true);
                REQUIRE(ss.str() == result);
        }

        SECTION( "Shrinking list should cause objects not to be listed" ) {
                l->shrink();
                l->shrink();

                ss.str("");

                bool error = false;

                try {
                        (*l)[0].print(ss);
                        (*l)[1].print(ss);
                        (*l)[2].print(ss);
                        (*l)[3].print(ss);
                } catch(...) {
                        error = true;
                }

                result = "NullObject\n";

                REQUIRE(error == true);
                REQUIRE(ss.str() == result);
        }

        SECTION( "Shrinking list that is empty should work" ) {
                l->shrink();
                l->shrink();
                l->shrink();
                l->shrink();

                ss.str("");

                bool error = false;

                try {
                        (*l)[0].print(ss);
                        (*l)[1].print(ss);
                        (*l)[2].print(ss);
                        (*l)[3].print(ss);
                } catch(...) {
                        error = true;
                }

                result = "";

                REQUIRE(error == true);
                REQUIRE(ss.str() == result);
        }
}
