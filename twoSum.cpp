/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> list;
        vector<int> ans;
        int n=nums.size();
        for(int i=0; i<n; ++i){
            int rem=target-nums[i];
            if(list.find(rem)!=list.end()){
                return {list[rem], i};
            }
            list[nums[i]] = i;
        }
       return ans; 
    }
};