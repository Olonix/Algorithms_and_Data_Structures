arr = list(map(int, input().split()))

low = mid = 0
high = len(arr) - 1

while mid <= high:
    if arr[mid] == 0:
        arr[mid], arr[low] = arr[low], arr[mid]
        mid += 1
        low += 1
    elif arr[mid] == 2:
        arr[mid], arr[high] = arr[high], arr[mid]
        high -= 1
    else:
        mid += 1

print(arr)