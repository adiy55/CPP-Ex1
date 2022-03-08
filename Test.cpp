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

    // given the same symbol
            CHECK(nospaces(mat(9, 7, '@', '@')) == nospaces("@@@@@@@@@\n"
                                                            "@@@@@@@@@\n"
                                                            "@@@@@@@@@\n"
                                                            "@@@@@@@@@\n"
                                                            "@@@@@@@@@\n"
                                                            "@@@@@@@@@\n"
                                                            "@@@@@@@@@"));

    // single char matrix, should take the first symbol
            CHECK(mat(1, 1, '#', '&') == "#");

    // square matrix
            CHECK(nospaces(mat(3, 3, '#', '!')) == nospaces("###\n"
                                                            "#!#\n"
                                                            "###"));

            CHECK(nospaces(mat(3, 5, '*', 'A')) == nospaces("***\n"
                                                            "*A*\n"
                                                            "*A*\n"
                                                            "*A*\n"
                                                            "***"));
    // switched rows and columns of previous case
            CHECK(nospaces(mat(5, 3, '*', 'A')) == nospaces("*****\n"
                                                            "*AAA*\n"
                                                            "*****"));

    // case-sensitive: changed symbol from uppercase to lowercase
            CHECK(nospaces(mat(5, 3, '*', 'A')) != nospaces(mat(5, 3, '*', 'a')));

    // same size, using single (but different) chars
            CHECK(nospaces(mat(5, 5, '$', '$')) != nospaces(mat(5, 5, '*', '*')));

}

TEST_CASE ("Bad input") {
    // even matrix size
            CHECK_THROWS(mat(10, 5, '$', '%'));
            CHECK_THROWS(mat(7, 20, '$', '%'));
            CHECK_THROWS(mat(0, 0, '$', '%'));
    // negative matrix size
            CHECK_THROWS(mat(-5, 0, '$', '%'));
            CHECK_THROWS(mat(0, -9, '$', '%'));
            CHECK_THROWS(mat(-5, -1, '$', '%'));
    // newline, tab, null terminator
            CHECK_THROWS(mat(3, 5, '\n', '*'));
            CHECK_THROWS(mat(9, 7, '^', '\r'));
            CHECK_THROWS(mat(1, 3, '\n', '\t'));
            CHECK_THROWS(mat(1, 3, '\0', '&'));
            CHECK_THROWS(mat(3, 19, '5', '\0'));
    // space character
            CHECK_THROWS(mat(5, 7, ' ', '7'));
            CHECK_THROWS(mat(7, 7, '@', ' '));
            CHECK_THROWS(mat(5, 5, ' ', ' '));

}
