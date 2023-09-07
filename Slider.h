#ifndef FINAL_SLIDER_H
#define FINAL_SLIDER_H
#include "GUIComponent.h"
#include "Font.h"

class Slider : public GUIComponent
{
private:
    sf::CircleShape circle;
    sf::RectangleShape line;
    sf::Text sliderName, value;
    float start, end, currentVal, slength;
public:
    Slider();
    Slider(std::string label, float start, float end, float length);
    std::string getSliderLabel();
    void setSliderLabel(std::string label);
    void setCurrentVal(float val);
    float getVal() const;

    void setPosition(const sf::Vector2f& pos);
    sf::FloatRect getGlobal();

    sf::Vector2f getPos();

    void setNewVal(float val);

    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};


#endif //FINAL_SLIDER_H
