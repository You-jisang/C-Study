#include <iostream>
#include "Password.hpp"

using namespace std;

template <class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity)
{
    try
    {
        if(capacity < 1) throw string("Queue capacity must be >0");
        queue = new T[capacity];
        front = rear = 0;
    }
    catch(string error){
        cout << error << endl; //try catch 이렇게 하는거 맞는지 확인
    }
}

template <class T>
Queue<T>::~Queue(){}

template <class T>
inline bool Queue<T>::IsEmpty() const
{
    return front == rear;
}

template <class T>
void Queue<T>::Push(const T& x)
{
    rear = (rear + 1) % capacity;
    queue[rear] = x;
}

template <class T>
int Queue<T>::Pop()
{
    try
    {
        if(IsEmpty()) throw string("Queue is Empty");
        front = (front+1)%capacity;
        return queue[front];
    }
    catch(string error)
    {
        cout << error << endl;
        return 0;   //Non-void function does not return a value in all control paths
    }
}

template <class T>
void Queue<T>::Print(int i)
{
    cout << queue[i] << " ";
}

template <class T>
void Queue<T>::Password(int time)
{
    int count = 1; //1~5 빼기 반복
    int fin = 1;
    //int now = 1;
    while (fin == 1)
    {
        int num = Pop();
        //cout << "num: " << num << endl;
        if (count == 6) count = 1;
        num -= count++;
        if (num <= 0) //맨뒤로 보내는 숫자가 0일 경우 한 과정 종료
        {
            num = 0;
            Push(num);
            cout << "#" << time << " ";
            for (int i = 1; i < 9; i++)
            {
                Print((front + i) % capacity);
            }
            cout << endl;
            
            fin = 0;
        }
        else Push(num);
        
        /*cout << endl;
        cout << "num " << now << ": " <<num << " count: " << count - 1 << " front: " << front<< " rear: " << rear;
        now++;
        if(now == 9) now = 1;
        
        cout << " push 후 rear: " << rear << endl;
        cout << "(front + 1) % capacity 부터 출력: ";
        for (int i = 1; i < 9; i++)
        {
            Print((front + i) % capacity);
        }
        cout << endl;
        cout << "queue 인덱스 0부터 출력: ";
        for (int i = 0; i < 9; i++)
        {
            Print(i % capacity);
        }
        cout << endl;*/
    }
}

template <class T>
void Queue<T>::Reset()
{
    front = rear = 0;
}
