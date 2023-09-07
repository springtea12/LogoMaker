#ifndef TEXTINPUTDEMO_TYPING_H
#define TEXTINPUTDEMO_TYPING_H
#include <SFML/Graphics.hpp>
#include "Font.h"
#include "States.h"
#include <string>
#include "Cursor.h"

class Typing : public sf::Drawable
{
private:
    sf::Text text;
    std::string s;
    Cursor c;
    bool accept = false;
public:
    Typing();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void setPosition(const sf::Vector2f& position);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    std::string getText();
    void setTypingText(std::string str);
    void typingAccept(bool a);
};

#endif //TEXTINPUTDEMO_TYPING_H
