#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    int rank;
};

int solution(vector<int> rank, vector<bool> attendance) {
    vector<Student> attendees; 
    for(int i=0; i<rank.size(); ++i) {
        if(attendance[i]) {
            attendees.push_back({i, rank[i]});
        }
    }
    
    sort(attendees.begin(), attendees.end(), [](const Student& a, const Student& b){ return a.rank<b.rank; });
    return ((10000*attendees[0].id)+(100*attendees[1].id)+attendees[2].id);
}