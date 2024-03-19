#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>

using namespace std;

class Lecture {
public:
    int number;
    Lecture* next;
    
    
    Lecture(int num);
    ~Lecture();
};

class LectureList {
public:
    Lecture* head;
    
    LectureList();
    ~LectureList();

    void addLecture(int num);
    void displayLectures();
};


#endif
