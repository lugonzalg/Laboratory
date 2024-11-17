from typing import List

def maxOperations(nums: List[int], k: int) -> int:
    
    num_map = {}
    res = 0

    for num in sorted(nums):

        search_num = k - num
        if num_map.get(search_num, 0):
            num_map[search_num] -= 1
            res += 1
        elif num in num_map:
            num_map[num] += 1
        else:
            num_map[num] = 1
    return res

maxOperations([2,5,4,4,1,3,4,4,1,4,4,1,2,1,2,2,3,2,4,2], 3)