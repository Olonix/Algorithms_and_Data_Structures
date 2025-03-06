from MyLinkedList import *

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

arr = list(map(int, input().split()))
val = int(input())
list1 = LinkedList()

for i in range(len(arr) - 1, -1, -1):
    list1.append_front(arr[i])

new_node = removeElements(list1.head, val)

new_list = LinkedList()
new_list.head = new_node
new_list.print_list()