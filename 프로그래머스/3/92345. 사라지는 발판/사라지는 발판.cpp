#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> pii;
typedef pair<int,bool> pib;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int n, m;
int ans = 0;
int aWinCnt, bWinCnt;
vector<vector<int>> bboard;

// 매 단계 게임이 종료할때까지 판단하고 내가 이길 수 있는 수가 있으면 그 수 중 가장 게임 횟수가 작은걸 반환, 내가 이길 수 없으면 가장 게임 횟수가 긴 걸 반환

vector<pii> getNextCoord(const pii& p) {
    int y = p.first;
    int x = p.second;
    vector<pii> candidates;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(0 <= ny && ny < n && 0 <= nx && nx < m) {
            if(bboard[ny][nx] == 1) {
                candidates.push_back({ny,nx});
            }
        }
    }
    return candidates;
}

// A 이기면 0, B 이기면 1 리턴
pib solve(pii aloc, pii bloc, int cnt, int turn) {
    pib res;
    int winCnt = 26, loseCnt = -1;
    if(turn == 0) { // A 차례
        if(bboard[aloc.first][aloc.second] == 0) { // A 패배
            return {cnt, 1};
        }
        vector<pii> nexts = getNextCoord(aloc);
        bool isAWinnable = 0;
        if(!nexts.empty()) {
            for(pii p : nexts) {
                bboard[aloc.first][aloc.second] = 0;
                res = solve(p, bloc, cnt+1, 1-turn);
                if(res.second == 0) { // A 승리
                    isAWinnable = 1;
                    winCnt = min(winCnt, res.first);
                } else {
                    loseCnt = max(loseCnt, res.first);    
                }
                
                bboard[aloc.first][aloc.second] = 1;
            }
            if(isAWinnable) return {winCnt, 0};
            else return {loseCnt, 1}; 
        } else {
            return {cnt, 1};
        }
    } else { // B 차례
        if(bboard[bloc.first][bloc.second] == 0) {
            return {cnt, 0};
        }
        vector<pii> nexts = getNextCoord(bloc);
        bool isBWinnable = 0;
        if(!nexts.empty()) {
            for(pii p : nexts) {
                int y = p.first;
                int x = p.second;
                bboard[bloc.first][bloc.second] = 0;
                res = solve(aloc, p, cnt+1, 1-turn);
                if(res.second == 1) {
                    isBWinnable = 1;
                    winCnt = min(winCnt, res.first);
                } else {
                    loseCnt = max(loseCnt, res.first);
                }
                bboard[bloc.first][bloc.second] = 1;
            }
            if(isBWinnable) return {winCnt, 1};
            else return {loseCnt, 0};
        } else {
            return {cnt, 0};
        }
    }
}


int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    n = board.size();
    m = board[0].size();
    bboard = board;
    
    pib res = solve({aloc[0], aloc[1]}, {bloc[0], bloc[1]}, 0, 0);
    answer = res.first;
    return answer;
}