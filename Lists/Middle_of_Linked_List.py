class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

def middleNode(head):
    slow = fast = head
    while fast != None and fast.next != None:
        slow = slow.next
        fast = fast.next.next
    
    return slow


import unittest

class TestMiddleNode(unittest.TestCase):

    # для удобства проверки
    def array_to_list(self, arr):
        if not arr:
            return None
        
        head = Node(arr[0])
        current = head
        for val in arr[1:]:
            current.next = Node(val)
            current = current.next
        
        return head

    def test_middle(self):
        head = self.array_to_list([1, 2, 3, 4, 5])
        middle_node = middleNode(head)
        self.assertEqual(middle_node.data, 3)

    def test_middle_even(self):
        head = self.array_to_list([1, 2, 3, 4, 5, 6])
        middle_node = middleNode(head)
        self.assertEqual(middle_node.data, 4)

    def test_single_element(self):
        head = self.array_to_list([1])
        middle_node = middleNode(head)
        self.assertEqual(middle_node.data, 1)

    def test_empty_list(self):
        head = self.array_to_list([])
        middle_node = middleNode(head)
        self.assertIsNone(middle_node)

if __name__ == "__main__":
    unittest.main()

# arr = list(map(int, input().split()))
# list1 = LinkedList()

# for i in range(len(arr) - 1, -1, -1):
#     list1.append_front(arr[i])

# new_node = middleNode(list1.head)

# new_list = LinkedList()
# new_list.head = new_node
# new_list.print_list()