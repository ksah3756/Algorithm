#include <bits/stdc++.h>

using namespace std;

// 11:00
// dp[s][e] -> s부터 e까지의 연산 수
int dp[201][201];

const int INF = INT_MAX;
vector<vector<int>> matrix;

int solve(int s, int e) {
    int& ret = dp[s][e];
    if(ret != INF) return ret;
    if(s == e) return ret = 0;
    if(s+1 == e) {
         return ret = matrix[s][0] * matrix[s][1] * matrix[e][1];
    }

    for(int i = s; i < e; i++) {
        ret = min(ret, matrix[s][0] * matrix[i][1] * matrix[e][1] + solve(s, i) + solve(i+1, e));
    }

    return ret;
}

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    
    int size = matrix_sizes.size();
    matrix = matrix_sizes;
    
    fill_n(&dp[0][0], 201*201, INF);
    
    answer = solve(0, size-1);
    
    return answer;
}