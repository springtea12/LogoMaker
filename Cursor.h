#ifndef TEXTINPUT_CURSOR_H
#define TEXTINPUT_CURSOR_H

#include "Letter.h"
#include <SFML/Graphics.hpp>

class Cursor : public sf::Drawable
{
private:
    Letter curs;
    sf::Clock clock;
    bool shown;
public:
    Cursor();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update();
    void setPos(float x, float y);
};


#endif //TEXTINPUT_CURSOR_H
