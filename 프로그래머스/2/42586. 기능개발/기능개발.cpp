#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    
    for(int i = 0; i < progresses.size(); i++) {
        int left = 100 - progresses[i];
        int tmp = left / speeds[i];
        if(left % speeds[i]) tmp++;
        days.push_back(tmp);
    }
    
    int cnt = 1, maxVal = days[0];
    for(int i = 1; i < days.size(); i++) {
        if(maxVal >= days[i]) {
            cnt++;
        } else {
            answer.push_back(cnt);
            cnt = 1;
            maxVal = days[i];
        }
    }
    answer.push_back(cnt);
    
    return answer;
}