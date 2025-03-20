#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int n : numbers) v.push_back(to_string(n));
    
    auto cmp = [](const string& s1, const string& s2) -> bool {
        return s1 + s2 > s2 + s1;
    };
    
    sort(v.begin(), v.end(), cmp);
    for(string s : v) answer.append(s);
    if(answer[0] == '0') answer = "0";
    return answer;
}