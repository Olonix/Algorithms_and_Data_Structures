arr = list(map(int, input().split()))

i = 0
len_arr = len(arr)

for j in range(len_arr):
    if arr[j] % 2 == 0:
        arr[i], arr[j] = arr[j], arr[i]
        i += 1

print(arr)