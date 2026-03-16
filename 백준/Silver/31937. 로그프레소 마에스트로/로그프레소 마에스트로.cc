#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Log {
    int t, a, b;
};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    if(cin>>n>>m>>k) {
        vector<bool> infection_com(n+1, false);
        for(int i=0; i<k; ++i) {
            int tmp;
            cin>>tmp;
            infection_com[tmp] = true;
        }

        vector<Log> logs(m);
        for(int i=0; i<m; ++i) {
            cin>>logs[i].t>>logs[i].a>>logs[i].b;
        }
        sort(logs.begin(),logs.end(),[](const Log& x, const Log& y){ return x.t<y.t; });

        for(int i=1; i<=n; ++i) {
            if(!infection_com[i]) {
                continue;
            }

            vector<bool> check_infection(n+1, false);
            check_infection[i] = true;

            for(auto& log : logs) {
                if(check_infection[log.a]) {
                    check_infection[log.b] = true;
                }
            }

            if(check_infection==infection_com) {
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}