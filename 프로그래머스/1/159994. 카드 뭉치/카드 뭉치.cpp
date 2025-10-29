#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int c1Idx, c2Idx, c1Size, c2Size;
    c1Idx = c2Idx = 0;
    c1Size = cards1.size();
    c2Size = cards2.size();
    for(const string g:goal){
        string c1 = (c1Size>c1Idx)?cards1[c1Idx]:" ";
        string c2 = (c2Size>c2Idx)?cards2[c2Idx]:" ";
        
        if(g==c1&&g!=c2) c1Idx++;
        else if(g!=c1&&g==c2) c2Idx++;
        else if(g!=c1&&g!=c2) return "No";
    }
    return "Yes";
}