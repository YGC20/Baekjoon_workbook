#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    int T, N; cin >> T;
    for(int tc=1; tc<=T; ++tc) {
        cin >> N;
        vector<pair<char, int>> words(N);
        for(int i=0; i<N; ++i) { cin >> words[i].first >> words[i].second; }
        
        string doc = "";
        vector<string> docs;
        for(auto& w : words) {
            for(int i=0; i<w.second; ++i) {
                doc += w.first;
                if(doc.length() >= 10) {
                    docs.push_back(doc);
                    doc.clear();
                }
            }
        }
        if(!doc.empty()) { docs.push_back(doc); }
        
        cout << "#" << tc << endl;
        for(auto& str : docs) { cout << str << endl; }
    }
    return 0;
}