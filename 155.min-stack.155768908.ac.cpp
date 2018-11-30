/*
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (33.27%)
 * Total Accepted:    222.8K
 * Total Submissions: 669.8K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */
#define MAX 10000
class MinStack {
public:
	int stack[MAX];
	int minstack[MAX];
	int stacktop = -1;
	int mintop = -1;
	int min = INT_MAX;

	/** initialize your data structure here. */
	MinStack() {
        
		int stacktop = -1;
		int mintop = -1;
	}

	void push(int x) {
        
		if (stacktop < (MAX -1))
		{
			
			stack[++stacktop] = x;

			if (x < min)
			{
				minstack[++mintop] = x;
				min = x;
			}
			else
			{
				minstack[++mintop] = min;
			}
		}

	}

	void pop() {

		if (stacktop > -1)
		{
			stacktop--;
			mintop--;
            if(stacktop == -1)
            {
                min = INT_MAX;
            }
            else
            {
                min = minstack[mintop];
            }
            
		}

	}

	int top() {
		if (stacktop > -1)
		{
            return stack[stacktop];
		
		}

	}

	int getMin() {

		if (mintop > -1)
		{
			return minstack[mintop];

		}

	}
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
