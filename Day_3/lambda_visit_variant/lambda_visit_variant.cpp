//
//  main.cpp
//  29_SI_Lambdas_Visit_variant
//
//  Created by Sathya Babu on 29/05/24.
//
 
#include <iostream>
#include <variant>
#include <vector>
using namespace std;
 
void callVisitSingleVatiant(){
    
    // visatable..
    constexpr auto printTheDataOfVisitor = [] ( const auto& t){ cout << t << endl ; };
    
    
    // visitor
    std::variant<int,float, std::string> genericDataVisitor{ " Hey Visitor "};
    
//    std::visit(     visitable , visitor    );
      std::visit(     printTheDataOfVisitor  , genericDataVisitor   );
    
}
 
 
void callVisitMultipleVatiant(){
    
    // visatable..
    constexpr auto printTheDataOfVisitor = [] ( const auto& t){ cout << t << endl ; };
    
    
    // visitor
    using myVariant = std::variant<int,float, std::string>  ;
    std::vector< myVariant > myVectorVariantVisitor{ 123," Hello variant"};
    
    
    for( auto VarToPrintVisitor : myVectorVariantVisitor)
    {
        //    std::visit(     visitable , visitor    );
        std::visit(     printTheDataOfVisitor  , VarToPrintVisitor   );
    }
    
}
 
 
 
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    callVisitSingleVatiant();
    callVisitMultipleVatiant();
    
  
    return 0;
}