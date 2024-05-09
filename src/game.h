#pragma once

class Game
{
public:
  void run();

private:
  void update();
  void draw();


  bool isRunning = true;
};
