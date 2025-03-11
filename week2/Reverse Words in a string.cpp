#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string reverseWords(string s) {
    vector<string> words;
    string word;
    stringstream ss(s);

    // Extract words while ignoring extra spaces
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the words
    reverse(words.begin(), words.end());

    // Construct the result
    string result;
    for (size_t i = 0; i < words.size(); i++) {
        result += words[i];
        if (i < words.size() - 1) result += " ";
    }

    return result;
}

int main() {
    string s = "  hello world  ";
    cout << "\"" << reverseWords(s) << "\"" << endl;  // Output: "world hello"
    return 0;
}
