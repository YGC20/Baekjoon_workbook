#include <sstream>
#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    int xsum=0, csum=0;
    string token;
    stringstream ss(polynomial);
    while(ss>>token){
        if(token=="+")  continue;
        if(token.back()=='x'){
            if(token.size()==1) xsum+=1;
            else xsum+=stoi(token.substr(0,token.size()-1));
        }
        else{
            csum+=stoi(token);
        }
    }
    string answer = "";
    if(xsum==0&&csum==0)    return 0;
    if(xsum!=0){
        if(xsum==1) answer = "x";
        else    answer=to_string(xsum)+"x";
    }
    if(csum!=0){
        if(!answer.empty()) answer+=" + ";
        answer+=to_string(csum);
    }
    return answer;
}