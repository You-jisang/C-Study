#include "Password.hpp"
#include "Password.cpp"
#include <iostream>

using namespace std;

int main()
{
    Queue<int> q = Queue<int>(9);
    
    int time = 1;
    while(true)
    {
        for (int i = 0; i < 8; i++)
        {
            int x = 0;
            cin >> x;
            q.Push(x);
        }
        q.Password(time);
        q.Reset();          //front, rear index 0으로 초기화
        time++;
    }
}
