#include "gui.h"

#include <raylib.h>

void GUI::setup()
{
  state = GUI_STATE::MAIN;
}

GUI_STATE GUI::update()
{
  return state;
}

void GUI::draw()
{
  switch (state)
  {
  case GUI_STATE::MAIN:
    break;

  default:
    break;
  }
}
