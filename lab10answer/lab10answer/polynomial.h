#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include "term.h"

class polynomial {

   friend std::ostream &operator<<( std::ostream &, const polynomial & );

public:
   polynomial();                                     // default constructor
   polynomial(const polynomial&);                    // copy    constructor
   polynomial(int size, double [], int []);          //         constructor
   ~polynomial();                                    //         destructor

   const polynomial &operator=(const polynomial &);     
         polynomial operator+ (const polynomial &) const; 
         polynomial operator- (const polynomial &) const;
         polynomial operator* (const polynomial &) const;
         polynomial operator+=(const polynomial &);
         polynomial operator-=(const polynomial &);
         polynomial operator*=(const polynomial &);

   int  degree() const;                              // returns degree
   bool isZero() const;                              // true for zero polynomial
   void print()  const;                              // print a polynomial 

private:
   term*   h;

};

#endif
