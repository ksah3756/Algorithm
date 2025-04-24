#include <string>
#include <vector>

using namespace std;
// 5:20
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++) {
        int x = arr1[i] | arr2[i];
        string s = "";
        for(int j = 0; j < n; j++) {
            if(x & (1 << (n-1-j))) s += '#';
            else s += ' ';
        }
        answer.push_back(s);
    }
    
    return answer;
}