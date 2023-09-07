#include "Box.h"

Box::Box()
{
    box.setFillColor(sf::Color::Black);
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::White);
    box.setPosition(350, 105);
    box.setSize({600, 80});
    type = false;
}

void Box::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
        window.draw(box);
}

void Box::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(box.getGlobalBounds().contains(mpos))
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            type = !type;
    if(!box.getGlobalBounds().contains(mpos))
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            if(type)
                type = !type;
    if(type)
    {
        box.setOutlineThickness(3);
        box.setOutlineColor(sf::Color::Magenta);
    }
    else
    {
        box.setOutlineThickness(2);
        box.setOutlineColor(sf::Color::White);
    }

}

void Box::update()
{

}

bool Box::acceptType()
{
    return type;
}

void Box::setPos(sf::Vector2f pos)
{
    box.setPosition(pos);
}
