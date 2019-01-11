#include "polynomial.h"
#include "term.h"
#include <iostream>

using namespace std;

polynomial::polynomial() : h(0) { };
polynomial::polynomial(const polynomial& p) {h = dup_terms(p.h);}
polynomial::polynomial(int size, double coef[], int expon[]) {h = build_poly(size,coef,expon);}
polynomial::~polynomial() {release(h); h = 0;}

void polynomial::plus(    polynomial a, polynomial b) {release(h); h = add(a.h, b.h);}
void polynomial::multiply(polynomial a, polynomial b) {release(h); h = mult_terms(a.h, b.h);}
int  polynomial::degree() const {return h ? h->exp : 0;}
bool polynomial::isZero() const {return !h;}
void polynomial::print()  const {if (h) print_terms(h); else cout << "  0" << endl;}

