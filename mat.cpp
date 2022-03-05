#include "mat.hpp"

using namespace std;

string ariel::mat(int cols, int rows, char symb1, char symb2) {
    if (cols % 2 == 0 || rows % 2 == 0) {
        throw "Mat size is always odd";
    }
    return "1";
}
