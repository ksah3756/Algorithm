#include <bits/stdc++.h>

using namespace std;
// 4:38
// 트라이에 리프 노드까지 도달하는 문자 수를 합하기?
typedef struct Node {
    char val;
    unordered_map<char, Node*> child;
    bool isUnique;
    
    Node(char val, bool isUnique) : val(val), isUnique(isUnique) {}
} Node;

Node* root;

int solution(vector<string> words) {
    int answer = 0;
    
    root = new Node('0', 0);
    
    for(string& word : words) {
        int i = 0;
        Node* cur = root;
        while(i < word.size()) {
            if(cur->child.find(word[i]) == cur->child.end()) {
                cur->child.insert({word[i], new Node(word[i], 1)});
            } else {
                cur->child[word[i]]->isUnique = 0;
            }
            cur = cur->child[word[i]];
            i++;
        }
    }
    
    for(string& word : words) {
        Node* cur = root;
        int i = 0;
        while(i < word.size()) {
            // cout << word[i] << ' ' << cur->isUnique << ' ';
            if(cur->isUnique) {
                break;
            }
            cur = cur->child[word[i++]];
        }
        answer += i;
        cout << '\n';
    }
    

    return answer;
}