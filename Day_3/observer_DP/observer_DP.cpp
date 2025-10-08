//
//  main.cpp
//  29_SI_Observers
//
//  Created by Sathya Babu on 29/05/24.
//
/*
Agenda for the day

Forward..
union - Variant
observer

lambda - various codes - Forward..
???
lambda recursion
tuple
Singleton - legacy way.. with shared_ptr
enabling shared ptr from this..
implementng Observer with a usecase
any
optional
*/


#include <iostream>
#include <vector>
using namespace std;

class Observer;


class SubjectAbs {

    virtual void attach(Observer) = 0;
    virtual void detach(Observer) = 0;
    virtual void anotify() = 0;



};

// concrete Subject

class Subject  // : public SubjectAbs {
{
    // wrappers around the vector will quell the pointer and ref usage..
    std::vector< Observer* > views;
    int value;

public:

    void attach(Observer* obs)
    {
        views.emplace_back(obs);
    }
    void detach(Observer* obs) {
        views.erase(std::remove(views.begin(), views.end(), obs), views.end());
    }
    void setValue(int val) {
        value = val;
        notify();
    }
    int getVal() {
        return value;
    }
    void notify();


};


class Observer {
    Subject* model;
    int denom;

public:

    Observer(Subject* mode, int div) {
        model = mode;
        denom = div;

        model->attach(this);  // we are sharing the concObserver'a this here..
        // Divide : shared_ptr_enable_this() { ..... }

    }
    virtual void update() = 0;

protected:

    Subject* getSubject() {
        return model;
    }
    int getDivisor() {
        return denom;
    }

};

class DivObserver : public Observer {
public:
    DivObserver(Subject* mod, int div) : Observer(mod, div) {}
    void update() {
        int v = getSubject()->getVal(), d = getDivisor();
        cout << v << " / " << d << " is " << v / d << endl;
    }

};


class MulObserver : public Observer {
public:
    MulObserver(Subject* mod, int div) : Observer(mod, div) {}
    void update() {
        int v = getSubject()->getVal(), d = getDivisor();
        cout << v << " * " << d << " is " << v * d << endl;
    }

};
void Subject::notify() {
    //    for( int i = 0 ; i < views.size() ; i++){
    //        views[ i ] -> update();
    //    }
    for (auto user : views) {
        user->update();
    }
}

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Observer !\n";

    Subject subj;

    DivObserver  divObs1(&subj, 4);
    DivObserver  divObs2(&subj, 3);
    MulObserver  mulObs1(&subj, 4);

    subj.setValue(14);

    return 0;
}
/*
Observer !
14 / 4 is 3
14 / 3 is 4
14 * 4 is 56
Program ended with exit code: 0
*/