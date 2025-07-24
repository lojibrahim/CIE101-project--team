#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"
#include <iostream>
using namespace std;

class GUI;

class cpalette
{
private:
    static GUI* pGUI;

public:
    cpalette(GUI* gui);
    static color chooseDrawColor();
    static color chooseFillColor();
};
