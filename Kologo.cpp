#include "Kologo.h"

Kologo::Kologo()
{
    label.setLabel("Logo Text:");
    label.setPos(40,835 );
    box.setPos({240, 825});
    typing.setPosition({245, 830});
    tCol.setLabel("Font Color: ");
    tCol.setPos({895, 850});
    bgCol.setLabel("Background Color: ");
    bgCol.setPos({1460, 850});
}

void Kologo::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(sf::Event::Closed == event.type )
    {
        std::cout << "Saved" << std::endl;
        sList.setString(typing.getText());
        sList.setTCol(tCol.getColInt());
        sList.setBGCol(bgCol.getColInt());
        SaveText::save(sList, "recent.txt");
    }

    menu.eventHandler(window, event);
    if(menu.menuClicked() == 0)
    {
        std::cout << "Save" << std::endl;
        menu.resetMenuClicked();
        sList.setString(typing.getText());
        sList.setTCol(tCol.getColInt());
        sList.setBGCol(bgCol.getColInt());
        SaveText::save(sList, "logoSettings.txt");
    }
    if(menu.menuClicked() == 1)
    {
        std::cout << "Load" << std::endl;
        menu.resetMenuClicked();
        SaveText::load(sList, "logoSettings.txt");
        typing.setTypingText(sList.getString());
        dBox.setTCol(tCol.getInt(sList.gTCol()));
        dBox.setTCol(bgCol.getInt(sList.gBGCol()));
        tCol.setColInt(sList.gTCol());
        bgCol.setColInt(sList.gBGCol());
        dBox.shadowPos(sList.getShadow());
        dBox.textOpac(sList.getTextOpacity());
    }
    if(menu.menuClicked() == 2)
    {
        menu.resetMenuClicked();
        SaveText::load(sList, "recent.txt");
        typing.setTypingText(sList.getString());
        dBox.setTCol(tCol.getInt(sList.gTCol()));
        dBox.setTCol(bgCol.getInt(sList.gBGCol()));
        tCol.setColInt(sList.gTCol());
        bgCol.setColInt(sList.gBGCol());
        dBox.shadowPos(sList.getShadow());
        dBox.textOpac(sList.getTextOpacity());
    }
    if(menu.renderClicked() == 0)
    {
        ScreenShot s;
        s.takeScreenShot(window, "screenshot.png");
        menu.resetRenderClicked();
    }
    box.eventHandler(window, event);
    if(box.acceptType())
    {
        typing.eventHandler(window, event);
    }

    tCol.eventHandler(window, event);
    bgCol.eventHandler(window, event);
    dBox.setTCol(tCol.getInt(tCol.getColInt()));
    dBox.setBGCol(bgCol.getInt(bgCol.getColInt()));
    dBox.setText(typing.getText());
    dBox.textPos(sList.getText());
    dBox.shadowPos(sList.getShadow());
    dBox.textOpac(sList.getTextOpacity());
    dBox.shadowOpac(sList.getShadowOpacity());
    dBox.fontSize(sList.getFontSize());
    dBox.BGOpac(sList.getBGOpacity());
    dBox.skew(sList.getSkew());
    sList.eventHandler(window, event);
}

void Kologo::update()
{
    typing.update();
}

void Kologo::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(sList);
    window.draw(dBox);
    window.draw(label);
    window.draw(box);
    window.draw(typing);
    window.draw(menu);
    window.draw(tCol);
    window.draw(bgCol);
}
