#include <bits/stdc++.h>

using namespace std;
int n;
typedef struct Node {
    map<string, Node> child;
    Node() : child() {}
    Node(const map<string,Node>& child) : child(child) {};
} Node;

Node head = Node();
const string PREFIX = "--";
void drawTrie(int, const Node&);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int x;
    string s;
    vector<vector<string>> v = vector(n, vector<string>());
    for(int i = 0; i < n; i++) {
        cin >> x;
        for(int j = 0; j < x; j++) {
            cin >> s;
            v[i].push_back(s);
        }
        Node* cur = &head;
        for(int j = 0; j < x; j++) {
            string ss = v[i][j];
            if(cur->child.find(ss) == cur->child.end()) {
                cur->child.insert({ss, Node()});
            }
            cur = &cur->child[ss];
        }
        
    }
    drawTrie(0, head);

    return 0;
}

void drawTrie(int depth, const Node& node) {
    
    string curPrefix = "";
    for(int i = 0; i < depth; i++) curPrefix += PREFIX;

    for(auto a: node.child) {
        cout << curPrefix << a.first << '\n';
        drawTrie(depth+1, a.second);
    }
}