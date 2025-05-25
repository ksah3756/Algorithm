#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0) return cities.size() * 5;
    
    list<string> cache;
    unordered_map<string, list<string>::iterator> map;
    
    for(string& city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        if(map.find(city) != map.end()) {
            answer++;
            auto iter = map[city];
            cache.erase(iter);
        } else {
            answer += 5;
            if(cache.size() == cacheSize) {
                string s = cache.back(); cache.pop_back();
                map.erase(s);
            }
        }
        cache.push_front(city);
        map.insert({city, cache.begin()});   
    }
    return answer;
}