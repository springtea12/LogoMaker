#include "SaveText.h"

void SaveText::save(SliderList &list, std::string filepath)
{
    std::ofstream ofs;
    ofs.open(filepath, std::ostream::out | std::ofstream::trunc);
    ofs.close();

    std::ofstream out;
    out.open(filepath);
    out << list.getTextOpacity() << std::endl;
    out << list.getShadowOpacity() << std::endl;
    out << list.getText().x << std::endl;
    out << list.getText().y << std::endl;
    out << list.getShadow().x << std::endl;
    out << list.getShadow().y << std::endl;
    out << list.getFontSize() << std::endl;
    out << list.getSkew() << std::endl;
    out << list.getBGOpacity() << std::endl;
    out << list.getString() << std::endl;
    out << list.gTCol() << std::endl;
    out << list.gBGCol() << std::endl;
    out.close();
}

void SaveText::load(SliderList &list, std::string filepath)
{
    std::ifstream fin;
    fin.open(filepath);
    if(fin.fail())
        throw "Could not find file";

    float tOpacity, sOpacity, tX, tY, sX, sY, fSize, skew, BGOpacity;
    std::string a;
    int tC, bgC;
    fin >> tOpacity;
    fin >> sOpacity;
    fin >> tX;
    fin >> tY;
    fin >> sX;
    fin >> sY;
    fin >> fSize;
    fin >> skew;
    fin >> BGOpacity;
    fin >> a;
    fin >> tC;
    fin >> bgC;

    list.setTCol(tC);
    list.setBGCol(bgC);
    list.setTextOpacity(tOpacity);
    list.setShaodwOpacity(sOpacity);
    list.setText({tX, tY});
    list.setShadow({sX, sY});
    list.setFontSize(fSize);
    list.setSkew(skew);
    list.setBGOpacity(BGOpacity);
    list.setString(a);

    fin.close();
}
