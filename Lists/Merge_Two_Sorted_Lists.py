class Node:
    def __init__ (self, data=None):
        self.data = data
        self.next = None

def mergeTwoLists(head1, head2):
    cur = dummy = Node()
    while head1 and head2:
        if head1.data < head2.data:
            cur.next = head1
            cur = head1
            head1 = head1.next
        else:
            cur.next = head2
            cur = head2
            head2 = head2.next
        
    if head1 or head2:
        if head1:
            cur.next = head1
        else:
            cur.next = head2
        
    return dummy.next


import unittest

class TestMergeTwoLists(unittest.TestCase):

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

    def test_merge(self):
        head1 = self.array_to_list([1, 3, 5])
        head2 = self.array_to_list([2, 4, 6])
        merged_head = mergeTwoLists(head1, head2)
        self.assertEqual(self.list_to_array(merged_head), [1, 2, 3, 4, 5, 6])

    def test_merge_one_empty(self):
        head1 = self.array_to_list([1, 2, 3])
        head2 = self.array_to_list([])
        merged_head = mergeTwoLists(head1, head2)
        self.assertEqual(self.list_to_array(merged_head), [1, 2, 3])

    def test_merge_both_empty(self):
        head1 = self.array_to_list([])
        head2 = self.array_to_list([])
        merged_head = mergeTwoLists(head1, head2)
        self.assertEqual(self.list_to_array(merged_head), [])

    def test_merge_single_element(self):
        head1 = self.array_to_list([1])
        head2 = self.array_to_list([2])
        merged_head = mergeTwoLists(head1, head2)
        self.assertEqual(self.list_to_array(merged_head), [1, 2])

    def test_merge_same_elements(self):
        head1 = self.array_to_list([1, 2, 2])
        head2 = self.array_to_list([2, 3, 3])
        merged_head = mergeTwoLists(head1, head2)
        self.assertEqual(self.list_to_array(merged_head), [1, 2, 2, 2, 3, 3])

if __name__ == "__main__":
    unittest.main()


# arr1 = list(map(int, input().split()))
# list1 = LinkedList()

# for i in range(len(arr1) - 1, -1, -1):
#     list1.append_front(arr1[i])

# arr2 = list(map(int, input().split()))
# list2 = LinkedList()

# for i in range(len(arr2) - 1, -1, -1):
#     list2.append_front(arr2[i])

# new_node = mergeTwoLists(list1.head, list2.head)

# new_list = LinkedList()
# new_list.head = new_node
# new_list.print_list()