arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

len1 = len(arr1)
len2 = len(arr2)

arr1 += [0] * len2

pointer1 = len1 - 1
pointer2 = len2 - 1
pointer3 = len1 + len2 - 1

while pointer2 >= 0:
    if pointer1 >=0 and arr1[pointer1] >= arr2[pointer2]:
        arr1[pointer3] = arr1[pointer1]
        pointer1 -= 1
    else:
        arr1[pointer3] = arr2[pointer2]
        pointer2 -=1
    pointer3 -= 1

print(arr1)
# while i < len1 and j < len2:
    