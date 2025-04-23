#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0) return cities.size() * 5;
    
    list<string> cache;
    unordered_map<string, list<string>::iterator> map;
    
    for(string& city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        if(map.find(city) == map.end()) { // miss
            if(cache.size() == cacheSize) { // LRU policy 적용
                string lru = cache.back(); cache.pop_back();
                map.erase(lru);
            }
            answer += 5;
        } else { // hit
            auto iter = map[city];
            cache.erase(iter);
            answer += 1;
        }
        cache.push_front(city);
        map[city] = cache.begin();
    }
    
    return answer;
}