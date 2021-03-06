// Jeffrey Lansford
// 4/10/18
// Lab10

#include "polynomial2.h"
#include <iostream>
#include <stdexcept>
using namespace std;

main() {
   double coe1[4] = {1,   2,  3,  4};
   double coe2[4] = {-1, -2, -3, -4};
   double coe3[6] = {3, 1, 6, 9, -7, 4};
   double coe4[2] = {1, 1};
   int    exp1[4] = {0,   4, 14, 18};
   int    exp2[4] = {0,  14,  4, 18};    // thorw exception
   int    exp3[6] = {0, 2, 4, 6, 8, 10};
   int    exp4[2] = {0, 2};
   

   polynomial p(4,coe1,exp1), q(4,coe2,exp1), s;
   cout << "P(x)        = ";
   p.print();
   cout << "Q(x)        = ";
   q.print();
   
   s = p;
   
   cout<< "S(x)        = ";
   s.print();
   
   s = (q + p);
   cout<< "S(x)((q+p))        = ";
   s.print();
   
   
   s = (q - p);
   cout<< "S(x)((q-p))        = ";
   s.print();
   
   s = (p - q);
   cout<< "S(x)((p-q))        = ";
   s.print();
   
   
   s = (p * q);
   cout<< "S(x)((p*q))        = ";
   s.print();
   
   polynomial z(2,coe4, exp4); 
   
   cout<<"Z(x) before =     ";
   z.print();
   
   z += p;
   
   cout<<"What Z(x) is now  =    ";
   z.print();
   
   
   cout<<"Print Overloading:           ";
   cout<<z<<" ~~~~ "<<s<<endl;
   
   

   
   
   
   try 
   {
      polynomial r(4,coe1,exp2);
   } 
   catch (invalid_argument &e) 
   {
      cout << "Exception: " << e.what() << endl<<endl; 
   }
   
}

/* outputs:

P(x)        =   4x^18 +  3x^14 +  2x^ 4 +  1
Q(x)        =  -4x^18 + -3x^14 + -2x^ 4 + -1
Q(x) + Q(x) =  -8x^18 + -6x^14 + -4x^ 4 + -2
P(x) + Q(x) =   0
P(x) * P(x) =  16x^36 + 24x^32 +  9x^28 + 16x^22 + 20x^18 +  6x^14 +  4x^ 8 +  4x^ 4 +  1

Exception: exponents are not in increasing order

*/
