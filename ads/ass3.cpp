#include <iostream> 
using namespace std; 
struct Point {
    int x, y;
};

const int MAX_SIZE = 100;

class Queue
{
private:
    Point arr[MAX_SIZE * MAX_SIZE];
    int front, rear;

public:
    Queue() : front(0), rear(0) {}
    void push(Point p)
    {
        arr[rear++] = p;
    }
    Point pop()
    {
        return arr[front++];
    }
    bool empty()
    {
        return front == rear;
    }
};
class Stack
{
private:
    Point arr[MAX_SIZE * MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}
    void push(Point p)
    {
        arr[++top] = p;
    }
    Point pop()
    {
        return arr[top--];
    }
    bool empty()
    {
        return top == -1;
    }
};

class MazeSolver
{
private:
    int maze[MAX_SIZE][MAX_SIZE];
    bool visited[MAX_SIZE][MAX_SIZE];
    Point parent[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    Point start, goal;
    Point directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    MazeSolver(int r, int c, Point s, Point g) : rows(r), cols(c), start(s), goal(g)
    {
        cout << "Enter the maze (0 for open, 1 for blocked):" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> maze[i][j];
                visited[i][j] = false;
                parent[i][j] = {-1, -1};
            }
        }
    }
    bool isValid(int x, int y)
    {
        return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0 && !visited[x][y];
    }
    void printPath()
    {
        Stack path;
        Point p = goal;
        while (!(p.x == -1 && p.y == -1))
        {
            path.push(p);
            p = parent[p.x][p.y];
        }
        cout << "Path: ";

        while (!path.empty())
        {
            Point step = path.pop();
            cout << "(" << step.x << ", " << step.y << ") ";
        }
        cout << endl;
    }
    bool DFS()
    {
        Stack s;
        s.push(start);
        visited[start.x][start.y] = true;
        parent[start.x][start.y] = {-1, -1};
        while (!s.empty())
        {
            Point curr = s.pop();
            if (curr.x == goal.x && curr.y == goal.y)
            {
                cout << "Path found using DFS!" << endl;
                printPath();
                return true;
            }
            for (auto d : directions)
            {
                int nx = curr.x + d.x;
                int ny = curr.y + d.y;
                if (isValid(nx, ny))
                {
                    visited[nx][ny] = true;
                    parent[nx][ny] = curr;
                    s.push({nx, ny});
                }
            }
        }
        cout << "No path found using DFS!" << endl;
        return false;
    }
    bool BFS()
    {
        Queue q;
        q.push(start);
        visited[start.x][start.y] = true;
        parent[start.x][start.y] = {-1, -1};
        while (!q.empty())
        {
            Point curr = q.pop();
            if (curr.x == goal.x && curr.y == goal.y)
            {
                cout << "Path found using BFS!" << endl;
                printPath();
                return true;
            }
            for (auto d : directions)
            {
                int nx = curr.x + d.x;
                int ny = curr.y + d.y;
                if (isValid(nx, ny))
                {
                    visited[nx][ny] = true;
                    parent[nx][ny] = curr;
                    q.push({nx, ny});
                }
            }
        }
        cout << "No path found using BFS!" << endl;
        return false;
    }
};
int main()
{
    int rows, cols, choice;

    Point start, goal;
    cout << "Enter maze dimensions (rows and cols): ";
    cin >> rows >> cols;
    cout << "Enter start position (x y): ";
    cin >> start.x >> start.y;
    cout << "Enter goal position (x y): ";
    cin >> goal.x >> goal.y;
    MazeSolver solver(rows, cols, start, goal);
    cout << "Select search algorithm: 1. DFS 2. BFS\nEnter choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        solver.DFS();
        break;
    case 2:
        solver.BFS();
        break;
    default:
        cout << "Invalid choice!" << endl;
    }
    return 0;
}
