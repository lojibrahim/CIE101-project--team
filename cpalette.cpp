#include "cpalette.h"
#include "GUI\GUI.h"


GUI* cpalette::pGUI = nullptr;



cpalette::cpalette(GUI* gui)
{
    pGUI = gui; // static pointer
}


    
color cpalette::chooseDrawColor()
{
    int x, y;
    color c;
     
    pGUI->getWindow()->GetMouseClick(x, y);

        if (x >= 1051 && x <= 1100 && y >= 0 && y <= 25) c = WHITE;
        else if (x >= 1051 && x <= 1100 && y >= 26 && y <= 50) c = BLACK;
        else if (x >= 1101 && x <= 1150 && y >= 0 && y <= 25) c = RED;
        else if (x >= 1101 && x <= 1150 && y >= 26 && y <= 50) c = BLUE;
        else if (x >= 1151 && x <= 1200 && y >= 0 && y <= 25) c = YELLOW;
        else if (x >= 1151 && x <= 1200 && y >= 26 && y <= 50) c = GREEN;
        else if (x >= 1201 && x <= 1250 && y >= 0 && y <= 25) c = ORANGE;
        else if (x >= 1201 && x <= 1250 && y >= 26 && y <= 50) c = CYAN;
        else if (x >= 1251 && x <= 1300 && y >= 0 && y <= 25) c = VIOLET;
        else if (x >= 1251 && x <= 1300 && y >= 26 && y <= 50) c = PINK;

    pGUI->SetDrawColor(c);
    
    return c;
}


color cpalette::chooseFillColor()
{
    int x, y;
    color c = pGUI->getCrntFillColor();;
    pGUI->getWindow()->GetMouseClick(x, y);
    if (x >= 1000 && x <= 1050 && y >= 26 && y <= 50) {

        pGUI->getWindow()->GetMouseClick(x, y);

        if (x >= 1051 && x <= 1100 && y >= 0 && y <= 25) c = WHITE;
        else if (x >= 1051 && x <= 1100 && y >= 26 && y <= 50) c = BLACK;
        else if (x >= 1101 && x <= 1150 && y >= 0 && y <= 25) c = RED;
        else if (x >= 1101 && x <= 1150 && y >= 26 && y <= 50) c = BLUE;
        else if (x >= 1151 && x <= 1200 && y >= 0 && y <= 25) c = YELLOW;
        else if (x >= 1151 && x <= 1200 && y >= 26 && y <= 50) c = GREEN;
        else if (x >= 1201 && x <= 1250 && y >= 0 && y <= 25) c = ORANGE;
        else if (x >= 1201 && x <= 1250 && y >= 26 && y <= 50) c = CYAN;
        else if (x >= 1251 && x <= 1300 && y >= 0 && y <= 25) c = VIOLET;
        else if (x >= 1251 && x <= 1300 && y >= 26 && y <= 50) c = PINK;

        pGUI->SetFillColor(c);
    }
    return c;
}