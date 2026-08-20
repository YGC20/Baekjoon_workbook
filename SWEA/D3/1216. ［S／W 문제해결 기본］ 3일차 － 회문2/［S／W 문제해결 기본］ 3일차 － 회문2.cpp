#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxLen = 0;

void manacher(string str)
{
    int len = static_cast<int>(str.length());
    vector<int> radius(len, 0);
    int mid = 0, right = 0;
    
    for(int i=1; i<(len-1); ++i) {
        int mirror = 2*mid - i;
        if(i<right) { radius[i] = min((right - i), radius[mirror]); }
        while(str[i + 1 + radius[i]] == str[i - 1 - radius[i]]) { ++radius[i]; }
        if((i + radius[i]) > right) {
            mid = i;
            right = i + radius[i];
            maxLen = max(maxLen, radius[i]);
        }
    } /* for i len-1 */
}

int main(int argc, char** argv)
{
	int T = 10;
    for(int tc=1; tc<=T; ++tc) {
        int N; cin>>N;
        vector<string> words(100);
        for(int i=0; i<100; ++i) {
			cin>>words[i];
        } /* for i 100 */
        
        vector<string> pdWord;
        string xTmp = "", yTmp = "";
        for(int i=0; i<100; ++i) {
            xTmp += "^#"; yTmp += "^#";
            for(int j=0; j<100; ++j) {
               xTmp += words[i][j]; xTmp += '#';
               yTmp += words[j][i]; yTmp += '#';
           } /* for j 100 */
            xTmp += '$'; yTmp += '$';
            pdWord.push_back(xTmp);
            pdWord.push_back(yTmp);
            xTmp.clear(); yTmp.clear();
        } /* for i 100 */
        
        for(auto& str : pdWord) {
            manacher(str);
        }
		cout << "#" << N << " " << maxLen << "\n";
        maxLen = 0;
    } /* for tc 10 */
    return 0;
}