class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Queue:
    def __init__(self, queue=None):
        if queue == None:
            self.items = []
        else:
            self.items = queue

    def enqueue(self, i):
        self.items.insert(0, i)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return len(self.items)

    def isEmpty(self):
        return self.size() == 0

    def __str__(self):
        return str(self.items)


class Linked_Queue:
    def __init__(self, queue=None):
        if queue == None:
            self.front = None
            self.rear = None
        else:
            self.front = queue.front
            self.rear = queue.rear

    def enqueue(self, i):
        temp = Node(i)
        if self.front == None:
            self.front = temp
            self.rear = temp
        else:
            self.rear.next = temp
            self.rear = temp

    def dequeue(self):
        if self.front == None:
            return None
        else:
            temp = self.front
            self.front = self.front.next
            return temp.data

    def size(self):
        count = 0
        p = self.front
        while p != None:
            count += 1
            p = p.next
        return count

    def isEmpty(self):
        return self.size() == 0

    def __str__(self):
        s = ""
        p = self.front
        while p != None:
            s += str(p.data) + " "
            p = p.next
        return s


class Arr_Queue:
    def __init__(self, n):
        self.items = [0]*n
        self.front = 0
        self.rear = n-1

    def enqueue(self, i):
        self.items.append(i)
        self.rear += 1

    def dequeue(self):
        self.front += 1

    def size(self):
        return self.rear - self.front + 1

    def isEmpty(self):
        return self.size() == 0

    def __str__(self):
        return str(self.items[self.front:self.rear+1])
