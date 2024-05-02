#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Time {
    int hr, min;
    Time() : hr(0), min(0) {}
    Time(int h, int m): hr(h), min(m) {}
    
    Time(const string& time) {
        char ch;
        istringstream foo(time);
        foo >> hr >> ch >> min;
    }
};

struct Compare {
    bool operator()(const Time& t1, const Time& t2) const {
        if (t1.hr == t2.hr)
            return t1.min < t2.min;
        return t1.hr < t2.hr;
    }
};

int main() {
    vector<Time> times;
    string input;
    
    getline(cin, input);
    
    istringstream iss(input);
    string token;
    while (iss >> token) {
        times.push_back(Time(token));
    }
    
    sort(times.begin(), times.end(), Compare());
    
    for (size_t i = 0; i < times.size() - 1; ++i) {
        cout << setw(2) << setfill('0') << times[i].hr << ":" << setw(2) << setfill('0') << times[i].min << " ";
    }
    cout << setw(2) << setfill('0') << times[times.size() - 1].hr << ":" << setw(2) << setfill('0') << times[times.size() - 1].min << endl;
    
    return 0;
}
