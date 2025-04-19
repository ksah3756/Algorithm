#include <bits/stdc++.h>

using namespace std;
bool visited[101];

int solution(vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    
    vector<int> card;
    card.push_back(0);
    for(int i : cards) {
        card.push_back(i);
    }
    
    vector<int> sizes;
    for(int i = 1; i <= n; i++) {
        int size = 0;
        int idx = i;
        while(!visited[idx]) {
            visited[idx] = 1;
            size++;
            idx = card[idx];
        }
        if(size) sizes.push_back(size);
    }
    sort(sizes.begin(), sizes.end(), greater<int>());
    
    answer = sizes[0] * sizes[1];
    return answer;
}