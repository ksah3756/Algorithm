#include <bits/stdc++.h>

using namespace std;
queue<int> bridge;
queue<int> trucks;
int bridge_weight, truck_cnt;
int b_length, total_weight;

void onboard_truck() {
    if(trucks.empty()) return;
    int weight = trucks.front();
    if(truck_cnt + 1 <= b_length && bridge_weight + weight <= total_weight) { // 트럭이 다리에 올라갈 수 있는 경우
        // 뒤에 트럭 넣기
        bridge.push(weight);
        // 다리 정보 최신화
        bridge_weight += weight;
        truck_cnt++;
        // 트럭 리스트에서 제거
        trucks.pop();
    } else {
        bridge.push(0);
    }
}

void leave_bridge() {
    int weight = bridge.front(); bridge.pop();
    if(weight == 0) return;
    
    bridge_weight -= weight;
    truck_cnt--;
    return;
}

// 다리에 진입할 수 있으면 그 시점부터 + 다리 길이 시간 후 다리를 지남 
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    b_length = bridge_length;
    total_weight = weight;
    
    for(int i = 0; i < bridge_length; i++) bridge.push(0);
    
    for(int t : truck_weights) trucks.push(t);
    
    int time = 0;
    while(!(truck_cnt == 0 && trucks.empty())) {
        time++;
    
        leave_bridge();
        onboard_truck();
    }
    
    answer = time;
    return answer;
}

