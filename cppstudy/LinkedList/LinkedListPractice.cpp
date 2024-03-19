// 대학교에서 강의 목록을 관리하는 간단한 시스템을 구현
// 강의 정보는 과목 이름, 과목 번호로 구성됨
// 이 시스템은 강의 정보를 추가하고, 삭제하며, 전체 강의 목록을 출력할 수 있음

/*
요구 사항:

1. 강의 정보를 저장하는 데 연결 리스트를 사용하십시오.
2. 연결 리스트를 활용한 강의 목록 관리 시스템 클래스를 설계하십시오.
3. 강의 정보를 추가하는 기능을 구현하십시오.
4. 강의 정보를 삭제하는 기능을 구현하십시오.
5. 전체 강의 목록을 출력하는 기능을 구현하십시오.

*/

#include <iostream>
#include <string>

using namespace std;

class Lecture {
public:
    string name;
    int number;
    Lecture* next;

    Lecture(string name, int number) : name(name), number(number), next(nullptr) {}
};

class LectureList {
public:
    Lecture* head;

    LectureList() : head(nullptr) {}

    void addLecture(string name, int number) {
        Lecture* lec = new Lecture(name, number);
        Lecture* current = head;

        lec->name = name;
        lec->number = number;
        lec->next = nullptr;

        if (head == nullptr){
            
            head = lec;
            
        }
        else
        {
            while(current->next != nullptr)
            {
                current = current->next;
            }
            current->next = lec;
            
        }
        
        
        // TODO: 새로운 Lecture 객체를 생성하고, 연결 리스트에 추가하기
    }

    void deleteLecture(int number) {
        Lecture* current = head;
        Lecture* pre = nullptr;

        while (current != nullptr)
        {
            if(current->number == number)
            {
                if(pre == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    pre->next = current->next;
                    delete current;
                    return;
                }
                
            }
            pre = current;
            current = current->next;
            
        }
        // TODO: 강의 번호로 해당 강의를 찾아 연결 리스트에서 삭제하기
    }

    void displayLectures() {
        Lecture* print = head;

        if(head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        while(print != nullptr)
        {
            
            cout << "Lecture: " << print->name << "(" << print->number << ")" << endl;
            print = print->next;
        }
        
        // TODO: 연결 리스트의 모든 강의를 출력하기
    }
};

int main() {
    LectureList myList;
    myList.addLecture("Data Structures", 101);
    myList.addLecture("Algorithms", 102);
    myList.addLecture("Operating Systems", 201);
    myList.addLecture("Computer Networks", 202);

    cout << "Initial list:" << endl;
    myList.displayLectures();

    myList.deleteLecture(102);

    cout << "After removing lecture 102:" << endl;
    myList.displayLectures();

    return 0;
}

