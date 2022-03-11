#include <vector>
#include "mat.hpp"

using namespace std;

void checkInput(int cols, int rows, char symb1, char symb2);

string vectorToString(vector <vector<char>> matrix, int rows, int cols);

namespace ariel {

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
        return vectorToString(matrix, rows, cols); //todo: deep copy of matrix?
    }
}

void checkInput(int cols, int rows, char symb1, char symb2) {
    if (rows < 0 || cols < 0 || rows % 2 == 0 || cols % 2 == 0 || isspace(symb1) != 0 || isspace(symb2) != 0 ||
        symb1 == '\0' || symb2 == '\0') {
        throw std::invalid_argument("invalid input");
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