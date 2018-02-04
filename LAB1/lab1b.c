// Jeffrey Lansford
// 2/4/18
// to reduce newlines between paragraphs to 1 line each
// input: any file with characters
// output: same file with newlines between bobies reduced

#include <stdio.h>

main()
{
    // ch for input and newlinecount to determine if more than one line	

    int ch,newlinecount = 0;

    // states for where in the paragraph the character is in

    enum states {paragraph_break, in_paragraph, newline} state = paragraph_break;
    
    while ((ch = getchar()) != EOF) { 

      	  //if statements to deicde what state it is	
	  
	  if ( ch < 32 && ch != '\n')
	  {
	    ch = 32;
	  }
	  
	  if ( state == paragraph_break && ch>= 33 && ch <= 126 ) 
	  {
	      state = in_paragraph;
	      newlinecount = 0;
	  }
	  
	  else if (state == in_paragraph && ch == '\n' ) 
	  {
	      state = newline;
	  }
	  
	  else if (state == newline && ch>= 33 && ch<=126) 
	  {
	      state = in_paragraph;
	      newlinecount = 0;
	  }
	  
	  else if ( state == paragraph_break && ch == '\n')
	  {
	    ch = 32;
	    newlinecount++;
	    state = newline;
	  }
	  
	  else if (state == newline && ch == '\n')
	  {
	    state = paragraph_break;
	  }
	  
	  // if statement to print out input
		  
	  if ( newlinecount < 1 )
	  {
	    putchar(ch);
	  }
	
    }
    
}
