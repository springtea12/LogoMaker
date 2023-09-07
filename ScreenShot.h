#ifndef FINAL_SCREENSHOT_H
#define FINAL_SCREENSHOT_H
#include "GUIComponent.h"
#include <iostream>
#include <string>

class ScreenShot
{
private:
    sf::Texture texture;
public:
    ScreenShot();
    void takeScreenShot(sf::RenderWindow &window, std::string filename);
};

#endif //FINAL_SCREENSHOT_H