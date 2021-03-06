#include <vector>
#include "mat.hpp"

using std::string;
using std::vector;
using std::invalid_argument;

namespace ariel {
    /**
     * Throws exception if the input is invalid.
     */
    void checkInput(int rows, int cols, char symb1, char symb2) {
        if (rows < 1 || cols < 1) {
            throw invalid_argument("Dimensions should be positive numbers!");
        }
        if (rows % 2 == 0 || cols % 2 == 0) {
            throw invalid_argument("Dimensions should be odd numbers!");
        }
        if (isspace(symb1) != 0 || isspace(symb2) != 0 || symb1 == '\0' || symb2 == '\0') {
            throw invalid_argument("Spaces, newlines and null terminators are invalid characters!");
        }
        if (isprint(symb1) == 0 || isprint(symb2) == 0) { // isprint function: https://tinyurl.com/2p9dyfa
            throw invalid_argument("Characters should be printable!");
        }
    }

    /**
     * Converts vector matrix to string. Adds a newline to every row except the last.
     * @return rug pattern as string
     */
    string vectorToString(vector<vector<char>> matrix, int rows, int cols) {
        string res;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                res += matrix.at(i).at(j);
            }
            if (i < rows - 1) {
                res += "\n";
            }
        }
        return res;
    }

    /**
     * Main function that creates the rug pattern.
     *
     * Vector: Stores elements in a dynamically allocated array.
     * Elements can be accessed using the operator[] or using at.
     * Both return a reference to the element, but only 'at' checks if the given position is in bounds
     * (and throws an out of range exception if it is not).
     * For more information: https://www.cplusplus.com/reference/vector/vector/
     */
    string mat(int cols, int rows, char symb1, char symb2) {
        checkInput(rows, cols, symb1, symb2);
        vector<vector<char>> matrix(rows, vector<char>(cols));
        int curr_row = 0;
        int curr_col = 0;
        char curr_symbol = symb1; // outer ring is always first symbol
        while (curr_row < rows && curr_col < cols) {
            for (int i = curr_row; i < rows - curr_row; ++i) { // fill columns in current layer
                matrix.at(i).at(curr_col) = curr_symbol;
                matrix.at(i).at(cols - curr_col - 1) = curr_symbol;
            }
            for (int i = curr_col; i < cols - curr_col; ++i) { // fill rows in current layer
                matrix.at(curr_row).at(i) = curr_symbol;
                matrix.at(rows - curr_row - 1).at(i) = curr_symbol;
            }
            curr_row += 1;
            curr_col += 1;
            curr_symbol = curr_symbol == symb1 ? symb2 : symb1; // alternate symbols
        }
        return vectorToString(matrix, rows, cols); // vector is passed by value
    }
}