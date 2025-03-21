#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;
typedef unordered_set<int> uset;
uset dp[9];

int solution(int N, int number) {
    int answer = 0;

    int x = 0;
    for(int i = 1; i <= 8; i++) {
        x = 10 * x + N;
        if(x == number) return answer = i;
        dp[i].insert(x);
    }
    
    // N 사용횟수는 계속 증가만 가능
    // dp[i] = N을 i번 사용했을 때 가능한 수의 집합
    // dp[i] = dp[j] (연산자) dp[i-j]
    for(int i = 2; i <= 8; i++) {
        for(int j = 1; j < i; j++) {
            for(int k : dp[j]) {
                for(int l : dp[i-j]) {
                    if(k+l == number || k-l == number || k*l == number) {
                        return answer = i;
                    }
                    dp[i].insert(k + l);
                    dp[i].insert(k - l);
                    dp[i].insert(k * l);
                    if(l != 0) {
                        if(k/l == number) return answer = i;
                        dp[i].insert(k / l);
                    }
                }
            }
        }
    }
    
    
    return answer = -1;
}
