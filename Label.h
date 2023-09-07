#ifndef TEXTINPUT_LABEL_H
#define TEXTINPUT_LABEL_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Font.h"

class Label : public sf::Text
{
public:
    Label();
    Label(std::string label);
    void setLabel(std::string label);
    std::string getLabel();
    void setPos(float x, float y);
};


#endif //TEXTINPUT_LABEL_H
