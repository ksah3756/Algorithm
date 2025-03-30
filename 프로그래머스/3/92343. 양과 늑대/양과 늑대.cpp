#include <bits/stdc++.h>

using namespace std;

// 이게 그래프가 아니라 이진 트리라는 점에 주목해야 할 거 같은데
// 방문 처리를 양의 개수, 방문 노드 비트마스크로?
// 완전 탐색을 했을 때의 시간 복잡도는?
int sze;
vector<vector<int>> tree(17, vector<int>());
int ans;

// 앞으로 갈 수 있는 노드들의 후보 리스트를 비트마스크로 관리
// 실제로 이동하면 후보에서 빼고, 자식 노드들을 후보 리스트에 추가
void dfs(const vector<int>& info, int cur, int lambCnt, int wolfCnt, bitset<17> candidates) {
    ans = max(ans, lambCnt);
    
    
    for(int nxt : tree[cur]) {
        candidates[nxt] = 1;
    }
    
    // 근데 이게 방문 순서가 어떻게 되느냐에 따라 방문이 가능할 수 있고 안될 수도 있는데
    // 예를 들어 불필요하게 늑대를 방문해서 가능한 경우가 막히는 경우
    // 그래서 후보 노드와 양의 수, 늑대 수를 함께 저장 필요
    for(int i = 0; i < sze; i++) {
        if(candidates[i] == 0) continue;
        
        if(info[i] == 0) {
            bitset<17> newCandidates = candidates;
            newCandidates[i] = 0;
            dfs(info, i, lambCnt+1, wolfCnt, newCandidates);
        } else {
            if(lambCnt > wolfCnt+1) {
                bitset<17> newCandidates = candidates;
                newCandidates[i] = 0;
                dfs(info, i, lambCnt, wolfCnt+1, newCandidates);
            }
        }
    }
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    sze = info.size();
    for(const vector<int>& e : edges) {
        int parent = e[0], child = e[1];
        tree[parent].push_back(child);
    }
    dfs(info, 0, 1, 0, bitset<17>(0));
    answer = ans;
    return answer;
}

