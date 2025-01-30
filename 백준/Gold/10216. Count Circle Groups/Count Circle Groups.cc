#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int t, n;
vector<pii> coord(3001);
int radius[3001];
int parent[3001], sze[3001];
int calculateDist(int,int);
int find(int);
void unionSet(int,int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    int x, y, r;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) parent[i] = i;
        memset(sze, 0, sizeof(sze));

        for(int i = 0; i < n; i++) {
            cin >> x >> y >> r;
            coord[i] = {x,y};
            radius[i] = r;
        }

        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                int dist = pow(radius[i]+radius[j], 2);
                if(calculateDist(i,j) <= dist) 
                    unionSet(i,j);
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(i == parent[i]) cnt++;
        }
        cout << cnt << '\n';
    }

}

int calculateDist(int i, int j) {
    return pow(coord[i].first - coord[j].first,2) + pow(coord[i].second - coord[j].second, 2);
}

int find(int n) {
    if(n == parent[n]) return n;
    return parent[n] = find(parent[n]);
}

void unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if(pa == pb) return;
    if(sze[pa] < sze[pb]) swap(pa, pb);

    parent[pb] = pa;
    int size = sze[pa] + sze[pb];
    sze[pa] = size;
    sze[pb] = size;
}