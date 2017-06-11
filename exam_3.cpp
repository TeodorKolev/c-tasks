#include <iostream>
#include <algorithm>

using namespace std;

void replaceAll(string& str, const string& from, const string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

int main()
{
    string s;
    if(getline(cin, s)) {
        replaceAll(s, "@", "at");
        cout << s << endl;
    }

    return 0;
}
