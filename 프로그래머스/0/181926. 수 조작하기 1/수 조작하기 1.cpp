#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    for(char cmd : control) {
        if(cmd=='w') {
            n++;
        }
        else if(cmd=='s') {
            n--;
        }
        else if(cmd=='d') {
            n+=10;
        }
        else if(cmd=='a') {
            n-=10;
        }
    }
    return n;
}