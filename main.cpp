#include <iostream>
#include "scene.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Scene* test = new Scene();

    delete(test);

    return 0;
}