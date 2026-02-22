#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string ret = "";
    int code_length = code.size();
    
    int mode = 0;
    for(int i=0; i<code.size(); ++i) {
        if(code[i]=='1') {
            mode = ((mode==0)?1:0);
            continue;
        }
        if(mode==0) {
            if(i%2==0) {
                ret+=code[i];
            }
        }
        else {
            if(i%2!=0) {
                ret+=code[i];
            }
        }
    }
    
    return (ret.size()!=0?ret:"EMPTY");
}