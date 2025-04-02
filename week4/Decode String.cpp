#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;
    string currentString = "";
    int k = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            k = k * 10 + (ch - '0');
        } else if (ch == '[') {
            countStack.push(k);
            stringStack.push(currentString);
            currentString = "";
            k = 0;
        } else if (ch == ']') {
            string decodedString = stringStack.top();
            stringStack.pop();
            int currentK = countStack.top();
            countStack.pop();
            while (currentK-- > 0) {
                decodedString += currentString;
            }
            currentString = decodedString;
        } else {
            currentString += ch;
        }
    }

    return currentString;
}

int main() {
    string s1 = "3[a]2[bc]";
    string s2 = "3[a2[c]]";
    string s3 = "2[abc]3[cd]ef";

    cout << decodeString(s1) << endl; // Output: aaabcbc
    cout << decodeString(s2) << endl; // Output: accaccacc
    cout << decodeString(s3) << endl; // Output: abcabccdcdcdef

    return 0;
}
