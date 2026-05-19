#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Num {
    int val;
    int dist;
};

vector<int> solution(vector<int> numlist, int n)
{
    vector<Num> distList;
    for(auto nl : numlist) {
        Num tmp;
        tmp.val = nl;
        tmp.dist = (n-nl)>0?n-nl:nl-n;
        distList.push_back(tmp);
    }
    sort(distList.begin(), distList.end(), [](const Num& a, const Num& b)
         {
             if(a.dist==b.dist) return a.val>b.val;
             return a.dist<b.dist;
         });
    vector<int> answer;
    for(auto dl : distList) {
        answer.push_back(dl.val);
    }
    return answer;
}