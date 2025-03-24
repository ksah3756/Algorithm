#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 원래는 6, 7일 주말인데 startday를 
// schedules에 다 +10
// timelogs 순회하면서 평일 한번이라도 지각하면 cnt X
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int &s : schedules) {
        int hour = s / 100;
        int min = s % 100 + 10;
        if(min >= 60) {
            min %= 60;
            hour++;
        }
        s = hour * 100 + min;
    }
    
    int sat = (13 - startday) % 7;
    int sun = (14 - startday) % 7;
    
    for(int i = 0; i < schedules.size(); i++) {
        bool flag = 1;
        for(int j = 0; j < 7; j++) {
            
            if(j == sat || j == sun) continue;
            if(timelogs[i][j] > schedules[i]) {
                flag = 0;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}