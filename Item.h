#ifndef FINAL_ITEM_H
#define FINAL_ITEM_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Font.h"
#include "Helper.h"

class Item : public sf::Drawable
{
private:
    sf::Text text;
    sf::RectangleShape rect;
    bool clicked = false;
public:
    Item();
    Item(std::string name);
    void setPosition(sf::Vector2f pos);
    void setString(const std::string& string);
    std::string getString() const;
    sf::Vector2f getPos();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::FloatRect getGlobal();
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    bool isClicked();
    void resetClicked();

};


#endif //FINAL_ITEM_H
