#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// 2:24
// 나올 수 있는건 무조건 n개인데 여기서 중복만 제거
int solution(vector<int> elements) {
    int answer = 0;
    
    int n = elements.size();
    int len = 0;
    
    unordered_set<int> set;
    
    while(len < n) {
        int s = 0;
        int e = s+len;
        
        int sum = 0;
        for(int i = s; i <= e; i++) sum += elements[i];
        set.insert(sum);
        
        for(int i = 0; i < n; i++) {
            sum -= elements[s];
            sum += elements[(e+1)%n];
            s++;
            e = (e+1)%n;
            set.insert(sum);
        }
        len++; 
    }
    
    answer = set.size();
    return answer;
}