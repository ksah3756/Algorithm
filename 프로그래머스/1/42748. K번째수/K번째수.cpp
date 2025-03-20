#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> cmd: commands) {
        vector<int> v;
        int s = cmd[0]-1, e = cmd[1]-1;
        for(int i = s; i <= e; i++) {
            v.push_back(array[i]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[cmd[2]-1]);
    }
    return answer;
}