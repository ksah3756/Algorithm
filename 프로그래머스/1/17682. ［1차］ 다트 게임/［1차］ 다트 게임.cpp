#include <string>

using namespace std;
// 4:50
int solution(string dartResult) {
    int answer = 0;
    
    int idx = 0;
    int size = dartResult.size();
    int prevScore = 0;
    
    while(idx < size) {
        int score = stoi(&dartResult[idx++]);
        if(dartResult[idx] == '0') idx++;
        char bonus = dartResult[idx++];
        
        if(bonus == 'D') score = (score*score);
        else if(bonus == 'T') score = (score*score*score);
        
        char op = ' ';
        if(idx < size && 
           (dartResult[idx] == '*' || dartResult[idx] == '#')) {
            op = dartResult[idx++];
        }
        
        if(op == '*') {
            score *= 2;
            answer += prevScore;
        } else if(op == '#') {
            score = -score;
        }
        answer += score;
        prevScore = score;   
    }
    return answer;
}