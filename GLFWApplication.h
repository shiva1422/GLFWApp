//
// Created by shivaaz on 5/12/23.
//

#ifndef GLFW_GLFWAPPLICATION_H
#define GLFW_GLFWAPPLICATION_H

#include "Application.hpp"

class GLFWwindow;
class GLFWApplication : public  KSApplication{
    
public:
    
    ~GLFWApplication() override;

    void run() override;

protected:
    void onWindowInit() override;

    void onDestroy() override;

    GLFWwindow* window = nullptr;


};


#endif //GLFW_GLFWAPPLICATION_H
