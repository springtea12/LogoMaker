#ifndef FINAL_ITEMLIST_H
#define FINAL_ITEMLIST_H
#include "Item.h"
#include <vector>

class ItemList : public sf::Drawable
{
private:
    std::vector<Item> itemList;
public:
    ItemList();
    void addItem(const std::string& string = "Item");
    void removeItem();
    void setPosition(sf::Vector2f pos);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    const Item operator[](int index);
    bool empty();
    int size();
    void resetClick();
    int indexClicked();
};

#endif //DROPDOWNMENU_ITEMLIST_H
