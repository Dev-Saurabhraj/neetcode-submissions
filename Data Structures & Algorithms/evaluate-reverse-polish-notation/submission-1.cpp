class Solution {

    int operation(int a, int b, char op){
        switch(op){
            case '-':
                return a-b;
                break;
            case '+':
                return a+b;
                break;
            case '*':
                return a*b;
                break;
            case '/':
                return a/b;
                break;
            default : 
                return 0;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string c : tokens){
            if(isdigit(c[0]) || (c[0] == '-' && c.size() > 1)){
            int k = stoi(c);
            st.push(k);
            }else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(operation(b, a, c[0]));
            }
            


        }
            return st.top();
    }
};
