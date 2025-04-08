#include <bits/stdc++.h>

using namespace std;
// 10:26

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    auto cmp = [&](const vector<int>& v1, const vector<int>& v2) -> bool {
      if(v1[col-1] == v2[col-1]) return v1[0] > v2[0];
        return v1[col-1] < v2[col-1];
    };
    sort(data.begin(), data.end(), cmp);
    
    for(int i = row_begin - 1; i < row_end; i++) {
        int S_i = 0;
        for(int x : data[i]) {
            S_i += x % (i+1);
        }
        answer ^= S_i;
    }
    
    return answer;
}