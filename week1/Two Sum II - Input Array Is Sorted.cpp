#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left + 1, right + 1}; // Convert to 1-based indexing
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {}; // This case will never occur as per problem constraints
}