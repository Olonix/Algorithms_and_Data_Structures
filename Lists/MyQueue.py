class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None
        self.prev = None

class Queue:
    def __init__(self):
        self.head = Node()
        self.tail = Node()

        self.head.next = self.tail
        self.tail.prev = self.head

        self.size = 0

    def push(self, value):
        new_node = Node(value)
        new_node.next = self.head.next
        new_node.prev = self.head
     
        self.head.next.prev = new_node

        self.head.next = new_node
        self.size += 1

    def pop(self):
        if self.head.next == self.tail:
            return None

        pop_result = self.tail.prev
        self.tail.prev = pop_result.prev

        pop_result.prev.next = pop_result.next
        pop_result.next = None
        pop_result.prev = None

        self.size -= 1
        return pop_result.data

    
    # для отладаки
    def print_list(self):
        cur_node = self.top
        output = ""

        while cur_node is not None:
            output += str(cur_node.data)

            if cur_node.next:
                output += " -> "
            cur_node = cur_node.next

        print(output)