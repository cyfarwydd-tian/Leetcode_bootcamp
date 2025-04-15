#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    int n = nums.size();
    vector<vector<int>> buckets(n + 1);
    for (auto& pair : freqMap) {
        buckets[pair.second].push_back(pair.first);
    }

    vector<int> result;
    for (int i = n; i >= 0 && result.size() < k; --i) {
        for (int num : buckets[i]) {
            result.push_back(num);
            if (result.size() == k) break;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
