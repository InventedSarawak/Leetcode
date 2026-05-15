class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # Using a monotonically decreasing deque.
        # Remove the window exiting element from the left.
        # Remove the elements till curr < right of the deque.
        # Zeroth element in deque will be largest.

        increasingDeque = deque([])
        for i in range(k):
            while increasingDeque and nums[increasingDeque[-1]] <= nums[i]:
                increasingDeque.pop()

            increasingDeque.append(i)

        slidingWindowMaximum = [nums[increasingDeque[0]]]
        for i in range(len(nums) - k):
            if increasingDeque[0] == i:
                increasingDeque.popleft()

            while increasingDeque and nums[increasingDeque[-1]] <= nums[i + k]:
                increasingDeque.pop()
            increasingDeque.append(i + k)

            slidingWindowMaximum.append(nums[increasingDeque[0]])

        return slidingWindowMaximum
            

