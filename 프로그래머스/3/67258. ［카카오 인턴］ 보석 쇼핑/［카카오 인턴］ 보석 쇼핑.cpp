#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> result = {0, (int)gems.size()};
    set<string> words(gems.begin(), gems.end());
    int totalWords = words.size();
    map<string, int> sector;
    
    int min_len = gems.size() + 1;
    int start = 0, end = 0;
    while(end < gems.size()) {
        sector[gems[end]]++;
        
        if(sector.size() == totalWords) {
            while(sector[gems[start]] > 1) {
                sector[gems[start++]]--;
            }
            
            if((end - start) < min_len) {
                min_len = (end - start);
                result = {start+1, end+1};
            }
        }
        end++;
    }
    return result;
}