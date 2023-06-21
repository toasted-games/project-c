#ifndef DOM_H
#define DOM_H

#include <iostream>
#include <string>
#include <raylib.h>
#include <fstream>

class DOM
{
public:
    DOM();

    void load(std::string file);

    void render();

private:
    int screenWidth = 0;
    int screenHeight = 0;
};

#endif