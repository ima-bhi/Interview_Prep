class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> stack;

        for (int a : asteroids) {
            // +ve el push on stack
            if (a > 0) {
                stack.push(a);
            } else {
                // if -ve
                // a=-5 , top=3  -- top<-a  -- pop el (while)
                while (!stack.empty() && stack.top() > 0 && stack.top() < -a) {
                    stack.pop();
                }

                // stc - {}
                if (stack.empty() || stack.top() < 0) {
                    // stk{-5}
                    stack.push(a);
                }

                if (!stack.empty() && stack.top() == -a) {
                    stack.pop();
                }
            }
        }

        std::vector<int> res(stack.size());
        int i = stack.size() - 1;
        // insert stack value on result
        while (!stack.empty()) {
            res[i--] = stack.top();
            stack.pop();
        }

        return res;        
    }
};