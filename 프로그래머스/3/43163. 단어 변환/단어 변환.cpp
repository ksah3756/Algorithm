#include <string>
#include <vector>
#include <queue>

using namespace std;
int dist[52][52];
bool visited[52];

int calculate_dist(const string &s1, const string &s2) {
    int cnt = 0;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i]) cnt++;
    }
    return cnt;
}

// 이거 모든 단어 간 dist 관계를 미리 계산
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    int target_idx = -1;
    vector<string> new_words;
    new_words.push_back(begin);
    
    for(int i = 0; i < words.size(); i++) {
        if(words[i].compare(target) == 0) {
            target_idx = i+1;
        }
        new_words.push_back(words[i]);
    }
    
    if(target_idx == -1) return answer = 0;
    
    for(int i = 0; i < new_words.size(); i++) {
        for(int j = 0; j < new_words.size(); j++) {
            if(i == j) dist[i][j] = 0;
            else {
                dist[i][j] = calculate_dist(new_words[i], new_words[j]);
            }
        }
    }
    
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    int cnt = -1;

    while(!q.empty()) {
        cnt++;
        int loop_size = q.size();
        
        for(int i = 0; i < loop_size; i++) {
            int cur = q.front(); q.pop();
            
            if(cur == target_idx) {
                return answer = cnt;
            }
            
            for(int nxt = 0; nxt < new_words.size(); nxt++) {
                if(dist[cur][nxt] != 1 || visited[nxt]) continue;
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    
    return answer = 0;
}