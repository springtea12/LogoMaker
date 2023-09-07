#ifndef FINAL_DISPIMAGE_H
#define FINAL_DISPIMAGE_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class dispImage
{
private:
    inline static sf::Texture img;
    static void loadImg();
public:
    static sf::Texture &getTexture(std::string imgName);
};

#endif //FINAL_DISPIMAGE_H
