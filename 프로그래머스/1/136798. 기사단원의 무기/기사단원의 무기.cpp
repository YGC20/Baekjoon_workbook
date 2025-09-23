#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i=1;i<=number;++i){
        int ap=1;
        for(int j=1;j<=i/2;++j){
            if(i%j==0)  ap++;
        }
        if(ap>limit)    answer+=power;
        else    answer+=ap;
    }
    return answer;
}