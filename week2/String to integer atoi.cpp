#include <iostream>
#include <climits>

using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.size(), sign = 1;
    long result = 0;
    
    // Step 1: Ignore leading whitespace
    while (i < n && s[i] == ' ') i++;
    
    // Step 2: Check for sign
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    // Step 3: Read digits and convert to integer
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        
        // Step 4: Handle overflow cases
        if (sign * result < INT_MIN) return INT_MIN;
        if (sign * result > INT_MAX) return INT_MAX;
        
        i++;
    }
    
    return sign * result;
}

int main() {
    // Test cases
    cout << myAtoi("42") << endl;           // Output: 42
    cout << myAtoi("   -042") << endl;      // Output: -42
    cout << myAtoi("1337c0d3") << endl;    // Output: 1337
    cout << myAtoi("0-1") << endl;         // Output: 0
    cout << myAtoi("words and 987") << endl; // Output: 0
    return 0;
}
