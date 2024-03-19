#ifndef Station_hpp
#define Station_hpp

#include <iostream>
#include <string>

using namespace std;



class StationChain {
public:
    string station;
    StationChain* next;
    
    StationChain(string st);
    ~StationChain();
};


class StationList {
public:
    StationChain* head;
    StationChain* tail;
    
    StationList();
    ~StationList();
    
    void Map(string* stations); //
    int Close(string nowStation);
    int Rename(string oldStation, string newStation);
    int MakeTri(string front, string rear, string newStation);
    int Make(string front, string newStation);
    void PrintMap(); //
    
    
    
};

#endif
