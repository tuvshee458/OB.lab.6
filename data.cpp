// оролт гаралт хийхэд хэрэгтэй сан (cout, endl)
#include <iostream>

// математик функц ашиглах сан (sqrt функц)
#include <cmath>

// эрэмбэлэхэд хэрэгтэй sort сан
#include <algorithm>

// std namespace ашиглах
using namespace std;


// ЭХ КЛАСС 
// бүх дүрсний суурь abstract класс тодорхойлж байна
class Shape {
protected:
    // дүрсний нэр хадгалах хувьсагч (дэд классууд ашиглах боломжтой)
    string name;

public:
    // байгуулагч функц - класс үүсэхэд нэр онооно
    Shape(string n = "Unknown") {
        name = n; // параметрээр ирсэн утгыг name-д хадгалж байна
    }

    // талбай олох virtual функц (заавал дэд класс хэрэгжүүлнэ)
    virtual double area() = 0;

    // периметр олох virtual функц (заавал override хийнэ)
    virtual double perimeter() = 0;

    // дүрсний нэрийг буцаах функц
    string getName() {
        return name;
    }
};


// SHAPE2D
// 2 хэмжээст дүрсүүдийн дунд класс (Shape-оос удамшиж байна)
class Shape2D : public Shape {
protected:
    // координат хадгалах хувьсагчид (x, y)
    double x, y;

public:
    // байгуулагч функц - эх классын constructor дуудаж байна
    Shape2D(string n, double x0, double y0)
        : Shape(n), x(x0), y(y0) {} // Shape руу name дамжуулж байна
};


//  CIRCLE

// Circle класс Shape2D-оос удамшиж байна
class Circle : public Shape2D {
private:
    // радиус хадгалах хувьсагч (зөвхөн Circle дотор ашиглана)
    double r;

public:
    // байгуулагч - координат ба радиус авна
    Circle(double x, double y, double radius)
        : Shape2D("Circle", x, y), r(radius) {} // эх класст name дамжуулж байна

    // талбай бодох функц (Shape-ийн функцыг override хийж байна)
    double area() override {
        return 3.14159 * r * r; // πr² томьёо
    }

    // периметр бодох функц
    double perimeter() override {
        return 2 * 3.14159 * r; // 2πr
    }
};


// SQUARE 

// Square класс Shape2D-оос удамшиж байна
class Square : public Shape2D {
private:
    // квадратын талын урт
    double side;

public:
    // байгуулагч - координат ба талын урт авна
    Square(double x, double y, double s)
        : Shape2D("Square", x, y), side(s) {}

    // талбай бодох функц
    double area() override {
        return side * side; // a²
    }

    // периметр бодох функц
    double perimeter() override {
        return 4 * side; // 4a
    }
};


// TRIANGLE 

// Triangle класс Shape2D-оос удамшиж байна
class Triangle : public Shape2D {
private:
    // гурвалжны талын урт
    double side;

public:
    // байгуулагч - координат ба тал авна
    Triangle(double x, double y, double s)
        : Shape2D("Triangle", x, y), side(s) {}

    // талбай бодох функц
    double area() override {
        return (sqrt(3) / 4) * side * side; // тэнцүү талт гурвалжин
    }

    // периметр бодох функц
    double perimeter() override {
        return 3 * side; // 3a
    }
};


// MAIN ФУНКЦ

int main() {

    // олон объект үүсгэж байна

    // 3 ширхэг Circle объект
    Circle  c1(0, 0, 3);
    Circle  c2(1, 1, 5);
    Circle  c3(2, 2, 1.5);

    // 3 ширхэг Square объект
    Square  s1(0, 0, 4);
    Square  s2(1, 0, 2);
    Square  s3(0, 1, 6);

    // 3 ширхэг Triangle объект
    Triangle t1(0, 0, 5);
    Triangle t2(1, 0, 3);
    Triangle t3(0, 1, 7);

    // өөр өөр классын объектуудыг нэг төрөл (Shape*) болгон хадгалж байна
    Shape* shapes[9] = {
        &c1, &c2, &c3,
        &s1, &s2, &s3,
        &t1, &t2, &t3
    };

    // талбайгаар эрэмбэлэх 
    // lambda функц ашиглаж area()-аар харьцуулж байна
    sort(shapes, shapes + 9, [](Shape* a, Shape* b) {
        return a->area() < b->area(); // багаас их
    });

    // үр дүн хэвлэх
    cout << "\nResults (sorted by area):\n";

    // бүх объектуудыг давталтаар хэвлэж байна
    for (int i = 0; i < 9; i++) {

        // дүрсний нэр
        cout << shapes[i]->getName() << endl;

        // талбай
        cout << "Area: " << shapes[i]->area() << endl;

        // периметр
        cout << "Perimeter: " << shapes[i]->perimeter() << endl;

        // ялгах шугам
        cout << "------------------\n";
    }

    // програм амжилттай дууслаа
    return 0;
}