#ifndef FINAL_INPUTBOX_H
#define FINAL_INPUTBOX_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Helper.h"
#include "Font.h"

class InputBox : public sf::Drawable
{
private:
    sf::RectangleShape rect;
    sf::Text label;
public:
    InputBox();
    InputBox(std::string string);
    void setLabel(std::string string);
    std::string getString();
    void setPos(sf::Vector2f pos);
    sf::FloatRect getGlobal();
    void setOutline(const sf::Color& color);
    void setFill(const sf::Color& color);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //DROPDOWNMENU_INPUTBOX_H
