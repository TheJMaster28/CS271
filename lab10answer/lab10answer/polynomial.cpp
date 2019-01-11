#include <iostream>
#include "polynomial.h"
#include "term.h"
using namespace std;

polynomial::polynomial() : h(0) { };
polynomial::polynomial(const polynomial& p) {h = dup_terms(p.h);}
polynomial::polynomial(int size, double coef[], int expon[]) {h = poly(size,coef,expon);}
// assume: expon[0] < expon[1] < expon[2] < ...

polynomial::~polynomial() {release(h); h = 0;}

int  polynomial::degree() const {return h ? h->exp : 0;}
bool polynomial::isZero() const {return !h;}
void polynomial::print()  const {if (h) print_terms(h); else cout << "  0" << endl;}

const polynomial &polynomial::operator=(const polynomial &a) {
   if (this == &a) return *this;
   release(h);
   h = dup_terms(a.h);
   return *this;
}

polynomial polynomial::operator+(const polynomial &a) const {
   polynomial b;
   b.h = add(h, a.h);
   return b;
}

polynomial polynomial::operator-(const polynomial &a) const {
   polynomial b;
   b.h = sub(h, a.h);
   return b;
}

polynomial polynomial::operator*(const polynomial &a) const {
   polynomial b;
   b.h = mult_terms(h, a.h);
   return b;
}

polynomial polynomial::operator+=(const polynomial &a) {
   term* h1 = add(h, a.h);
   release(h);   
   h = h1; 
   return *this;
}

polynomial polynomial::operator-=(const polynomial &a) {
   term* h1 = sub(h, a.h);
   release(h);   
   h = h1; 
   return *this;
}

polynomial polynomial::operator*=(const polynomial &a) {
   term* h1 = mult_terms(h, a.h);
   release(h);   
   h = h1; 
   return *this;
}

ostream &operator<<(ostream &output, const polynomial &p) {
   p.print();
   return output;
}
