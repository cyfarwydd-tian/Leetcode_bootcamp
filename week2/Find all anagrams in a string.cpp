#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.length() < p.length()) return result;

    vector<int> p_count(26, 0), s_count(26, 0);

    // Count frequency of characters in p
    for (char c : p) {
        p_count[c - 'a']++;
    }

    int p_len = p.length();
    int s_len = s.length();

    // Sliding window initial fill
    for (int i = 0; i < p_len; i++) {
        s_count[s[i] - 'a']++;
    }

    // Check if first window is an anagram
    if (s_count == p_count) result.push_back(0);

    // Slide the window through s
    for (int i = p_len; i < s_len; i++) {
        // Add new character to the window
        s_count[s[i] - 'a']++;
        // Remove the leftmost character from window
        s_count[s[i - p_len] - 'a']--;

        // Compare counts
        if (s_count == p_count) {
            result.push_back(i - p_len + 1);
        }
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    
    vector<int> result = findAnagrams(s, p);
    
    cout << "Output: [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
