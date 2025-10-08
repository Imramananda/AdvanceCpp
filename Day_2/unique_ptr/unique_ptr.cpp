#include <iostream>
#include <memory>

struct Foo {
    Foo() { std::cout << "Foo::Foo Constructor" << std::endl; }
    ~Foo() { std::cout << "Foo::~Foo" << std::endl; }

    void foo() { std::cout << "Foo::foo" << std::endl; }
};
void f(const Foo&) {
    std::cout << "f(const Foo&)" << std::endl;
}

int main(int argc, const char* argv[]) {
   
    std::unique_ptr< Foo > p1(std::make_unique< Foo >());
    std::cout << p1.get() << std::endl;
    // if( p1 ) p1->foo();

     //std::unique_ptr< Foo > p2 ;
    // p2 = p1 ;  // not allowed

    std::unique_ptr< Foo > p2(std::move(p1)); //??
    p2->foo();
    p1->foo();

    std::cout << p1.get() << std::endl;
    std::cout << p2.get() << std::endl;

    return 0;
}