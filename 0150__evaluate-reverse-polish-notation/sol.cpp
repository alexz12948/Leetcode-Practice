typedef long long ll;

class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        const int n = tokens.size();
        unordered_set<string> operators ({"*","+","-","/"});

        stack<ll> calc;
        for (int i = 0; i < n; i++) {
            if (operators.find(tokens[i]) != operators.end()) {
                ll first = calc.top();
                calc.pop();
                ll second = calc.top();
                calc.pop();
                switch (tokens[i][0]) {
                    case '*':
                        calc.push(second * first);
                        break;
                    case '+':
                        calc.push(second + first);
                        break;
                    case '-':
                        calc.push(second - first);
                        break;
                    default:
                        calc.push(second / first);
                }
            } else
                calc.push(stoi(tokens[i]));
        }

        return calc.top();
    }
};