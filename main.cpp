#include <iostream>
#include "camera.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Camera* test = new Camera();
    test->Render();
    test->CreateImage();
    delete(test);
    return 0;
}
