#include "MenuList.h"

MenuList::MenuList()
{
    menu.setLabel("File");
    menu.addMenu("Save");
    menu.addMenu("Load");
    menu.addMenu("Recent");
    menu.addMenu("Quit");
    menu.addMenu("Close Project");
    menu.setPosition({2,3});
    menu.setFillColor({123, 123, 123});
    menu.setOutline({107, 107, 107});
    render.setLabel("Render");
    render.addMenu("Export Image");
    render.setFillColor({123, 123, 123});
    render.setOutline({107, 107, 107});
    render.setPosition({menu.getGlobal().width + menu.getGlobal().left, 3});
}

void MenuList::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(menu.indexClicked() == 3)
        window.close();
    menu.eventHandler(window, event);
    render.eventHandler(window, event);
}

int MenuList::menuClicked()
{
    return menu.indexClicked();
}

int MenuList::renderClicked()
{
    return render.indexClicked();
}

void MenuList::update()
{

}

void MenuList::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(menu);
    window.draw(render);
}

void MenuList::resetMenuClicked()
{
    menu.resetClicked();
}

void MenuList::resetRenderClicked()
{
    render.resetClicked();
}
