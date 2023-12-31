﻿#include <iostream>

enum operation
{
    ex, 
    circle, 
    triangle,
    square, 
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
    double tempEdge, tempHeight = 0.0;
    int input;
    
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
            {
                std::cout << "Enter shap's coordinates: ";
                std::cin >> tempX >> tempY;
                std::cout << "Enter shap's color: ";
                std::cin >> tempC;
                std::cout << "Enter shap's radius: ";
                std::cin >> tempEdge;
                Circle* circle = new Circle(tempX, tempY, tempC, tempEdge);
                std::cout << "This Circle is " << circle->getColor() << std::endl;;
                std::cout << "This Circle's area is " << circle->areaC() << std::endl;;
                std::cout << "This Circle discribe is " << circle->describeC() << std::endl;;
                delete circle;
                //circle = nullptr;
            }
                break;
            case operation::triangle:
            {
                std::cout << "Enter shap's coordinates: ";
                std::cin >> tempX >> tempY;
                std::cout << "Enter shap's color: ";
                std::cin >> tempC;
                std::cout << "Enter shap's edge: ";
                std::cin >> tempEdge;
                Triangle* triangle = new Triangle(tempX, tempY, tempC, tempEdge);
                std::cout << "This Triangle is " << triangle->getColor() << std::endl;;
                std::cout << "This Triangle's area is " << triangle->areaT() << std::endl;;
                std::cout << "This Triangle discribe is " << triangle->describeTandS() << std::endl;;
                delete triangle;
                //triangle = nullptr;
            }
                break;
            case operation::square:
            {
                std::cout << "Enter shap's coordinates: ";
                std::cin >> tempX >> tempY;
                std::cout << "Enter shap's color: ";
                std::cin >> tempC;
                std::cout << "Enter shap's edge: ";
                std::cin >> tempEdge;
                Square* square = new Square(tempX, tempY, tempC, tempEdge);
                std::cout << "This Square is " << square->getColor() << std::endl;;
                std::cout << "This Square's area is " << square->areaS() << std::endl;;
                std::cout << "This Square discribe is " << square->describeTandS() << std::endl;;
                delete square;
                //square = nullptr;
            }
                break;
            case operation::rectangle:
            {
                std::cout << "Enter shap's coordinates: ";
                std::cin >> tempX >> tempY;
                std::cout << "Enter shap's color: ";
                std::cin >> tempC;
                std::cout << "Enter shap's widht: ";
                std::cin >> tempEdge;
                std::cout << "Enter shap's height: ";
                std::cin >> tempHeight;
                Rectangle* rectangle = new Rectangle(tempX, tempY, tempC, tempEdge, tempHeight);
                std::cout << "This Rectangle is " << rectangle->getColor() << std::endl;;
                std::cout << "This Rectangle's area is " << rectangle->areaS() << std::endl;;
                std::cout << "This Rectangle discribe is " << rectangle->describeTandS() << std::endl;;
                delete rectangle;
                //rectangle = nullptr;
            }
                break;
            case operation::ex:

                return 0;

            }
        }
    }
}