/*
Platform   : LeetCode
Problem    : 1. Two Sum
Topic      : Array, Hash Map
Difficulty : Easy

Time Complexity : O(n)
Space Complexity: O(n)

Author : Pitabash Jena
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    vector<int> ans1 = obj.twoSum(nums1, target1);

    cout << "Test Case 1: ";
    for (int x : ans1)
        cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;

    vector<int> ans2 = obj.twoSum(nums2, target2);

    cout << "Test Case 2: ";
    for (int x : ans2)
        cout << x << " ";
    cout << endl;

    // Test Case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;

    vector<int> ans3 = obj.twoSum(nums3, target3);

    cout << "Test Case 3: ";
    for (int x : ans3)
        cout << x << " ";
    cout << endl;

    return 0;
}