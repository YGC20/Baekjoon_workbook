#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    answer.reserve(s.size());
    
    for(size_t i=0;i<s.size();++i){
        char c = s[i];
        bool word_start = (i==0)||(s[i-1]==' ');
        bool is_alpha = (('A'<=c&&c<='Z')||('a'<=c&&c<='z'));
        if(word_start&&is_alpha)    c &= ~32;
        else if(!word_start&&is_alpha)  c|= 32;
        answer+=c;
    }
    return answer;
}