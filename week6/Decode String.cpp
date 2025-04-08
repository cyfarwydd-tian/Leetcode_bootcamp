#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {
    stack<string> strStack;
    stack<int> numStack;
    string currStr = "";
    int num = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');  // Build multi-digit number
        } else if (ch == '[') {
            numStack.push(num);
            strStack.push(currStr);
            num = 0;
            currStr = "";
        } else if (ch == ']') {
            int repeatCount = numStack.top(); numStack.pop();
            string prevStr = strStack.top(); strStack.pop();
            string temp = "";
            for (int i = 0; i < repeatCount; ++i) {
                temp += currStr;
            }
            currStr = prevStr + temp;
        } else {
            currStr += ch;
        }
    }

    return currStr;
}

// Example usage
int main() {
    string s1 = "3[a]2[bc]";
    string s2 = "3[a2[c]]";
    string s3 = "2[abc]3[cd]ef";

    cout << decodeString(s1) << endl;  // Output: aaabcbc
    cout << decodeString(s2) << endl;  // Output: accaccacc
    cout << decodeString(s3) << endl;  // Output: abcabccdcdcdef

    return 0;
}
