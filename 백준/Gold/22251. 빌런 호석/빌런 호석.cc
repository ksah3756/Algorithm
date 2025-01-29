#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<bitset<7>> digits(10);
vector<bitset<7>> num;
int n, k, p, x;
void changeNumberToBits(vector<bitset<7>>& tmp, int i);
ll solve();
int calculateDiffBits(vector<bitset<7>>& v1, vector<bitset<7>>& v2);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    digits[0] = bitset<7>("1111110");
    digits[1] = bitset<7>("0000110");
    digits[2] = bitset<7>("1011011");
    digits[3] = bitset<7>("1001111");
    digits[4] = bitset<7>("0100111");
    digits[5] = bitset<7>("1101101");
    digits[6] = bitset<7>("1111101");
    digits[7] = bitset<7>("1000110");
    digits[8] = bitset<7>("1111111");
    digits[9] = bitset<7>("1101111");

    cin >> n >> k >> p >> x;
    changeNumberToBits(num, x);
    cout << solve() << '\n';
    return 0;
}

void changeNumberToBits(vector<bitset<7>>& tmp, int i) {
    int cnt = 0;
    while(i) {
        tmp.push_back(digits[i%10]);
        i /= 10;
        cnt++;
    }
    for(int i = 0; i < k-cnt; i++) tmp.push_back(digits[0]);
    reverse(tmp.begin(), tmp.end());
}

ll solve() {
    vector<bitset<7>> v;
    ll cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(i == x) continue;
        changeNumberToBits(v, i);
        int diffBits = calculateDiffBits(num, v);
        if(diffBits <= p) cnt++;
        v.clear();
    }
    return cnt;
}

int calculateDiffBits(vector<bitset<7>>& v1, vector<bitset<7>>& v2) {
    int cnt = 0;
    for(int i = 0; i < k; i++) {
        bitset<7> b1 = v1[i], b2 = v2[i]; 
        for(int j = 0; j < 7; j++) {
            if(b1[j] != b2[j]) cnt++;
        } 
    }
    return cnt;
}