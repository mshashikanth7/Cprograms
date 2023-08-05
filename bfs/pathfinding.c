#include <stdio.h>

#define SIZE 5

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
int findPath(int maze[SIZE][SIZE], int row, int col) {
    // If destination is reached
    if (maze[row][col] == 9) {
        return 1;
    }

    // Mark the current cell as visited (3)
    if (maze[row][col] != 2) {
        maze[row][col] = 3;
    }

    // Move right
    if (isValidMove(maze, row, col + 1) && findPath(maze, row, col + 1)) {
        return 1;
    }

    // Move down
    if (isValidMove(maze, row + 1, col) && findPath(maze, row + 1, col)) {
        return 1;
    }

    // Move up
    if (isValidMove(maze, row - 1, col) && findPath(maze, row - 1, col)) {
        return 1;
    }

    // Move left
    if (isValidMove(maze, row, col - 1) && findPath(maze, row, col - 1)) {
        return 1;
    }

    // If no path is found, backtrack and mark the cell as unvisited (0)
    if (maze[row][col] != 2) {
        maze[row][col] = 0;
    }
    
    return 0;
}

int main() {
    int maze[SIZE][SIZE] = {
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {2, 0, 0, 9, 0}
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

    if (findPath(maze, startRow, startCol)) {
        printf("\nPath Found:\n");
        printMaze(maze);
    } else {
        printf("\nNo Path Found!\n");
    }

    return 0;
}