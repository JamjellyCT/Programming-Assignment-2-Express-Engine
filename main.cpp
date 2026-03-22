#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    // TODO
    return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    // TODO
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    // TODO
    return false;
}

bool isValidInfix(const vector<Token>& tokens) {
    // TODO
    return false;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    // TODO
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    // TODO
    return 0.0;
}

// Main

int main() {
    // string line;
    // getline(cin, line);
    //
    // vector<Token> tokens = tokenize(line);
    //
    // if (isValidPostfix(tokens)) {
    //     cout << "FORMAT: POSTFIX\n";
    //     cout << "RESULT: " << evalPostfix(tokens) << "\n";
    // }
    // else if (isValidInfix(tokens)) {
    //     vector<Token> postfix = infixToPostfix(tokens);
    //     cout << "FORMAT: INFIX\n";
    //     cout << "POSTFIX: ";
    //     for (const auto& t : postfix) {
    //         cout << t.value << " ";
    //     }
    //     cout << "\n";
    //     cout << "RESULT: " << evalPostfix(postfix) << "\n";
    // }
    // else {
    //     cout << "FORMAT: NEITHER\n";
    //     cout << "ERROR: invalid expression\n";
    // }


    //Manual Test
    ArrayStack<int> myStack;
    cout << "Is empty: " << myStack.empty() << endl;
    cout << "Top element: " << myStack.top() << endl;
    myStack.pop();

    cout << endl;

    myStack.push(10);
    myStack.push(20);
    cout << "Top element: " << myStack.top() << endl;
    myStack.push(30);
    cout << "Top element: " << myStack.top() << endl;
    cout << "Is empty: " << myStack.empty() << endl;
    cout << "Size: " << myStack.size() << endl;

    cout << endl;

    myStack.pop();
    myStack.pop();

    cout << "Top element: " << myStack.top() << endl;

    myStack.pop();
    myStack.pop();

    cout << "Top element: " << myStack.top() << endl;
    cout << "Is empty: " << myStack.empty() << endl;
    cout << "Size: " << myStack.size() << endl;

    cout << endl;

    myStack.push(10);
    myStack.push(20);


    return 0;
}
