#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int n, m, k;
//벽을 부순적이 없는 경우는 visited의 첫번째 index를 0, 벽을 이미 한번 부순 경우는 1
bool visited[11][1000][1000] = {false,};
int map[1000][1000];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0}, k });
	bool is_end = false;
	int cnt = 0;
	int r, c;
	int breakable_cnt;
	while (!(is_end || q.empty())) {
		cnt += 1;
		int loop_size = q.size();
		for (int _ = 0; _ < loop_size; _++) {
			if (is_end) break;
			r = q.front().first.first;
			c = q.front().first.second;
			breakable_cnt = q.front().second; q.pop();
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr == n - 1 && nc == m - 1) {
					is_end = true;
					break;
				}
				if (!((0 <= nr && nr < n) && (0 <= nc && nc < m))) continue;
				//갈려는 곳이 벽이면, 낮밤 확인
				if (map[nr][nc] == 1) {
					if (breakable_cnt != 0 && !visited[breakable_cnt-1][nr][nc]) {
						//낮이므로 부수고 이동
						if (cnt % 2 == 1) {
							int temp_breakable = breakable_cnt - 1;
							q.push({ {nr, nc}, temp_breakable });
							for (int i = 0; i <= temp_breakable; i++) {
								visited[i][nr][nc] = true;
							}
						}
						//밤이므로 제자리에서 아침 기다리기
						else q.push({ { r, c }, breakable_cnt });
					}
				}
				else {
					if (!visited[breakable_cnt][nr][nc]) {
						q.push({ {nr, nc}, breakable_cnt });
						for (int i = 0; i <= breakable_cnt; i++) {
							visited[i][nr][nc] = true;
						}
					}
				}
			}
		}
	}
	if (is_end) cout << cnt + 1;
	else cout << -1;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i <= k; i++) visited[i][0][0] = true;
	if (n == 1 && m == 1) cout << 1;
	else bfs();
	return 0;
}