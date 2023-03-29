#include <iostream>

using namespace std;

//(1 ≤R1, R2, C1, C2 ≤ 10) 조건이 있기때문에 10으로 size 제한, 매개변수로 사용하기 위해 크기 지정
void Plus(int a[][10], int b[][10], const int r, const int c);
void Minus(int a[][10], int b[][10], const int r, const int c);

int main(int argc, char const *argv[])
{
    //a행렬의 행 개수, 열 개수 변수 선언 및 입력
    int r1; int c1;
    cin >> r1 >> c1;
    //함수 전달하기 위해 2차원 배열 사이즈 지정
    int a[r1][10];
    //배열 a에 원소 입력
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> a[i][j];
        }
    }

    //배열에 원소가 잘 들어갔는지 확인
    /*for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j];
        }
    }*/

    //b행렬의 행 개수, 열 개수 변수 선언 및 입력
    int r2; int c2;
    cin >> r2 >> c2;

    int b[r2][10];
    //배열 b에 원소 입력
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> b[i][j];
        }
    }
    //연산 불가능한 경우 "계산 오류" 출력 후 종료
    if (r1 != r2 || c1 != c2) {
        cout << "계산 오류" <<  endl;
        return 0;
    }
    //덧셈, 뺄셈 함수 호출
    Plus(a, b, r1, c1);
    Minus(a, b, r1, c1);

}
//덧셈
void Plus(int a[][10], int b[][10], const int r, const int c) {

    for (int i = 0; i < r; i++) {
        
        for (int j = 0; j < c; j++) {
            cout << a[i][j] + b[i][j] << " ";
        }
        cout << endl;
    }
}
//뺄셈
void Minus(int a[][10], int b[][10], const int r, const int c) {

    for (int i = 0; i < r; i++) {
        
        for (int j = 0; j < c; j++) {
            cout << a[i][j] - b[i][j] << " ";
        }
        cout << endl;
    }
}
