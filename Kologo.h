#ifndef FINAL_KOLOGO_H
#define FINAL_KOLOGO_H
#include "MenuList.h"
#include "SliderList.h"
#include "SaveText.h"
#include "ScreenShot.h"
#include "Typing.h"
#include "Box.h"
#include "Label.h"
#include "DisplayBox.h"
#include "Color.h"
#include <iostream>

class Kologo : public GUIComponent
{
private:
    MenuList menu;
    SliderList sList;
    Typing typing;
    Box box;
    Label label;
    DisplayBox dBox;
    Color tCol, bgCol;
    bool loaded = false, resetted = false;
public:
    Kologo();
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};


#endif //FINAL_KOLOGO_H
