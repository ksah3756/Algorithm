#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;

// 11:38
// 개구간에서는 안맞는다는건 정확히 정수에서 걸치는건 동시에 요격 불가능
// 끝나는 순으로 정렬한다면 
// [[1,4],[4,5],[3,7],[4,8],[5,12],[11,13],[10,14]]
// 어짜피 다음 s가 e보다 크거나 같으면 별도의 요격이 필요하고 무조건 다음에 나오는 e 값이 이전 e값보다 크므로 
int solution(vector<vector<int>> targets) {
    int answer = 0;
    vector<pii> points;
    for(const vector<int>& v : targets) {
        points.push_back({v[0],v[1]});
    }
    
    auto compare = [] (const pii& p1, const pii& p2) -> bool {
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second < p2.second;
    };
    
    sort(points.begin(), points.end(), compare);
    vector<bool> isDeleted(points.size(), 0);
    
    int idx = 0;
    while(idx < points.size()) {
        pii cur = points[idx];
        int nxt = idx+1;
        answer++;
        while(nxt < points.size() && cur.second > points[nxt].first) nxt++;
        idx = nxt;
    }
    
    return answer;
}