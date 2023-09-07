#ifndef FINAL_HELPER_H
#define FINAL_HELPER_H
#include <SFML/Graphics.hpp>
#include <cmath>

class Helper
{
public:
    template <typename T>
    static void centerText(const T &obj, sf::Text &text);
};

#include "Helper.cpp"
#endif //FINAL_HELPER_H
