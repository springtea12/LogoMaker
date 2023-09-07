#include "MultiText.h"
MultiText::MultiText() {}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for(Letter a : letters)
    {
        window.draw(a);
    }
}

void MultiText::pop()
{
    if(!letters.empty())
    {
        letters.pop_back();
    }
}

void MultiText::push_back(char letter)
{

    float xtra;
    if(letters.empty())
    {
        letters.push_back(Letter(letter, x, y));
    }
    else {
        xtra = letters.back().getFont()->getGlyph(letters.back().getCharacter(), letters.back().getCharacterSize(), false).advance;
        letters.push_back(Letter(letter, xtra + letters.back().getPosition().x, y));
    }
}

Letter MultiText::begin()
{
    return letters.front();
}

Letter MultiText::end()
{
    return letters.back();
}

void MultiText::setPos(float xCoord, float yCoord)
{
    x = xCoord;
    y = yCoord;
}

std::string MultiText::getString()
{
    std::string s = "";
    for(Letter a : letters)
    {
        s += a.getCharacter();
    }
    return s;
}

void MultiText::updateColor()
{
    auto start = letters.begin();
    auto end = letters.begin();
    std::string sub = "";
    for(; end != letters.end(); ++end)
    {
        if(end->getCharacter() == ' ')
        {
            if(sub == "int" || sub == "char" || sub == "double" || sub == "float")
                for(;start != end; ++start)
                    start->setColor(sf::Color::Blue);
            else
                for(;start != end; ++start)
                {
                    char temp = start->getCharacter();
                    if((!(temp >= '0' && temp <= '9')) && temp != 33 && temp != 37 && temp != 38 && temp != 47
                       && temp != 42 && temp != 43 && temp != 45 && !(temp >= '<' && temp <= '>'))
                    start->setColor(sf::Color::White);
                }
            sub = "";
            start = end;
        }
        else
        {
            sub += end->getCharacter();
        }
    }
}

bool MultiText::empty()
{
    return letters.empty();
}
