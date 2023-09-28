#include "menu.h"

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

Menu::Menu()
{
    this->state = MenuState::MAIN;

    this->screenWidth = static_cast<float>(GetScreenWidth());
    this->screenHeight = static_cast<float>(GetScreenHeight());

    this->background = LoadImage("assets/background.png");
    ImageResize(&background, static_cast<int>(screenWidth), static_cast<int>(screenHeight));
    this->backgroundTexture = LoadTextureFromImage(background);

    this->backgroundBlur = LoadShader(0, "assets/backgroundBlur.fs");
}

void Menu::update()
{
    screenWidth = static_cast<float>(GetScreenWidth());
    screenHeight = static_cast<float>(GetScreenHeight());

    if (this->state == MenuState::GAME)
    {
        return;
    }

    switch (this->state)
    {
    case MenuState::MAIN:
        this->renderMain();
        break;
    case MenuState::SETTINGS:
        this->renderSettings();
        break;
    }
}

Rectangle Menu::getMenuWrapper()
{
    float width = 600.0f;
    float height = 400.0f;

    if (screenWidth < 600.0f || screenHeight < 400.0f)
    {
        std::cout << "Screen size is too small for menu" << std::endl;
        return {0.0f, 0.0f, 0.0f, 0.0f};
    }
    else if (screenWidth < 800.0f || screenHeight < 600.0f)
    {
        width = 600.0f;
        height = 400.0f;
    }
    else if (screenWidth < 1366.0f || screenHeight < 768.0f)
    {
        width = 800.0f;
        height = 600.0f;
    }
    else if (screenWidth < 1920.0f || screenHeight < 1080.0f)
    {
        width = 1366.0f;
        height = 768.0f;
    }
    else
    {
        width = 1920.0f;
        height = 1080.0f;
    }

    return {(screenWidth - width) / 2.0f, (screenHeight - height) / 2, width, height};
}

void Menu::renderMain()
{
    Rectangle menuWrapper = this->getMenuWrapper();

    DrawTexture(backgroundTexture, 0, 0, WHITE);

    // Create a blur effect on the background behind the menu wrapper
    BeginShaderMode(backgroundBlur);

    DrawTextureRec(backgroundTexture, menuWrapper, {menuWrapper.x, menuWrapper.y}, WHITE);

    EndShaderMode();

    // GuiDrawRectangle(menuWrapper, 0, BLACK, {128, 128, 128, 48});
    DrawRectangleRounded(menuWrapper, 0.1f, 0, {128, 128, 128, 128});

    GuiSetStyle(DEFAULT, TEXT_SIZE, 64);
    GuiDrawText("Project C", {menuWrapper.x + 10, menuWrapper.y + 300, menuWrapper.width - 20, 50}, TEXT_ALIGN_CENTER, BLACK);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

    renderButtons(menuWrapper);
}


void Menu::renderSettings()
{
    GuiLabel({0, 0, 100, 20}, "Settings");

    bool buttonPressed = GuiButton({0, 20, 100, 20}, "Back");

    if (buttonPressed)
    {
        this->state = MenuState::MAIN;
    }
}


void Menu::renderButtons(Rectangle container)
{
    float containerOffsetY = container.y;
    float containerHeight = container.height;

    float mainButtonWidth = 400;
    float mainButtonHeight = 80;
    float mainButtonMargin = 20;
    float secondButtonWidth = 190;
    float secondButtonHeight = 50;
    float secondButtonMargin = mainButtonWidth - secondButtonWidth * 2;

    float buttonsHeight = mainButtonHeight * 2 + mainButtonMargin * 2 + secondButtonHeight;

    float mainButtonX = (screenWidth - mainButtonWidth) / 2;

    float playButtonY = containerOffsetY + (containerHeight - buttonsHeight) / 2;

    GuiSetStyle(DEFAULT, TEXT_SIZE, 32);
    bool buttonPlay = GuiButton({mainButtonX, playButtonY, mainButtonWidth, mainButtonHeight}, "Play");

    float multiplayerButtonY = playButtonY + mainButtonHeight + mainButtonMargin;
    bool buttonMultiplayer = GuiButton({mainButtonX, multiplayerButtonY, mainButtonWidth, mainButtonHeight}, "Multiplayer");
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

    float secondButtonY = multiplayerButtonY + mainButtonHeight + mainButtonMargin;
    float exitButtonX = mainButtonX + secondButtonWidth + secondButtonMargin;
    bool buttonSettings = GuiButton({mainButtonX, secondButtonY, secondButtonWidth, secondButtonHeight}, "Settings");
    bool buttonExit = GuiButton({exitButtonX, secondButtonY, secondButtonWidth, secondButtonHeight}, "Exit");

    if (buttonPlay)
    {
        this->state = MenuState::PLAY;
    }

    if (buttonMultiplayer)
    {
        this->state = MenuState::MULTIPLAYER;
    }

    if (buttonExit)
    {
        CloseWindow();
    }

    if (buttonSettings)
    {
        this->state = MenuState::SETTINGS;
    }
}
