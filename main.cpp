#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

//Easily tokenize using this :D
#include <sstream>
//Check if string is digit
#include <bits/stdc++.h>

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
    // Ex string: 3 + 4 * 2 or 3 4 2 * +
    stringstream ss(line);
    string s;
    Token t;

    while (getline(ss,s, ' ')) {
        t.value = s;
        tokens.push_back(t);
    }

    //Old implementation
    //int length = line.length();
    // for (int i = 1; i < length; i++) {
    //     if (line.substr(i - 1, 1) != " ") {
    //         t.value = line.substr(i - 1, 1);
    //         tokens.push_back(t);
    //     }
    // }

    //test
    // for (int i = 0; i < tokens.size(); i++) {
    //     cout << tokens[i].value << endl;
    // }

    return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}


bool isDigit(const string& s) {

    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}


/*
 *Specifies order of operations.
 *Operations wit higher precedence are evaluated before those with lower.
 *If equal, read from left to right
*/
int precedence(const string& op) {
    // TODO

    //old implementation
    // switch (op) {
    //     case "+":
    //     case "-":
    //         return 1;
    //     case "*":
    //     case "/":
    //         return 2;
    //     case "(":
    //     case ")":
    //         return 3;
    // }

    if (isOperator(op)) {
        if (op == "+" || op == "-") {
            return 1;
        }
        else if (op == "*" || op == "/") {
            return 2;
        }
    }
    else {
        return 0; //Not operator if precedence 0
    }


}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    // TODO
    //list empty
    if (tokens.empty() || tokens.size() <= 2) {
        cout << "Empty vector or only 2 elements" << endl;
        return false;
    }

    //checks first two elements are numbers
    if (!(isDigit(tokens[0].value) && isDigit(tokens[1].value))) {
        cout << "First two elements are not numbers" << endl;
        return false;
    }

    int opCount = 0;
    int numCount = 2;

    for (int i = 2; i < tokens.size(); i++) {
        if (i == tokens.size() - 1 && !isOperator(tokens[i].value)) {
            cout << "Last element is not an operator" << endl;
            return false;
        }
        else if (isDigit(tokens[i].value)) {
            numCount++;
        }
        else if (isOperator(tokens[i].value)) {
            opCount++;
        }
        else {
            //not a digit or operator
            cout << "Vector contains element that is not a digit or operator" << endl;
            return false;
        }
    }

    if (numCount - opCount == 1) {
        return true;
    }
    else {
        cout << "numCount - operatorCount is not equal to 1" << endl;
        return false;
    }
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
    // ArrayStack<int> myStack;
    // cout << "Is empty: " << myStack.empty() << endl;
    // cout << "Top element: " << myStack.top() << endl;
    // myStack.pop();
    //
    // cout << endl;
    //
    // myStack.push(10);
    // myStack.push(20);
    // cout << "Top element: " << myStack.top() << endl;
    // myStack.push(30);
    // cout << "Top element: " << myStack.top() << endl;
    // cout << "Is empty: " << myStack.empty() << endl;
    // cout << "Size: " << myStack.size() << endl;
    //
    // cout << endl;
    //
    // myStack.pop();
    // myStack.pop();
    //
    // cout << "Top element: " << myStack.top() << endl;
    //
    // myStack.pop();
    // myStack.pop();
    //
    // cout << "Top element: " << myStack.top() << endl;
    // cout << "Is empty: " << myStack.empty() << endl;
    // cout << "Size: " << myStack.size() << endl;
    //
    // cout << endl;
    //
    // myStack.push(10);
    // myStack.push(20);

    //Tokenizer test, validPostfix test
    //string toky = "3 + 4 * 2";
    string toky2 = "333 44 + - 22";

    //vector<Token> tokens = tokenize(toky);
    vector<Token> tokenz = tokenize(toky2);
    cout << endl;

    // 0 false, 1 true
    //cout << "Valid Postfix: " << isValidPostfix(tokens) << endl;
    cout << "Valid Postfix: " << isValidPostfix(tokenz) << endl;



    return 0;
}
