arr = list(map(int, input().split()))
target = int(input())

i = 0
j = len(arr) - 1

while i != j:
    target_sum = arr[i] + arr[j]

    if target_sum == target: 
        break
    elif target_sum < target:
        i += 1
    else:
        j -= 1

if i != j:
    print(i, j)
else:
    print('Не нашел')