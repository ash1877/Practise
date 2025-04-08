#include<stdio.h>



int main(){
  int n = 5;
    int val = n + n - 1;
    for(int row = 0; row < n; row++, val -= 2) 
    {
        for(int col = 0; col < val - 1; col++) 
        {
            if(col == 0)
                printf("*");
            else
                printf(" ");
        }
        printf("*");
        printf("\n");
    }
 
return 0;
      }
