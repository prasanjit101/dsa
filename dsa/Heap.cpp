class Heap
{
public:
    Heap(int size);
    ~Heap();
    void insert(int value);
    int remove();

private:
    int *heap;
    int size;
    int count;
    void heapify(int index);
    void swap(int *a, int *b);
};

// Path: Heap.cpp
Heap::Heap(int size)
{
    this->size = size;
    this->count = 0;
    this->heap = new int[size];
}

// Path: Heap.cpp
Heap::~Heap()
{
    delete[] this->heap;
}

// Path: Heap.cpp
void Heap::insert(int value)
{
    if (this->count == this->size)
    {
        return;
    }
    this->heap[this->count] = value;
    this->count++;
    this->heapify(this->count - 1);
}

// Path: Heap.cpp
int Heap::remove()
{
    if (this->count == 0)
    {
        return -1;
    }
    int result = this->heap[0];
    this->heap[0] = this->heap[this->count - 1];
    this->count--;
    this->heapify(0);
    return result;
}

// Path: Heap.cpp
void Heap::heapify(int index)
{
    int parent = (index - 1) / 2;
    if (this->heap[index] > this->heap[parent])
    {
        this->swap(&this->heap[index], &this->heap[parent]);
        this->heapify(parent);
    }
}

// Path: Heap.cpp
void Heap::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
