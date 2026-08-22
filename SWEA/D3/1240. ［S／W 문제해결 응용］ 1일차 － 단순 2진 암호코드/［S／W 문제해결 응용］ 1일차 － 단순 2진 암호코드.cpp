#include<iostream>
using namespace std;

string decode[10] = {
    "0001101", "0011001", "0010011", "0111101", "0100011", 
    "0110001", "0101111", "0111011", "0110111", "0001011"
};

int main(int argc, char** argv)
{
    int T; cin >> T;
    int N, M;
    for(int tc=1; tc<=T; ++tc) {
        cin >> N >> M;
        string code = "";
        for(int i=0; i<N; ++i) {
            string temp = "";
            cin >> temp;
            for(int j=M-1; j>=0; --j) {
                if(temp[j] == '1') { code = temp.substr((j-55), 56); break; }
            } /* for j 0 */
        } /* for i N*/
        
        int encode = 0;
        int sum = 0;
        for(int i=0; i<8; ++i) {
            string temp = code.substr((i * 7), 7);
            for(int j=0; j<10; ++j) {
                if(decode[j] == temp) {
                    sum += j;
                    if(i%2==0) { encode += (j*3); }
                    else { encode += j; }
                }
            } /* for j 10 */
        } /* for i 8 */
        if(encode % 10 != 0) { sum = 0; }
        cout << "#" << tc << " " << sum << endl;
    } /* for tc T */
    return 0;
}