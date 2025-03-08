#include <string>
#include <vector>
#include <iostream>

using namespace std;
int userSize, emSize;
int ansCount, ansMoney;
int discountRate[4] = {10,20,30,40};
vector<int> emDiscount;
void solve(const vector<vector<int>>& users, const vector<int>& emoticons, int idx);


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    emSize = emoticons.size();
    userSize = users.size();
    emDiscount.resize(emSize);
    solve(users, emoticons, 0);

    answer.push_back(ansCount);
    answer.push_back(ansMoney);

    return answer;
}

void solve(const vector<vector<int>>& users, const vector<int>& emoticons, int idx) {
    if(idx == emSize) {
        int curCount = 0, curMoney = 0;
        for(int i = 0; i < userSize; i++) {
            int disThreshold = users[i][0];
            int moneyThreshold = users[i][1];
            int money = 0;
            for(int j = 0; j < emSize; j++) {
                if(emDiscount[j] >= disThreshold) {
                    money += (100-emDiscount[j]) * emoticons[j] / 100;
                }
            }
            // cout << money << '\n';
            if(money >= moneyThreshold) curCount++;
            else curMoney += money;    
        }
        // cout << curCount << ' ' << curMoney << '\n';
        if(ansCount < curCount) {
            ansCount = curCount;
            ansMoney = curMoney;
        } else if(ansCount == curCount) {
            if(ansMoney < curMoney) ansMoney = curMoney;
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        emDiscount[idx] = discountRate[i];
        solve(users, emoticons, idx+1);
    }
}

