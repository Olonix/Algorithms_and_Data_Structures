from MyLinkedList import LinkedList

def middleNode(head):
    slow = fast = head
    while fast != None and fast.next != None:
        slow = slow.next
        fast = fast.next.next
    
    return slow

arr = list(map(int, input().split()))
list1 = LinkedList()

for i in range(len(arr) - 1, -1, -1):
    list1.append_front(arr[i])

new_node = middleNode(list1.head)

new_list = LinkedList()
new_list.head = new_node
new_list.print_list()