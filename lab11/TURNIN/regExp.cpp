// Jeffrey Lansford
// lab 11
#include "regExp.h"
#include <iostream>



   regExp& regExp::operator++(int) {
       
      
       if ( this->type == kleene_star ) {
           
           return *this;
       }
       
       if ( this->type == empty_string ){

           return *this;
       }
       
       if ( this->type == empty_set ){
           
          return *new regExp("");
          
       }
       else {
           
       return *new regExp(kleene_star, this->dup(), 0);
       
       }
       
   
   }// Kleene star   operator             
   
   regExp& regExp::operator^(regExp& r){
       
       
       
       if ( this->type == empty_string  )
           return r; 
       if ( r.type == empty_string  )
           return *this;
       if ( this->type == empty_set  )
           return *this;
       if ( r.type == empty_set  )
           return r;
       
       return *new regExp(concat, this->dup(), r.dup() );
       
       
   }// concatenation operator   
   
   regExp& regExp::operator|(regExp& r) {
       
      
       
       if ( r.type == empty_set )
           return *this;
       if ( this->type == empty_set )
           return r;
       
       return *new regExp(alt, this->dup(), r.dup() ); 
       
   }// alternation   operator
   
   const regExp& regExp::operator=(const regExp &r) {
       
       if ( this != &r ) {
           
           this->type = r.type;     
           this->c = r.c;
           destroyHelper(this->e);
           destroyHelper(this->e1);
           this->e = r.e ? (r.e)->dup():0;
           this->e1 = r.e1 ? (r.e1)->dup():0;
           this->empty = r.empty;
       } 
        
       return *this;

   
   }// equal opertator
   
   
   
   regExp::regExp(expType t, regExp *r , regExp *r1 ) 
         : type(t) , e(r), e1(r1) , empty(false) 
   {
       assert(type==concat || type==alt || type==kleene_star);
   }
   
   
   
   regExp* regExp::dup() {
       
       if ( this->type == empty_set ) {
           return new regExp();
       }
       else if ( this->type == empty_string ) {
           return new regExp("");   
       }
       else if ( this->type == literal ) {
           return new regExp(c);
       }
       else if ( this->type == alt) {
           return new regExp(alt,e->dup(),e1->dup());   
       }
       else if ( this->type == concat ) {
           return new regExp(concat,e->dup(),e1->dup());   
       }
       else if ( this->type == kleene_star ) {
           return new regExp(kleene_star, e->dup(), 0 );
       }
       
      
       
   }
   
   void regExp::destroyHelper( regExp *r ) {
       
       if ( r == 0  ){
           //delete r;
           return;
       }
       destroyHelper(r->e);
       destroyHelper(r->e1);
       r->e = 0;
       r->e1 = 0;
       delete r;
        
   }
   
   void regExp::print() const {
       
       
     if (this->type == empty_set )
         std::cout<<"0";
     else if (this->empty == true )
         std::cout<<"1";
     else if( this->type == literal)
         std::cout<<(this->c);
     else if (this->type == concat) {
         (*(this->e)).print();
         (*(this->e1)).print();
         
     }
     else if (this->type == alt ) { 
         std::cout<<"(";
         (*(this->e)).print();
         std::cout<<"|";
         (*(this->e1)).print();
         std::cout<<")";
   }
     else if (this->type == kleene_star){
         if ((*(this->e)).type != alt ) {
             std::cout<<"(";
             (*(this->e)).print();
             std::cout<<")*";
         }
         
     
         else {
             (*(this->e)).print();
             std::cout<<"*";
        }
     
     }
      
   }
   
   
