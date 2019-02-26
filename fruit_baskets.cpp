/*
Fruit into Baskets 
In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

    Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
    Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.

Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

 

Example 1:

Input: [1,2,1]
Output: 3
Explanation: We can collect [1,2,1].

*/
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        if(n<2)
            return n;
        int start =0; int end=start+1;
        int tree2=-1;
        int count=0, max_count=0;
        while(start<n-1 && end<n){
            // cout<<"Start: "<<tree[start]<<endl;
            if(tree[end]==tree[start]){
                // cout<<"F"<<endl;
                end++;
            }                
            else if(tree2==-1){
                tree2 = tree[end];
                // cout<<"G"<<endl;
                end++;
            }
            else if(tree[end]==tree2){
                end++;
                // cout<<"H"<<endl;
            }
            else{
                // cout<<"Restart"<<endl;
                count = end-start;
                max_count = max(max_count, count);
                start=start+1;
                end=start+1;
                tree2=-1;
            }
        }
        count = end-start;
        max_count = max(max_count, count);
        return max_count;
    }
};
