/*
Trapping Rain Water
Given n non-negative integers representing an elevation map 
where the width of each bar is 1, compute how much water it is able to trap after raining. 
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water=0;
        if(n < 1)
            return 0;
        vector<int> right_max(n, 0);
        vector<int> left_max(n, 0);
        int max = INT_MIN;
        for(int i=0; i<n; i++){
            if(height[i] > max)
                max = height[i];
            right_max[i] = max;
        }
        max = INT_MIN;
        for(int j=n-1; j>=0; --j){
            if(height[j] > max)
                max = height[j];
            left_max[j] = max;
        }
        for(int k  =0; k<n; k++){
            water += min(left_max[k], right_max[k])-height[k];
        }
        return water;
    }
};