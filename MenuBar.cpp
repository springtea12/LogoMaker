#include "MenuBar.h"
MenuBar::MenuBar() : MenuBar("Click Here")
{
}

MenuBar::MenuBar(std::string string)
{
    setLabel(string);
    MenuBar::setPosition({0,0});
    enableState(HIDDEN);
}

void MenuBar::addMenu(std::string string)
{
    list.addItem(string);
}

void MenuBar::removeMenu()
{
    list.removeItem();
}

void MenuBar::setPosition(sf::Vector2f pos)
{
    box.setPos(pos);
    list.setPosition({pos.x, pos.y + box.getGlobal().height});
}

void MenuBar::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(box.getGlobal().contains(mpos))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            toggleState(HIDDEN);
//            if(!checkState(FRESHINDEX))
//                toggleState(FRESHINDEX);
        }
    }
    if(!checkState(HIDDEN))
    {
        list.eventHandler(window, event);
        if(list.indexClicked() >= 0)
        {
            toggleState(HIDDEN);
            lastClicked = list.indexClicked();
            list.resetClick();
        }
    }
}

void MenuBar::update()
{
    //
}

void MenuBar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(box);
    if(!States::checkState(HIDDEN))
        target.draw(list);
}

const std::string &MenuBar::getLabel() const
{
    return label;
}

void MenuBar::setLabel(const std::string &label)
{
    MenuBar::label = label;
    box.setLabel(label);
}

void MenuBar::setOutline(const sf::Color &color)
{
    box.setOutline(color);
}

void MenuBar::setFillColor(const sf::Color &color)
{
    box.setFill(color);
}

sf::FloatRect MenuBar::getGlobal()
{
    return box.InputBox::getGlobal();
}

int MenuBar::indexClicked()
{
    return lastClicked;
}

void MenuBar::resetClicked()
{
    lastClicked = -1;
}
