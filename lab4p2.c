void dfs(char** grid, int row, int col, int rows, int cols) {
    if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] != '1') {
        return;
    }


    grid[row][col] = '0';

    dfs(grid, row - 1, col, rows, cols); 
    dfs(grid, row + 1, col, rows, cols); 
    dfs(grid, row, col - 1, rows, cols); 
    dfs(grid, row, col + 1, rows, cols); 
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (grid == NULL || gridSize == 0 || *gridColSize == 0) return 0;

    int numIslands = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                numIslands++;
                dfs(grid, i, j, gridSize, gridColSize[i]);
            }
        }
    }
    return numIslands;
}
