#ifndef FINAL_SLIDERLIST_H
#define FINAL_SLIDERLIST_H
#include "Slider.h"
#include <vector>
#include <string>

class SliderList : public GUIComponent
{
private:
    std::vector<Slider> sList;
    std::string t;
    int tCol = 0, bgCol = 7;
public:
    SliderList();
    void setPos(sf::Vector2f pos);
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void update() override;
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    // Getters and Setters
    void setTextOpacity(int val);
    int getTextOpacity();
    void setShaodwOpacity(int val);
    int getShadowOpacity();
    void setText(sf::Vector2f pos);
    sf::Vector2f getText();
    void setShadow(sf::Vector2f pos);
    sf::Vector2f getShadow();
    void setFontSize(int val);
    int getFontSize();
    void setSkew(int val);
    int getSkew();
    void setBGOpacity(int val);
    int getBGOpacity();
    void setString(std::string s);
    std::string getString();
    void setTCol(int col);
    void setBGCol(int col);
    int gTCol();
    int gBGCol();
    void setImgPos(sf::Vector2f pos);
    sf::Vector2f getImgPos();
};


#endif //FINAL_SLIDERLIST_H
