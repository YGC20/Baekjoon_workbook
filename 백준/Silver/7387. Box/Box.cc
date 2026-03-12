#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Plat {
    int w, h;
    bool operator<(const Plat& other) const {
        if(w!=other.w) return w<other.w;
        return h<other.h;
    }
    bool operator==(const Plat& other) const {
        return w==other.w && h==other.h;
    }
};

void solutionA(vector<Plat>& palt);

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Plat> pallets(6);
    for(int i=0; i<6; ++i) {
        int x, y;
        cin>>x>>y;
        pallets[i] = {min(x,y), max(x,y)};
    }
    sort(pallets.begin(), pallets.end());

    solutionA(pallets);

    return 0;
}

void solutionA(vector<Plat>& palt)
{
    if(palt[0]==palt[1] && palt[2]==palt[3] && palt[4]==palt[5]) {
        if(palt[0].w==palt[2].w && palt[0].h==palt[4].w && palt[2].h==palt[4].h) {
            cout<<"POSSIBLE\n";
        }
        else {
            cout<<"IMPOSSIBLE\n";
        }
    }
    else {
        cout<<"IMPOSSIBLE\n";
    }
}