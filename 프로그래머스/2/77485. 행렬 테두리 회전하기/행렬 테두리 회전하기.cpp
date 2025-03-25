#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;
int arr[101][101];

// 10:00
// 아니면 덱에 원소들 다 넣고 마지막 원소 빼서 앞으로 넣으면 순회긴 한데
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            arr[i][j] = (i-1) * columns + j;
        }
    }
    
    int minVal;
    deque<int> dq;
    
    for(const vector<int> &q : queries) {
        minVal = 101 * 101;
        int minY = q[0], minX = q[1], maxY = q[2], maxX = q[3];
        int x = minX, y = minY;
        while(x <= maxX) dq.push_back(arr[y][x++]);
        x--; y++;
        while(y <= maxY) dq.push_back(arr[y++][x]);
        y--; x--;
        while(x >= minX) dq.push_back(arr[y][x--]);
        x++; y--;
        while(y > minY) dq.push_back(arr[y--][x]);
        
        // for(auto iter = dq.begin(); iter != dq.end(); iter++) {
        //     cout << *iter << ' ';
        // }
        // cout << '\n';
        
        int back = dq.back();
        dq.pop_back();
        dq.push_front(back);
        
        while(x <= maxX) {
            int t = dq.front(); dq.pop_front();
            arr[y][x++] = t;
            minVal = min(minVal, t);
        }
        x--; y++;
        while(y <= maxY) {
            int t = dq.front(); dq.pop_front();
            arr[y++][x] = t;
            minVal = min(minVal, t);
        }
        y--; x--;
        while(x >= minX) {
            int t = dq.front(); dq.pop_front();
            arr[y][x--] = t;
            minVal = min(minVal, t);
        }
        x++; y--;
        while(y > minY) {
            int t = dq.front(); dq.pop_front();
            arr[y--][x] = t;
            minVal = min(minVal, t);
        }
        y++;
        
        // for(int i = 1; i <= rows; i++) {
        //     for(int j = 1; j <= columns; j++) {
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        
        answer.push_back(minVal);
    }
    
    return answer;
}