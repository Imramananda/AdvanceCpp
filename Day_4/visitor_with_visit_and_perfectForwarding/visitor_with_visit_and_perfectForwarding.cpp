//
//  main.cpp
//  30_SI_Visitor_Share_enabled
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include <memory>
#include <vector>
#include <variant>

class Visitor;

class Visitable {
public:
    virtual ~Visitable() = default;
    virtual double accept(std::shared_ptr<Visitor> v) = 0;
};

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual double visit(std::shared_ptr<Visitable> visitable) = 0;
};

class House : public Visitable, public std::enable_shared_from_this<House> {
public:
    House(double v) : value(v) {}

    double getValue() const {
        return value;
    }

    double accept(std::shared_ptr<Visitor> v) override {
        return v->visit(shared_from_this());
    }

private:
    double value;
};

class StudentLoan : public Visitable, public std::enable_shared_from_this<StudentLoan> {
public:
    StudentLoan(double a) : amount(a) {}

    double getAmount() const {
        return amount;
    }

    double accept(std::shared_ptr<Visitor> v) override {
        return v->visit(shared_from_this());
    }

private:
    double amount;
};

class TaxVisitor : public Visitor {
public:
    double visit(std::shared_ptr<Visitable> visitable) override {
        // dereferencing the shared_ptr obj to House is a must & safe
        auto housePtr = std::dynamic_pointer_cast<House>(visitable);
        if (housePtr) {
            std::cout << "Housing Loan -> ";
            return housePtr->getValue() * 0.1; // 10% tax on the value of the house
        }

        auto loanPtr = std::dynamic_pointer_cast<StudentLoan>(visitable);
        if (loanPtr) {
            std::cout << "Study Loan -> ";
            return loanPtr->getAmount() * 0.05; // 5% tax on the loan amount
        }

        return 0.0;
    }
};

int main() {
    std::vector<std::shared_ptr<Visitable>> visitables;
    visitables.push_back(std::make_shared<House>(500000.0));
    visitables.push_back(std::make_shared<StudentLoan>(10000.0));

    auto taxVisitor = std::make_shared<TaxVisitor>();

    double totalTax = 0.0;
    for (auto& visitable : visitables) {
        totalTax += visitable->accept(taxVisitor);
    }

    std::cout << "Total tax: Rs. " << totalTax << std::endl;

    return 0;
}
/*
Housing Loan -> Study Loan -> Total tax: Rs. 50500
Program ended with exit code: 0
*/
has context menu


has context menu