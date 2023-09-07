#ifndef TEXTINPUT_BOX_H
#define TEXTINPUT_BOX_H
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
class Box : public GUIComponent
{
private:
    sf::RectangleShape box;
    bool type;
public:
    Box();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    bool acceptType();
    void setPos(sf::Vector2f pos);
};


#endif //TEXTINPUT_BOX_H
