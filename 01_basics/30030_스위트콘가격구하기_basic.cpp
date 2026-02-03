#include <iostream>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cout << static_cast<int>(static_cast<double>(N) / 11 * 10) << "\n";
    return 0;
}
