#include <queue>

using namespace std;

class MyStack {
public:
	queue<int>	_q;

    MyStack() {
    }

    void push(int x) {
		this->_q.emplace(x);
    }

    int pop() {
		int	retval;

		retval = this->top();
		this->_q.pop();
		return retval;
    }

    int top() {
		return this->_q.back();
    }

    bool empty() {
		return this->_q.empty();
    }
};

int main() {

    MyStack ms;

    ms.push(1);
    ms.push(2);
    ms.top();
    ms.pop();
    ms.empty();

    return 0;
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
