#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    int deliveryIdx, pickupIdx;
    deliveryIdx = pickupIdx = n-1;
    int deliveryCap, pickupCap, lastIdx = n-1;
    
    while(lastIdx >= 0) {
        while(deliveries[deliveryIdx] == 0) deliveryIdx--;
        while(pickups[pickupIdx] == 0) pickupIdx--;
        lastIdx = max(deliveryIdx, pickupIdx);

        if(lastIdx >= 0) answer += (lastIdx+1) * 2;
        else break;

        deliveryIdx = pickupIdx = lastIdx;
        deliveryCap = pickupCap = cap;
        while(deliveryCap && deliveryIdx >= 0) {
            // cout << "delivery: ";
            // cout << deliveryIdx+1 << ' ' << deliveryCap << '\n';
            if(deliveries[deliveryIdx] > deliveryCap) {
                deliveries[deliveryIdx] -= deliveryCap;
                break;
            } else {
                deliveryCap -= deliveries[deliveryIdx];
                deliveries[deliveryIdx--] = 0;
            }
        }
    
        while(pickupCap && pickupIdx >= 0) {
            // cout << "pickup: ";
            // cout << pickupIdx+1 << ' ' << pickupCap << '\n';
            if(pickups[pickupIdx] > pickupCap) {
                pickups[pickupIdx] -= pickupCap;
                break;
            } else {
                pickupCap -= pickups[pickupIdx];
                pickups[pickupIdx--] = 0;
            }
        }
        // cout << deliveryIdx+1 <<  ' ' << pickupIdx+1 << '\n';
    }
    return answer;
}