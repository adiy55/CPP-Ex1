#include "doctest.h"
#include "mat.hpp"

using namespace ariel;

#include <string>
#include <algorithm>
#include <limits>

int MAX_INT = std::numeric_limits<int>::max();
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}


TEST_CASE ("Good input") {
            CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                            "@-------@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-@---@-@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-------@\n"
                                                            "@@@@@@@@@"));
            CHECK(mat(1, 1, '#', '&') == "#"); // checks that first char was taken
            CHECK(nospaces(mat(3, 3, '#', '!')) == nospaces("###\n"
                                                            "#!#\n"
                                                            "###"));

            CHECK(nospaces(mat(3, 5, '*', 'A')) == nospaces("***\n"
                                                            "*A*\n"
                                                            "*A*\n"
                                                            "*A*\n"
                                                            "***"));

            CHECK(nospaces(mat(5, 3, '*', 'A')) == nospaces("*****\n"
                                                            "*AAA*\n"
                                                            "*****"));


            CHECK(nospaces(mat(5, 3, '*', 'A')) != nospaces(mat(5, 3, '*', 'a')));
    /* Add more test here */
}

TEST_CASE ("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(7, 20, '$', '%'));
    CHECK_THROWS(mat(0, 0, '$', '%'));

    CHECK_THROWS(mat(0, 0, '$', '%'));
    CHECK_THROWS(mat(5, 0, '$', '%'));
    CHECK_THROWS(mat(5, -1, '$', '%'));

    CHECK_THROWS(mat(3, 5, '\n', '*'));
    CHECK_THROWS(mat(9, 7, '^', '\r'));
    CHECK_THROWS(mat(1, 3, '\n', '\t'));

    CHECK_THROWS(mat(5, 7, ' ', '7'));
    CHECK_THROWS(mat(7, 7, '@', ' '));
    CHECK_THROWS(mat(5, 5, ' ', ' '));

    CHECK_THROWS(mat(MAX_INT, 7, '@', '&')); // todo: check val
    CHECK_THROWS(mat(15, MAX_INT, '*', '&'));
    CHECK_THROWS(mat(MAX_INT, MAX_INT, '*', '&'));

    CHECK_THROWS(mat(5, 5, '*', '*')); // todo: ?

    /* Add more test here */
}
