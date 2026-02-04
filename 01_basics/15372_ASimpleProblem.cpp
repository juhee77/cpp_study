#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    long long b;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b;

        // endl 사용시 시간 초과  cout << b * b << endl;
        cout << b * b << "\n";
    }
    return 0;
}
