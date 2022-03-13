#include "mat.hpp"

void preset(void);

void userInput(void);

using std::cin;
using std::cout;
using std::endl;
using std::exception;
using ariel::mat;

int main() {
    int mode;
    while (cin) { // continues while cin was successful // https://stackoverflow.com/questions/19483126/whats-the-difference-between-whilecin-and-whilecin-num
        cout << "For preset input enter 1\nFor user input enter 2\nEnter any other character to exit\n";
        cin >> mode;
        if (mode == 1) {
            preset();
        } else if (mode == 2) {
            userInput();
        } else {
            cout << "Exiting program\n";
            return 0;
        }
    }
    return 0;
}

/**
 * Prints preset rug according to user selection.
 */
void preset() {
    int selection;
    cout << "Select:\n1 = 7x9 | 2 = 5x13 | 3 = 5x5\n";
    cin >> selection;
    if (selection == 1) {
        cout << mat(9, 7, '@', '-') << endl;
    } else if (selection == 2) {
        cout << mat(13, 5, 'A', '*') << endl;
    } else if (selection == 3) {
        cout << mat(5, 5, '$', '!') << endl;
    } else {
        cout << "Invalid selection\n";
    }
}

/**
 * Prints rug when given a valid user input.
 */
void userInput() {
    int rows, cols;
    char symbol1, symbol2;
    cout << "Enter (with spaces in between): rows, columns, first symbol, second symbol\n";
    cin >> rows >> cols >> symbol1 >> symbol2;
    try {
        cout << mat(cols, rows, symbol1, symbol2) << endl;
    } catch (exception &ex) {
        cout << "Invalid input: " << ex.what() << endl;
    }
}