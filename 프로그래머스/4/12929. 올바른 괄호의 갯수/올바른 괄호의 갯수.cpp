#include <string>
#include <vector>

using namespace std;
// 일단 여는 괄호 수 가 닫는 괄호 수보단 항상 같거나 커야 함
// 근데 중복이 문제네
// 현재 문자열 길이랑 남은 왼,오 괄호수가 같으면 같은 경우 -> 이러면 dp인데
// dp[i][j] -> 괄호 문자열 길이가 i, l 괄호의 개수가 j일 때 경우의 수
int dp[29][15];
int N;

int solve(int len, int l) {
    int& ret = dp[len][l];
    if(ret) return ret;
    
    if(len == (N<<1)) return ret = 1;
    
    // r을 놓을 수 있는건 l 개수가 r 개수보다 많을 때
    if(l+1 <= N) ret += solve(len+1, l+1);
    if(l > len-l) {
        ret += solve(len+1, l);
    }
    return ret;
}

int solution(int n) {
    int answer = 0;
    N = n;
    answer = solve(0, 0);
    return answer;
}