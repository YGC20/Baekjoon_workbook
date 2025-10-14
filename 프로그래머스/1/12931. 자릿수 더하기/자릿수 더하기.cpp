#include <iostream>
#include <cmath>
using namespace std;
int solution(int n){
    int digitLength = (int)log10(n)+1;
    int sum = 0;
    for(int i = digitLength;i>=0;--i){
        sum += n/pow(10,i);
        n %= (int)pow(10,i);
    }
    cout << sum << endl;
    return sum;
}