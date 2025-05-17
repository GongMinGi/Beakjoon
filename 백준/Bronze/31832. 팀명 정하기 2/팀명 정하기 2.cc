#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S;
    while (N--) {
        cin >> S;
        // 2) 길이 10 이하
        if (S.size() > 10) continue;

        // 1) 대문자 수 ≤ 소문자 수
        int upper = 0, lower = 0;
        for (char c : S) {
            if ('A' <= c && c <= 'Z') ++upper;
            else if ('a' <= c && c <= 'z') ++lower;
        }
        if (upper > lower) continue;

        // 3) 숫자로만 구성되지 않아야 함
        bool has_non_digit = false;
        for (char c : S) {
            if (!(c >= '0' && c <= '9')) {
                has_non_digit = true;
                break;
            }
        }
        if (!has_non_digit) continue;

        // 모든 조건 통과 시 출력 후 종료
        cout << S;
        return 0;
    }

    return 0;
}
