#include <iostream>
#include "GLFWApplication.h"
#include "CV/cv_main.hpp"


int main()
{
    std::shared_ptr<GLFWApplication> app = std::make_shared<GLFWApplication>();
    app->run();
    return 0;
}
