class Solution {
public:
    int dfs(vector<vector<int>>&grid, int row, int col)
    {
        //current dfs touches the boundary, then return INT_MAX as a 'MARKER'
        if (row < 0 or col < 0 or row == grid.size() or col == grid[0].size()) 
			return INT_MAX; 
        if (grid[row][col] == 0) return 0;
        
        grid[row][col] = 0;  //mark curr cell 'visited' by making it a water cell
        //=============================================================
		//each dfs call return  count of connected land cells in a gven  direction
        int topCount = dfs(grid, row - 1, col);
        int bottomCount = dfs(grid, row + 1, col);
        int leftCount = dfs(grid, row, col - 1);
        int rightCount = dfs(grid, row, col + 1);
        //==================================================================
        //if dfs from any side returns "INT_MAX", it denotes that current cell somewhere leads to boundary
        if (topCount == INT_MAX or bottomCount == INT_MAX or leftCount == INT_MAX or rightCount == INT_MAX)
            return INT_MAX;
        else return (topCount + bottomCount + leftCount + rightCount + 1);
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0) continue;
                
				//landCellsCount denotes the size of island
				//landCellsCount = INT_MAX would denote that island touches the boundary
                int landCellsCount = dfs(grid, i, j);
                if (landCellsCount != INT_MAX) ans += landCellsCount; 
                
            }
        }
        return ans;
        
    }
};
