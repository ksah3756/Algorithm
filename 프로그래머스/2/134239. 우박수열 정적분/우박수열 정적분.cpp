#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 1:45
vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> h;
    
    while(1) {
        h.push_back(k);
        if(k == 1) break;
        
        if(k % 2 == 0) k /= 2;
        else k = k*3 + 1;
    }
    
    
    // 구간 합처럼 넓이 합을 구해놓는게..
    vector<double> sum(h.size()-1);
    
    double prev = 0;
    for(int i = 0; i < h.size()-1; i++) {
        double tmp = (h[i]+h[i+1]) / 2;
        sum[i] = prev + tmp;
        prev = sum[i];
    }
    
    int n = h.size()-1;
    for(const vector<int>& v : ranges) {
        int s = v[0], e = n + v[1];
        double d;
        if(s > e) d = -1;
        else if(s == 0) d = sum[e-1]; 
        else d = sum[e-1] - sum[s-1];
        answer.push_back(d);
    }
    return answer;
}