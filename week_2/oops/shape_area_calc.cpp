// Create a base class Shape with derived classes Circle and Rectangle that demonstrates inheritance and polymorphism.
//
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;

    virtual void display() {
        cout << "Area     : " << area() << "\n";
        cout << "Perimeter: " << perimeter() << "\n";
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override {
        return M_PI * radius * radius;
    }

    double perimeter() override {
        return 2 * M_PI * radius;
    }

    void display() override {
        cout << "\n--- Circle ---\n";
        cout << "Radius   : " << radius << "\n";
        Shape::display();
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }

    double perimeter() override {
        return 2 * (length + width);
    }

    void display() override {
        cout << "\n--- Rectangle ---\n";
        cout << "Length   : " << length << "\n";
        cout << "Width    : " << width << "\n";
        Shape::display();
    }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(7);
    shapes[1] = new Rectangle(5, 10);

    for (int i = 0; i < 2; i++) {
        shapes[i]->display();
        delete shapes[i];
    }

    return 0;
}	
