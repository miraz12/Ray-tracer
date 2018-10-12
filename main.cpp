#define GLM_ENABLE_EXPERIMENTAL 1
#include <iostream>
#include "camera.h"

int main() {
    Camera* test = new Camera();
    test->Render();
    test->CreateImage();
    delete(test);
    std::cout << "Finished render" << std::endl;
    return 0;
}
