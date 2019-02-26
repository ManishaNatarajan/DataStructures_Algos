/*
Given a 2d grid map of '1's (land) and '0's (water), 
count the number of islands. An island is surrounded by water 
and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water. 
*/
class Solution {
public:
    void explore(vector<vector<char>>& grid,int i,int j){
        int row_nbr[] = {-1,0,1,0};
        int col_nbr[] = {0,-1,0,1};
        int ROW = grid.size();
        int COL = grid[0].size();
        grid[i][j]='0';
        for(int k=0; k<4; ++k){
            int row_idx = row_nbr[k]+i;
            int col_idx = col_nbr[k]+j;
            if(row_idx>=0 && row_idx<ROW && col_idx>=0 && col_idx<COL && grid[row_idx][col_idx]=='1'){
                explore(grid, row_idx, col_idx);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int ROW = grid.size();
        if(!ROW)
            return 0;
        int COL = grid[0].size();
        // vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        for(int i=0; i<ROW; ++i){
            for(int j=0; j<COL; ++j){
                if(grid[i][j]=='1'){
                     ++count;
                    explore(grid, i, j);
                }
               
            }
        }
        return count;
    }
};
