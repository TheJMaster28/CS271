#ifndef TERM_H
#define TERM_H

struct term {
   int        exp;   // exponent
   double     coe;   // coefficient
   term*      next;  
   term(int e, double c, term* n=0) : exp(e), coe(c), next(n) {}
};

void    release(term *);                  
void    print_terms(const term *);         
term*   dup_terms(const term *);            
term*   poly(int size, const double [], const int []);  
term*   add(const term *, const term *); 
term*   sub(const term *, const term *);
term*   mult(const term *, double, int);
term*   mult_terms(const term *, const term *);

#endif
