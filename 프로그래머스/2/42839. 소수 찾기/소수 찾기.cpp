#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num){
    if(num<2) return false;
    for(int i=2;i<=sqrt(num);++i)
        if(num%i==0) return false;
    return true;
}
int solution(string numbers) {
    set<int> num;
    sort(numbers.begin(),numbers.end());
    do{
        string tmp;
        for(int i=0;i<numbers.size();++i){
            tmp+=numbers[i];
            if(isPrime(stoi(tmp)))
                num.insert(stoi(tmp));
        }
    } while(next_permutation(numbers.begin(),numbers.end()));
    int answer = num.size();
    return answer;
}