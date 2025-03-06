def merge_sorted_arrays(arr1, arr2):
    len1 = len(arr1)
    len2 = len(arr2)
    arr1 += [0] * len2
    
    pointer1 = len1 - 1
    pointer2 = len2 - 1
    pointer3 = len1 + len2 - 1
    
    while pointer2 >= 0:
        if pointer1 >= 0 and arr1[pointer1] >= arr2[pointer2]:
            arr1[pointer3] = arr1[pointer1]
            pointer1 -= 1
        else:
            arr1[pointer3] = arr2[pointer2]
            pointer2 -= 1
        pointer3 -= 1
    
    return arr1


import unittest

class TestMergeSortedArrays(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(merge_sorted_arrays([1, 3, 5], [2, 4, 6]), [1, 2, 3, 4, 5, 6])
        self.assertEqual(merge_sorted_arrays([1, 2, 3], [4, 5, 6]), [1, 2, 3, 4, 5, 6])
        self.assertEqual(merge_sorted_arrays([4, 5, 6], [1, 2, 3]), [1, 2, 3, 4, 5, 6])
    
    def test_empty(self):
        self.assertEqual(merge_sorted_arrays([], [1, 2, 3]), [1, 2, 3])
        self.assertEqual(merge_sorted_arrays([1, 2, 3], []), [1, 2, 3])
        self.assertEqual(merge_sorted_arrays([], []), [])
    
    def test_duplicates(self):
        self.assertEqual(merge_sorted_arrays([1, 2, 2], [2, 3, 3]), [1, 2, 2, 2, 3, 3])
        self.assertEqual(merge_sorted_arrays([1, 1, 1], [1, 1, 1]), [1, 1, 1, 1, 1, 1])
    
    # def test_large_numbers(self):
    #     self.assertEqual(merge_sorted_arrays([1000, 2000, 3000], [1500, 2500, 3500]), [1000, 1500, 2000, 2500, 3000, 3500])

if __name__ == "__main__":
    unittest.main()
