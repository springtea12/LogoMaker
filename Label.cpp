#include "Label.h"

Label::Label()
{
    setFont(Font::getFont());
    setCharacterSize(40);
    setPosition(110, 120);
    setFillColor(sf::Color::White);
}

Label::Label(std::string label)
{
    setFont(Font::getFont());
    setCharacterSize(50);
    setFillColor(sf::Color::White);
    setString(label);
    setPosition(110, 120);
}

void Label::setLabel(std::string label)
{
    setString(label);
}

std::string Label::getLabel()
{
    return getString();
}

void Label::setPos(float x, float y)
{
    setPosition(x, y);
}
