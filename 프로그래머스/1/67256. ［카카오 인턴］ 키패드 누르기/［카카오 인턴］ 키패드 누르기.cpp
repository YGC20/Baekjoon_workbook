#include <string>
#include <vector>
#include <cmath>
using namespace std;

pair<int,int> pos(int num){
    if(num==0) num=11;
    return {(num-1)/3,(num-1)%3};
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right = 12;
    for(int num:numbers){
        if(num==1||num==4||num==7){
            left = num;
            answer+="L";
        }
        else if(num==3||num==6||num==9){
            right = num;
            answer+="R";
        }
        else{
            auto [lx,ly] = pos(left);
            auto [rx,ry] = pos(right);
            auto [nx,ny] = pos(num);
            
            int ld = abs(lx-nx)+abs(ly-ny);
            int rd = abs(rx-nx)+abs(ry-ny);
            
            if(ld<rd){
                left = num;
                answer+="L";
            }
            else if(ld>rd){
                right = num;
                answer+="R";
                
            }
            else{
                if(hand=="right"){
                    right = num;
                    answer+="R";
                }
                else{
                    left = num;
                    answer+="L";
                }
            }
        }
    }
    return answer;
}