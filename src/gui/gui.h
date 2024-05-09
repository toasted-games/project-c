#pragma once

enum class GUI_STATE
{
  OHFUCK = -1,
  MAIN,
  SINGLE,
  MULTIPLAYER,
  SETTINGS,
  GAME
};

class GUI
{
public:
  void setup();
  GUI_STATE update();
  void draw();

private:
  GUI_STATE state = GUI_STATE::OHFUCK;


};

extern GUI gui;
