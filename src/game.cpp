#include "game.h"

#include <raylib.h>

#include "gui/gui.h"

void Game::run()
{
  InitWindow(1400, 800, "Project C");
  SetExitKey(KEY_F10);

  gui.setup();

  while (isRunning)
  {
    this->update();
    this->draw();

    isRunning &= !WindowShouldClose();
  }

  CloseWindow();
}

void Game::update()
{
  GUI_STATE guiState = gui.update();

  if (guiState == GUI_STATE::OHFUCK)
  {
    TraceLog(LOG_FATAL, "Game shat itself :)");
    isRunning = false;
    return;
  }
}

void Game::draw()
{
  BeginDrawing();
  ClearBackground(RAYWHITE);

  

  gui.draw(); // Make sure this is last !important
  EndDrawing();
}