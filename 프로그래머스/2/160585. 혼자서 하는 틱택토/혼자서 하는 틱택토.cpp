#include <string>
#include <vector>

using namespace std;
// 9:50
// O를 먼저 놓으니까 O개수가 무조건 X보다 크거나같음
// 게임 종료 조건(가로,세로,대각선 채움)에서 끝나지 않은 경우 X
// 1. O 개수가 항상 X 개수와 같거나 1 커야 함
// 2. 종료 패턴이 있는 데 그 이후 놓은 흔적이 있는지
// O가 승리면 X 개수는 O 개수 -1, X 승리면 O, X 개수 같고 O는 승리 패턴 X
int solution(vector<string> board) {
    int answer = -1;
    
    int oCnt = 0, xCnt = 0;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == 'O') oCnt++;
            else if(board[i][j] == 'X') xCnt++;
        }
    }
    
    if(!(oCnt == xCnt || oCnt == xCnt+1)) return 0;
    
    auto checkIfWin = [&](char role) -> bool {
        // 가로 3
        for(int i = 0; i < 3; i++) {
            if(board[i][0] == role &&
               board[i][1] == role &&
               board[i][2] == role)
                return true;
        }
        // 세로 3
        for(int i = 0; i < 3; i++) {
            if(board[0][i] == role &&
               board[1][i] == role &&
               board[2][i] == role)
                return true;
        }
        // 대각선 3
        if(board[0][0] == role &&
           board[1][1] == role &&
           board[2][2] == role)
            return true;
        if(board[0][2] == role &&
           board[1][1] == role &&
           board[2][0] == role)
            return true;
        return false;
    };
    
    bool oWin = checkIfWin('O');
    bool xWin = checkIfWin('X');
    
    if(oWin && xWin) return 0;
    else if(oWin && !xWin) {
        if(oCnt == xCnt+1) return 1;
        return 0;
    }
    else if(!oWin && xWin) {
        if(oCnt == xCnt) return 1;
        return 0;
    } else { // 개수 문제없고 둘 다 이긴 상태는 아닌데 나올 수 없는 경우가 있나?
        return 1;
    }
}