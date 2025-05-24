#include <string>
#include <vector>

using namespace std;

// i,j / j,k
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int n = arr1.size();
    int m = arr1[0].size();
    int l = arr2[0].size();
    vector<vector<int>> answer(n, vector<int>(l));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < l; j++) {
            int tmp = 0;
            for(int k = 0; k < m; k++) {
                tmp += arr1[i][k] * arr2[k][j];
            } 
            answer[i][j] = tmp;
        }
        
    }
    
    return answer;
}