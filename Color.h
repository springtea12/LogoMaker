#ifndef FINAL_COLOR_H
#define FINAL_COLOR_H
#include "GUIComponent.h"
#include "Font.h"
#include <vector>
class Color : public GUIComponent
{
private:
    std::vector<sf::RectangleShape> cols;
    sf::RectangleShape currentColor, holder;
    sf::Text text;
    int cur;
public:
    Color();
    void setLabel(std::string label);
    void setPos(sf::Vector2f pos);

    sf::Color getCol();
    void setCol(sf::Color col);
    int getColInt();
    sf::Color getInt(int val);
    void setColInt(int val);

    void draw(sf::RenderTarget &window, sf::RenderStates states) const;

    void eventHandler(sf::RenderWindow &window, sf::Event event);

    void update();
};


#endif //FINAL_COLOR_H
