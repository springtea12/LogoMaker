#ifndef FINAL_DROPDOWNMENU_H
#define FINAL_DROPDOWNMENU_H
#include "InputBox.h"
#include "ItemList.h"
#include "GUIComponent.h"

class MenuBar : public GUIComponent
{
private:
    InputBox box;
    ItemList list;
    std::string label;
    int lastClicked = -1;
public:
    const std::string &getLabel() const;

    void setLabel(const std::string &label);

public:
    MenuBar();
    MenuBar(std::string string);
    void addMenu(std::string string);
    void removeMenu();
    void setPosition(sf::Vector2f pos);
    void setOutline(const sf::Color& color);
    void setFillColor(const sf::Color& color);
    sf::FloatRect getGlobal();
    int indexClicked();
    void resetClicked();

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};


#endif //FINAL_DROPDOWNMENU_H
