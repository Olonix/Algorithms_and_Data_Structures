def two_sum(arr, target):
    if arr == []:
        return None
    
    i = 0
    j = len(arr) - 1

    while i != j:
        target_sum = arr[i] + arr[j]

        if target_sum == target: 
            return i, j
        elif target_sum < target:
            i += 1
        else:
            j -= 1

    return None


import unittest

class TestTwoSum(unittest.TestCase):
    def test_found(self):
        self.assertEqual(two_sum([1, 2, 3, 4, 6], 6), (1, 3))
        self.assertEqual(two_sum([2, 7, 11, 15], 9), (0, 1))
        self.assertEqual(two_sum([1, 3, 4, 5, 5, 10], 11), (0, 5))

    def test_not_found(self):
        self.assertIsNone(two_sum([1, 2, 3, 4, 5], 10))
        self.assertIsNone(two_sum([], 5))
        self.assertIsNone(two_sum([1], 1))

    def test_many_cases(self):
        self.assertIn(two_sum([-3, -1, 0, 2, 4], 1), [(0, 4), (1, 3)])
        self.assertIn(two_sum([0, 0, 0, 0], 0), [(0, 1), (0, 2), (0, 3), (1, 2), (1, 3), (2, 3)])

if __name__ == "__main__":
    unittest.main()