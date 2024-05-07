#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Point {
protected:
    double x, y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    virtual void draw() const = 0;
    virtual void erase() const = 0;
    virtual void move(double dx, double dy) {
        x += dx;
        y += dy;
    }
    virtual void rotate(double angle) {
        double rad_angle = angle * M_PI / 180.0;
        double new_x = x * cos(rad_angle) - y * sin(rad_angle);
        double new_y = x * sin(rad_angle) + y * cos(rad_angle);
        x = new_x;
        y = new_y;
    }
};

class Line : public Point {
protected:
    double x2, y2;
public:
    Line(double x1, double y1, double x2, double y2) : Point(x1, y1), x2(x2), y2(y2) {}
    void draw() const override {
        std::cout << "Drawing a line from (" << x << ", " << y << ") to (" << x2 << ", " << y2 << ")" << std::endl;
    }
    void erase() const override {
        std::cout << "Erasing line from (" << x << ", " << y << ") to (" << x2 << ", " << y2 << ")" << std::endl;
    }
};

class Rectangle : public Point {
protected:
    double width, height;
public:
    Rectangle(double x, double y, double width, double height) : Point(x, y), width(width), height(height) {}
    void draw() const override {
        std::cout << "Drawing a rectangle with top-left corner at (" << x << ", " << y << "), width " << width << " and height " << height << std::endl;
    }
    void erase() const override {
        std::cout << "Erasing rectangle with top-left corner at (" << x << ", " << y << "), width " << width << " and height " << height << std::endl;
    }
};

class Square : public Rectangle {
public:
    Square(double x, double y, double side_length) : Rectangle(x, y, side_length, side_length) {}
};

class Rhombus : public Square {
public:
    Rhombus(double x, double y, double side_length) : Square(x, y, side_length) {}
    void draw() const override {
        std::cout << "Drawing a rhombus with center at (" << x << ", " << y << ") and side length " << width << std::endl;
    }
    void erase() const override {
        std::cout << "Erasing rhombus with center at (" << x << ", " << y << ") and side length " << width << std::endl;
    }
};

class Parallelogram : public Square {
public:
    Parallelogram(double x, double y, double side_length) : Square(x, y, side_length) {}
};

int main() {
    Line line(0, 0, 2, 2);
    Rectangle rectangle(1, 1, 3, 4);
    Square square(2, 2, 5);
    Rhombus rhombus(3, 3, 4);
    Parallelogram parallelogram(4, 4, 6);

    line.draw();
    rectangle.draw();
    square.draw();
    rhombus.draw();
    parallelogram.draw();

    line.erase();
    rectangle.erase();
    square.erase();
    rhombus.erase();
    parallelogram.erase();

    line.move(1, 1);
    rectangle.rotate(45);
    square.move(-1, -1);
    rhombus.rotate(90);
    parallelogram.move(2, 2);

    return 0;
}




