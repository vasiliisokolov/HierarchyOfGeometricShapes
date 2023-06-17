#include <iostream>
#include <vector>

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

    void setColor(int input)
    {
        if (input > 3 || input < 0)
        {
            c = none;
        }
        else
        {
            switch (input)
            {
            case 0:
                c = none;
                break;
            case 1:
                c = red;
                break;
            case 2:
                c = blue;
                break;
            case 3:
                c = green;
                break;
            }
        }
        
    }

    std::string getColor()
    {
        switch (c)
        {
        case 0:
            return "none";
            break;
        case 1:
            return "red";
            break;
        case 2:
            return "blue";
            break;
        case 3:
            return "green";
            break;
        }
    }

    Figure (int inX, int inY, int inC)
    {
        cX = inX;
        cY = inY;
        setColor(inC);
    }
};

class Circle : public Figure
{

public:

    double radius;

    double areaC()
    {
        return atan(1) * 4 * radius;
    }

    double describeC()
    {
        return radius * radius;
    }

    Circle(int inX, int inY, int inC, double inRadius): Figure(inX, inY, inC)
    {
        radius = inRadius;
    }
};

class Triangle : public Figure
{
public:

    double edge;

    double areaT()
    {
        return edge * edge * std::sqrt(3) / 4;
    }
    
    double describeTandS()
    {
        return edge * edge;
    }

    Triangle (int inX, int inY, int inC, double inEdge) : Figure(inX, inY, inC)
    {
        edge = inEdge;
    }
    
};

class Square : public Triangle
{
public:

    double areaS()
    {
        return edge * edge;
    }

    Square (int inX, int inY, int inC, double inEdge) : Triangle (inX, inY, inC, inEdge)
    {
        
    }
};

class Rectangle : public Square
{
public:

    double height;

    double areaR()
    {
        return edge * height;
    }

    double describeR()
    {
        return edge * height;
    }

    Rectangle (int inX, int inY, int inC, double inWidth, double inHeight) : Square(inX, inY, inC, inWidth)
    {
        height = inHeight;
        
    }

};

int main()
{
    
    int tempX, tempY, tempC;
    double tempEdge , tempHeight;
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
                std::cout << "Enter shap's coordinates: ";
                std::cin >> tempX >> tempY;
                std::cout << "Enter shap's color: ";
                std::cin >> tempC;
                std::cout << "Enter shap's radius: ";
                std::cin >> tempEdge;
                Circle* circle = new Circle (tempX, tempY, tempC, tempEdge);
                std::cout << "This Circle is" << circle->getColor();
                std::cout << "This Circle's area is " << circle->areaC();
                std::cout << "This Circle discribe is " << circle->describeC();
                delete circle;
                //circle = nullptr;
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