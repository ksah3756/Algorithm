#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

// gcd가 아닐 수도 있
// 결국엔 모든 수를 다 나눌 수 있어야 하니까
// 두 배열에 대해 전체 gcd를 구하고 이의 약수들이 후보 수
// 근데 gcd가 다른 배열에서 나누어 떨어지는 수가 있으면 이의 약수들도 당연히 나누어 떨어지지
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int tmpA;
    if(arrayA.size() == 1) tmpA = arrayA[0];
    else {
         tmpA = gcd(arrayA[0], arrayA[1]);
        for(int i = 2; i < arrayA.size(); i++) {
            tmpA = gcd(tmpA, arrayA[i]);
        }
    }
   
    int tmpB;
    if(arrayB.size() == 1) tmpB = arrayB[0];
    else {
        tmpB = gcd(arrayB[0], arrayB[1]);
        for(int i = 2; i < arrayB.size(); i++) {
            tmpB = gcd(tmpB, arrayB[i]);
        }
    }
    
    bool isAPossible = 1, isBPossible = 1;
    
    for(int b : arrayB) {
        if(b % tmpA == 0) {
            isAPossible = 0;
            break;
        } 
    }
    
    for(int a : arrayA) {
        if(a % tmpB == 0) {
            isBPossible = 0;
            break;
        }
    }
    
    if(!isAPossible && !isBPossible) return 0;
    else if(isAPossible && !isBPossible) return tmpA;
    else if(!isAPossible && isBPossible) return tmpB;
    else return max(tmpA, tmpB);
}



