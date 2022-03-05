#include "doctest.h"
#include "mat.hpp"

using namespace ariel;

TEST_CASE ("Good input") {
            CHECK((mat(9, 7, '@', '-')) == "1");
    /* Add more test here */
}

TEST_CASE ("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
/* Add more test here */
}