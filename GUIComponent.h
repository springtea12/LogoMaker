#ifndef FINAL_GUICOMPONENT_H
#define FINAL_GUICOMPONENT_H
#include <SFML/Graphics.hpp>
#include "States.h"

class GUIComponent : public sf::Drawable, public States
{
public:
    // Pure virtual function. "= 0" will make children implement the function.
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;

    // Update is also forced.
    virtual void update() = 0;
};


#endif //FINAL_GUICOMPONENT_H
