// Jeffrey Lansford
// Lab 2
// 2/11/18


# include <stdio.h>

int getLine( char s[], int size);
void copy( char to[], char from[]);

main()
{
      
    // defining arrays line and longest with max character line of 100
  
    #define MAX_LINE_LENGTH 100
    
    char line[MAX_LINE_LENGTH]; 
    
    char longest[MAX_LINE_LENGTH];
    
    // varable for input
    
    int c;
    
    // varables for getLine() output
    
    int linenum;
    
    int longestnum = 0;
    
    // varable dor for loop and array index
    
    int i;
    
    // loops to get input into line array then calculates number of characters  
    
    for ( i =0; (c = getchar()) != EOF; i++ )
       {
           line[i] = c;
           
           if ( c == '\n')
           {
               linenum = getLine(line, MAX_LINE_LENGTH);
               
	       // if statement to determine longest line
	       
               if ( linenum > longestnum )
               {
                   longestnum = linenum;
                   copy(longest, line);
               }
              
               i =-1;
           }
           
       }
       
       // print longest line
       
       printf("\n%s\n", longest);
       
       
}// main

// counts number of characters in a line

int getLine( char s[], int size)
{
 
    // numline count for number characters  
  
    int numLine = 0;
    
    int i;
    
    /* loop to count characters and check if character is EOF, bigger than size, 
      and if its newline
      if char is \n , then put null car "\0" and return numline
    */
    
    for (i=0; s[i] != '\0'  ; i++ )
    {
        numLine++; 
        
        if ( s[i] == EOF)
            return 0;
        
        if ( numLine > size)
            return -1;
        
	if ( s[i] == '\n' )
        {
            s[i+1] = '\0';
            return numLine;
        }
           
       
    }

    
    
}// getLine

// copies from[] to to[]

void copy( char to[], char from[])
{
    int i; 
    
    for (i = 0; from[i]; i++ )
      to[i] =  from[i];
   
}// copy
