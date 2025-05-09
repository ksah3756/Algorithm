#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 9;
    vector<int> ext = weak;
    for(int w : weak) ext.push_back(w+n);
    
    int size = weak.size();
    
    do {
        for(int i = 0; i < size; i++) {
            int idx = i, cnt = 0;
            for(int j = 0; j < dist.size(); j++) {
                int cur = ext[idx];
                int end = cur+dist[j];
                while(idx+1 < ext.size() && cur <= end) {
                    cnt++;
                    cur = ext[++idx];
                }
                
                if(cnt >= size) {
                    answer = min(answer, j+1);
                    break;
                }
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == 9) answer = -1;
    return answer;
}