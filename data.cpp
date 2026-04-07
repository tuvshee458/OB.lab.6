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
    void input() {
        setName("Toirog");
        cout << "Toirog-iin tuv koordinat (x y): ";
        cin >> x >> y;

        cout << "Toirog-iin Radius oruul: ";
        cin >> r;
    }
        
    double area() {
        return M_PI * r * r;
    }        
    double circumference() {
        return 2 * M_PI * r;
    }
};



// Square класс
class Square : public Shape2D {
private:
    double side;       // талын урт
 
    // 4 оройн координатууд (x,y - зүүн дээд орой Shape2D-с удамшсан)
    double x2, y2;     // баруун дээд орой
    double x3, y3;     // баруун доод орой
    double x4, y4;     // зүүн доод орой
 
public:
    // Оролт: зүүн дээд оройн координат болон талын урт авна,
    // бусад гурван оройг тооцоолж хадгална
    void input() {
        setName("Квадрат");
        cout << "Квадратын зүүн дээд оройн x координат: ";
        cin >> x;
        cout << "Квадратын зүүн дээд оройн y координат: ";
        cin >> y;
        cout << "Квадратын талын урт: ";
        cin >> side;
 
        // Зүүн дээд орой  (x,  y) - Shape2D-с удамшсан
        // Баруун дээд орой (x2, y2) - x чиглэлд side-аар шилжсэн
        x2 = x + side;  y2 = y;
        // Баруун доод орой (x3, y3) - x болон y чиглэлд side-аар шилжсэн
        x3 = x + side;  y3 = y - side;
        // Зүүн доод орой  (x4, y4) - y чиглэлд side-аар шилжсэн
        x4 = x;         y4 = y - side;
    }
 
    // Талбай = тал * тал
    double area() {
        return side * side;
    }
 
    // Периметр = 4 * тал
    double perimeter() {
        return 4 * side;
    }
};



// Triangle класс 
class Triangle : public Shape2D {
private:
    double x1, y1; // дээд орой
    double x2, y2, x3, y3; // бусад орой
    double side;
    

public:
    void input(){
        cout << "Zuv gurvaljingiin taliin urt: ";
        cin >> side;

        cout << "Deed oroin koordinat (x y): ";
        cin >> x1 >> y1;

        double h = sqrt(3) / 2 * side;

        // бусад оройг тооцоолно
        x2 = x1 - side / 2;
        y2 = y1 - h;

        x3 = x1 + side / 2;
        y3 = y1 - h;

        setName("Zuv Gurvaljin");
    }
        
    double area() { //Гурвалжны талбайг олох
        return (sqrt(3) / 4) * side * side;
    }
    double perimeter() { //Гурвалжны периметрийг олох
        return 3 * side;
    }
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
