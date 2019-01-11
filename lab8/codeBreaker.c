// Jeffrey Lansford
// Lab 8
// 4/3/18
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
   char line[128];
   // history array and h guess counter
   int history[500];
   int h = 0; 
   // loop counter
   int loopC;
   // variable to store guess to check history[]
   int currentVal;
   // variable for if colors are right, 0 or 1
   int rightColo = 0;
   // varibles for logic of a1 = 0 a2 = 4
   int temp=0, temp1=0, temp2=0, temp3=0;
   int rando, changeVal0=0, changeVal1=0, changeVal2=0, changeVal3=0, hisC;
   // variables for guesses and data returned from the codeMaker
   int gs1, gs2, gs3, gs4;
   int a1, a2;
   // variables for a1 = 0  and a2 = 0, either 0 or 1
   int not0 = 0, not1 = 0, not2 = 0, not3 = 0, not4 = 0, not5 = 0; 
   FILE *logf;
   logf = fopen("codeBreaker.log","w");
   srand(0);
   do {
       // if statement to check what colors are not in the answer 
       if ( a1 == 0 && a2 == 0 && h >= 1) {
               if ( gs1 == 0 || gs2  == 0 || gs3 == 0 || gs4 == 0 ) 
                   not0 = 1;
               if ( gs1 == 1 || gs2  == 1 || gs3 == 1 || gs4 == 1 ) 
                   not1 = 1;
               if ( gs1 == 2 || gs2  == 2 || gs3 == 2 || gs4 == 2 ) 
                   not2 = 1;
               if ( gs1 == 3 || gs2  == 3 || gs3 == 3 || gs4 == 3 ) 
                   not3 = 1;
               if ( gs1 == 4 || gs2  == 4 || gs3 == 4 || gs4 == 4 ) 
                   not4 = 1;
               if ( gs1 == 5 || gs2  == 5 || gs3 == 5 || gs4 == 5 ) 
                   not5 = 1; 
           } 
        // if statement for having right colors and rearranges guess til right
        if ( a2 == 4 || rightColo == 1 ) {
            while ( hisC == 0)   {
                temp = gs1;
                temp1 = gs2;
                temp2 = gs3;
                temp3 = gs4;
                currentVal = (gs1 * 1000) + (gs2 * 100) + (gs3 * 10 ) + gs4;
                changeVal0=0, changeVal1=0, changeVal2=0, changeVal3=0;
                while ( (temp != -1 || temp1 !=-1 || temp2 !=-1 || temp3 !=-1) ) { 
                rando = rand()%100;
                if ( changeVal0 == 0) {
                if ( rando < 25 && temp != -1 )  {
                        gs1 = temp;
                        temp = -1;
                        changeVal0 = 1;
                    }
                else if ( rando < 50 && temp1 != -1 ){
                        gs1 = temp1;
                        temp1 = -1;
                        changeVal0 = 1;
                    }
                else if ( rando < 75 && temp2 != -1 ) {
                        gs1 = temp2;
                        temp2 = -1;
                        changeVal0 = 1;
                    }
                else if ( temp3 != -1 ){
                        gs1 = temp3;
                        temp3 = -1;
                        changeVal0 = 1;
                    }
                }
                rando = rand()%100;
                if ( changeVal1 == 0 ) {
                if ( rando < 25 && temp != -1 ) {
                        gs2 = temp;
                        temp = -1;
                        changeVal1 = 1;
                    }
                else if ( rando < 50 && temp1 != -1 ){
                        gs2 = temp1;
                        temp1 = -1;
                        changeVal1 = 1;
                    }
                else if ( rando < 75 && temp2 != -1 ) {
                        gs2 = temp2;
                        temp2 = -1;
                        changeVal1 = 1;
                    }
                else if ( temp3 != -1 ){
                        gs2 = temp3;
                        temp3 = -1;
                        changeVal1 = 1;
                    }
                }
                rando = rand()%100;
                if ( changeVal2 == 0 ) {
                if ( rando < 25 && temp != -1 ) {
                        gs3 = temp;
                        temp = -1;
                        changeVal2 = 1;
                    }
                else if ( rando < 50 && temp1 != -1 ){
                        gs3 = temp1;
                        temp1 = -1;
                        changeVal2 = 1;
                    }
                else if ( rando < 75 && temp2 != -1 ) {
                        gs3 = temp2;
                        temp2 = -1;
                        changeVal2 = 1;
                    }
                else if ( temp3 != -1 ){
                        gs3 = temp3;
                        temp3 = -1;
                        changeVal2 = 1;
                    }
                }
                rando = rand()%100;
                if ( changeVal3 == 0  ) {
                if ( rando < 25 && temp != -1 ) {
                        gs4 = temp;
                        temp = -1;
                        changeVal3 = 1;
                    }
                else if ( rando < 50 && temp1 != -1 ){
                        gs4 = temp1;
                        temp1 = -1;
                        changeVal3 = 1;
                    }
                else if ( rando < 75 && temp2 != -1 ) {
                        gs4 = temp2;
                        temp2 = -1;
                        changeVal3 = 1;
                    }
                else if ( temp3 != -1 ){
                        gs4 = temp3;
                        temp3 = -1;
                        changeVal3 = 1;
                    }
                }
                rightColo = 1;
                }
                currentVal = (gs1 * 1000) + (gs2 * 100) + (gs3 * 10 ) + gs4;
                // checks history, rearrange guess for a different value
                for ( loopC = 0; loopC < h && changeVal0 && changeVal1 && changeVal2 && changeVal3 ; loopC++ ) {
                    if  ( currentVal == history[loopC] ) {  
                        hisC = 0; 
                        break;
                    }
                    else { hisC = 1; }    
                }// end for
            }// end while
        }// end if
        else { gs1=rand()%6; gs2=rand()%6; gs3=rand()%6; gs4=rand()%6; }
       currentVal = (gs1 * 1000) + (gs2 * 100) + (gs3 * 10 ) + gs4;
       if ( rightColo != 1 ) {
        // for loop to check what colors are not and changes guesses if that color
        for ( loopC = 0; loopC < h ; loopC++)
        {
            if ( not0 == 1 ) {
                if ( gs1 == 0 ) gs1++; 
                if ( gs2 == 0 ) gs2++;
                if ( gs3 == 0 ) gs3++;
                if ( gs4 == 0 ) gs4++;   
            }
            if ( not1 == 1 ) {
                if ( gs1 == 1 ) gs1++; 
                if ( gs2 == 1 ) gs2++;
                if ( gs3 == 1 ) gs3++;
                if ( gs4 == 1 ) gs4++;   
            }
            if ( not2 == 1 ) {
                if ( gs1 == 2 ) gs1++; 
                if ( gs2 == 2 ) gs2++;
                if ( gs3 == 2 ) gs3++;
                if ( gs4 == 2 ) gs4++;   
            }
            if ( not3 == 1 ) {
                if ( gs1 == 3 ) gs1++; 
                if ( gs2 == 3 ) gs2++;
                if ( gs3 == 3 ) gs3++;
                if ( gs4 == 3 ) gs4++;   
            }
            if ( not4 == 1 ) {
                if ( gs1 == 4 ) gs1++; 
                if ( gs2 == 4 ) gs2++;
                if ( gs3 == 4 ) gs3++;
                if ( gs4 == 4 ) gs4++;   
            }
            if ( not5 == 1 ) {
                if ( gs1 == 5 ) { 
                    gs1 = 0; 
                    if (not0 == 1 ) gs1++; 
                    if (not0 == 1 && not1 == 1 ) gs1++; 
                    if (not0 == 1 && not1 == 1 && not2 == 1 ) gs1++; 
                    if (not0 == 1 && not1 == 1 && not2 == 1 && not3 == 1 ) gs1++;
                }
                if ( gs2 == 5 ) {
                    gs2 = 0;
                    if (not0 == 1 ) gs2++; 
                    if (not0 == 1 && not1 == 1 ) gs2++; 
                    if (not0 == 1 && not1 == 1 && not2 == 1 ) gs2++; 
                    if (not0 == 1 && not1 == 1 && not2 == 1 && not3 == 1 ) gs2++; 
                }
                if ( gs3 == 5 ) { 
                    gs3 = 0;
                    if (not0 == 1 ) gs3++; 
                    if (not0 == 1 && not1 == 1 ) gs3++; 
                    if (not0 == 1 && not1 == 1 && not2 == 1 ) gs3++; 
                    if (not0 == 1 && not1 == 1 && not2 == 1 && not3 == 1 ) gs3++;    
                }
                if ( gs4 == 5 ) { 
                    gs4 = 0;  
                    if (not0 == 1 ) gs4++; 
                    if (not0 == 1 && not1 == 1 ) gs4++; 
                    if (not0 == 1 && not1 == 1 && not2 == 1 ) gs4++; 
                    if (not0 == 1 && not1 == 1 && not2 == 1 && not3 == 1 ) gs4++;
                }
            } 
            currentVal = (gs1 * 1000) + (gs2 * 100) + (gs3 * 10 ) + gs4;
            // checks history of past guess, changes if repeated
            while( currentVal == history[loopC] ) {
                gs1=rand()%6; gs2=rand()%6; gs3=rand()%6; gs4=rand()%6;
                currentVal = (gs1 * 1000) + (gs2 * 100) + (gs3 * 10 ) + gs4;
                loopC = 0;  
            }// end while  
        }// end for 
       }// end if 
      // stores guess into history 
      history[h] = currentVal;
      h++;
      hisC = 0; 
      fprintf(logf, "write  to controller: %d %d %d %d\n", gs1, gs2, gs3, gs4);
      printf(                             "%d %d %d %d\n", gs1, gs2, gs3, gs4);
      fflush(stdout);
      if (fgets(line,sizeof(line),stdin) < 0)
      {
          fprintf(logf,"End of input reached\n");
          fclose(logf);
          return;
      }
      if (sscanf(line,"%d%d", &a1, &a2) != 2)
      {
          fprintf(logf,"error: couldn't extract all 2 values!\n");
          return;
      }
      fprintf(logf, "read from controller: %d %d\n",a1,a2);
   } while (a1 < 4);
   fprintf(logf,"Done!\n");
   close(logf);

}

