#include <string>
#include <vector>
using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db)
{
    bool findId = false, findPw = false;
    for(auto data : db) {
        if(id_pw[0]==data[0] && id_pw[1]==data[1]) {
            findId = true; findPw = true;
        }
        else if(id_pw[0]==data[0] && id_pw[1]!=data[1])
            findId = true;
    }
    
    if(findId && findPw)
        return "login";
    else if(findId && !findPw)
        return "wrong pw";
    else
        return "fail";
}