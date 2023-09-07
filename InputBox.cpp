#include "InputBox.h"
InputBox::InputBox() : InputBox("Click here")
{
}

InputBox::InputBox(std::string string)
{
    label.setString(string);
    label.setFont(Font::getFont());
    label.setFillColor(sf::Color::White);

    rect.setSize({400, 50});
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineThickness(2);
    rect.setOutlineColor(sf::Color::White);
    Helper::centerText(rect, label);
}

void InputBox::setLabel(std::string string)
{
    label.setString(string);
    Helper::centerText(rect, label);
}

std::string InputBox::getString()
{
    return label.getString();
}

void InputBox::setPos(sf::Vector2f pos)
{
    rect.setPosition(pos);
    Helper::centerText(rect, label);
}

sf::FloatRect InputBox::getGlobal()
{
    return rect.getGlobalBounds();
}

void InputBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(rect);
    target.draw(label);
}

void InputBox::setOutline(const sf::Color &color)
{
    rect.setOutlineColor(color);
}

void InputBox::setFill(const sf::Color &color)
{
    rect.setFillColor(color);
}
