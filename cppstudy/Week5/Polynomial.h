#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <iostream>


using namespace std;

class Polynomial {
    
    
public:
    Polynomial(); // 다항식 p(x)=0를 반환
    ~Polynomial();
    void NewTerm(const float, const int);
    void inputTerm(const float, const int);
    float GetCoef();
    int GetExp();
    friend ostream& operator << (ostream& os, Polynomial& p);
    
private:
    
    class Term* termArray;  // array of nonzero terms, 0이 아닌 항으로 구성된 배열
    int capacity;           // size of termArray
    int terms;              // number of nonzero terms, 0이 아닌 항의 수
}; // polynomial 정의 끝

class Term {

friend Polynomial;  //Polynomial 클래스 private 접근 가능
public:

private:
    float coef; //계수
    int exp;    //지수
    
};
#endif /* Polynomial_hpp */
