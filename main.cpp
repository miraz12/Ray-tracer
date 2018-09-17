#include <iostream>
#include "triangle.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Triangle* test = new Triangle();

    delete(test);

    return 0;
}