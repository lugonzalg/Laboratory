from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:

        prefix_sum = count = 0
        sum_table = {0: 1}

        for num in nums:

            prefix_sum += num
            result = prefix_sum - k

            count += sum_table.get(result, 0)
            sum_table[prefix_sum] = 1 + sum_table.get(prefix_sum, 0)

        return count


    #    left = right = total = count = 0
    #    end = len(nums)

    #    while right < end:

    #        if total < k:
    #            total += nums[right]
    #            right += 1
    #        elif total > k:
    #            total -= nums[left]
    #            left += 1
    #        else:
    #            count += 1
    #            right += 1

    #    while total >= k and left < end:

    #        if total > k:
    #            total -= nums[left]
    #            left += 1
    #        else:
    #            count += 1
    #            total -= nums[left]
    #            left += 1

    #    return count

def main() -> int:

    sl = Solution()

    print(f"Result: {sl.subarraySum([1,1,1], 2)}")
    print(f"Result: {sl.subarraySum([1], 0)}")

if __name__ == "__main__":
    main()