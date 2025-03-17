#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;
void hanoi(int, int, int);

vector<vector<int>> solution(int n) {
    
    hanoi(n, 1, 3);
    return answer;
}

// src, middle, dest 로 나누면
// 항상 n-1 하노이 탑을 일단 middle에 두고, 맨 밑 원판을 dest에 둔 후 middle에 두었던 n-1원판을 dest에 놓기

void hanoi(int n, int src, int dest) {
    if(n == 1) {
        vector<int> v = {src, dest};
        answer.push_back(v);
        return;
    }
    int middle = 6 - (src+dest);
    hanoi(n-1, src, middle);
    
    vector<int> v = {src, dest};
    answer.push_back(v);
    
    hanoi(n-1, middle, dest);
}

