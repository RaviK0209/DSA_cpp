#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateSubsequences(string input, string output, int index, vector<string>& result) {
    if (index == input.size()) {
        result.push_back(output);
        return;
    }
    generateSubsequences(input, output + input[index], index + 1, result); // Include
    generateSubsequences(input, output, index + 1, result); // Exclude
}

int main() {
    string str = "abc";
    vector<string> subsequences;
    
    generateSubsequences(str, "", 0, subsequences);
    
    sort(subsequences.begin(), subsequences.end());

    for (string s : subsequences) {
        cout << s << endl;
    }

    return 0;
}
