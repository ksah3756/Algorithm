#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<char, int> um;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int todayYear = stoi(today.substr(0,4));
    int todayMonth = stoi(today.substr(5,2));
    int todayDay = stoi(today.substr(8,2));
    int todayDate = todayYear * 10000 + todayMonth * 100 + todayDay;

    for(string s: terms) {
        um.insert({s[0], stoi(s.substr(2))});
    }

    vector<int> answer;
    int i = 1;
    for(string s : privacies) {
        int tmp = um[s[11]];
        int year = stoi(s.substr(0,4));
        int month = stoi(s.substr(5,2));
        int day = stoi(s.substr(8,2));

        int newMonth = month + tmp;
        int yearPlus = newMonth / 12;
        month = newMonth % 12;
        year += yearPlus;
        if(month == 0) {
            month = 12;
            year--;
        }
        int newDate = year * 10000 + month * 100 + day;
        cout << newDate << ' ' << todayDate << '\n';
        if(newDate <= todayDate) answer.push_back(i);
        i++;
    }
    
    return answer;
}