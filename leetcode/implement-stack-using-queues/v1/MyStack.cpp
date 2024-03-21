//-> https://leetcode.com/problems/implement-stack-using-queues/solutions/3969470/99-74-one-queue-approach/

#include <queue>

using namespace std;

class MyStack {
public:
	queue<int>	_q;

    MyStack() {
    }

    void push(int x) {
      this->_q.push(x);
      for (size_t i = 0; i < this->_q.size() - 1; ++i) {
          this->_q.push(this->_q.front());
          this->_q.pop();
        }
    }

    int pop() {
      int	retval;

      retval = this->top();
      this->_q.pop();
		return retval;
    }

    int top() {
		return this->_q.front();
    }

    bool empty() {
		return this->_q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

