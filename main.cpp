#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

//Easily tokenize using this :D
#include <sstream>
//Check if string is digit
#include <cctype>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
};


//Helper
bool isDigit(const string& s) {

    if (s.empty()) {
        return false;
    }

    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}


bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    // TODO
    // Ex string: 3 + 4 * 2 or 3 4 2 * +
    //stringstream ss(line);
    //string s;
    Token t;
    int i = 0;

    while (i < line.size()) {
        if (line[i] == ' ') {
            i++;
        }
        else if (isdigit(line[i])) {
            string num = "";

            while ( i < line.size() && isdigit(line[i])) {
                num+= line[i];
                i++;
            }
            t.value = num;
            tokens.push_back(t);

        }
        else {
            t.value = line[i];
            tokens.push_back(t);
            i++;
        }
    }


    // while (getline(ss,s, ' ')) {
    //     t.value = s;
    //     tokens.push_back(t);
    //     // if (isDigit(s) || isOperator(s) || s == ")" || s == "(") {
    //     //     tokens.push_back(t);
    //     // }
    // }

    //Old implementation
    //int length = line.length();
    // for (int i = 1; i < length; i++) {
    //     if (line.substr(i - 1, 1) != " ") {
    //         t.value = line.substr(i - 1, 1);
    //         tokens.push_back(t);
    //     }
    // }

    //test
    for (int i = 0; i < tokens.size(); i++) {
        cout << tokens[i].value << endl;
    }

    return tokens;
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

    return 0; //Not operator if precedence 0


}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    // TODO
    //list empty
    if (tokens.empty() || tokens.size() <= 2) {
        //cout << "Empty vector or only 2 elements" << endl;
        return false;
    }

    //checks first two elements are numbers
    if (!(isDigit(tokens[0].value) && isDigit(tokens[1].value))) {
        //cout << "First two elements are not numbers" << endl;
        return false;
    }

    int opCount = 0;
    int numCount = 2;

    for (int i = 2; i < tokens.size(); i++) {
        if (!isDigit(tokens[i].value) && !isOperator(tokens[i].value) && tokens[i].value != ")"  && tokens[i].value != "(") {
           // cout << "Can only contain num or op or parenthesis" << endl;
            return false;
        }


        if (i == tokens.size() - 1 && !isOperator(tokens[i].value)) {
            //cout << "Last element is not an operator" << endl;
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
            //cout << "Vector contains element that is not a digit or operator" << endl;
            return false;
        }
    }

    if (numCount - opCount == 1) {
        return true;
    }
    else {
        //cout << "numCount - operatorCount is not equal to 1" << endl;
        return false;
    }
}

bool isValidInfix(const vector<Token>& tokens) {
    // TODO
    //Parentheses balance counter
    int bracketcount = 0;

    //checks
    bool operatorExpected = false;
    //bool numExpected = true;


    if (tokens.empty() || tokens.size() <= 2) {
        //cout << "List empty / Less than 2" << endl;
        return false;
    }

    if (isOperator(tokens[0].value)) {
        //cout << "Infix cannot start with an operator" << endl;
        return false;
    }

    for (int i = 0; i < tokens.size(); i++) {
        if (!isDigit(tokens[i].value) && !isOperator(tokens[i].value) && tokens[i].value != ")"  && tokens[i].value != "(") {
            //cout << "Can only contain num or op or parenthesis" << endl;
            return false;
        }


        if (tokens[i].value == "(") {
            bracketcount++;
            operatorExpected = false;
        }
        else if (tokens[i].value == ")") {
            //num expected
            if (operatorExpected == false) {
                //cout << "num expected not )" << endl;
                return false;
            }


            //no opening bracket exist to pair closing bracket
            if (bracketcount == 0) {
                //cout << "no ( to pair ) with." << endl;
                return false;
            }

            bracketcount--;
            //operatorExpected = false;
        }
        else if (isDigit(tokens[i].value) && !operatorExpected) {
            operatorExpected = true;
        }
        else if (isDigit(tokens[i].value) && operatorExpected) {
            // token[i - 1] shouldn't cause an issue cause operatorExpected can't be true for the first value
            if (tokens[i - 1].value == ")") {
                continue;
            }
            else {
                //back to back numbers
                //cout << "Number not expected, index: " << i <<  endl;
                return false;
            }
        }
        else if (isOperator(tokens[i].value) && operatorExpected) {
            operatorExpected = false;
        }
        else if (isOperator(tokens[i].value) && !operatorExpected) {
            //cout << "Operator not expected" << endl;
            return false;
        }
    }

    if (bracketcount != 0) {
        //cout << "Brackets not balanced" << endl;
        return false;
    }

    if (!operatorExpected) {
        //ends on operator
        return false;
    }

    return true;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    // TODO



    ArrayStack<string> stack;
    string postfix = "";

    for (int i = 0; i < tokens.size(); i++) {
        if (isDigit(tokens[i].value)) {
            postfix = postfix + tokens[i].value + " ";
        }
        else if (tokens[i].value == "(") {
            //push ( to stack
            if (i != 0 && isDigit(tokens[i - 1].value)) {
                stack.push("*");
            }
            else {
                stack.push(tokens[i].value);
            }
        }
        else if (tokens[i].value == ")") {
            while (!stack.empty() && stack.top() != "(") {
                postfix = postfix + stack.top() + " ";
                stack.pop();
            }
            stack.pop();
            if (i != tokens.size() - 1  && isDigit(tokens[i + 1].value)) {
                stack.push("*");
            }
        }
        else {
            //if operator
            while (!stack.empty() && stack.top() != "(" && (precedence(stack.top()) > precedence(tokens[i].value)
                || precedence(stack.top()) == precedence(tokens[i].value))) {
                postfix = postfix + stack.top() + " ";
                stack.pop();
            }
            stack.push(tokens[i].value);
        }
    }

    while (!stack.empty()) {
        if (stack.size() == 1) {
            postfix = postfix + stack.top();
        }
        else {
            postfix = postfix + stack.top() + " ";
        }
        stack.pop();
    }

    //cout << postfix << endl;

    output = tokenize(postfix);

    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    // TODO
    for (int i = 0; i < tokens.size(); i++) {

        if (isDigit(tokens[i].value)) {
            //string to num
            double num;
            stringstream(tokens[i].value) >> num;

            //push num to stack
            stack.push(num);
        }
        else {
            double operand2 = stack.top();
            stack.pop();
            double operand1 = stack.top();
            stack.pop();

            if (tokens[i].value == "+") {
                stack.push(operand1 + operand2);
            }
            else if (tokens[i].value == "-") {
                stack.push(operand1 - operand2);
            }
            else if (tokens[i].value == "*") {
                stack.push(operand1 * operand2);
            }
            else if (tokens[i].value == "/") {
                stack.push(operand1 / operand2);
            }
        }
    }

    return stack.top();
}

// Main

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }


    /*
     * Incorrect Results
     *3 - 2 * ( 4 + 2 ) Result 9 supposed to be -9 fixed
     *2 - 4 Result 2 supposed to be -2 fixed
     *(3 + 4) fixed
     *3 +  4 fixed
     *(3)(3) + 2
     *3 + 4 + fixed
     */

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
    //make sure string is correctly formated with the spaces, " 3 + 4" will not tokenize correctly
    //string toky = "( 4 + 2 ) * 3 + 2";
    //string toky2 = "+ + +";

    //vector<Token> tokens = tokenize(toky);
    //vector<Token> tokenz = tokenize(toky2);
    //cout << endl;

    // 0 false, 1 true
    //cout << "Valid Infix: " << isValidInfix(tokens) << endl;
    //cout << "Valid Postfix: " << isValidPostfix(tokenz) << endl;

    /*
     * Incorrect Infix result
     * ( 3 + ) + 4 falsely returns true, fixed
     * ( 3 + 4 ) 4 falsely returns false, fixed
     * ( 3 + 4 ) ) ( + 4 falsely returns true, fixed
     * 3 + 4 ( ) empty parenthesis, falsely returns true fixed
     * 3 ( ) + 4 falsely returns true, fixed
     */



    /*
     *Incorrect postfix to infix result
     *  ( 3 + 2 ) + 5 * 2"
     *  ( 3 + 2 )
     */


    //vector<Token> newTok = infixToPostfix(tokens);

    //cout << "Valid Postfix: " << isValidPostfix(newTok) << endl;
    //cout << "RESULT: " << evalPostfix(newTok) << endl;
    return 0;
}
