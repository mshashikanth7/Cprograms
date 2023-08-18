/*14a. Write a C program to implement traverse the graph in DFS order.

Test Case example:

input= 5
0 1 1 1 0
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
0 1 1 1 0
1
output=
1 2 5 3 4


*/
// Start writing program from here
#include <stdio.h>
void dfs(int);
int G[10][10], visited[10], n, s;
void main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &G[i][j]);
    for (i = 1; i <= n; i++)
        visited[1] = 0;
    scanf("%d", &s);
    dfs(s);
}

void dfs(int i)
{
    int j;
    printf("%d ", i);
    visited[i] = 1;
    for (j = 1; j <= n; j++)
        if ((visited[j] == 0) && G[i][j] == 1)
            dfs(j);
}
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////

/*14 b. Write a C program to traverse the graph in BFS order.

Test Case example:

input= 5
0 1 1 1 0
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
0 1 1 1 0
3
output=
3 1 5 2 4


*/
// Start writing program from here
#include <stdio.h>

int q[20], front = -1, rear = -1, a[20][20], vis[20];
int delete();
void add(int item);
void bfs(int s, int n);

void main()
{
    int n, i, s, j;
    // printf("ENTER THE NUMBER VERTICES ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            // printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0 ",i,j);
            scanf("%d", &a[i][j]);
        }
    }
    // printf("THE ADJACENCY MATRIX IS\n");

    for (i = 1; i <= n; i++)
        vis[i] = 0;

    // printf("\n ENTER THE SOURCE VERTEX :");
    scanf("%d", &s);
    bfs(s, n);
}
void bfs(int s, int n)
{
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete ();
    if (p != 0)
        printf(" %d", p);
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
            if ((a[p][i] != 0) && (vis[i] == 0))
            {
                add(i);
                vis[i] = 1;
            }
        p = delete ();
        if (p != 0)
            printf(" %d ", p);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            bfs(i, n);
}

void add(int item)
{
    if (rear == 19)
        printf("QUEUE FULL");
    else
    {
        if (rear == -1)
        {
            q[++rear] = item;
            front++;
        }
        else
            q[++rear] = item;
    }
}
int delete()
{
    int k;
    if ((front > rear) || (front == -1))
        return (0);
    else
    {
        k = q[front++];
        return (k);
    }
}