class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> eval; 

        for (const string &token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = eval.top();
                eval.pop();
                int left = eval.top();
                eval.pop();
                int val;

                if (token == "+") {
                    val = left + right;    
                } else if (token == "-") {
                    val = left - right;
                } else if (token == "*") {
                    val = left * right;
                } else if (token == "/") {
                    val = left / right;
                }

                eval.push(val);
            
            } else eval.push(stoi(token)); 
        }

        return eval.top();
    }
};