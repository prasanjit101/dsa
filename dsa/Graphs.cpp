#include <iostream>

class Adjacency_Matrix
{
    int **matrix;
    int size;

public:
    Adjacency_Matrix(int size)
    {
        this->size = size;
        matrix = new int *[size];
        for (int i = 0; i < size; i++)
        {
            matrix[i] = new int[size];
        }
    }
    void addEdge(int src, int dest, int weight)
    {
        matrix[src][dest] = weight;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    ~Adjacency_Matrix()
    {
        for (int i = 0; i < size; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    bool isEdge(int src, int dest)
    {
        return matrix[src][dest] != 0;
    }
    int getWeight(int src, int dest)
    {
        return matrix[src][dest];
    }
};

class Adjacency_List
{
    struct Node
    {
        int des;
        int weight;
        Node *next;
    };

    Node **list;
    int size;
    friend void dfs(Adjacency_List &, int);
    friend void bfs(Adjacency_List &, int);
    friend void recursive_dfs(Adjacency_List &, int, int, bool *);
    friend bool detect_cycle(Adjacency_List &, int, int, bool *, int);

public:
    Adjacency_List(int size)
    {
        this->size = size;
        list = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            list[i] = nullptr;
        }
    }
    void addEdge(int src, int des, int w)
    {
        Node *node = new Node;
        node->des = des;
        node->weight = w;
        node->next = list[src];
        list[src] = node;
    }
    int getEdge(int src, int des)
    {
        Node *n = list[src];
        while (n != nullptr)
        {
            if (n->des == des)
            {
                return n->weight;
            }
            n = n->next;
        }
        return 0;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << i << " -> ";
            Node *node = list[i];
            while (node != nullptr)
            {
                std::cout << node->des << " ";
                node = node->next;
            }
            std::cout << std::endl;
        }
    }
    ~Adjacency_List()
    {
        for (int i = 0; i < size; i++)
        {
            Node *node = list[i];
            while (node != nullptr)
            {
                Node *temp = node;
                node = node->next;
                delete temp;
            }
        }
        delete[] list;
    }
};

// breadth first traversal without recursion
void bfs(Adjacency_List &list, int size)
{
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++)
        visited[i] = false;
    int *queue = new int[size];
    int front = 0, rear = 0;
    queue[rear] = 0;
    rear = (rear + 1) % size;
    while (front != rear)
    {
        int curr = queue[front];
        front = (front + 1) % size;
        if (visited[curr])
            continue;
        std::cout << curr << " ";
        visited[curr] = true;
        Adjacency_List::Node *node = list.list[curr];
        while (node != nullptr)
        {
            if (visited[node->des])
            {
                queue[rear] = node->des;
                rear = (rear + 1) % size;
            }
            node = node->next;
        }
    }
    delete[] visited;
    delete[] queue;
}

// depth first traversal without recursion
void dfs(Adjacency_List &list, int size)
{
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++)
        visited[i] = false;
    int *stack = new int[size];
    int top = -1;
    stack[++top] = 0;
    while (top != -1)
    {
        int curr = stack[top--];
        if (visited[curr])
            continue;
        std::cout << curr << " ";
        visited[curr] = true;
        Adjacency_List::Node *node = list.list[curr];
        while (node != nullptr)
        {
            if (!visited[node->des])
            {
                stack[++top] = node->des;
            }
            node = node->next;
        }
    }
    delete[] visited;
    delete[] stack;
}

// depth first traversal using recursion
void recursive_dfs(Adjacency_List &list, int size, int curr, bool *visited)
{
    if (visited[curr])
        return;
    std::cout << curr << " ";
    visited[curr] = true;
    Adjacency_List::Node *node = list.list[curr];
    while (node != nullptr)
    {
        if (!visited[node->des])
        {
            recursive_dfs(list, size, node->des, visited);
        }
        node = node->next;
    }
}

// detect cycle in directed graph using dfs
bool detect_cycle(Adjacency_List &list, int size, int curr, bool *visited, int parent)
{
    if (visited[curr])
        return true;
    visited[curr] = true;
    Adjacency_List::Node *node = list.list[curr];
    while (node != nullptr)
    {
        if (!visited[node->des])
        {
            if (detect_cycle(list, size, node->des, visited, curr))
                return true;
        }
        else if (node->des != parent)
            return true;
        node = node->next;
    }
    return false;
}