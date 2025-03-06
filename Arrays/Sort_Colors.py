def sort_colors(arr):
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
    return arr


import unittest

class TestSortColors(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(sort_colors([2, 0, 2, 1, 1, 0]), [0, 0, 1, 1, 2, 2])
        self.assertEqual(sort_colors([2, 2, 2, 1, 1, 0, 0, 0]), [0, 0, 0, 1, 1, 2, 2, 2])
    
    def test_all_zeros(self):
        self.assertEqual(sort_colors([0, 0, 0]), [0, 0, 0])
    
    def test_all_ones(self):
        self.assertEqual(sort_colors([1, 1, 1]), [1, 1, 1])
    
    def test_all_twos(self):
        self.assertEqual(sort_colors([2, 2, 2]), [2, 2, 2])
    
    def test_empty(self):
        self.assertEqual(sort_colors([]), [])
    
    def test_single_element(self):
        self.assertEqual(sort_colors([0]), [0])
        self.assertEqual(sort_colors([1]), [1])
        self.assertEqual(sort_colors([2]), [2])

    def test_two_colors(self):
        self.assertEqual(sort_colors([0, 1, 0, 1, 1, 0]), [0, 0, 0, 1, 1, 1])
        self.assertEqual(sort_colors([1, 2, 1, 2, 2, 1]), [1, 1, 1, 2, 2, 2])
        self.assertEqual(sort_colors([0, 2, 0, 2, 2, 0]), [0, 0, 0, 2, 2, 2])

if __name__ == "__main__":
    unittest.main()
