

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
   char line[128];

   int gs1, gs2, gs3, gs4;
   int a1, a2;
   FILE *logf;
   logf = fopen("codeBreaker.log","w");

   srand(0);
   
   do {

      gs1=rand()%6; gs2=rand()%6; gs3=rand()%6; gs4=rand()%6;

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

