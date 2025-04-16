#include <bits/stdc++.h>

using namespace std;
// 1:54
// 일단 timetable 분으로 바꾸고 오름차순 정렬
// startTime = 09:00 보다 작거나 같은 time 중에서 최대 m개 pop 하고 n--, startTime += t
// n == 1일때 타야하므로 앞에서부터 m번째 time-1, 만약 startTime 보다 작거나 같은 수가 m개 미만이면 그냥 startTime
string intToString(int time) {
    int h = time / 60;
    int m = time % 60;
    
    string hString, mString;
    
    hString = to_string(h);
    if(hString.size() == 1) hString = "0" + hString;
    
    mString = to_string(m);
    if(mString.size() == 1) mString = "0" + mString;
    
    return hString + ":" + mString;
}

int stringToInt(string s) {
    string h = s.substr(0,2);
    string m = s.substr(3,2);
    
    return stoi(h) * 60 + stoi(m);
}

string solution(int n, int t, int m, vector<string> timetable) {
    int startTime = 540;
    int size = timetable.size();
    
    sort(timetable.begin(), timetable.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(const string& s : timetable) {
        int min = stringToInt(s);
        pq.push(min);
    }
    
    while(!pq.empty() && n > 1) {
        int cnt = 0;
        while(!pq.empty() && pq.top() <= startTime) {
            cnt++;
            pq.pop();
            if(cnt == m) break;
        }
        n--;
        startTime += t;
    }
    
    int cnt = 0;
    int lastTime;
    while(!pq.empty() && pq.top() <= startTime) {
        cnt++;
        lastTime = pq.top(); pq.pop();
        if(cnt == m) break;
    }
    if(cnt < m) return intToString(startTime);
    return intToString(lastTime-1);
}

