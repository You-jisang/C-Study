#include <iostream>

using namespace std;

void sort(int *a, const int n);
int BinarySearch1(int *a, const int x, const int left, const int right);


int main(int argc, char const *argv[])
{
    int n = 10;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a , n);

    for (int i = 0; i < n; i++) {
        
        cout << a[i] <<" ";
    }
    cout << endl;

    int data, res;
    cin >> data;


    res = BinarySearch1(a, data, 0, n - 1);
    
    if (res >= 0) {
        cout << data << "는" << res << "번쨰 입니다." << endl;
    } else cout << data << "는" << "없습니다." << endl;
    
    return 0;
}


void sort(int *a, const int n) {
    for(int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (a[k] < a[i]) {
                swap(a[i], a[k]);
            }
        }
    }
}

int BinarySearch1(int *a, const int x, const int left, const int right) {
    
    
    while (left <= right) {
        int middle = (left + right) / 2;

        if (x < a[middle]) return BinarySearch1(a, x, left, middle - 1);
        else if (x > a[middle]) return BinarySearch1(a, x, middle + 1, right);
        else return middle;
    }
    return -1;
}
