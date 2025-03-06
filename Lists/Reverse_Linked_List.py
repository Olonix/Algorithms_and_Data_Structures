from MyLinkedList import LinkedList

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

arr = list(map(int, input().split()))
list1 = LinkedList()

for i in range(len(arr) - 1, -1, -1):
    list1.append_front(arr[i])

new_node = reverseLinkedList(list1.head)

new_list = LinkedList()
new_list.head = new_node
new_list.print_list()