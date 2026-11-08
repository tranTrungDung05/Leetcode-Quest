bool isInLine(int* tx, int* ty, int x, int y, int gridSize, int* gridColSize){
    bool fx = false;
    bool fy = false;

    if (tx[x] > 1) {
        fx = true;
    }

    if (ty[y] > 1) {
        fy = true;
    }

    return fx || fy;
}

int countServers(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    int m = gridSize;
    int n = *gridColSize;

    int* tx = (int*) calloc(m, sizeof(int));
    int* ty = (int*) calloc(n, sizeof(int));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                tx[i]++; 
                ty[j]++;
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1 && isInLine(tx, ty, i, j, gridSize, gridColSize)){
                count++;
            }
        }
    }

    free(tx);
    free(ty);

    return count;
}