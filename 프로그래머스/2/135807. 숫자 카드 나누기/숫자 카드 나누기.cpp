#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    int temp;
    while(b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int i;
    int gcdA = arrayA[0], gcdB = arrayB[0];
    for(i=1; i<arrayA.size(); ++i) {
        gcdA = gcd(gcdA, arrayA[i]);
        gcdB = gcd(gcdB, arrayB[i]);
    }
    
    bool checkA = true, checkB = true;
    for(i=0; i<arrayA.size(); ++i) {
        if(arrayA[i] % gcdB == 0) { checkA = false; break; }
    }
    for(i=0; i<arrayB.size(); ++i) {
        if(arrayB[i] % gcdA == 0) { checkB = false; break; }
    }
    
    if(checkA || checkB) { return (gcdA > gcdB)?gcdA:gcdB; }
    else { return 0; }
}