from typing import List, Tuple

class TimeMap:

    def __init__(self):

        self.ts = {}

    def set(self, key: str, value: str, timestamp: int) -> None:

        if not key in self.ts:
            self.ts[key] = [(timestamp, value)]
        else:
            self.ts[key].append((timestamp, value)) 

    def _binary_search(self, times: List[Tuple[int, str]], stamp: int) -> str:

        low, high = 0, len(times) - 1
        ans = ""

        while low <= high:

            mid = low + (high - low) // 2

            if times[mid][0] > stamp:
                high = mid - 1
            else:
                ans = times[mid][1]
                low = mid + 1

        return ans

    def get(self, key: str, timestamp: int) -> str:
        
        ts = self.ts.get(key)

        if ts is None:
            return ""

        return self._binary_search(ts, timestamp)
        
def main() -> int:


    tm = TimeMap()
    tm.set('love', 'high', 10)
    tm.set('love', 'low', 20)
    print(f"{tm.get('love', 5)}")
    print(f"{tm.get('love', 10)}")
    print(f"{tm.get('love', 15)}")
    print(f"{tm.get('love', 20)}")
    print(f"{tm.get('love', 25)}")

if __name__ == "__main__":
    main()

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)