#ifndef FINAL_FONT_H
#define FINAL_FONT_H
#include <SFML/Graphics.hpp>

class Font
{
private:
    static sf::Font font;
    static void loadFont();
public:
    static sf::Font& getFont();
    sf::Font& getFont(std::string fontName);
};


#endif //FINAL_FONT_H
