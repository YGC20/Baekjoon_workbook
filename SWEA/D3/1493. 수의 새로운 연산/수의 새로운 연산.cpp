#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int posToVal(int x, int y)
{
    return (((x + y - 1 ) * (x + y - 2)) / 2 + x);
}

pair<int,int> valToPos(int val)
{
    int m = (int)((sqrt(8.0 * val + 1) - 1) / 2);

    while((m * m + m)/2 < val) { ++m; }
    while(m > 0 && (m * m - m)/2 >= val) { --m; }

    int x = val - ((m * m - m) / 2);
    int y = m + 1 - x;
    return {x, y};
}

int main(int argc, char** argv)
{
    int T, p, q; cin >> T;
    for(int tc=1; tc<=T; ++tc) {
        cin >> p >> q;
        auto pos1 = valToPos(p);
        auto pos2 = valToPos(q);

        int x = pos1.first + pos2.first;
        int y = pos1.second + pos2.second;

        int result = posToVal(x, y);
        cout << "#" << tc << " " << result << endl;
    }
    return 0;
}