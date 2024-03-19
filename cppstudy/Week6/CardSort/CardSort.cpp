#include "CardSort.h"
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
Card<T>::Card()
{
    Trump = new T[52]{"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13"}; // 트럼프 카드 초기화 인덱스에 따라서 카드 크기 정렬 S-D-H-C순서
}


template <typename T>
Card<T>::~Card() { }

template <typename T>
T& Card<T>::GetTrump(int i)
{
    return Trump[i];
}

template <typename T>
Deque<T>::Deque(int dequeCapacity):capacity(dequeCapacity)
{
    try
    {
        if(capacity < 1) throw string("capasity is not 0");
        deque = new T[capacity];
        front = rear = 0;
    }
    catch(string error)
    {
        cout << error << endl;
    }
}

template <typename T>
Deque<T>::~Deque() {}

template <class T>
inline bool Deque<T>::IsEmpty() const
{
    return front==rear;
}

template <class T>
inline T& Deque<T>::Front() const
{
    try
    {
        if(IsEmpty()) throw front;
        return deque[(front+1)%capacity];
    }
    catch(int exception)
    {
        cout << "Queue is empty" << endl;
        return deque[front];
    }
}

template <class T>
inline T& Deque<T>::Rear() const
{
    try
    {
        if(IsEmpty()) throw rear;
        return deque[rear];
    }
    catch(int exception)
    {
        cout << "Queue is empty" << endl;
        return deque[rear];
    }
}

template <typename T>
void Deque<T>::DequeSort(int x)
{
    if(IsEmpty() == 1) //첫 카드 지급
    {
        Push(x);
        return;//함수 중간에 종료
    }
    PrintDeque(); //이전 데크 한번 출력
    //x와 deque 내부 값들을 비교해 x가 들어갈 인덱스 찾기
    int index = 0; //x가 들어갈 인덱스
    int flag = 0;
    if (rear < front && front != capacity - 1)
    {
        for (int i = (front + 1) % capacity; i < capacity; i++)
        {
            if (deque[i] > x) //1. 중간에 x보다 큰 수를 만났을 때
            {
                index = i;
                flag = 1;
                break;
            }
        }
        if (flag == 0) //앞에서 x보다 큰수가 없을 때만 탐색
        {
            for (int i = 0; i <= rear; i ++)
            {
                if (deque[i] > x) //1. 중간에 x보다 큰 수를 만났을 때
                {
                    index = i;
                    flag = 1;
                    break;
                }
            }
        }
        
    }
    else
    {
        for(int i = (front + 1) % capacity; i <= rear; i++)  //원형 데크이기때문에 크기로 나눈 나머지 값으로 설정
        {
            if (deque[i] > x) //1. 중간에 x보다 큰 수를 만났을 때
            {
                index = i;
                flag = 1;
                break;
            }
            
        }
    }
    
    if (flag == 0) //2. 중간에 x보다 큰 수를 만나지 못했을 때
    {
        Push(x);
        return;
    }
    //1-1.가까운 거리 찾기
    int FtoX = abs(((front + capacity + 1) % capacity) - index); //x - r - f순서고려
    int XtoR = abs(index - (rear % capacity));
    
    if (FtoX > XtoR) //
    {
        for(int i = 0; i < XtoR + 1; i++) //r-x거리 + 1
        {
            PushRear();
        }
        Push(x);
        for(int i = 0; i < XtoR + 1; i++)
        {
            PopRear();
        }
    }
    else
    {
        for(int i = 0; i < FtoX; i++) //f-x거리만큼만
        {
            PushFront();
        }
        ReversePush(x);
        for(int i = 0; i < FtoX; i++) //f-x거리만큼만 -> index 앞의 원소 개수 만큼
        {
            PopFront();
        }
        
    }
}

template <typename T>
void Deque<T>::Push(int x)
{
    rear = (rear + 1) % capacity;
    deque[rear] = x;
    PrintDeque();
}

template <typename T>
void Deque<T>::ReversePush(int x)
{
    deque[front] = x;
    front = (front + capacity - 1) % capacity;
    PrintDeque();
}

template <typename T>
void Deque<T>::PushFront()
{
    rear = (rear + 1) % capacity;
    deque[rear] = Front();
    front = (front + 1) % capacity;
    PrintDeque();
}

template <typename T>
void Deque<T>::PopFront()
{
    deque[front] = Rear();
    rear = (rear + capacity - 1) % capacity; //-1할때는 반드시 배열의 크기를 한번 더 더해줘야함
    front = (front + capacity - 1) % capacity;
    PrintDeque();
}

template <typename T>
void Deque<T>::PushRear()
{
    deque[front] = Rear();
    front = (front + capacity - 1) % capacity;  //front가 0일 경우 배열의 크기를 더해 주지않으면 -1이됨
    rear = (rear + capacity - 1) % capacity;    //rear가 0일 경우 배열의 크기를 더해주지않으면 -1이됨
    PrintDeque();
}

template <typename T>
void Deque<T>::PopRear()
{
    rear = (rear + 1) % capacity;
    deque[rear] = Front();
    front = (front + 1) % capacity;
    PrintDeque();
}

template <typename T>
void Deque<T>::PrintDeque()
{
    Card<string> card;
    
    if (rear < front && front != capacity -1) // rear가 front보다 뒤에있고 front가 마지막 인덱스가 아닐때 구분
    {
        for (int i = (front + 1) % capacity; i < capacity; i++)
        {
            cout << card.GetTrump(deque[i]) << " ";
        }
        for(int i = 0; i <= rear; i++)
        {
            cout << card.GetTrump(deque[i]) << " ";
        }
        cout << endl;
    }
    else
    {
        for(int i = (front + 1) % capacity; i <= rear; i++)
        {
            cout << card.GetTrump(deque[i]) << " ";
        }
        cout << endl;
    }
    
    
}
