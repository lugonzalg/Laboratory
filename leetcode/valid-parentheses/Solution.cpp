#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
            for (auto c: s) {
                switch (c) {
                    case '(':
                        st.push(c);
                        break ;
                    case '[':
                        st.push(c);
                        break ;
                    case '{':
                        st.push(c);
                        break ;
                    case ')':
                        if (st.top() != '(')
                            return false;
                        st.pop();
                        break ;
                    case ']':
                        if (st.top() != '[')
                            return false;
                        st.pop();
                        break ;
                    case '}':
                        if (st.top() != '{')
                            return false;
                        st.pop();
                        break ;
                }
            }
        if (st.size())
            return false;
        return true;
    }
};

int main() {
	Solution sl;

	sl.isValid("()");

	return 0;
}

