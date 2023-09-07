#include "ItemList.h"
ItemList::ItemList()
{

}

void ItemList::addItem(const std::string &string)
{
    Item temp(string);
    if(itemList.empty())
        temp.setPosition({0,0});
    else
        temp.setPosition({itemList.back().getPos().x, itemList.back().getPos().y + itemList.back().getGlobal().height});
    itemList.push_back(temp);
}

void ItemList::removeItem()
{
    if(!itemList.empty())
        itemList.pop_back();
}

void ItemList::setPosition(sf::Vector2f pos)
{
    if(!itemList.empty())
    {
        for(int i = 0; i < itemList.size(); i++)
        {
            itemList[i].setPosition({pos.x, pos.y + (i * itemList[i].getGlobal().height)});
        }
    }
}

void ItemList::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(Item a : itemList)
    {
        target.draw(a);
    }
}

void ItemList::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(Item &a : itemList)
    {
        a.Item::eventHandler(window, event);
    }
}

const Item ItemList::operator[](int index)
{
    return itemList[index];
}

bool ItemList::empty()
{
    return itemList.empty();
}

int ItemList::size()
{
    return itemList.size();
}

void ItemList::resetClick()
{
    for(Item &a : itemList)
        a.resetClicked();
}

int ItemList::indexClicked()
{
    for(int i = 0; i < itemList.size(); i++)
    {
        if(itemList[i].isClicked())
            return i;
    }
    return -1;
}
