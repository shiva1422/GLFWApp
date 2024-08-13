//
// Created by shivaaz on 5/12/23.
//

#ifndef GLFW_GLFWAPPLICATION_H
#define GLFW_GLFWAPPLICATION_H

#include "Application.hpp"
#include "glad/glad.h"

class GLFWwindow;
class GLFWApplication : public  KSApplication{
    
public:
    
    ~GLFWApplication() override;

    void run() override;

protected:
    void onWindowInit() override;

    void onDestroy() override;

    GLFWwindow* window = nullptr;

private:

    bool compileShaders();
    GLuint textureProg = 0;


};


#endif //GLFW_GLFWAPPLICATION_H
