#include <iostream>

class Figure
{
    enum color
    {
        none = 0,
        red = 1,
        blue = 2,
        green = 3
    };
    int cX;
    int cY;
    color c;

};

int main()
{
    std::cout << "Hello World!\n";
}