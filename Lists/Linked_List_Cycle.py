from MyLinkedList import LinkedList

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

arr = list(map(int, input().split()))
pos = int(input())

# создаем цикличный список
list1 = LinkedList()
last_node = None

for i in range(len(arr) - 1, -1, -1):
    list1.append_front(arr[i])

    if last_node is None:
        last_node = list1.head

    if i == pos:
        last_node.next = list1.head

isCycled = hasCycle(list1.head)
print(isCycled)

if isCycled:
    list1.print_cycle_list()
else:
    list1.print_list()