//
//  main.cpp
//  30_SI_Visitor_Legacy
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include <vector>
using namespace std;


class HousingLoan;
class StudentLoan;

// Auditor
class Visitor {
public:
    virtual double visit(HousingLoan&) = 0;
    virtual double visit(StudentLoan&) = 0;

};

// me...
class Visitable {
public:
    virtual double accept(Visitor& v) = 0;
};

//----------- My Job / class

class HousingLoan : public Visitable {
public:

    HousingLoan(double v) : value(v) {}
    double accept(Visitor& v) override {
        return v.visit(*this); // HousingLoan
    }
    double getValue() {
        return value;
    }
private:
    double value;
};

class StudentLoan : public Visitable {
public:

    StudentLoan(double v) :amount(v) {}
    double accept(Visitor& v) override {
        return v.visit(*this);  // StudentLoan
    }
    double getAmmount() {
        return amount;
    }
private:
    double amount;
};

// implement auditor class...

class TaxVisitor : public Visitor
{
public:

    double visit(HousingLoan& house)  override
    {
        cout << " Calculation Housing loan : ";
        return  house.getValue() * 0.1; // 10% tax on house

    }
    double visit(StudentLoan& loan)  override
    {
        cout << " Calculation Student loan : ";
        return  loan.getAmmount() * 0.05; // 5 tax on house

    }
};

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Visitor..\n";
    std::vector< Visitable* > visitable;
    visitable.emplace_back((new HousingLoan(500000.0)));
    visitable.emplace_back((new StudentLoan(10000.0)));

    TaxVisitor taxVisitor;

    double totalTax = 0.0;
    for (auto asset : visitable) {
        totalTax += asset->accept(taxVisitor);
    }

    cout << " Total tax on House and StudentLoan is " << totalTax << endl;

    return 0;
}
/*
HVisitor..
  Calculation Housing loan :  Calculation Student loan :  Total tax on House and StudentLoan is 50500
Program ended with exit code: 0
*/