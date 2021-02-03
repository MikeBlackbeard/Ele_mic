#include <stdio.h>
int main(){
for(;;){
  printf("----Press 1 to open Window-------\n");
  printf("----Press 2 to semi open window--\n");
  printf("----Press 3 to close window------\n");
  printf("----Press 4 to open all window---\n");
  printf("----Press 5 to Close all window--\n");
  int x  ;
  scanf("%d",&x);
  switch (x)

   {
       case 1: printf("Window Open.\n");
               break;
       case 2: printf("Window is Semiopen.\n");
                break;
       case 3: printf("Window is Closed.\n");
               break;
       case 4: printf("All Window is Open.\n");
                    break;
       case 5: printf("All Window is closed.\n");
                   break;
       default: printf("Please choose the correct number! \n");
                break;
   }
}
   return 0;
}
