class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

def reverseLinkedList(head):
    if head == None or head.next == None:
        return head
    
    prev = None
    current = head

    while current != None:
        next = current.next
        current.next = prev
        prev = current
        current = next

    head = prev
    return head


import unittest

class TestReverseLinkedList(unittest.TestCase):

    # две функции для удобства проверки
    def list_to_array(self, head):
        result = []
        while head:
            result.append(head.data)
            head = head.next

        return result

    def array_to_list(self, arr):
        if not arr:
            return None
        
        head = Node(arr[0])
        current = head
        for val in arr[1:]:
            current.next = Node(val)
            current = current.next
        
        return head

    def test_reverse(self):
        head = self.array_to_list([1, 2, 3, 4, 5])
        reversed_head = reverseLinkedList(head)
        self.assertEqual(self.list_to_array(reversed_head), [5, 4, 3, 2, 1])

    def test_single_element(self):
        head = self.array_to_list([1])
        reversed_head = reverseLinkedList(head)
        self.assertEqual(self.list_to_array(reversed_head), [1])

    def test_empty_list(self):
        head = self.array_to_list([])
        reversed_head = reverseLinkedList(head)
        self.assertEqual(self.list_to_array(reversed_head), [])

    def test_two_elements(self):
        head = self.array_to_list([1, 2])
        reversed_head = reverseLinkedList(head)
        self.assertEqual(self.list_to_array(reversed_head), [2, 1])

    def test_three_elements(self):
        head = self.array_to_list([1, 2, 3])
        reversed_head = reverseLinkedList(head)
        self.assertEqual(self.list_to_array(reversed_head), [3, 2, 1])

if __name__ == "__main__":
    unittest.main()

# arr = list(map(int, input().split()))
# list1 = LinkedList()

# for i in range(len(arr) - 1, -1, -1):
#     list1.append_front(arr[i])

# new_node = reverseLinkedList(list1.head)

# new_list = LinkedList()
# new_list.head = new_node
# new_list.print_list()