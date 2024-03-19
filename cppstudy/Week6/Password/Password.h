#ifndef Password_hpp
#define Password_hpp

#include <iostream>

using namespace std;



template <class T>
class Queue{
private:
    T* queue;
    int rear;
    int front;
    int capacity;
public:
    Queue(int queueCapacity = 10);
    ~Queue();
    inline bool IsEmpty() const;
    void Push(const T& item);
    int Pop();
    void Print(int i);
    void Password(int time);
    void Reset();
};

#endif
