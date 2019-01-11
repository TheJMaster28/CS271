// Jeffrey Lansford
// 4/10/18
// Lab10

#include "term2.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;


void  release(term *t){
// free all terms pointed to by t
    if ( !t ) {
        free(t);
        return;
    }
    release(t->next);
    free(t);
}

void  print_terms(term *t){     
// print terms
    if (!t) return;
    if ( t->exp == 0 ) { cout <<  t->coe << " "<<endl<<endl; }
    else { cout << t->coe << "x^" << t->exp << " + "; }
    print_terms(t->next);
}

void  print_termsDUP(term *t){     
// print terms
    if (!t) return;
    if ( t->exp == 0 ) { cout <<  t->coe << " "; }
    else { cout << t->coe << "x^" << t->exp << " + "; }
    print_termsDUP(t->next);
}

term* dup_terms(term *t) {
// duplicate terms (copy constructor)
    if ( !t ) {
        term* h = NULL;
        return h;
    }
    term* h = (term*)malloc(sizeof(struct term));
    h->coe = t->coe;
    h->exp = t->exp;
    h->next = dup_terms(t->next);
    return h;
}

term* add(term *a, term *b){    
// add the two polynomials a and b
// return a linked list of terms
    if ( !a && !b ) {
        term* h = NULL;
        return h;
    }
    term* h = (term*)malloc(sizeof(struct term));
    if ( !a && b ) {
        h->coe = b->coe;
        h->exp = b->exp;
        h->next = add(a, (b->next)); 
    }
    else if ( a && !b ) {
        h->coe = a->coe;
        h->exp = a->exp;
        h->next = add((a->next), b);
    }
    
    else if ( (a->exp) == (b->exp) ) {
        h->coe = (a->coe) + (b->coe);
        h->exp = a->exp;
        h->next = add(a->next, b->next);
    }
    else if ( (a->exp) < (b->exp) ) {
        h->coe = b->coe;
        h->exp = b->exp;
        h->next = add(a, (b->next));
        
    }    
    else if ( (a->exp) > (b->exp) ) {
        h->coe = a->coe;
        h->exp = a->exp;
        h->next = add((a->next), b);
    } 
    return h; 
}

term* sub(term *a, term *b) {
    
    if ( !a && !b ) {
        term* h = NULL;
        return h;
    }
    term* h = (term*)malloc(sizeof(struct term));
    if ( !a && b ) {
        h->coe = b->coe;
        h->exp = b->exp;
        h->next = sub(a, (b->next)); 
    }
    else if ( a && !b ) {
        h->coe = a->coe;
        h->exp = a->exp;
        h->next = sub((a->next), b);
    }
    
    else if ( (a->exp) == (b->exp) ) {
        h->coe = (a->coe) - (b->coe);
        h->exp = a->exp;
        h->next = sub(a->next, b->next);
    }
    else if ( (a->exp) < (b->exp) ) {
        h->coe = b->coe;
        h->exp = b->exp;
        h->next = sub(a, (b->next));
        
    }    
    else if ( (a->exp) > (b->exp) ) {
        h->coe = a->coe;
        h->exp = a->exp;
        h->next = sub((a->next), b);
    } 
    return h; 

}

term* build_poly(int size, double coef[], int expon[]) {
// build a linked list of terms 
// assume: expon[0] < expon[1] < expon[2] < ...
// if assumption is not satisfied, throw an invalid_argument exception
    int y = size - 1;
    if ( y < 0 ) {
        term* h = NULL;
        return h;
    }
    int x;
    for ( x = 1 ; x < size ; x++ ) {
    if ( expon[x] < expon[x-1] )
        throw invalid_argument("expon[] is not sorted");
    }
    term* h = (term*)malloc(sizeof(struct term)); 
    h->coe = coef[y];
    h->exp = expon[y];
    h->next = build_poly( y, coef, expon );
    return h; 
    
}
term* mult(term *t, double coef, int expon){            
// return a new polynomial that is the result of multiplying the polynomial t with the term with coefficient "coef" and exponent "expon"
    if ( !t ){ 
        term* h = NULL; 
        return h;
    }
    term* h = (term*)malloc(sizeof(struct term));
    h->coe = (t->coe) * coef;
    h->exp = (t->exp) + expon;
    h->next = mult((t->next), coef, expon);
    return h; 
    
}

term* mult_terms(term *a, term *b){
// multiple two polynomials a and b
    if ( (!a && !b) || !a ) {
        term* h = NULL;
        return h;
    }
    term* h = mult( b, (a->coe), (a->exp) );
    return add(mult_terms((a->next), b), h ); 
}
