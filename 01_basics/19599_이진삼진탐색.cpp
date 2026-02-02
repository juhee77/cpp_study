#include <iostream>
#include <vector>

using namespace std;

int N;
// B[i]: i번째 원소를 이진 탐색으로 찾을 때 참조 횟수
// T[i]: i번째 원소를 삼진 탐색으로 찾을 때 참조 횟수
vector<int> B, T;

void binary_search_sim(int l, int r, int cnt) {
    if (l > r) return;

    int mid = (l + r) / 2;
    B[mid] = cnt;
    binary_search_sim(l, mid - 1, cnt + 1);
    binary_search_sim(mid + 1, r, cnt + 1);
}

void ternary_search_sim(int l, int r, int cnt) {
    if (l > r) return;

    int m1 = l + (r - l) / 3;       // left_third
    int m2 = r - (r - l) / 3;       // right_third

    T[m1] = cnt;

    if (m1 != m2) {
        T[m2] = cnt + 1;
    }

    ternary_search_sim(l, m1 - 1, cnt + 2);
    if (m1 != m2) {
        ternary_search_sim(m1 + 1, m2 - 1, cnt + 2);
        ternary_search_sim(m2 + 1, r, cnt + 2);
    } else {
        ternary_search_sim(m2 + 1, r, cnt + 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    B.resize(N);
    T.resize(N);

    binary_search_sim(0, N - 1, 0);
    ternary_search_sim(0, N - 1, 0);

    int ans1 = 0; // B < T
    int ans2 = 0; // B == T
    int ans3 = 0; // B > T

    for (int i = 0; i < N; i++) {
        if (B[i] < T[i]) ans1++;
        else if (B[i] == T[i]) ans2++;
        else ans3++;
    }

    cout << ans1 << "\n";
    cout << ans2 << "\n";
    cout << ans3 << "\n";

    return 0;
}