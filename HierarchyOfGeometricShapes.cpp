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

    double describe()
    {
        return radius * radius;
    }

    Circle(int inX, int inY, color inC, double inRadius): radius(inRadius)
    {
        cX = inX;
        cY = inY;
        c = inC;
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
    
    double describe()
    {
        return edge * edge;
    }

    Triangle (int inX, int inY, color inC, double inEdge) : edge(inEdge)
    {
        cX = inX;
        cY = inY;
        c = inC;
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

    double describe()
    {
        return edge * edge;
    }

    Square (int inX, int inY, color inC, double inEdge) : edge(inEdge)
    {
        cX = inX;
        cY = inY;
        c = inC;
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

    double describe()
    {
        return width * height;
    }

    Rectangle (int inX, int inY, color inC, double inWidth, double inHeight) : width(inWidth), height(inHeight)
    {
        cX = inX;
        cY = inY;
        c = inC;
    }

};

int main()
{
    int input;
    std::cout << "Choose the shape: ";
    std::cin >> input;

    while (true)
    {
        std::cout << "Choose the shape: ";
        std::cin >> input;
        if (input > 4 || input < 0)
        {
            std::cerr << "Error! Wrong operation! Try again!" << std::endl;
        }
        else
        {
            switch (input)
            {
            case operation::circle:
                break;
            case operation::square:
                
                break;
            case operation::triangle:
                
                break;
            case operation::rectangle:

                break;
            case operation::ex:

                return 0;

            }
        }
    }
}