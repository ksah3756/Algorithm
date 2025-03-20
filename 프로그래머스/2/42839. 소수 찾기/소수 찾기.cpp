#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
int cnt = 0;
bool visited[10000000];
bool used[7];

void solve(string& numbers, string& str, int idx) {
    if(idx == numbers.size()) {
        if(str.empty()) return;
        int n = stoi(str);
        if(n == 0 || n == 1 || visited[n]) return;
        visited[n] = 1;
        bool flag = 1;
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) {
                flag = 0;
                break;
            }
        }
        // cout << n << ' ' << flag << '\n';
        if(flag) cnt++;
        return;
    }
    for(int i = 0; i < numbers.size(); i++) {
        if(used[i]) continue;
        str += numbers[i];
        used[i] = 1;
        solve(numbers, str, idx+1);
        str.pop_back();
        used[i] = 0;
        solve(numbers, str, idx+1);
    }
}

int solution(string numbers) {
    int answer = 0;
    string str = "";
    solve(numbers, str, 0);
    answer = cnt;
    return answer;
}

