#include "Typing.h"

void Typing::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(text);
    if(accept)
        target.draw(c);
}

Typing::Typing()
{
    text.setFont(Font::getFont());
    text.setCharacterSize(50);
}

void Typing::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(sf::Event::TextEntered == event.type)
    {
        s = text.getString();
        if(event.text.unicode == 8)
            s.pop_back();
        else
            s.push_back(static_cast<char>(event.text.unicode));
    }
}

void Typing::update()
{
    text.setString(s);
    c.update();
}

void Typing::setPosition(const sf::Vector2f &position)
{
    text.setPosition(position);
}

std::string Typing::getText()
{
    return text.getString();
}

void Typing::typingAccept(bool a)
{
    accept = a;
}

void Typing::setTypingText(std::string str)
{
    text.setString(str);
    while(!s.empty())
        s.pop_back();
    for(int i = 0; i < str.length(); i++)
        s.push_back(str[i]);
}
