#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;
    
    
    for(vector<string>& v : clothes) {
        um[v[1]]++;
    }
    
    for(auto m : um) {
        answer *= (m.second+1);
    }    
    answer--;
    return answer;
}