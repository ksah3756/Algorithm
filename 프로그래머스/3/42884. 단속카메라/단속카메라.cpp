#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    -----
        ------------
     -----  
                   --
*/
// 일단 출발점 기준으로 오름차순 정렬 후 구간 내 겹치는 수가 가장 많은 지점을 선택
// 해당 경로를 감시할 수 있도록 카메라를 설치 할거면 맨 뒤에다 하는게 무조건 낫겠네
int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    auto cmp = [](const vector<int>& v1, const vector<int>& v2) -> bool {
        if(v1[1] == v2[1]) return v1[0] < v2[0];
        return v1[1] < v2[1];
    };
    
    sort(routes.begin(), routes.end(), cmp);
   
    int idx = 0;
    while(idx < routes.size()) {
        const vector<int>& route = routes[idx];
        int p = route[1];
        idx++;
        while(idx < routes.size() && routes[idx][0] <= p && p <= routes[idx][1]) 
            idx++;
        
        answer++;
    }
    
    return answer;
}