#ifndef FINAL_APPLICATION_H
#define FINAL_APPLICATION_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "GUIComponent.h"
#include "Kologo.h"

class Application
{
private:
    sf::RenderWindow window;
    // Data structure to hold things that we want to draw, so we don't
    // have to manually input each one.
    std::vector<GUIComponent*> objects;

    void runLoop();
    void eventListener();
public:
    Application();
    Application(sf::VideoMode videoMode, std::string title);
    void run();
    void addDrawable(GUIComponent& object);
    void test();
};

#endif //FINAL_APPLICATION_H
