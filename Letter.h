#ifndef MULTITEXT_LETTER_H
#define MULTITEXT_LETTER_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Font.h"

class Letter : public sf::Text
{
public:
    Letter();
    Letter(char letter, float x, float y);
    char getCharacter();
    void setColor(const sf::Color& color);
    sf::Color singleCharCol(char character);
};

#endif //MULTITEXT_LETTER_H
