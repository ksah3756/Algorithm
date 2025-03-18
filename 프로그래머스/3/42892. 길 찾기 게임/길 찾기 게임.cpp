#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v1, v2;
typedef pair<int,int> pii;
//각 서브 트리 기준으로 루트만 구하면 이 루트보다 작은 x 값은 왼쪽 서브트리, 루트보다 큰 x 값은 오른쪽 서브트리
int findRoot(const vector<vector<int>>& v, int s, int e);
void solve1(const vector<vector<int>>& v, int s, int e);
void solve2(const vector<vector<int>>& v, int s, int e);

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    int i = 1;
    int size = 0;
    
    for(vector<int>& v : nodeinfo) {
        v.push_back(i++);
        size++;
    }
    
    auto cmp = [](const vector<int>& v1, const vector<int>& v2) -> bool {
        return v1[0] < v2[0];
    };
    
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    
    solve1(nodeinfo, 0, size-1);
    answer.push_back(v1);
    solve2(nodeinfo, 0, size-1);
    answer.push_back(v2);
    
    return answer;
}

int findRoot(const vector<vector<int>>& v, int s, int e) {
    int maxVal = v[s][1], ret = s;
    for(int i = s; i <= e; i++) {
        if(v[i][1] > maxVal) {
            ret = i;
            maxVal = v[i][1];
        }
    }
    return ret;
}

void solve1(const vector<vector<int>>& v, int s, int e) {
    if(s == e) {
        v1.push_back(v[s][2]);
        return;
    }
    int root = findRoot(v, s, e);
    v1.push_back(v[root][2]);
    if(root-1 >= s) solve1(v, s, root-1);
    if(root+1 <= e) solve1(v, root+1, e);
}

void solve2(const vector<vector<int>>& v, int s, int e) {
    if(s == e) {
        v2.push_back(v[s][2]);
        return;
    }
    int root = findRoot(v, s, e);
    if(root-1 >= s) solve2(v, s, root-1);
    if(root+1 <= e) solve2(v, root+1, e);
    v2.push_back(v[root][2]);
}