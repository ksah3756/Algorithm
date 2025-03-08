#include <bits/stdc++.h>

using namespace std;
int parent[201];
int sze[201];
int n, m;
int find(int);
void unionSet(int, int);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int x;
    for(int i = 1; i <= n; i++) parent[i] = i;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> x;
            if(x) unionSet(i,j);
        }
    }

    cin >> x;
    int p = find(x);
    bool isPossible = 1;
    for(int i = 1; i < m; i++) {
        cin >> x;
        if(find(x) != p) {
            isPossible = 0;
            break;
        }
    }
    isPossible? cout << "YES" << '\n' : cout << "NO" << '\n';
    return 0;
}

int find(int n) {
    if(n == parent[n]) return n;
    return parent[n] = find(parent[n]);
}

void unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if(pa == pb) return;

    if(sze[pa] < sze[pb]) swap(pa,pb);
    int size = sze[pa] + sze[pb];
    parent[pb] = pa;
    sze[pa] = sze[pb] = size;
}