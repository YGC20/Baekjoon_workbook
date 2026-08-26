#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int T; cin >> T;
    int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for(int tc=1; tc<=T; ++tc) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        int dCnt = 0;
        for(int d=sm; d<=em; ++d) { dCnt += days[d]; }
        dCnt -= ((sd - 1) + (days[em] - ed));
        cout << "#" << tc << " " << dCnt << endl;
    }
    return 0;
}