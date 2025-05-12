#include <iostream>
#include <stack>
using namespace std;

bool hasRedundantBrackets(const string &str) {
    stack<char> st;

    for (char ch : str) {
        if (ch == ')') {
            bool hasOperator = false;

            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                st.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    hasOperator = true;
            }

            if (!st.empty())
                st.pop();

            if (!hasOperator)
                return true;
        } else {
            st.push(ch);
        }
    }

    return false;
}

int main() {
    string input;
    cin >> input;

    if (hasRedundantBrackets(input))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
