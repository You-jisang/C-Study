#include <iostream>

using namespace std;

void Permutation(char *a, const int k, const int m);

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    char a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << endl;

    Permutation(a, 0, n - 1);

    return 0;
}


void Permutation(char *a, const int k, const int m) {
    if (k == m) {
        for (int i = 0; i <= m; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = k; i <= m; i++) {
            swap(a[k], a[i]);
            Permutation(a, k + 1, m);
            swap(a[i], a[k]);
        }
        
    }

}

