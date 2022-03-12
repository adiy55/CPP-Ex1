#include <vector>
#include "mat.hpp"

using std::string;
using std::vector;
using std::invalid_argument;

namespace ariel {
    // todo: unreachable
    void checkInput(int cols, int rows, char symb1, char symb2) {
        if (rows < 1 || cols < 1 || rows % 2 == 0 || cols % 2 == 0) {
            throw invalid_argument("Invalid integer input!");
        }
        if (isspace(symb1) != 0 || isspace(symb2) != 0 || symb1 == '\0' || symb2 == '\0' || isprint(symb1) == 0 ||
            isprint(symb2) == 0) {
            throw invalid_argument("Invalid char input!");
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
        int left_row = 0;
        int right_row = rows - 1;
        int left_col = 0;
        int right_col = cols - 1;
        char curr_symb = symb1;
        while (left_row <= right_row && left_col <= right_col) {
            for (int i = left_row; i <= right_row; ++i) {
                matrix[i][left_col] = curr_symb;
                matrix[i][right_col] = curr_symb;
            }
            for (int i = left_col; i < right_col; ++i) {
                matrix[left_row][i] = curr_symb;
                matrix[right_row][i] = curr_symb;
            }
            left_row++;
            right_row--;
            left_col++;
            right_col--;
            curr_symb = curr_symb == symb1 ? symb2 : symb1;
        }
        if (left_row == right_row) {
            for (int i = left_col; i <= right_col; ++i) {
                matrix[left_row][i] = curr_symb;
            }
        } else if (left_col == right_col) {
            for (int i = left_row; i <= right_row; ++i) {
                matrix[i][left_col] = curr_symb;
            }
        }
        return vectorToString(matrix, rows, cols); // vector is passed by value
    }

}

