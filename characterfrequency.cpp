#include <iostream>
#include <map>
using namespace std;

int main() {
    string s;
    cout<<"enter a string"<<endl;
    cin >> s;

    map<char, int> freq;

    for (char c : s) {
        c=tolower(c);
        freq[c]++;
    }

    for (auto it = freq.begin(); it != freq.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
