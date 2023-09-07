#ifndef FINAL_MENULIST_H
#define FINAL_MENULIST_H
#include "MenuBar.h"

class MenuList : public GUIComponent
{
private:
    MenuBar menu, render;
public:
    MenuList();

    int menuClicked();
    int renderClicked();
    void resetMenuClicked();
    void resetRenderClicked();

    void eventHandler(sf::RenderWindow &window, sf::Event event);

    void update() override;

    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};

#endif //FINAL_MENULIST_H