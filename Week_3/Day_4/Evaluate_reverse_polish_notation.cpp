class Solution {
public:
    bool isOperand(string s) {
        if (!(s == "+" || s == "-" || s == "*" || s == "/")) return true;
        else return false;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string s : tokens) {
            if (isOperand(s)) {
                st.push(stoi(s));
            } else {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                if (s == "+") st.push(num2 + num1);
                else if (s == "-") st.push(num2 - num1);
                else if (s == "*") st.push(num2 * num1);
                else st.push(num2 / num1);
            }
        }

        return st.top();
    }
};
