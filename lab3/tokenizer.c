// Jeffrey Lansford
// 2 - 18 - 18
// Lab 3

#include "tokenizer.h"

int get_token(int *w)
{
    int numCount = 0, temHold = 0 ;
    int *z;
    
    
    // loop to get input from file
    while  ((*w = getc(fpi)) != EOF )
    {
     
      // checks if *w is char 0 - 9
     if ( *w >= '0' && *w <= '9' )
     {
          // makes *w the actual value of number
         *w = *w - 48;
	 
	 // checks if first number in a sequence of an Operand 
	 if ( numCount == 0 )
	 {
	      // checks if *w is not zero and stores in another variable 
	      if ( *w != 0 )
	      {
	
	      numCount = 1;
	      temHold = *w;
	     
	      }
	          
	 }
	 
	 // combines numbers if not first number I.G: 7 , 8 = 78
	 else 
	 {
	   
	      numCount = 1;
	      temHold = (temHold * 10) + *w;
	      
	 }
	  // gets next char and checks if not a number 
	 *z = getc(fpi);
	 
	 if ( *z  < '0' || *z > '9' )
	 {
	   
	   ungetc(*z, fpi);
	   *w = temHold;
	   numCount = 0;
	   return Operand;
	 }
	 
	 else 
	    ungetc(*z, fpi);  
	
     } 
     
     // series of else if's to check if *w is '(', ')', '+', '*', '/', '-',  
     else if ( *w == '(' )
         return OpenParen;
     
     
     else if ( *w == ')' )
         return CloseParen;
     
     else if ( *w == '+' )
         return Plus;
     
     else if ( *w == '-' )
         return Minus;
     
     else if (*w == '*' )
         return Mult;
     
     else if (*w == '/' )
         return Divide;
     
     // exits if *w is not a recogized symbol excluding non-printable characters 
     else if ( *w >= 33 && *w <= 126 )
     {
       
	printf("\nnot a token; program aborts\n");
	
	exit(1);
     }
     
    }
}// main

