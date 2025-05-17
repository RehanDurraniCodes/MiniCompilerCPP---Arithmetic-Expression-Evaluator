// MiniCompilerCPP - Arithmetic Expression Evaluator
// Supports +, -, *, / and parentheses
#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <map>
#include <cmath>

using namespace std;

int precedence(char op) {
    if(op == '+'|| op == '-') return 1;
    if(op == '*'|| op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infixToPostfix(const string& expr) {
    stack<char> opStack;
    stringstream output;

    for (size_t i = 0; i < expr.size(); ++i) {
        char token = expr[i];

        if (isspace(token)) continue;

        if (isdigit(token)) {
            while (i < expr.size() && (isdigit(expr[i]) || expr[i] == '.')) {
                output << expr[i++];
            }
            output << ' ';
            --i;
        } else if (token == '(') {
            opStack.push(token);
        } else if (token == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                output << opStack.top() << ' ';
                opStack.pop();
            }
            opStack.pop(); // pop '('
        } else if (isOperator(token)) {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(token)) {
                output << opStack.top() << ' ';
                opStack.pop();
            }
            opStack.push(token);
        }
    }

    while (!opStack.empty()) {
        output << opStack.top() << ' ';
        opStack.pop();
    }

    return output.str();
}

double evaluatePostfix(const string& postfix) {
    stack<double> valueStack;
    stringstream tokens(postfix);
    string token;

    while (tokens >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            valueStack.push(stod(token));
        } else if (token.size() == 1 && isOperator(token[0])) {
            double b = valueStack.top(); valueStack.pop();
            double a = valueStack.top(); valueStack.pop();
            switch (token[0]) {
                case '+': valueStack.push(a + b); break;
                case '-': valueStack.push(a - b); break;
                case '*': valueStack.push(a * b); break;
                case '/': valueStack.push(a / b); break;
            }
        }
    }

    return valueStack.top();
}

int main() {
    string expression;
    cout << "Enter arithmetic expression: ";
    getline(cin, expression);

    string postfix = infixToPostfix(expression);
    cout << "Postfix: " << postfix << endl;

    double result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
