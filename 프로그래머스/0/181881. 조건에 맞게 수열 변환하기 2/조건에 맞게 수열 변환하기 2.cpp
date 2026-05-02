#include <string>
#include <vector>
using namespace std;

int solution(vector<int> arr)
{
    int cnt = 0;
    vector<int> check = arr;
    while(true) {
        for(auto& a : arr) {
            if(a>=50 && a%2==0)
                a/=2;
            else if(a<50 && a%2!=0)
                a = a*2+1;
        }
        
        cnt++;
        if(check==arr) return cnt-1;
        else check = arr;
    }
}