#ifndef FINAL_SAVETEXT_H
#define FINAL_SAVETEXT_H
#include <string>
#include <fstream>
#include "SliderList.h"
class SaveText
{
public:
    static void save(SliderList &list, std::string filepath);
    static void load(SliderList &list, std::string filepath);
};


#endif //FINAL_SAVETEXT_H
