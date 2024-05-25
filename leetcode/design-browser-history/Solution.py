class Node:

    def __init__(self, url: str, nextNode=None, prevNode=None):

        self.url = url
        self.next = nextNode
        self.prev = prevNode

class BrowserHistory:

    def __init__(self, homepage: str):
        self.curr = Node(homepage)

    def visit(self, url: str) -> None:

        self.curr.next = Node(url=url, prevNode=self.curr)
        self.curr = self.curr.next
        
    def back(self, steps: int) -> str:

        while self.curr.prev and steps:
            steps -= 1
            self.curr = self.curr.prev

        return self.curr.url

    def forward(self, steps: int) -> str:

        while self.curr.next and steps:
            steps -= 1
            self.curr = self.curr.next

        return self.curr.url

def main() -> int:

    bh = BrowserHistory("leetcode.com");
    bh.visit("google.com")# You are in "leetcode.com". Visit "google.com"
    bh.visit("facebook.com")# You are in "leetcode.com". Visit "google.com"
    bh.visit("youtube.com")# You are in "leetcode.com". Visit "google.com"
    print(f"back: {bh.back(1)}")# You are in "youtube.com", move back to "facebook.com" return "facebook.com"
    print(f"back: {bh.back(1)}")# You are in "facebook.com", move back to "google.com" return "google.com"
    print(f"forward: {bh.forward(1)}")# You are in "google.com", move forward to "facebook.com" return "facebook.com"
    bh.visit("linkedin.com")# You are in "facebook.com". Visit "linkedin.com"
    print(f"forward: {bh.forward(7)}")# You are in "google.com", move forward to "facebook.com" return "facebook.com"
    print(f"back: {bh.back(2)}")# You are in "facebook.com", move back to "google.com" return "google.com"
    print(f"back: {bh.back(2)}")# You are in "facebook.com", move back to "google.com" return "google.com"

if __name__ == "__main__":
    main()

# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)