from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:

        temps = [temperatures[0]]
        ans = [0] * len(temperatures)

        for idx in range(1, len(temperatures)):

            offset = 0
            while temperatures[idx] > temps[-1]:
                temps.pop()
                ans[idx - offset] = 1 + offset

            temps.append(temperatures[idx])

        
        #ans = [0]
        #max_temps = []
        #max_temp = -1
        #diff = 0
        #n = len(temperatures)

        #for tmp in reversed(temperatures):
        #    max_temp = max(max_temp, tmp)
        #    max_temps.append(max_temp)

        #for idx in range(n -1):

        #    if temperatures[n - 2 - idx] < temperatures[n - 1 - idx]:
        #        ans.append(1)

        #    elif temperatures[n - 2 - idx] < max_temps.pop():
        #        ans.append(-1)
        #        diff = 0
        #    else:
        #        ans.append(0)
        #        diff += 1

        #print(max_temps)
        return ans

def main() -> int:

    sl = Solution()

    temps = [73,74,75,71,69,72,76,73]
    print(f"ans 1: {sl.dailyTemperatures(temps)}")

if __name__ == "__main__":
    main()