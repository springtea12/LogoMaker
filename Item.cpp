#include "Item.h"
Item::Item() : Item("")
{
}

Item::Item(std::string name)
{
    text.setString(name);
    text.setFont(Font::getFont());
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(30);

    rect.setSize({400, 50});
    rect.setFillColor({107, 107, 107});
    Helper::centerText(rect, text);
}

void Item::setString(const std::string &string)
{
    text.setString(string);
    Helper::centerText(rect, text);
}

std::string Item::getString() const
{
    return text.getString();
}

void Item::setPosition(sf::Vector2f pos)
{
    rect.setPosition(pos);
    Helper::centerText(rect, text);
}

sf::Vector2f Item::getPos()
{
    return rect.getPosition();
}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(rect);
    target.draw(text);
}

sf::FloatRect Item::getGlobal()
{
    return rect.getGlobalBounds();
}

void Item::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(rect.getGlobalBounds().contains(mpos))
    {
        rect.setFillColor(sf::Color::Blue);
        text.setCharacterSize(35);
        Helper::centerText(rect, text);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            clicked = true;
    }
    if(!rect.getGlobalBounds().contains(mpos))
    {
        text.setCharacterSize(30);
        Helper::centerText(rect, text);
        rect.setFillColor({107, 107, 107});
    }
}

bool Item::isClicked()
{
    return clicked;
}

void Item::resetClicked()
{
    clicked = false;
}
