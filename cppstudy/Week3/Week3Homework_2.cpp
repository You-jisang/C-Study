#include <iostream>

using namespace std;

void sort(int *a, const int n);
int BinarySearch(int *a, const int x, const int left, const int right);

int main(int argc, char const *argv[])
{
    //수열 a의 크기와 정수 x 변수 선언 및 입력
    int size; int data;
    cin >> size >> data;

    //수열 a 생성 및 크기 지정
    int a[size];

    //수열a에 원소 입력
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    //선택 정렬 함수
    sort(a, size);
    
    //data보다 큰 정수가 수열 내에 없을 경우
    if (a[size - 1] <= data) {
        cout << "Error" << endl;
        return 0;
    }
    //이원 탐색
    int res = BinarySearch(a, data, 0, size - 1);

    //data보다 큰 자연수 출력
    for (int i = res; i < size; i++) {
        if (a[i] <= data) continue; //두 가지 경우
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
//선택 정렬
void sort(int *a, const int n) {
    for (int i = 0; i < n; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++) {
            if (a[k] < a[j]) j = k;
        }
        swap(a[i], a[j]);
    }
}

//순환 이원 탐색
int BinarySearch(int *a, const int x, const int left, const int right) {
    
    while(left <= right) {
        int middle = (left + right) / 2;
        if(x < a[middle]) return BinarySearch(a, x, left, middle - 1);
        else if (x > a[middle]) return BinarySearch(a, x, middle + 1, right);
        else return middle; //인덱스 middle
    }
    return 0; //인덱스 0
}

