class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class circular_linked_list:
    # Constructor
    def __init__(self):
        self.head = None
        self.end = None
        self.size = 0
    # length

    def __len__(self):
        return self.size
    # to string

    def __str__(self):
        s = ""
        p = self.head
        while p is not None:
            s += str(p.data) + " "
            p = p.next
            if p == self.head:
                break
        return s
    # iterate

    def __iter__(self):
        p = self.head
        while p is not None:
            yield p.data
            p = p.next
            if p == self.head:
                break
    # deletion

    def delete_from_start(self):
        if self.size == 0:
            print("List is empty")
            return
        elif self.size == 1:
            self.head = None
            self.end = None
            self.size = 0
        else:
            self.head = self.head.next
            self.end.next = self.head
            self.size -= 1

    def delete_from_end(self, nod):
        if self.size == 0:
            print("List is empty")
            return
        else:
            n = self.search(nod)
            n.next = self.head
            self.end = n
            self.size -= 1
    # insertion

    def insert_at_start(self, data):
        temp = Node(data)
        if self.size == 0:
            self.head = temp
            self.end = temp
            self.end.next = self.head
        else:
            temp.next = self.head
            self.head = temp
            self.end.next = self.head
        self.size += 1

    def insert_at_end(self, data):
        temp = Node(data)
        if self.size == 0:
            self.head = temp
            self.end = temp
            self.end.next = self.head
        else:
            self.end = temp
            self.end.next = self.head
        self.size += 1
    # peek

    def peek(self):
        return self.head.data
    # clear

    def clear(self):
        self.head = None
        self.end = None
        self.size = 0
    # is empty

    def is_empty(self):
        return self.size == 0
    # search

    def search(self, x):
        p = self.head
        i = None
        while p.next is not None:
            if p.next == x:
                i = p
                break
            p = p.next.next
            if p == self.head:
                break
        return i

    def print(self):
        p = self.head
        while p is not None:
            print(p.data)
            p = p.next


class linked_list:
    def __init__(self):
        self.head = None
        self.size = 0

    def __len__(self):
        return self.size

    def __str__(self):
        s = ""
        p = self.head
        while p is not None:
            s += str(p.data) + " "
            p = p.next
        return s

    def __iter__(self):
        p = self.head
        while p is not None:
            yield p.data
            p = p.next

    def delete_from_start(self):
        if self.size == 0:
            print("List is empty")
            return
        else:
            self.head = self.head.next
            self.size -= 1

    def delete_from_end(self):
        if self.size == 0:
            print("List is empty")
            return
        else:
            p = self.head
            i = 1
            while i < len(self) - 1:
                p = p.next
                i += 1
            p.next = None
            self.size -= 1

    def insert_at_start(self, data):
        temp = Node(data)
        if self.size == 0:
            self.head = temp
        else:
            temp.next = self.head
            self.head = temp
        self.size += 1

    def insert_at_end(self, data):
        temp = Node(data)
        if self.size == 0:
            self.head = temp
        else:
            p = self.head
            while p.next is not None:
                p = p.next
            p.next = temp
        self.size += 1

    def peek(self):
        return self.head.data

    def clear(self):
        self.head = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def search(self, x):
        p = self.head
        i = None
        while p.next is not None:
            if p.next == x:
                i = p
                break
            p = p.next
        return i

    def print(self):
        p = self.head
        while p is not None:
            print(p.data)
            p = p.next
