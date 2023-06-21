#include "dom.h"

using namespace std;

DOM::DOM()
{
    std::cout << "DOM constructor called" << std::endl;
}

void DOM::load(std::string file)
{
    std::string path = "../layouts/" + file;

    std::ifstream templateFile(path);

    std::string myText;

    if (!templateFile)
    {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }

    std::string line;
    while (getline(templateFile, line))
    {
        myText += line;
    }

    templateFile.close();

    std::cout << myText << std::endl;

    std::cout << "DOM load called" << std::endl;
}

void DOM::render()
{
    this->screenWidth = GetScreenWidth();
    this->screenHeight = GetScreenHeight();

    // std::cout << "Screen width: " << this->screenWidth << std::endl;
    // std::cout << "Screen height: " << this->screenHeight << std::endl;
    // std::cout << "DOM render called\n"
    //           << std::endl;
}
