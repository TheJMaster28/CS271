// Jeffrey Lansford
// 2/4/18
// input: files
// output: spaces between =, ==, !=

#include <stdio.h>

main()
{
  
  // ch variable for input
  
  int ch;
   
  // states for program to tell what kind of equal is it
  
  enum states { one_equal, two_equal, not_equal, no_equal } state = no_equal;
  
  // loop for going through input's characters
  
  while ((ch = getchar()) != EOF )
  {
      
      // if statements to change state depending on what kind of equal 
    
      if ( ch == '=' && state == no_equal )
      {
	putchar(32);
	putchar(ch);
	state = one_equal;
      }
      
      else if ( state == one_equal && ch == '=' )
      {
	state = two_equal;
	
      }
      
      else if ( state == no_equal && ch == '!' )
      {
	putchar(32);
	state = not_equal;
	putchar(ch);
      }
      
      // if statemnets to add spacing between '=' characters or '==' or '!='
      
      if ( state == one_equal && ch != '=' )
      {
	putchar(32);
	putchar(ch);
	state = no_equal;
      }
      
      else if ( state == two_equal && ch == '='  )
      {
	putchar(ch);
	putchar(32);
	state = no_equal;
      }
      
      else if ( state == not_equal && ch == '=')
      {
	putchar(ch);
	putchar(32);
	state = no_equal;
      }
      else if ( ch != '=' && ch != '!')
      {
	putchar(ch);
	state = no_equal;
      }
      
      // resets state
      
      if ( ch == '\n' )
      {
	state = no_equal;
      }
  
      
  }// while
    
  
  
  
}// main
