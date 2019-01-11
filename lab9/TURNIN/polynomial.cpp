// Jeffrey Lansford
// 4/10/18
// Lab9

#include "polynomial.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;
    

   polynomial::polynomial()
        : h ( (term*)malloc(sizeof(struct term)) ) 
   {                                        
   // default constructor
       h->coe = 0;
       h->exp = 0;
       h->next = NULL;
   }

   polynomial::polynomial(const polynomial& p) 
        : h ( dup_terms( p.h )  )
   {                  
   // copy constructor     
   }
   
   polynomial::polynomial(int size, double coef[], int expon[]) 
        : h ( build_poly(size, coef, expon)  )
   {
   // constructor
   // assume: expon[0] < expon[1] < expon[2] < ...
   // if assumption is not satisfied, throw an invalid_argument exception
       
   }

   polynomial::~polynomial() {                                       
   // destructor
       release(h);
   }
   
   void polynomial::plus(polynomial a, polynomial b) {               
   // add two polynomials
      h = add(a.h, b.h);
   }
   
   void polynomial::multiply(polynomial a, polynomial b) {           
   // multiply two polynomials
       h = mult_terms(a.h,b.h);
   }
   
   int  polynomial::degree() const {                                 
   // returns degree of polynomial
       term* w = dup_terms(h);
       while ( w->next )
           w = w->next;
       return (w->exp);
       
   }
   
   bool polynomial::isZero() const {                                 
   // true if the polynomial is a zero polynomial
   // false otherwise
       term* w = dup_terms(h);
       bool t = true;
       for ( ; w ; w = (w->next)) {   
        if ( (w->coe) != 0 ) {
           return false;
        }
       }
       return t; 
   }

   void polynomial::print()  const {                                 
   // print a polynomial
       bool m = isZero();
       if ( m == true ) { cout << "0" << " "<<endl<<endl; } 
       else {print_terms(h);} 
       
   }
