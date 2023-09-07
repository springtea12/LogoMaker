#include "Color.h"

Color::Color()
{
    enableState(HIDDEN);
    text.setFont(Font::getFont());
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    currentColor.setSize({40,40});
    currentColor.setOutlineColor(sf::Color::White);
    currentColor.setOutlineThickness(1);
    holder.setSize({210, 110});
    holder.setFillColor({128,128,128});
    for(int i = 0; i < 8; i++)
    {
        sf::RectangleShape temp;
        temp.setSize({40, 40});
        temp.setOutlineColor(sf::Color::Black);
        temp.setOutlineThickness(1);
        cols.push_back(temp);
    }
    text.setPosition({0,0});
    currentColor.setPosition({0,0});
    holder.setPosition({currentColor.getPosition().x + currentColor.getSize().x/2,
                        currentColor.getPosition().y + currentColor.getSize().y/2});
    for(int i = 0; i < 4; i++)
    {
        cols[i].setPosition({holder.getPosition().x + 10 + i * 50,
                             holder.getPosition().y + 10});
    }
    for(int i = 4; i < 8; i++)
    {
        cols[i].setPosition({holder.getPosition().x + 10 + i * 50,
                             holder.getPosition().y + 60});
    }

    cols[0].setFillColor(sf::Color::Red);
    cols[1].setFillColor(sf::Color::Yellow);
    cols[2].setFillColor(sf::Color::Green);
    cols[3].setFillColor(sf::Color::Cyan);
    cols[4].setFillColor(sf::Color::Blue);
    cols[5].setFillColor(sf::Color::Magenta);
    cols[6].setFillColor(sf::Color::Black);
    cols[7].setFillColor({211, 211, 211});
    currentColor.setFillColor(cols[0].getFillColor());
    cur = 0;
}

void Color::setLabel(std::string label)
{
    text.setString(label);
}

void Color::setPos(sf::Vector2f pos)
{
    text.setPosition(pos);
    currentColor.setPosition({text.getGlobalBounds().width + text.getGlobalBounds().left,
                              text.getGlobalBounds().top - 2});
    holder.setPosition({currentColor.getPosition().x + currentColor.getSize().x * (float)(4.0/5),
                        currentColor.getPosition().y + currentColor.getSize().y * (float)(4.0/5)});
    for(int i = 0; i < 4; i++)
    {
        cols[i].setPosition({holder.getPosition().x + 10 + i * 50,
                             holder.getPosition().y + 10});
    }
    for(int i = 4; i < 8; i++)
    {
        cols[i].setPosition({holder.getPosition().x + 10 + (i -4) * 50,
                             holder.getPosition().y + 60});
    }
}

void Color::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(text);
    window.draw(currentColor);
    if(!checkState(HIDDEN))
    {
        window.draw(holder);
        for (sf::RectangleShape palette: cols)
            window.draw(palette);
    }
}

void Color::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(currentColor.getGlobalBounds().contains(mpos))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            toggleState(HIDDEN);
        }
    }
    if(!checkState(HIDDEN))
        for(int i = 0; i < 8; i++)
        {
            if(cols[i].getGlobalBounds().contains(mpos))
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    currentColor.setFillColor(cols[i].getFillColor());
                    cur = i;
                    toggleState(HIDDEN);
                }
            }
        }
}

void Color::update()
{

}

sf::Color Color::getCol()
{
    return currentColor.getFillColor();
}

void Color::setCol(sf::Color col)
{
    currentColor.setFillColor(col);
}

int Color::getColInt()
{
    return cur;
}

sf::Color Color::getInt(int val)
{
    cur = val;
    return cols[val].getFillColor();
}

void Color::setColInt(int val)
{
    cur = val;
    currentColor.setFillColor(getInt(val));
}
