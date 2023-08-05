#include <stdio.h>

#define SIZE 5
#define INF 99999

// Function to print the maze
void printMaze(int maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is valid to move to
int isValidMove(int maze[SIZE][SIZE], int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && (maze[row][col] == 0 || maze[row][col] == 9));
}

// Recursive function to find the path
void dfs(int maze[SIZE][SIZE], int row, int col, int pathLen, int *minPathLen) {
    if (maze[row][col] == 9) {
        if (pathLen < *minPathLen) {
            *minPathLen = pathLen;
        }
        return;
    }

    // Mark the current cell as visited (3)
    if (maze[row][col] != 2) {
        maze[row][col] = 3;
    }

    // Move right
    if (isValidMove(maze, row, col + 1)) {
        dfs(maze, row, col + 1, pathLen + 1, minPathLen);
    }

    // Move down
    if (isValidMove(maze, row + 1, col)) {
        dfs(maze, row + 1, col, pathLen + 1, minPathLen);
    }

    // Move up
    if (isValidMove(maze, row - 1, col)) {
        dfs(maze, row - 1, col, pathLen + 1, minPathLen);
    }

    // Move left
    if (isValidMove(maze, row, col - 1)) {
        dfs(maze, row, col - 1, pathLen + 1, minPathLen);
    }

    // Mark the cell as unvisited (0)
    if (maze[row][col] != 2) {
        maze[row][col] = 0;
    }
}

int main() {
    int maze[SIZE][SIZE] = {
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 9, 0, 0},
        {0, 1, 1, 1, 0},
        {2, 0, 0, 0, 0}
    };

    printf("Original Maze:\n");
    printMaze(maze);

    int startRow = -1, startCol = -1;
    // Finding the starting point
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (maze[i][j] == 2) {
                startRow = i;
                startCol = j;
                break;
            }
        }
    }

    if (startRow == -1 || startCol == -1) {
        printf("Starting point not found!\n");
        return -1;
    }

    int minPathLen = INF;
    dfs(maze, startRow, startCol, 0, &minPathLen);

    if (minPathLen != INF) {
        printf("\nShortest Path Found: %d\n", minPathLen);
        printMaze(maze);
    } else {
        printf("\nNo Path Found!\n");
    }

    return 0;
}
