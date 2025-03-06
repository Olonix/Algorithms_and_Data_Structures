def even_first(arr):
    i = 0
    len_arr = len(arr)
    for j in range(len_arr):
        if arr[j] % 2 == 0:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    return arr


import unittest

class TestEvenFirst(unittest.TestCase):
    def test_basic(self):
        self.assertIn(even_first([3, 1, 2, 4, 7, 6]), ([2, 4, 6, 3, 1, 7], [2, 4, 6, 1, 3, 7], [2, 4, 6, 3, 7, 1], [2, 4, 6, 1, 7, 3], [2, 4, 6, 7, 1, 3], [2, 4, 6, 7, 3, 1]))
        self.assertIn(even_first([1, 2, 3, 4, 5, 6]), ([2, 4, 6, 1, 3, 5], [2, 4, 6, 1, 5, 3], [2, 4, 6, 3, 1, 5], [2, 4, 6, 3, 5, 1], [2, 4, 6, 5, 3, 1], [2, 4, 6, 5, 1, 3]))
        self.assertIn(even_first([4, 3, 2, 1]), ([4, 2, 3, 1], [4, 2, 1, 3]))
    
    def test_empty(self):
        self.assertEqual(even_first([]), [])
    
    def test_single_element(self):
        self.assertEqual(even_first([2]), [2])
        self.assertEqual(even_first([1]), [1])
    
    def test_only_evens_or_odds(self):
        self.assertEqual(even_first([2, 4, 6]), [2, 4, 6])
        self.assertEqual(even_first([1, 7, 3]), [1, 7, 3])

if __name__ == "__main__":
    unittest.main()