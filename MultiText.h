#ifndef MULTITEXT_MULTITEXT_H
#define MULTITEXT_MULTITEXT_H
#include <SFML/Graphics.hpp>
#include "Letter.h"
#include <list>

class MultiText : public sf::Drawable
{
private:
    std::list<Letter> letters;
    float x = 0;
    float y = 0;
    int charSize;
public:
    MultiText();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void pop();
    void push_back(char letter);
    Letter begin();
    Letter end();
    std::string getString();
    void updateColor();
    void setPos(float x, float y);
    bool empty();
};


#endif //MULTITEXT_MULTITEXT_H
