# реализация стэка (по факту нигде не используется, но раньше использовался в экспериментальных целях)
class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None
    
    def push(self, data):
        new_node = Node(data)

        if not self.top:
            self.top = new_node
            return

        new_node.next = self.top
        self.top = new_node

    def pop(self):
        if not self.top:
            return None
        
        top = self.top
        if self.top.next is not None:
            self.top = self.top.next
        else:
            self.top = None

        return top.data
    
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