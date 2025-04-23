#include <bits/stdc++.h>

using namespace std;
typedef pair<int,string> pis;

// 11:39
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0) return cities.size() * 5;
    
    auto lower_case = [&](string s) -> string {
        for(int i = 0; i < s.size(); i++) {
            if('A' <= s[i] && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
        }  
        return s;
    };
    
    unordered_map<string, int> map;
    vector<pis> cache;
    
    auto findLRUIdx = [&]() -> int {
        int minIdx = cities.size();
        int ret = -1;
        
        for(int i = 0; i < cache.size(); i++) {
            if(minIdx > cache[i].first) {
                minIdx = cache[i].first;
                ret = i;
            }
        }
    
        return ret;
    };
    
    auto updateCache = [&](string s, int idx) -> void {
        for(pis& p : cache) {
            if(p.second.compare(s) == 0) {
                p.first = idx;
                break;
            }
        }
    };
    
    for(int i = 0; i < cities.size(); i++) {
        string city = lower_case(cities[i]);
        
        if(map.find(city) == map.end()) { // cache miss
            if(cache.size() == cacheSize) { // LRU 캐시 삭제
                int idx = findLRUIdx();
                map.erase(cache[idx].second);
                cache[idx].first = i;
                cache[idx].second = city;
            } else {
                cache.push_back({i,city});
            }
            map[city];
            answer += 5;
        } else { // cache hit
            updateCache(city, i);
            answer += 1;
        }
    }

    return answer;
}