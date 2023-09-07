#include "Font.h"

sf::Font Font::font;
void Font::loadFont()
{
    font.loadFromFile("fonts/arial.ttf");
}

sf::Font &Font::getFont()
{
    loadFont();
    return font;
}

sf::Font &Font::getFont(std::string fontName)
{
    sf::Font temp;
    temp.loadFromFile("fonts/" + fontName);
    return temp;
}
