#include "CardSort.h"
#include "CardSort.cpp"
#include <iostream>
#include <random>

using namespace std;

int main()
{
    Card<string> card; //트럼프 카드 생성 - string으로 생성자에서 초기화했기 때문에 T에는 string밖에 못 들어감

    int capasity = 0;
    cin >> capasity;    // 선택할 카드의 수
    Deque<int> cardSort = Deque<int>(capasity + 2); //인덱스로 카드의 크기를 비교할 것이기 때문에 T타입을 int형으로 하고 데크를 위해 (카드의 수 + 2) 만큼 크기를 지정해줌 데크안에서 숫자(인덱스)로 거리를 비교하고 마지막에 GetTrump로 card(string자료형)으로 변환해줌
    random_device rd;                               //랜덤 난수
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,51);
    
    int N[capasity];
    int count = 1;
    N[0] = dis(gen);
    while (count != capasity)   //중복 방지
    {
        int flag = 0;
        int num = dis(gen);
        for (int i = 0; i < count; i++)
        {
            if(N[i] == num) flag++;
        }
        if(flag == 0)
        {
            N[count++] = num;
        }
    }
    
    for(int i = 0; i < capasity; i++)
    {
        cout << "선택 된 카드 " << i + 1 << ":" << card.GetTrump(N[i]) << endl;
        cardSort.DequeSort(N[i]);
        cout << endl;
    }
    
    

}
