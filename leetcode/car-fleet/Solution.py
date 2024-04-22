from typing import List

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:

        vehicles = [(pos, sp) for pos, sp in zip(position, speed)]
        vehicles.sort(reverse=True)

        vehicle = vehicles.pop(0)
        stack = [(target - vehicle[0]) / vehicle[1]]

        for vehicle in vehicles:
            res = (target - vehicle[0]) / vehicle[1]
            if res > stack[-1]:
                stack.append(res)

        return len(stack)

        #rates = {}
        #ans = 0

        #for sp, pos in zip(speed, position):

            #res = (target - pos) / sp
            #rates[res] = 1 + rates.get(res, 0)

        #print(rates)
        #return ans

def main() -> int:

    sl = Solution()

    target = 12
    pos = [10,8,0,5,3]
    speed = [2,4,1,1,3]
    print(f"ans 1: {sl.carFleet(target, pos, speed)}")

if __name__ == "__main__":
    main()