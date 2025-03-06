class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

def removeElements(head, val):
    dummy = Node()
    dummy.next = head

    prev = dummy
    cur = head

    while cur != None:
        if cur.data == val:
            prev.next = cur.next
        else:
            prev = cur
        
        cur = prev.next

    return dummy.next


import unittest

class TestRemoveElements(unittest.TestCase):

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

    def test_remove(self):
        head = self.array_to_list([1, 2, 6, 3, 4, 5, 6])
        new_head = removeElements(head, 6)
        self.assertEqual(self.list_to_array(new_head), [1, 2, 3, 4, 5])

    def test_remove_single(self):
        head = self.array_to_list([1, 2, 3])
        new_head = removeElements(head, 2)
        self.assertEqual(self.list_to_array(new_head), [1, 3])

    def test_remove_no_match(self):
        head = self.array_to_list([1, 2, 3])
        new_head = removeElements(head, 4)
        self.assertEqual(self.list_to_array(new_head), [1, 2, 3])

    def test_remove_all(self):
        head = self.array_to_list([6, 6, 6])
        new_head = removeElements(head, 6)
        self.assertEqual(self.list_to_array(new_head), [])

    def test_empty_list(self):
        head = self.array_to_list([])
        new_head = removeElements(head, 1)
        self.assertEqual(self.list_to_array(new_head), [])

if __name__ == "__main__":
    unittest.main()

# arr = list(map(int, input().split()))
# val = int(input())
# list1 = LinkedList()

# for i in range(len(arr) - 1, -1, -1):
#     list1.append_front(arr[i])

# new_node = removeElements(list1.head, val)

# new_list = LinkedList()
# new_list.head = new_node
# new_list.print_list()