#ifndef RECTANGLE_H
#define RECTANGLE_H

using namespace std;

class Rectangle {
public:
    Rectangle(int, int, int, int, int); //생성자 선언
    ~Rectangle(); //파괴자
    int GetNum();
    int GetHeight();
    int GetWidth();
    int GetArea();
    friend ostream& operator <<(ostream& os, Rectangle& r); //연산자 다중

private:
    int rNum, xLow, yLow, height, width;
};
#endif
