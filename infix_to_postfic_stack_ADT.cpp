#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> operators;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            } else {
                throw invalid_argument("Mismatched parenthesis");
            }
        } else { // Operator
            while (!operators.empty() && precedence(ch) <= precedence(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        if (operators.top() == '(' || operators.top() == ')') {
            throw invalid_argument("Mismatched parenthesis");
        }
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infix_expression;
    cout << "Enter the infix expression: ";
    getline(cin, infix_expression);

    try {
        string postfix_expression = infixToPostfix(infix_expression);
        cout << "Postfix expression: " << postfix_expression << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
