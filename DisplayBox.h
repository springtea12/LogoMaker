#ifndef FINAL_DISPLAYBOX_H
#define FINAL_DISPLAYBOX_H
#include "GUIComponent.h"
#include "Font.h"
#include "dispImage.h"
#include <iostream>

class DisplayBox : public GUIComponent
{
private:
    sf::Text text, shadow;
    sf::RectangleShape rect;
    sf::Sprite dImg;
    int imgXsize = 100, imgYsize = 100;
    bool showSprite = false;
public:
    DisplayBox();
    void setText(std::string s);
    void textPos(sf::Vector2f pos);
    void shadowPos(sf::Vector2f pos);
    void textOpac(int val);
    void shadowOpac(int val);
    void BGOpac(int val);
    void fontSize(int val);
    void skew(int val);
    void setTCol(sf::Color col);
    void setBGCol(sf::Color col);
    void loadSprite(std::string s);
    void imgPos(sf::Vector2f pos);

    void eventHandler(sf::RenderWindow &window, sf::Event event);

    void update();
    void resetSprite();
    void setIcon(sf::Texture& texture);
    void resetSpriteScale();

protected:
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //FINAL_DISPLAYBOX_H
