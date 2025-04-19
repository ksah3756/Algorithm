#include <string>
#include <vector>

using namespace std;

// a, b 크기 상관 X
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

// 24 32 -> 96
int solution(vector<int> arr) {
    int answer = 0;
    
    if(arr.size() == 1) return arr[0];
    
    answer = arr[0] * arr[1] / gcd(arr[0], arr[1]);
    
    for(int i = 2; i < arr.size(); i++) {
        answer = answer * arr[i] / gcd(answer, arr[i]);
    }
    return answer;
}