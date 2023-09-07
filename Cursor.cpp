#include "Cursor.h"

Cursor::Cursor()
{
    curs = Letter('|', 300, 400);
    shown = false;
}

void Cursor::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(shown)
        target.draw(curs);
}

void Cursor::update()
{
    if(clock.getElapsedTime() >= sf::milliseconds(450.f))
    {
        shown = !shown;
        clock.restart();
    }
}

void Cursor::setPos(float x, float y)
{
    curs.setPosition(x, y);
}
