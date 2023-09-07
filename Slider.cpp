#include "Slider.h"

Slider::Slider() : Slider("Slider", 0, 10, 200)
{

}

Slider::Slider(std::string label, float start, float end, float length)
{
    Slider::start = start, Slider::end = end, currentVal = (end - start)/2, slength = length;
    sliderName.setString(label);
    sliderName.setCharacterSize(40);
    sliderName.setFont(Font::getFont());
    sliderName.setPosition({100,100});

    line.setSize({length,3});
    line.setFillColor(sf::Color::White);
    line.setPosition({sliderName.getPosition().x + sliderName.getGlobalBounds().width + 20,
                      sliderName.getPosition().y + (float)((((double)sliderName.getGlobalBounds().height)/1.3))});

    circle.setRadius(12);
    circle.setFillColor(sf::Color::Magenta);
    circle.setPosition({line.getPosition().x + line.getGlobalBounds().width/2 - circle.getRadius(),
                        line.getPosition().y - circle.getRadius() + line.getSize().y/2});

    value.setString(std::to_string((int)currentVal));
    value.setCharacterSize(sliderName.getCharacterSize());
    value.setFont(Font::getFont());
    value.setPosition({line.getPosition().x + line.getGlobalBounds().width + 15, sliderName.getPosition().y});
}

std::string Slider::getSliderLabel()
{
    return sliderName.getString();
}

void Slider::setSliderLabel(std::string label)
{
    sliderName.setString(label);
}

void Slider::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(circle.getGlobalBounds().contains(mpos))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(mpos.x >= line.getPosition().x && mpos.x <= line.getPosition().x + line.getSize().x)
            {
                circle.setPosition({mpos.x - circle.getRadius(),line.getPosition().y + line.getSize().y/2 - circle.getRadius()});
            }
        }
    }
    currentVal = start + (circle.getPosition().x + circle.getRadius() - line.getPosition().x) * (end-start) / line.getSize().x;
    value.setString(std::to_string((int)currentVal));
//    setCurrentVal(start + (circle.getPosition().x + circle.getRadius() - line.getPosition().x) * (end-start) / line.getSize().x);
}

void Slider::setCurrentVal(float val)
{
    currentVal = val;
    value.setString(std::to_string((int)val));
}

void Slider::update()
{

}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(sliderName);
    window.draw(line);
    window.draw(circle);
    window.draw(value);
}

float Slider::getVal() const
{
    return currentVal;
}

void Slider::setPosition(const sf::Vector2f &pos)
{
    sliderName.setPosition(pos);
    line.setPosition({sliderName.getPosition().x + sliderName.getGlobalBounds().width + 20,
                      sliderName.getPosition().y + (float)((((double)sliderName.getGlobalBounds().height)/1.3))});
    circle.setPosition({line.getPosition().x + line.getGlobalBounds().width/2 - circle.getRadius(),
                        line.getPosition().y - circle.getRadius() + 2 + line.getSize().y/2});
    value.setPosition({line.getPosition().x + line.getGlobalBounds().width + 10, sliderName.getPosition().y});
}

sf::FloatRect Slider::getGlobal()
{
    sf::FloatRect glob = sliderName.getGlobalBounds();
    glob.width += line.getSize().x + value.getGlobalBounds().width;
    return glob;
}

sf::Vector2f Slider::getPos()
{
    sf::Vector2f a(sliderName.getPosition());
    return a;
}

void Slider::setNewVal(float val)
{
    currentVal  = val;
    circle.setPosition({line.getPosition().x + (float)((val-start) / (end - start) * slength) - circle.getRadius(),
                        line.getPosition().y - circle.getRadius() + line.getSize().y/2});
}
