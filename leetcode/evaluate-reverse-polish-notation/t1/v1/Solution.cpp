class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>  stck;
        int val1, val2;
        for (auto elem: tokens) {
            switch(elem[0]) {
                case '-': {
                    if (elem.size() != 1) {
                        stck.push(atoi(elem.c_str()));
                        break ;
                    }
                    val1 = stck.top();
                    stck.pop();
                    val2 = stck.top();
                    stck.pop();
                    stck.push(val2 - val1);
                    break ;
                }
                case '+': {
                    val1 = stck.top();
                    stck.pop();
                    val2 = stck.top();
                    stck.pop();
                    stck.push(val2 + val1);
                    break ;
                }
                case '/': {
                    val1 = stck.top();
                    stck.pop();
                    val2 = stck.top();
                    stck.pop();
                    stck.push(val2 / val1);
                    break ;
                }
                case '*': {
                    val1 = stck.top();
                    stck.pop();
                    val2 = stck.top();
                    stck.pop();
                    stck.push(val2 * val1);
                    break ;
                }
                default: {
                    stck.push(atoi(elem.c_str()));
                }
            }
        }
        return stck.top();
    }
};

int main() {}
