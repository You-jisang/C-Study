#ifndef CardSort_h
#define CardSort_h

#include <iostream>
#include <cstdlib>


using namespace std;

template<typename T>
class Card
{
public:
    Card();
    ~Card();
    T& GetTrump(int i);
    
private:
    T* Trump;           //트럼프 카드를 string 자료형으로 S1부터 C13까지 넣고 인덱스로 크기 비교
    
};

template <typename T>
class Deque{
private:
    T* deque;
    int rear;
    int front;
    int capacity;
    
public:
    Deque(int dequeCapacity);
    ~Deque();
    inline bool IsEmpty() const;    //비어있으면 예외처리 및 첫번째 카드 입력시 조건으로 사용
    inline T& Front() const;        //Push, Pop에 사용
    inline T& Rear() const;         //Push, Pop에 사용
    void DequeSort(int x);          //카드 정렬(데크)
    void Push(int x);               //Front일 때 지급받은 카드 Push
    void ReversePush(int x);        //Rear일 때 지급받은 카드 Push
    void PushFront();               //Front일 때 지급받은 카드를 넣기 위해 작은 카드들 뒤로 보내기
    void PopFront();                //Front일 때 Push하고 뒤로 보낸 작은 카드들 다시 앞으로 보내기
    void PushRear();                //Rear일 때 지급받은 카드를 넣기 위해 큰 카드를 앞으로 보내기
    void PopRear();                 //Rear일 때 ReversePush하고 앞으로 보낸 큰 카드를 다시 뒤로 보내기
    void PrintDeque();              //데크 front + 1 부터 rear까지 출력
};


#endif
