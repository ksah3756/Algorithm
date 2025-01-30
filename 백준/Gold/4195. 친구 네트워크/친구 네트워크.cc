#include <bits/stdc++.h>

using namespace std;
int t, n;
int parent[200001], sze[200001];
int find(int);
void unionSet(int,int);
unordered_map<string, int> hashMap;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    string s1, s2;
    while(t--) {
        cin >> n;
        int idx = 1;
        for(int i = 0; i < n; i++) {
            cin >> s1 >> s2;
            if(hashMap.find(s1) == hashMap.end()) {
                parent[idx] = idx;
                sze[idx] = 1;
                hashMap[s1] = idx++;
            }
            if(hashMap.find(s2) == hashMap.end()) {
                parent[idx] = idx;
                sze[idx] = 1;
                hashMap[s2] = idx++;
            }
            // cout << hashMap[s1] << ' '  << hashMap[s2] << '\n';
            unionSet(hashMap[s1], hashMap[s2]);
            cout << sze[parent[hashMap[s1]]] << '\n';
        }
        hashMap.clear();
    }
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
    if(sze[pa] < sze[pb]) swap(pa, pb);
    parent[pb] = pa;
    int size = sze[pa] + sze[pb];
    sze[pa] = sze[pb] = size;
}