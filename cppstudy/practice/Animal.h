#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;

class Animal {
private:
    int food;
    int weight;
    
public:
    void SetAnimal(int f, int w)
    {
        food = f;
        weight = w;
    }
    
    void PrintAnimal()
    {
        cout << food << ", " << weight << endl;
    }
};
#endif
