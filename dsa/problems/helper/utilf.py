class Node:
    def __init__(self, x) -> None:
        self.val = x
        self.left = None
        self.right = None


def ListToTree(arr):
    if len(arr) == 0:
        return None
    root = Node(arr[0])
    q = [root]
    i = 1
    while i < len(arr):
        node = q.pop(0)
        if arr[i] != None:
            node.left = Node(arr[i])
            q.append(node.left)
        i += 1
        if i >= len(arr):
            break
        if arr[i] != None:
            node.right = Node(arr[i])
            q.append(node.right)
        i += 1
    return root
