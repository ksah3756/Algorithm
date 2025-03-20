#include <string>
#include <vector>

using namespace std;

typedef struct Node {
    vector<Node*> child;
    bool isEnd;
    Node() : child(10, nullptr), isEnd(false) {};
} Node;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    Node *root = new Node();
    
    for(string pn : phone_book) {
        if(!answer) break;
        Node *cur = root;
        for(int i = 0; i < pn.size(); i++) {
            int j = pn[i] - '0';
            
            if(cur->child[j] == nullptr) {
                cur->child[j] = new Node();
            } else {
                if(cur->child[j]->isEnd || i == pn.size()-1) {
                    answer = false;
                    break;
                }
            }
            cur = cur->child[j];
            if(i == pn.size()-1) cur->isEnd = true;
        }
    }
    
    return answer;
}