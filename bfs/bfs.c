#include <stdio.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

// Structure to store coordinates (x, y) of a cell
typedef struct {
    int x, y;
} Point;

// Function to check if a cell is valid (within matrix boundaries)
bool isValid(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

// Function to check if a cell is walkable (0) and not visited
bool isWalkable(int matrix[ROW][COL], bool visited[ROW][COL], int x, int y) {
    return (isValid(x, y) && matrix[x][y] == 0 && !visited[x][y]);
}

// Function to perform Breadth-First Search
bool BFS(int matrix[ROW][COL], Point src, Point dest) {
    if (!isValid(src.x, src.y) || !isValid(dest.x, dest.y)) {
        return false;
    }

    bool visited[ROW][COL] = {false};
    Point parent[ROW][COL]; // To store the parent of each cell
    visited[src.x][src.y] = true;

    Point queue[ROW * COL];
    int front = 0, rear = 0;
    queue[rear++] = src;

    int dx[] = {-1, 0, 1, 0}; // Possible x movements (up, right, down, left)
    int dy[] = {0, 1, 0, -1}; // Possible y movements (up, right, down, left)

    while (front < rear) {
        Point curr = queue[front++];
        if (curr.x == dest.x && curr.y == dest.y) {
            return true; // Path found
        }

        for (int i = 0; i < 4; i++) {
            int next_x = curr.x + dx[i];
            int next_y = curr.y + dy[i];

            if (isWalkable(matrix, visited, next_x, next_y)) {
                visited[next_x][next_y] = true;
                queue[rear++] = (Point){next_x, next_y};
                parent[next_x][next_y] = curr;
            }
        }
    }

    return false; // Path not found
}

// Function to print the walkable path
void printPath(int matrix[ROW][COL], Point src, Point dest, Point parent[ROW][COL]) {
    Point current = dest;
    while (current.x != src.x || current.y != src.y) {
        matrix[current.x][current.y] = 3; // Mark the walkable path as 3
        current = parent[current.x][current.y];
    }
    matrix[src.x][src.y] = 2; // Mark the source as 2
    matrix[dest.x][dest.y] = 9; // Mark the destination as 9

    // Print the matrix with the walkable path
    printf("Matrix with Walkable Path:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROW][COL] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 9}
    };

    Point src = {0, 2}; // Source coordinates (x, y)
    Point dest = {4, 4}; // Destination coordinates (x, y)

    Point parent[ROW][COL]; // To store the parent of each cell
    if (BFS(matrix, src, dest)) {
        printPath(matrix, src, dest, parent);
    } else {
        printf("Path from source to destination not found.\n");
    }

    return 0;
}
