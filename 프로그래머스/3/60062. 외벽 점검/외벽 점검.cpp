#include <bits/stdc++.h>

using namespace std;
// 9:08
// 아 근데 이렇게 하는것보다 그냥 dist 순열구하고 일직선으로 생각해서 구하는게 더 쉬울려나
vector<bool> visited;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 9;
    
    vector<int> ext = weak;
    int size = weak.size();
    for(int w : weak) {
        ext.push_back(w+n);
    }

    do {
        for(int k = 0; k < size; k++) {
            int idx = k, cnt = 0;
            for(int i = 0; i < dist.size(); i++) {
                int cur = ext[idx];
                int end = cur + dist[i];
                while(idx+1 < ext.size() && cur <= end) {
                    cnt++;
                    cur = ext[++idx];
                }
                if(cnt >= size) {
                    answer = min(answer, i+1);
                    break;
                }   
            }  
        }           
    } while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == 9) answer = -1;
    return answer;
}