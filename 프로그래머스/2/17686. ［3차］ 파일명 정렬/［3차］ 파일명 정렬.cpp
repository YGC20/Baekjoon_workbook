#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct FileData{
    string head;
    int num;
};

FileData outNumber(const string& s)
{
    FileData fd;
    int idx = 0;
    while(idx < s.length() && !isdigit(s[idx])) {
        fd.head += tolower(s[idx]);
        idx++;
    }
    
    string temp = "";
    while(idx < s.length() && isdigit(s[idx]) && temp.length() < 5) {
        temp += s[idx];
        idx++;
    }
    
    if(!temp.empty()) {
        fd.num = stoi(temp);
    } else {
        fd.num = 0;
    }
    return fd;
}

bool compare(const string& a, const string& b)
{
    FileData af = outNumber(a);
    FileData bf = outNumber(b);
    
    if(af.head == bf.head) {
        return af.num < bf.num;
    }
    return af.head < bf.head;
}

vector<string> solution(vector<string> files)
{
    stable_sort(files.begin(), files.end(), compare);
    return files;
}