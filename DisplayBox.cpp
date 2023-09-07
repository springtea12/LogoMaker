#include "DisplayBox.h"

DisplayBox::DisplayBox()
{
    rect.setSize({1700, 600});
    rect.setPosition({150,140});
    rect.setFillColor(sf::Color::Magenta);
    text.setString("");
    shadow.setString("");
    text.setFont(Font::getFont());
    shadow.setFont(Font::getFont());
    shadow.setScale(1,-1);
}

void DisplayBox::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void DisplayBox::update()
{

}

void DisplayBox::setText(std::string s)
{
    text.setString(s);
    shadow.setString(s);
}

void DisplayBox::textPos(sf::Vector2f pos)
{
    text.setPosition({150 + pos.x, 140 + pos.y});
}

void DisplayBox::imgPos(sf::Vector2f pos)
{
    dImg.setPosition(150 + pos.x, 140 + pos.y);
}

void DisplayBox::shadowPos(sf::Vector2f pos)
{
    shadow.setPosition({150 + pos.x, 140 + pos.y});
}

void DisplayBox::textOpac(int val)
{
    sf::Color temp = text.getColor();
    temp.a = val;
    text.setColor(temp);
}

void DisplayBox::shadowOpac(int val)
{
    sf::Color temp = shadow.getColor();
    temp.a = val;
    shadow.setColor(temp);
}

void DisplayBox::BGOpac(int val)
{
    sf::Color temp = rect.getFillColor();
    temp.a = val;
    rect.setFillColor(temp);
}

void DisplayBox::fontSize(int val)
{
    text.setCharacterSize(val);
    shadow.setCharacterSize(val);
}

void DisplayBox::skew(int val)
{
    shadow.setScale(1,-1 * val/100.0);
}

void DisplayBox::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(rect);
    if(showSprite)
        window.draw(dImg);
    window.draw(text);
    window.draw(shadow);
}

void DisplayBox::setTCol(sf::Color col)
{
    text.setFillColor(col);
    shadow.setFillColor(col);
}

void DisplayBox::setBGCol(sf::Color col)
{
    rect.setFillColor(col);
}

void DisplayBox::loadSprite(std::string s)
{
    dImg.setTexture(dispImage::getTexture(s));
    dImg.scale({(1 / dImg.getGlobalBounds().height) * 120
                       ,(1 / dImg.getGlobalBounds().width) * 120});
    showSprite = true;
    dImg.setPosition({150, 140});
}

void DisplayBox::setIcon(sf::Texture& texture)
{
    dImg.setTexture(texture);
//    dImg.scale({(1.f / dImg.getGlobalBounds().height) * imgXsize
//                       ,(1.f / dImg.getGlobalBounds().width) * imgYsize});
    dImg.scale({(1 / dImg.getGlobalBounds().height) * 120
                       ,(1 / dImg.getGlobalBounds().width) * 120});
    showSprite = true;
    dImg.setPosition({150, 140});
}

void DisplayBox::resetSprite()
{
    showSprite = false;
}

void DisplayBox::resetSpriteScale()
{
    dImg.scale((dImg.getGlobalBounds().height)/120,
               dImg.getGlobalBounds().width/120);
}
