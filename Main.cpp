#include "mat.hpp"

using std::cin, std::cout, std::endl;

int main() {
    int mode;
    cout << "For preset input enter 0\nFor user input enter 1\n";
    cin >> mode;
    if (mode == 0) {
        cout << "7x9:\n";
        cout << ariel::mat(9, 7, '@', '-') << endl;
        cout << "\n5x13:\n";
        cout << ariel::mat(13, 5, 'A', '*') << endl;
    }
    if (mode == 1) {
        int rows, cols;
        char symbol1, symbol2;
        cout << "Enter (with spaces in between): rows, columns, first symbol, second symbol\n";
        cin >> rows >> cols >> symbol1 >> symbol2;
        cout << ariel::mat(cols, rows, symbol1, symbol2) << endl;
    }
    return 0;
}
