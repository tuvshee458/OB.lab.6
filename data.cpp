#include <iostream>   // оролт гаралт ашиглах сан
#include <cmath>      // математик функц (sqrt гэх мэт)
using namespace std;  // std namespace ашиглах


// Shape класс 
class Shape {
protected:
    string name; // дүрсний нэр

public:
    void setName(string n) { // нэр оноох функц
        name = n;
    }

    string getName() { // нэр буцаах функц
        return name;
    }
};



class Shape2D : public Shape {
protected:
    double x, y; // ерөнхий координат

public:
    void setPosition(double x0, double y0) { // байрлал оноох
        x = x0; // x координат
        y = y0; // y координат
    }
};



// Circle класс
class Circle : public Shape2D {
private:
    double r;

public:
    void input();          
    double area();         
    double circumference();
};



// Square класс
class Square : public Shape2D {
private:
    double side;

public:
    void input();      
    double area();     
    double perimeter();
};



// Triangle класс 
class Triangle : public Shape2D {
private:
    double side;

public:
    void input();      
    double area();     
    double perimeter();
};


int main() {

    Circle c; // Circle объект үүсгэх
    Square s; // Square объект үүсгэх
    Triangle t; // Triangle объект үүсгэх


    c.input(); 
    cout << "Тойргийн талбай: " << c.area() << endl; // талбай хэвлэх
    cout << "Тойргийн урт: " << c.circumference() << endl; // урт хэвлэх

    cout << "------------------" << endl; 

    s.input(); 
    cout << "Квадратын талбай: " << s.area() << endl; // талбай
    cout << "Квадратын приметр: " << s.perimeter() << endl; // приметр

    cout << "------------------" << endl;


    t.input(); 
    cout << "Гурвалжны талбай: " << t.area() << endl; // талбай
    cout << "Гурвалжны приметр: " << t.perimeter() << endl; // приметр

    return 0; 
}