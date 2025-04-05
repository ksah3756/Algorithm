#include <string>
#include <vector>

using namespace std;

// 상하좌우 네개의 벽에 대해 

// 공이 먼저 맞는걸 판별하려면 ccw로 일직선인지 판별하는거 말고 다른 방법이 있나?
// 그냥 x나 y가 일치하지만 않는다면 그럴일은 없겠구나
int sX, sY;
int calculateDist(int x, int y) {
    return (sX-x)*(sX-x) + (sY-y)*(sY-y);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    sX = startX;
    sY = startY;
    for(const vector<int>& v : balls) {
        int destX = v[0];
        int destY = v[1];
        int val = 2e+6+1;
        // 왼벽: -x, y
        // 오벽: 2m-x, y
        // 아래벽: x, 2n-y
        // 위벽: x, -y
        if(!(startY == destY && destX < startX)) val = min(val, calculateDist(-destX, destY)); 
        if(!(startX == destX && startY < destY)) val = min(val, calculateDist(destX, 2*n-destY));
        if(!(startY == destY && startX < destX)) val = min(val, calculateDist(2*m-destX, destY));
        if(!(startX == destX && destY < startY)) val = min(val, calculateDist(destX, -destY));
        answer.push_back(val);
    }
    
    return answer;
}