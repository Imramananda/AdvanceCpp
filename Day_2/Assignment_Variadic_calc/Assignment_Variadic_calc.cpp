//
//  main.cpp
//  28_SI_AsssignmentVariadic_Calc
//
//  Created by Sathya Babu on 28/05/24.
//
//[15:04] Dudhat, Gaurang (ADV D IN MO RI-PS MT RADIO)
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

#include <unordered_map>

#include <functional>

#include <memory>

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

    Add(std::shared_ptr< Expression > left, std::shared_ptr< Expression > right)

        : left_(left), right_(right) {}

    int interpret() override {

        return left_->interpret() + right_->interpret();

    }


private:

    std::shared_ptr< Expression > left_;

    std::shared_ptr< Expression > right_;

};

// NonTerminal expression ( + / * - )

class Subtract : public Expression {

public:

    Subtract(std::shared_ptr< Expression > left, std::shared_ptr< Expression > right)

        : left_(left), right_(right) {}

    int interpret() override {

        return left_->interpret() - right_->interpret();

    }


private:

    std::shared_ptr< Expression > left_;

    std::shared_ptr< Expression > right_;

};

// NonTerminal expression ( + / * - )

class Multiply : public Expression {

public:

    Multiply(std::shared_ptr< Expression > left, std::shared_ptr< Expression > right)

        : left_(left), right_(right) {}

    int interpret() override {

        return left_->interpret() * right_->interpret();

    }


private:

    std::shared_ptr< Expression > left_;

    std::shared_ptr< Expression > right_;

};

class Divide : public Expression {

public:

    Divide(std::shared_ptr< Expression > left, std::shared_ptr< Expression > right)

        : left_(left), right_(right) {}

    int interpret() override {

        return left_->interpret() / right_->interpret();

    }


private:

    std::shared_ptr< Expression > left_;

    std::shared_ptr< Expression > right_;

};

// House keeping Phase II

std::shared_ptr< Expression > add(std::shared_ptr< Expression > left, std::shared_ptr< Expression > right) { return  std::make_shared< Add >(left, right); }

std::shared_ptr< Expression > mul(std::shared_ptr< Expression > left, std::shared_ptr< Expression > right) { return  std::make_shared<Multiply>(left, right); }

std::shared_ptr< Expression > divide(std::shared_ptr< Expression > left, std::shared_ptr< Expression > right) { return  std::make_shared <Divide>(left, right); }

std::shared_ptr< Expression > sub(std::shared_ptr< Expression > left, std::shared_ptr< Expression > right) { return  std::make_shared <Subtract>(left, right); }


// if its literal push the same on to stack

// if iys an op check for the pre... * /


class Calculator {

public:

    Calculator() {

        operators_["+"] = &add;

        operators_["*"] = &mul;

        operators_["-"] = &sub;

        operators_["/"] = &divide;

    }

    std::stack< std::shared_ptr< Expression > > stack;

    //::basic_stringstream<char> ss(expression);

      // parse the data ..

      // check for the token 2 3 4  * -

      // integral   0  Push the data on to stack

      // NonIntegral  1( * - )  pop the data from the stack..

      //  store the prod 12 in stack

      //

       //  Our core interpreter...

/*    template<typename  First>

    void variadic_ex( const First& first )

    {

        if (operators_.count(std::to_string(first))) { // if count 0 goto else push it in stack LIFO

                    // returns 0 for number( 2 3 4 ) 1 for ( * + ) operator

                    std::cout << " count..  "<< operators_.count(std::to_string(first)) <<std::endl;

                    //                                 1

                    Expression* right = stack.top();   // 4   // 12

                    std::cout  << " right " << right->interpret() << std::endl ;  // 4

                    stack.pop();

                    Expression* left = stack.top();   // 3    // 2

                    std::cout  << " Leftm" << left->interpret() << std::endl ;    // 3

                    stack.pop();

                    //  stack.push( Add(left, right));

                    std::cout  << " token___ " << std::to_string(first) << std::endl ;   // *

                    stack.push( operators_[ std::to_string(first) ](left, right) );  // pushing mul *

                    //                       *      4      3       // 12

                    //                       +      12     2       // 14

        }else{

                    std::cout << " count at  else "<< operators_.count(std::to_string(first)) <<std::endl;

                    //  function to convert the string to an integer,  --> 4 3 2 store it in stack

                    stack.push(new Number((first)));

        }

    }

    template<typename  First, typename... Rest>

    void variadic_ex( const First& first, const Rest&... rest )

    {

        if (operators_.count(std::to_string(first))) { // if count 0 goto else push it in stack LIFO

                    // returns 0 for number( 2 3 4 ) 1 for ( * + ) operator

                    std::cout << " count..  "<< operators_.count(std::to_string(first)) <<std::endl;

                    //                                 1

                    Expression* right = stack.top();   // 4   // 12

                    std::cout  << " right " << right->interpret() << std::endl ;  // 4

                    stack.pop();

                    Expression* left = stack.top();   // 3    // 2

                    std::cout  << " Leftm" << left->interpret() << std::endl ;    // 3

                    stack.pop();

                    //  stack.push( Add(left, right));

                    std::cout  << " token___ " << std::to_string(first) << std::endl ;   // *

                    stack.push( operators_[ std::to_string(first) ](left, right) );  // pushing mul *

                    //                       *      4      3       // 12

                    //                       +      12     2       // 14

        }else{

                    std::cout << " count at  else "<< operators_.count(std::to_string(first)) <<std::endl;

                    //  function to convert the string to an integer,  --> 4 3 2 store it in stack

                    stack.push(new Number((first)));

        }

        variadic_ex(rest...);

    }

*/

    template<typename  First>

    void variadic_ex(const First& first)

    {

        if (operators_.count(first)) { // if count 0 goto else push it in stack LIFO

            // returns 0 for number( 2 3 4 ) 1 for ( * + ) operator

            std::cout << " count..  " << operators_.count(first) << std::endl;

            //                                 1

            std::shared_ptr< Expression > right = stack.top();   // 4   // 12

            std::cout << " right " << right->interpret() << std::endl;  // 4

            stack.pop();

            std::shared_ptr< Expression > left = stack.top();   // 3    // 2

            std::cout << " Leftm" << left->interpret() << std::endl;    // 3

            stack.pop();

            //  stack.push( Add(left, right));

            std::cout << " token___ " << first << std::endl;   // *

            stack.push(operators_[first](left, right));  // pushing mul *

            //                       *      4      3       // 12

            //                       +      12     2       // 14

        }
        else {

            std::cout << " count at  else " << operators_.count(first) << std::endl;

            //  function to convert the string to an integer,  --> 4 3 2 store it in stack

            stack.push(std::make_shared< Number>(std::stoi(first)));

        }

    }
    [15:04] Dudhat, Gaurang(ADV D IN MO RI - PS MT RADIO)
        template<typename  First, typename... Rest>

    void variadic_ex(const First& first, const Rest&... rest)

    {

        if (operators_.count(first)) { // if count 0 goto else push it in stack LIFO

            // returns 0 for number( 2 3 4 ) 1 for ( * + ) operator

            std::cout << " count..  " << operators_.count(first) << std::endl;

            //                                 1

            std::shared_ptr< Expression > right = stack.top();   // 4   // 12

            std::cout << " right " << right->interpret() << std::endl;  // 4

            stack.pop();

            std::shared_ptr< Expression > left = stack.top();   // 3    // 2

            std::cout << " Leftm" << left->interpret() << std::endl;    // 3

            stack.pop();

            //  stack.push( Add(left, right));

            std::cout << " token___ " << first << std::endl;   // *

            stack.push(operators_[first](left, right));  // pushing mul *

            //                       *      4      3       // 12

            //                       +      12     2       // 14

        }
        else {

            std::cout << " count at  else " << operators_.count(first) << std::endl;

            //  function to convert the string to an integer,  --> 4 3 2 store it in stack

            stack.push(std::make_shared <Number>(std::stoi(first)));

        }

        variadic_ex(rest...);

    }

    template < typename First, typename ... Rest>

    std::shared_ptr< Expression > parse(const First& first, const Rest&... rest) {

        // tokens are --> ( "2 3 4 * +" )

        variadic_ex(first, rest...);


        return stack.top();// while

    }


private:

    std::unordered_map<std::string, std::function< std::shared_ptr< Expression >(std::shared_ptr< Expression >, std::shared_ptr< Expression >) > > operators_;

};




int main(int argc, const char* argv[]) {

    // insert code here...

    std::cout << "POSIX infix calc..\n";

    Calculator calculator;

    std::shared_ptr< Expression > expression = calculator.parse("2", "3", "4", "*", "+");   // Variadic...

    cout << expression->interpret() << endl;      // 14...

    return 0;

}
