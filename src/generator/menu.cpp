#include "./ux/button.h"
#include <iostream>
#include "./menu.h"

void handleButtonEvents();

Button button("Click me!", {
                               100,
                               100,
                               200,
                               50,
                               BLUE,
                               RED,
                           });

Button closeButton("Close", {
                                100,
                                200,
                                400,
                                50,
                                BLUE,
                                RED,
                            });

Button fullScreen("Full Screen", {
                                     100,
                                     500,
                                     100,
                                     50,
                                     BLUE,
                                     RED,
                                 });

void loadMenu()
{
    std::cout << "Loading menu...\n";
}

void updateMenu()
{
    handleButtonEvents();

    button.update();
    closeButton.update();
    fullScreen.update();
}

void handleButtonEvents()
{
    button.onClick([]()
                   { std::cout << "Button clicked!\n"; });

    closeButton.onClick([]()
                        { CloseWindow(); });

    fullScreen.onClick([]()
                       {    
                            ToggleFullscreen();
                            if (IsWindowFullscreen())
                            {
                                SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
                           }
                           else
                           {
                               SetWindowSize(800, 800);
                           } });
}
