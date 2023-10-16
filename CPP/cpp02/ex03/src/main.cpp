#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void printMap(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point a(10, 30);
    Point b(0, 0);
    Point c(20, 0);
    float x;
    float y;

    std::cout << "Input x and y (x y): ";
    std::cin >> x >> y;
    if (std::cin.fail())
    {
        std::cout << "\n\tBad input\n" << std::endl;
        return (EXIT_FAILURE);
    }

    bool isInside = bsp(a, b, c, Point(x, y));

    printMap(a, b, c, Point(x, y));

    if (isInside)
        std::cout << "(" << x << "," << y << ") is inside the triangle" << std::endl;
    else
        std::cout << "(" << x << "," << y << ") is outside the triangle" << std::endl;

    return 0;
}

void printMap(Point const a, Point const b, Point const c, Point const point)
{
    const int mapWidth = 21;
    const int mapHeight = 6;

    std::cout << "Map:" << std::endl;
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            Point current(j, i);
            char symbol = ' ';

            if (current == a || current == b || current == c)
                symbol = 'A';  // Use 'A' para todos os vértices
            else if (current == point)
                symbol = 'P';

            std::cout << symbol;
        }
        std::cout << std::endl;
    }

    std::cout << "Legend:" << std::endl;
    std::cout << "A - Triangle vertices" << std::endl;
    std::cout << "P - Test point" << std::endl;
}


