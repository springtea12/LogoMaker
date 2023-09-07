#include "SliderList.h"

SliderList::SliderList()
{
    sList.push_back(Slider("Text Opacity: ", 0, 255, 400));
    sList.push_back(Slider("Shadow Opacity: ", 0, 255, 400));
    sList.push_back(Slider("Text X-Axis: ", 0, 1700, 850));
    sList.push_back(Slider("Text Y-Axis: ", 0, 600, 600));
    sList.push_back(Slider("Shadow X-Axis: ", 0, 1700, 850));
    sList.push_back(Slider("Shadow Y-Axis: ", 0, 600, 600));
    sList.push_back(Slider("Font Size: ", 10, 100, 180));
    sList.push_back(Slider("Skew: ", 0, 100, 200));
    sList.push_back(Slider("Background Opacity:", 0, 255, 400));
    sList.push_back(Slider("Image X:", 0, 1700, 375));
    sList.push_back(Slider("Image Y:", 0, 600, 300));
    sList[0].setPosition({40, 930});
    for(int i = 1; i < 6; i++)
        sList[i].setPosition({sList[0].getPos().x,
                              sList[i-1].getGlobal().top + 75});
    sList[6].setPosition({sList[0].getGlobal().left + sList[0].getGlobal().width + 150,
                          sList[0].getPos().y});
    sList[7].setPosition({sList[6].getGlobal().left + sList[6].getGlobal().width + 150,
                          sList[0].getPos().y});
    sList[8].setPosition({sList[6].getGlobal().left - 5, sList[1].getGlobal().top - 12});
    sList[9].setPosition({1910, 300});
    sList[10].setPosition({1910, 400});
}

void SliderList::setPos(sf::Vector2f pos)
{
    sList[0].setPosition(pos);
    for(int i = 1; i < 6; i++)
        sList[i].setPosition({sList[0].getPos().x,
                              sList[i-1].getGlobal().top + 50});
    sList[6].setPosition({sList[0].getGlobal().left + sList[0].getGlobal().width + 150,
                          sList[0].getPos().y});
    sList[7].setPosition({sList[6].getGlobal().left + sList[6].getGlobal().width + 150,
                          sList[0].getPos().y});
    sList[8].setPosition({sList[6].getGlobal().left - 5, sList[1].getGlobal().top - 12});
}

void SliderList::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(int i = 0; i < sList.size(); i++)
        sList[i].eventHandler(window, event);
}

void SliderList::update()
{

}

void SliderList::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for(int i = 0; i < sList.size(); i++)
        window.draw(sList[i]);
}

void SliderList::setTextOpacity(int val)
{
    sList[0].setNewVal(val);
}

int SliderList::getTextOpacity()
{
    return sList[0].getVal();
}

void SliderList::setShaodwOpacity(int val)
{
    sList[1].setNewVal(val);
}

int SliderList::getShadowOpacity()
{
    return sList[1].getVal();
}

void SliderList::setText(sf::Vector2f pos)
{
    sList[2].setNewVal(pos.x);
    sList[3].setNewVal(pos.y);
}

sf::Vector2f SliderList::getText()
{
    sf::Vector2f pos({sList[2].getVal(), sList[3].getVal()});
    return pos;
}

void SliderList::setShadow(sf::Vector2f pos)
{
    sList[4].setNewVal(pos.x);
    sList[5].setNewVal(pos.y);
}

sf::Vector2f SliderList::getShadow()
{
    sf::Vector2f pos({sList[4].getVal(), sList[5].getVal()});
    return pos;
}

void SliderList::setFontSize(int val)
{
    sList[6].setNewVal(val);
}

int SliderList::getFontSize()
{
    return sList[6].getVal();
}

void SliderList::setSkew(int val)
{
    sList[7].setNewVal(val);
}

int SliderList::getSkew()
{
    return sList[7].getVal();
}

void SliderList::setBGOpacity(int val)
{
    sList[8].setNewVal(val);
}

int SliderList::getBGOpacity()
{
    return sList[8].getVal();
}

void SliderList::setString(std::string s)
{
    t = s;
}

std::string SliderList::getString()
{
    return t;
}

void SliderList::setTCol(int col)
{
    tCol = col;
}

void SliderList::setBGCol(int col)
{
    bgCol = col;
}

int SliderList::gTCol()
{
    return tCol;
}

int SliderList::gBGCol()
{
    return bgCol;
}

void SliderList::setImgPos(sf::Vector2f pos)
{
    sList[9].setNewVal(pos.x);
    sList[10].setNewVal(pos.y);
}

sf::Vector2f SliderList::getImgPos()
{
    return {sList[9].getVal(), sList[10].getVal()};
}
