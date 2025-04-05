#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// 4:00
// 그냥 수열에 1부터 시작하는 펄스랑 -1부터 시작하는 펄스 곱해놓고 두 수열 각각에 대해 연속합 가장 큰거 구해서 둘 중 더 큰걸 반환?
// 2, 3, -6, 1, 3, -1, 2, 4
// 2, -3, -6, -1, 3, 1, 2, -4
// -2, 3, 6, 1, -3, -1, -2, 4
long long solution(vector<int> sequence) {
    long long answer = 0;
    
    int len = sequence.size();
    vector<ll> v1, v2;
    
    v1.push_back(0);
    v2.push_back(0);
    
    for(int i = 0; i < len; i++) {
        if(i%2 == 0) {
            v1.push_back(sequence[i]);
            v2.push_back(-sequence[i]);
        } else {
            v1.push_back(-sequence[i]);
            v2.push_back(sequence[i]);
        }
    }
    
    for(int i = 1; i <= len; i++) {
        v1[i] = v1[i] + v1[i-1];
        v2[i] = v2[i] + v2[i-1];
    }
    
    int s = 1, e = 1;
    ll sum = 0, maxVal1 = 0, maxVal2 = 0;
    while(e <= len) {
        sum = v1[e] - v1[s-1];
        while(sum > 0 && e <= len) {
            maxVal1 = max(maxVal1, sum);
            e++;
            sum = v1[e] - v1[s-1];
        }
        s = e+1;
        e = s;
    }
    
    s = e = 1;
    sum = 0;
    while(e <= len) {
        sum = v2[e] - v2[s-1];
        while(sum > 0 && e <= len) {
            maxVal2 = max(maxVal2, sum);
            e++;
            sum = v2[e] - v2[s-1];
        }
        s = e+1;
        e = s;
    }
    
    answer = max(maxVal1, maxVal2);
    return answer;
}