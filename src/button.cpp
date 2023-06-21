#include "button.h"

Button::Button()
{
    this->text = "Button";
    this->style = Style();
};

Button::Button(std::string text)
{
    this->text = text;
    this->style = Style();
};

Button::Button(std::string text, Style style)
{
    this->text = text;
    this->style = style;
};

void Button::drawButton()
{

    DrawRectangle(
        this->style.position.x,
        this->style.position.y,
        this->style.width,
        this->style.height,
        this->style.backgroundColor);
    DrawText(
        this->text.c_str(),
        this->style.position.x + 10,
        this->style.position.y + 10,
        20,
        this->style.color);
}

void Button::onClick(std::function<void()> callback)
{
    this->click = callback;
}

void Button::onHover(std::function<void()> callback)
{
    this->hover = callback;
}

void Button::handleEvents()
{
    if (this->checkClick())
    {
        this->click();
    }

    if (this->checkHover())
    {
        this->hover();
    }
}

bool Button::checkClick()
{
    bool isClick = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    if (isClick)
    {
        Vector2 mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(
                mousePosition,
                {
                    this->style.position.x,
                    this->style.position.y,
                    this->style.width,
                    this->style.height,
                }))
        {
            return true;
        }
    }

    return false;
}

bool Button::checkHover()
{
    return false;
}

void Button::update()
{
    this->drawButton();
    this->handleEvents();
}
