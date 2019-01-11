// Jeffrey Lansford
// 4/10/18
// Lab10

#include "polynomial2.h"
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
   
   const polynomial &polynomial::operator=( const polynomial &a )  {
       if ( this == &a ) 
            return *this;
       release(h);
       h = dup_terms(a.h);
       return *this;
   }
   
   const polynomial polynomial::operator+(const polynomial &a )  {
       polynomial b;
       b.h = add(this->h, a.h);
       return b; 
       
   }
   
   const polynomial polynomial::operator-(const polynomial &a ) {
       polynomial b;
       b.h = sub(this->h, a.h);
       return b; 
       
   }
   
   const polynomial polynomial::operator*(const polynomial &a )  {
       polynomial b;
       b.h = mult_terms(this->h, a.h);
       return b; 
       
   }
   
   const polynomial &polynomial::operator+=( const polynomial &a )  {
       polynomial b;
       b.h = add(this->h, a.h);
       if ( this == &b ) 
            return *this;
       release(h);
       h = dup_terms(b.h);
       return *this;
       
       
   }
   
   const polynomial &polynomial::operator-=(const polynomial &a )  {
       polynomial b;
       b.h = sub(this->h, a.h);
       if ( this == &b ) 
            return *this;
       release(h);
       h = dup_terms(b.h);
       return *this;
       
   }
   
   const polynomial &polynomial::operator*=(const polynomial &a ) {
       polynomial b;
       b.h = mult_terms(this->h, a.h);
       if ( this == &b ) 
            return *this;
       release(h);
       h = dup_terms(b.h);
       return *this;
       
   }
   
   ostream& operator<<(ostream &output, const polynomial &a){
       
       term* w = dup_terms(a.h);
       bool t = true;
       for ( ; w ; w = (w->next)) {   
        if ( (w->coe) != 0 ) {
           t = false;
           break;
        }
        else { t = true;}
       }
       
       if ( t == true ) { output << "0" << " "; } 
       else {
           
           print_termsDUP(a.h);
           
           
       } 
       
       return output;
       
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
       else {print_terms(h); } 
       
   }
   
