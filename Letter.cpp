#include "Letter.h"

Letter::Letter()
{
}

Letter::Letter(char letter, float x, float y)
{
    setFont(Font::getFont());
    setCharacterSize(50);
    setString(letter);
    setFillColor(singleCharCol(letter));
    setPosition(x, y);
}

sf::Color Letter::singleCharCol(char character)
{
    if(character >= '0' && character <= '9')
        return sf::Color::Red;
    if(character >= '<' && character <= '>')
        return sf::Color::Green;
    if(character == 33 || character == 37 || character == 38 || character == 47
        || character == 42 || character == 43 || character == 45)
        return sf::Color::Green;
    return sf::Color::White;
}

char Letter::getCharacter()
{
    return getString()[0];
}

void Letter::setColor(const sf::Color &color)
{
    setFillColor(color);
}
