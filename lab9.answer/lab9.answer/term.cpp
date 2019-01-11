
#include "term.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

void release(term *t) { 
   if (!t) return;  
   release(t->next); 
   delete t; 
} 

void print_terms(term *t) {
   if (!t) { cout << endl; return; }
   cout << setw(3) << t->coe; 
   if (t->exp ) cout << "x^" << setw(2) << t->exp; 
   if (t->next) cout << " +"; 
   print_terms( t -> next ); 
}

term* dup_terms(term *t) {
   if (!t) return 0;
   return new term(t->exp, t->coe, dup_terms(t->next));
}

term* build_poly(int size, double coef[], int expon[]) {
   if (size == 0) return 0;
   if (size > 1 && expon[size-2] > expon[size-1]) 
      throw invalid_argument("exponents are not in increasing order");
   return new term(expon[size-1], coef[size-1], build_poly(size-1, coef, expon));
} 

term* add(term *a, term *b) {
   if (!a)              return dup_terms(b); 
   if (!b)              return dup_terms(a); 
   if (a->exp > b->exp) return new term(a->exp, a->coe,          add(a->next,b)); 
   if (a->exp < b->exp) return new term(b->exp, b->coe,          add(a,b->next)); 
   if (a->coe + b->coe) return new term(a->exp, a->coe + b->coe, add(a->next,b->next));
   return add(a->next,b->next);
}

term* mult(term *t, double coef, int expon) {
   if (!t) return 0;
   return new term(expon + t->exp, coef * t->coe, mult(t->next, coef, expon));
}

/* following will generate temporary terms that are not reclaimed.

term* mult_terms(term *a, term *b) {
   if (!a) return 0;
   return add(mult(b, a->coe, a->exp), mult_terms(a->next,b));
}

*/

term* mult_terms(term *a, term *b) {
   if (!a) return 0;
   term* t1 = mult(b, a->coe, a->exp); 
   term* t2 = mult_terms(a->next,b);
   term* t  = add(t1, t2);
   release(t1);
   release(t2);
   return t;
}
