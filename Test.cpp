#include "doctest.h"
#include "mat.hpp"

using namespace ariel;

#include <string>
#include <algorithm>

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

            CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                             "@-----------@\n"
                                                             "@-@@@@@@@@@-@\n"
                                                             "@-----------@\n"
                                                             "@@@@@@@@@@@@@"));

            CHECK(nospaces(mat(3, 5, '*', 'A')) == nospaces("***\n"
                                                            "*A*\n"
                                                            "*A*\n"
                                                            "*A*\n"
                                                            "***"));
    // switched rows and columns of previous case
            CHECK(nospaces(mat(5, 3, '*', 'A')) == nospaces("*****\n"
                                                            "*AAA*\n"
                                                            "*****"));

}

TEST_CASE ("Given the same symbol") {

            CHECK(nospaces(mat(9, 7, '@', '@')) == nospaces("@@@@@@@@@\n"
                                                            "@@@@@@@@@\n"
                                                            "@@@@@@@@@\n"
                                                            "@@@@@@@@@\n"
                                                            "@@@@@@@@@\n"
                                                            "@@@@@@@@@\n"
                                                            "@@@@@@@@@"));

}

TEST_CASE ("Single row or column matrix- should use the first symbol") {

            CHECK(mat(1, 1, '#', '&') == "#");

            CHECK(nospaces(mat(1, 9, '$', '@')) == nospaces("$\n"
                                                            "$\n"
                                                            "$\n"
                                                            "$\n"
                                                            "$\n"
                                                            "$\n"
                                                            "$\n"
                                                            "$\n"
                                                            "$"));

            CHECK(mat(9, 1, '*', '&') == "*********");

}

TEST_CASE ("Square matrix") {

            CHECK(nospaces(mat(3, 3, '#', '!')) == nospaces("###\n"
                                                            "#!#\n"
                                                            "###"));

}

TEST_CASE ("Symbol and case-sensitivity") {

    // changed symbol from uppercase to lowercase
            CHECK(nospaces(mat(5, 3, '*', 'A')) != nospaces(mat(5, 3, '*', 'a')));

    // same size matrix, using single (but different) chars
            CHECK(nospaces(mat(5, 5, '$', '$')) != nospaces(mat(5, 5, '*', '*')));

}

TEST_CASE ("Bad input") {
    // contains even numbers
            CHECK_THROWS(mat(10, 5, '$', '%'));

            CHECK_THROWS(mat(7, 20, '$', '%'));

            CHECK_THROWS(mat(0, 0, '$', '%'));

}

TEST_CASE ("Negative input size") {

            CHECK_THROWS(mat(-5, 0, '$', '%'));

            CHECK_THROWS(mat(9, -9, '$', '%'));

            CHECK_THROWS(mat(-5, -1, '$', '%'));

}

TEST_CASE ("Invalid characters- newline, tab, null terminator, space") {

            CHECK_THROWS(mat(3, 5, '\n', '*'));

            CHECK_THROWS(mat(9, 7, '^', '\r'));

            CHECK_THROWS(mat(1, 3, '\n', '\t'));

            CHECK_THROWS(mat(1, 3, '\0', '&'));

            CHECK_THROWS(mat(3, 19, '5', '\0'));

            CHECK_THROWS(mat(5, 7, ' ', '7'));

            CHECK_THROWS(mat(7, 7, '@', ' '));

            CHECK_THROWS(mat(5, 5, ' ', ' '));

}
