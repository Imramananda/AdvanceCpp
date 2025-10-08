//
//  main.cpp
//  28_SI_Intrepreter_DP
//
//  Created by Sathya Babu on 28/05/24.
//

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
// House keeping work Phase I

class Expression {
public:
    virtual int interpret() = 0;

};


// Terminal / Literal expression
class Number : public Expression {
public:
    Number(int value) : value_(value) {}

    int interpret() override {
        return value_;
    }
private:
    int value_;
};

// NonTerminal expression ( + / * - )
class Add : public Expression {
public:

    Add(Expression* left, Expression* right)
        : left_(left), right_(right) {}

    int interpret() override {
        return left_->interpret() + right_->interpret();
    }


private:
    Expression* left_;
    Expression* right_;

};
// NonTerminal expression ( + / * - )
class Subtract : public Expression {
public:

    Subtract(Expression* left, Expression* right)
        : left_(left), right_(right) {}

    int interpret() override {
        return left_->interpret() - right_->interpret();
    }


private:
    Expression* left_;
    Expression* right_;

};
// NonTerminal expression ( + / * - )
class Multiply : public Expression {
public:

    Multiply(Expression* left, Expression* right)
        : left_(left), right_(right) {}

    int interpret() override {
        return left_->interpret() * right_->interpret();
    }


private:
    Expression* left_;
    Expression* right_;

};

class Divide : public Expression {
public:

    Divide(Expression* left, Expression* right)
        : left_(left), right_(right) {}

    int interpret() override {
        return left_->interpret() / right_->interpret();
    }


private:
    Expression* left_;
    Expression* right_;

};

// House keeping Phase II

Expression* add(Expression* left, Expression* right) { return  new Add(left, right); }
Expression* mul(Expression* left, Expression* right) { return  new Multiply(left, right); }
Expression* divide(Expression* left, Expression* right) { return  new Divide(left, right); }
Expression* sub(Expression* left, Expression* right) { return  new Subtract(left, right); }

class Calculator {
public:

    Calculator() {
        operators_["+"] = &add;
        operators_["*"] = &mul;
        operators_["-"] = &sub;
        operators_["/"] = &divide;
    }

    // parse the data ..
    // check for the token 2 3 4  * -
    // integral   0  Push the data on to stack
    // NonIntegral  1( * - )  pop the data from the stack..
    //  store the prod 12 in stack
    //

     //  Our core interpreter...

    Expression* parse(const std::string& expression) {
        std::stack< Expression* > stack;

        std::basic_stringstream<char> ss(expression); // does basic streaming job
        std::string token;

        // tokens are --> ( "2 3 4 * +" )
        while (getline(ss, token, ' ')) {  // '  ' delimiter
            std::cout << " token " << token << " count  " << operators_.count(token) << std::endl;
            //                           234                        0
            if (operators_.count(token)) { // if count 0 goto else push it in stack LIFO
                // returns 0 for number( 2 3 4 ) 1 for ( * + ) operator
                std::cout << " count..  " << operators_.count(token) << std::endl;
                //                                 1
                Expression* right = stack.top();   // 4   // 12

                std::cout << " right " << right->interpret() << std::endl;  // 4
                stack.pop();
                Expression* left = stack.top();   // 3    // 2
                std::cout << " Leftm" << left->interpret() << std::endl;    // 3
                stack.pop();

                //  stack.push( Add(left, right));
                std::cout << " token___ " << token << std::endl;   // *
                stack.push(operators_[token](left, right));  // pushing mul *
                //                       *      4      3       // 12
                //                       +      12     2       // 14

            }
            else {

                std::cout << " count at  else " << operators_.count(token) << std::endl;
                //  function to convert the string to an integer,  --> 4 3 2 store it in stack
                stack.push(new Number(std::stoi(token)));
            }
        }
        return stack.top();
    }  // while

private:
    std::unordered_map<std::string, std::function< Expression* (Expression*, Expression*) > > operators_;
};



int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "POSIX infix calc..\n";
    Calculator calculator;
    Expression* expression = calculator.parse("2 3 4 * +");   // Variadic...
    cout << expression->interpret() << endl;      // 14...
    return 0;
}
/*
POSIX infix calc..
  token 2 count  0
  count at  else 0
  token 3 count  0
  count at  else 0
  token 4 count  0
  count at  else 0   // store it in stack
  token * count  1
  count..  1
  right 4
  Left 3
  token___ *   ( 12 )
  token + count  1
  count..  1
  right 12
  Leftm  2
  token___ +  ( 12 + 2 )
14
Program ended with exit code: 0
*/