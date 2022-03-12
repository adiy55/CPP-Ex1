#include "mat.hpp"

using std::cin, std::cout, std::endl;

int main() {
    int rows, cols;
    char symbol1, symbol2;
    cin >> rows >> cols >> symbol1 >> symbol2;
    cout << ariel::mat(rows, cols, symbol1, symbol2) << endl;
    return 0;
}
