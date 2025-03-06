def reverseArray(arr, left, right):
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1

arr = list(map(int, input().split()))
n = len(arr)
k = int(input()) % n

reverseArray(arr, 0, n - k - 1)
reverseArray(arr, n - k, n - 1)
reverseArray(arr, 0, n - 1)

print(arr)