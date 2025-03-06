class Node:
    def __init__ (self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
  
    def append_front(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return

        new_node.next = self.head
        self.head = new_node

    def append_back(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return

        cur_node = self.head
        while cur_node.next is not None:
            cur_node = cur_node.next
        cur_node.next = new_node

    def print_list(self):
        cur_node = self.head
        output = ""

        while cur_node is not None:
            output += str(cur_node.data)

            if cur_node.next:
                output += " -> "
            cur_node = cur_node.next

        print(output)

    def print_cycle_list(self):
        cur_node = self.head
        output = ""
        visited = set()

        while cur_node is not None:

            if cur_node in visited:
                output += str(cur_node.data)
                output += " (цикл обнаружен!)"
                break

            visited.add(cur_node)
            output += str(cur_node.data)

            if cur_node.next:
                output += " -> "
            cur_node = cur_node.next

        print(output)