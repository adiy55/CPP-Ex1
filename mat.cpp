#include <vector>
#include "mat.hpp"

using std::string;
using std::vector;
using std::invalid_argument;

namespace ariel {
    // todo: unreachable
    void checkInput(int cols, int rows, char symb1, char symb2) {
        if (rows < 1 || cols < 1) {
            throw invalid_argument("Dimensions should be positive numbers!");
        }
        if (rows % 2 == 0 || cols % 2 == 0) {
            throw invalid_argument("Dimensions should be odd numbers!");
        }
        if (isspace(symb1) != 0 || isspace(symb2) != 0 || symb1 == '\0' || symb2 == '\0') {
            throw invalid_argument("Spaces, newlines and null terminators are invalid characters!");
        }
        if (isprint(symb1) == 0 || isprint(symb2) == 0) {
            throw invalid_argument("Characters should be printable!");
        }
    }

    string vectorToString(vector <vector<char>> matrix, int rows, int cols) {
        string res;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                res += matrix[i][j];
            }
            if (i < rows - 1) {
                res += "\n";
            }
        }
        return res;
    }

    string mat(int cols, int rows, char symb1, char symb2) {
        checkInput(cols, rows, symb1, symb2);
        vector <vector<char>> matrix(rows, vector<char>(cols));
        int curr_row = 0;
        int curr_col = 0;
        char curr_symbol = symb1;
        while (curr_row < rows && curr_col < cols) {
            for (int i = curr_row; i < rows - curr_row; ++i) {
                matrix[i][curr_col] = curr_symbol;
                matrix[i][cols - curr_col - 1] = curr_symbol;
            }
            for (int i = curr_col; i < cols - curr_col; ++i) {
                matrix[curr_row][i] = curr_symbol;
                matrix[rows - curr_row - 1][i] = curr_symbol;
            }
            curr_row += 1;
            curr_col += 1;
            curr_symbol = curr_symbol == symb1 ? symb2 : symb1;
        }
        return vectorToString(matrix, rows, cols); // vector is passed by value
    }
}