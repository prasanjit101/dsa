class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void add(int data)
    {
        Node *node = new Node(data);
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        size++;
    }
    void add(int data, int index)
    {
        if (index < 0 || index > size)
        {
            return;
        }
        Node *node = new Node(data);
        if (index == 0)
        {
            node->next = head;
            head = node;
        }
        else if (index == size)
        {
            tail->next = node;
            tail = node;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
        size++;
    }
    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else if (index == size - 1)
        {
            Node *temp = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
        size--;
    }
    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
