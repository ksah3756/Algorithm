#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;

typedef struct Node {
    int genre_cnt, cnt, num;
    Node(int genre_cnt, int cnt, int num) : genre_cnt(genre_cnt), cnt(cnt), num(num) {};
} Node;

typedef struct Compare {
    bool operator()(const Node& n1, const Node& n2) {
        if(n1.genre_cnt == n2.genre_cnt) {
            if(n1.cnt == n2.cnt) return n1.num > n2.num;
            return n1.cnt < n2.cnt;
        }
        return n1.genre_cnt < n2.genre_cnt;
    }
} Compare;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int size = genres.size();
    
    unordered_map<string, vector<pii>> um;
    priority_queue<Node, vector<Node>, Compare> pq;
    
    for(int i = 0; i < size; i++) {
        um[genres[i]].push_back({plays[i], i});
    }
    
    for(auto m: um) {
        int sum = 0;
        for(auto p : m.second) {
            sum += p.first;
        }

        for(auto p : m.second) {
            pq.push(Node(sum, p.first, p.second));
        }
    }
    unordered_map<int, int> count;
    while(!pq.empty()) {
        Node n = pq.top(); pq.pop();
        if(count[n.genre_cnt]++ < 2) 
            answer.push_back(n.num);  
    }
    
    return answer;
}