#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

// 1:52
// 그냥 내 양 옆 중 가장 작은 수를 찾고 그 수들이 둘 다 나보다 작으면 불가능, 1 또는 0 이면 가능
// 인덱스까지 같이 저장해서 정렬하고 오름차순일 때 차례대로 탐색하면서 인덱스 최소값, 최대값을 유지해서 내 인덱스 값이 그 사이에 있다면 불가능
int solution(vector<int> a) {
    int answer = 1;
    vector<pii> arr;
    
    for(int i = 0; i < a.size(); i++) {
        arr.push_back({a[i], i});
    }
    
    sort(arr.begin(), arr.end());
    
    int minIdx = arr[0].second;
    int maxIdx = arr[0].second;
    
    for(int i = 1; i < arr.size(); i++) {
        int myIdx = arr[i].second;
        if(!(minIdx < myIdx && myIdx < maxIdx)) {
            answer++;
        }
        if(minIdx > myIdx) minIdx = myIdx;
        if(maxIdx < myIdx) maxIdx = myIdx;
    }
    
    return answer;
}