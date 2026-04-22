#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string cmd = "";
    for(int i=1; i<numLog.size(); i++) {
        int nl = numLog[i] - numLog[i-1];
        if(nl==1) {
            cmd+="w";
        }
        else if(nl==-1) {
            cmd+="s";
        }
        else if(nl==10) {
            cmd+="d";
        }
        else if(nl==-10) {
            cmd+="a";
        }
    }
    return cmd;
}