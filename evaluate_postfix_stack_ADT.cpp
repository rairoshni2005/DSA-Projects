#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

double evaluatePostfix(const string& postfix) {
    stack<double> operands;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            operands.push(ch - '0'); // Convert character digit to integer and push onto stack
        } else if (isOperator(ch)) {
            if (operands.size() < 2) {
                throw invalid_argument("Invalid postfix expression");
            }
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();

            switch (ch) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        throw invalid_argument("Division by zero");
                    }
                    operands.push(operand1 / operand2);
                    break;
            }
        }
    }

    if (operands.size() != 1) {
        throw invalid_argument("Invalid postfix expression");
    }

    return operands.top();
}

int main() {
    string postfix_expression;
    cout << "Enter the postfix expression: ";
    getline(cin, postfix_expression);

    try {
        double result = evaluatePostfix(postfix_expression);
        cout << "Result: " << result << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
