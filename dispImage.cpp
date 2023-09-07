#include "dispImage.h"

sf::Texture &dispImage::getTexture(std::string imgName)
{
    img.loadFromFile(imgName);
    return img;
}
