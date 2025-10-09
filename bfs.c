#include
#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];
void enqueue(int v) {
if (rear == MAX - 1) {
printf("Queue Overflow\n");
return;
}
if (front == -1) {
front = 0;
}
queue[++rear] = v;
}
int dequeue() {
if (front == -1 || front > rear) {
return -1;
}
return queue[front++];
}
int isEmpty() {
return (front == -1 || front > rear);
}
void BFS(int adj[][MAX], int n, int start) {
int i, v;
for (i = 0; i < n; i++)
visited[i] = 0;

enqueue(start);
visited[start] = 1;

printf("BFS traversal starting from vertex %d:\n", start);

while (!isEmpty()) {
v = dequeue();
printf("%d ", v);

for (i = 0; i < n; i++) {
if (adj[v][i] == 1 && visited[i] == 0) {
enqueue(i);
visited[i] = 1;
}
}
}
printf("\n");
}
int main() {
int n, start, i, j;
int adj[MAX][MAX];

printf("Enter number of vertices: ");
scanf("%d", &n);

printf("Enter adjacency matrix:\n");
for (i = 0; i < n; i++){
for (j = 0; j < n; j++){
scanf("%d", &adj[i][j]);}
}
printf("Enter starting vertex: ");
scanf("%d", &start);

BFS(adj, n, start);

return 0;
}
