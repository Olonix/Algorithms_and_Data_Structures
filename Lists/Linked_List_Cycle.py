class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

def hasCycle(head):
    if head == None or head.next == None:
        return False

    slow = head
    fast = head.next
    while slow != fast:
        if fast == None or fast.next == None:
            return False
        slow = slow.next
        fast = fast.next.next

    return True


import unittest

class TestLinkedListCycle(unittest.TestCase):

    def test_cycle(self):
        # 1 -> 2 -> 3 -> 4 -> 2
        node1 = Node(1)
        node2 = Node(2)
        node3 = Node(3)
        node4 = Node(4)
        
        node1.next = node2
        node2.next = node3
        node3.next = node4
        node4.next = node2

        self.assertTrue(hasCycle(node1))

    def test_no_cycle(self):
        # 1 -> 2 -> 3 -> 4
        node1 = Node(1)
        node2 = Node(2)
        node3 = Node(3)
        node4 = Node(4)
        
        node1.next = node2
        node2.next = node3
        node3.next = node4
        
        self.assertFalse(hasCycle(node1))

    def test_single_node_no_cycle(self):
        # 1
        node1 = Node(1)
        self.assertFalse(hasCycle(node1))

    def test_single_node_with_cycle(self):
        # 1 -> 1 (цикл)
        node1 = Node(1)
        node1.next = node1
        
        self.assertTrue(hasCycle(node1))

    def test_empty_list(self):
        # Пустой список
        self.assertFalse(hasCycle(None))


if __name__ == "__main__":
    unittest.main()



# arr = list(map(int, input().split()))
# pos = int(input())

# # создаем цикличный список
# list1 = LinkedList()
# last_node = None

# for i in range(len(arr) - 1, -1, -1):
#     list1.append_front(arr[i])

#     if last_node is None:
#         last_node = list1.head

#     if i == pos:
#         last_node.next = list1.head

# isCycled = hasCycle(list1.head)
# print(isCycled)

# if isCycled:
#     list1.print_cycle_list()
# else:
#     list1.print_list()