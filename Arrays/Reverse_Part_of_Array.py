def reverse_part_of_array(arr, left, right):
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1

def rotate_array(arr, k):
    n = len(arr)
    if n == 0:
        return arr
    k = k % n
    reverse_part_of_array(arr, 0, n - k - 1)
    reverse_part_of_array(arr, n - k, n - 1)
    reverse_part_of_array(arr, 0, n - 1)
    return arr


import unittest

class TestRotateArray(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(rotate_array([1, 2, 3, 4, 5], 2), [4, 5, 1, 2, 3])
        self.assertEqual(rotate_array([10, 20, 30, 40], 1), [40, 10, 20, 30])
    
    def test_empty(self):
        self.assertEqual(rotate_array([], 3), [])
    
    def test_single_element(self):
        self.assertEqual(rotate_array([42], 3), [42])
    
    def test_large_rotation(self):
        self.assertEqual(rotate_array([1, 2, 3], 6), [1, 2, 3])
        self.assertEqual(rotate_array([1, 2, 3], 73), [3, 1, 2])

if __name__ == "__main__":
    unittest.main()