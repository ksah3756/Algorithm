#include <string>
#include <vector>

using namespace std;
// 12:05
// 일단 문자열 시간 전부 초로 바꾸기
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int videoH = stoi(video_len.substr(0,2));
    int videoM = stoi(video_len.substr(3,2));
    int videoLen = videoH * 60 + videoM;
    
    int curH = stoi(pos.substr(0,2));
    int curM = stoi(pos.substr(3,2));
    int cur = curH * 60 + curM;
    
    int opStartH = stoi(op_start.substr(0,2));
    int opStartM = stoi(op_start.substr(3,2));
    int opStart = opStartH * 60 + opStartM;
    
    int opEndH = stoi(op_end.substr(0,2));
    int opEndM = stoi(op_end.substr(3,2));
    int opEnd = opEndH * 60 + opEndM;
    
    for(string& s : commands) {
        if(opStart <= cur && cur <= opEnd) cur = opEnd;
        if(s.compare("next") == 0) {
            cur += 10;
            if(cur > videoLen) cur = videoLen;
        } else {
            cur -= 10;
            if(cur < 0) cur = 0;
        }
    }
    
    if(opStart <= cur && cur <= opEnd) cur = opEnd;
    
    curH = cur / 60;
    curM = cur % 60;
    
    string hour = to_string(curH);
    string minute = to_string(curM);
    
    if(curH < 10) answer += ("0"+hour);
    else answer += hour;
    
    answer += ":";
    
    if(curM < 10) answer += ("0"+minute);
    else answer += minute;
    
    return answer;
}