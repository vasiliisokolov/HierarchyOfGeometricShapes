#include <iostream>

enum operation
{
    ex, 
    circle, 
    square, 
    triangle, 
    rectangle
};

class Figure
{
public:

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

class Circle : public Figure
{

public:

    double radius;

    double area()
    {
        return atan(1) * 4 * radius;
    }
};

class Triangle : public Figure
{
public:

    double edge;

    double area()
    {
        return edge * edge * std::sqrt(3) / 4;
    }
};

class Square : public Figure
{
public:

    double edge;

    double area()
    {
        return edge * edge;
    }
};

class Rectangle : public Figure
{
public:

    double width, height;

    double area()
    {
        return width * height;
    }
};

int main()
{
    std::cout << "";
}