from MyLinkedList import *

def mergeTwoLists(head1, head2):
    cur = dummy = Node()
    while head1 and head2:               
        if head1.data < head2.data:
            cur.next = head1
            head1, cur = head1.next, head1
        else:
            cur.next = head2
            head2, cur = head2.next, head2
            
    if head1 or head2:
        cur.next = head1 if head1 else head2
        
    return dummy.next

arr1 = list(map(int, input().split()))
list1 = LinkedList()

for i in range(len(arr1) - 1, -1, -1):
    list1.append_front(arr1[i])

arr2 = list(map(int, input().split()))
list2 = LinkedList()

for i in range(len(arr2) - 1, -1, -1):
    list2.append_front(arr2[i])

new_node = mergeTwoLists(list1.head, list2.head)

new_list = LinkedList()
new_list.head = new_node
new_list.print_list()