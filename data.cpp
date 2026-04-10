#include <iostream>   // оролт гаралт
#include <cmath>      // математик функц
#include <windows.h>  // монгол текст
using namespace std;


// ЭХ КЛАСС 

// Shape ерөнхий класс (abstract)
class Shape {
protected:
    string name; 

public:
    // байгуулагч - нэр онооно
    Shape(string n = "Unknown") {
        name = n;
    }

    // override 
    virtual double area() = 0;

    // периметр
    virtual double perimeter() = 0;

    // нэр буцаах
    string getName() {
        return name;
    }
};


// 2D SHAPE

class Shape2D : public Shape {
protected:
    double x, y; // координат

public:
    // байгуулагч - эх классыг дуудна
    Shape2D(string n = "Shape2D", double x0 = 0, double y0 = 0)
        : Shape(n) {
        x = x0;
        y = y0;
    }
};


// CIRCLE 

class Circle : public Shape2D {
private:
    double r; // радиус

public:
    // default байгуулагч
    Circle() : Shape2D("Circle", 0, 0) {
        r = 0;
    }

    // хэрэглэгчээс утга авах
    void input() {
        cout << "Toirog tuv (x y): ";
        cin >> x >> y;

        cout << "Radius: ";
        cin >> r;
    }

    // талбай (override)
    double area() override {
        return M_PI * r * r;
    }

    // урт (override)
    double perimeter() override {
        return 2 * M_PI * r;
    }
};


// SQUARE

class Square : public Shape2D {
private:
    double side; // тал

public:
    // default байгуулагч
    Square() : Shape2D("Square", 0, 0) {
        side = 0;
    }

    // оролт авах
    void input() {
        cout << "Square zuun deed (x y): ";
        cin >> x >> y;

        cout << "Side: ";
        cin >> side;
    }

    // талбай
    double area() override {
        return side * side;
    }

    // периметр
    double perimeter() override {
        return 4 * side;
    }
};


// TRIANGLE

class Triangle : public Shape2D {
private:
    double side; // тал
    double x1, y1, x2, y2, x3, y3; // оройнууд

public:
    // default байгуулагч
    Triangle() : Shape2D("Triangle", 0, 0) {
        side = 0;
    }

    // оролт авах
    void input() {
        cout << "Triangle side: ";
        cin >> side;

        cout << "Top point (x y): ";
        cin >> x1 >> y1;

        // өндрийг бодох
        double h = sqrt(3) / 2 * side;

        // доод оройнууд
        x2 = x1 - side / 2;
        y2 = y1 - h;

        x3 = x1 + side / 2;
        y3 = y1 - h;
    }

    // талбай
    double area() override {
        return (sqrt(3) / 4) * side * side;
    }

    // периметр
    double perimeter() override {
        return 3 * side;
    }
};


// MAIN

int main() {

    // монгол текст зөв гаргах
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // объектууд
    Circle c;
    Square s;
    Triangle t;

    // input авах
    c.input();
    s.input();
    t.input();

    // Shape pointer массив
    Shape* shapes[3];

    // объектуудын хаяг оноох
    shapes[0] = &c;
    shapes[1] = &s;
    shapes[2] = &t;

    cout << "\n RESULTS \n";

    // бүх дүрсийг нэг циклээр ажиллуулах
    for (int i = 0; i < 3; i++) {

        // нэр хэвлэх
        cout << shapes[i]->getName() << endl;

        // талбай хэвлэх
        cout << "Area: " << shapes[i]->area() << endl;

        // периметр хэвлэх
        cout << "Perimeter: " << shapes[i]->perimeter() << endl;

        cout << "------------------" << endl;
    }

    return 0; // програм дууслаа
}