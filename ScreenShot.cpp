#include "ScreenShot.h"

ScreenShot::ScreenShot()
{

}

void ScreenShot::takeScreenShot(sf::RenderWindow &window, std::string filename)
{
    sf::Texture wholeWindow;
    wholeWindow.create(window.getSize().x, window.getSize().y);
    wholeWindow.update(window);
    // Sets the right and bottom max edge
    texture.create(1700, 600);
    // For update
    // X -> -val to push the image to the left, +val for the right
    // Y -> -val to push the image down, +val for up
    texture.update(wholeWindow, -150, -140);
    if (texture.copyToImage().saveToFile(filename))
    {
        std::cout << "screenshot saved to " << filename << std::endl;
    }
}
