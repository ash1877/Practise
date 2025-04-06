#include<stdio.h>
#include<stdlib.h>
int main()
{
   
    
    int n;
    scanf("%d",&n);
    int **arr;
    int rows = 5, cols = 4;
    
    // Allocate memory for row pointers
    arr = (int **)malloc(n * sizeof(int *));
    
    // Allocate memory for each row
    for (int i = 0; i < n; i++) 
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    
    for(int row =0;row < n;row++)
    {
        for(int col = 0;col < n;col++)
        {
            scanf("%d",&arr[row][col]);
        }
    }
    
    
    int row_ps[10],col_ps[10]; // store the row and column position of each occurence of the zero in the matrix
    int index = 0;


// loop thru matrix and change the zero to sum of its neighbours 
    for(int row = 0;row < n;row++)
    {
        for(int col = 0;col < n;col++)
        {
              if(arr[row][col] == 0)
              {
                  int sum = 0;
                  sum += col + 1 < n?arr[row][col + 1]:0;
                  sum += col - 1 >= 0?arr[row][col - 1]:0;
                  sum += row - 1>=0?arr[row - 1][col]:0;
                  sum += row + 1 < n?arr[row + 1][col]:0;
                  
                 arr[row][col] =sum;
                 row_ps[index] = row;
                 col_ps[index]  =col;
                  index++;
                  
              }
        }
        
    }
    
  
    for(int i = 0;i < index;i++)
    {
        
        int row = row_ps[i];
        int col = col_ps[i];
        
          if (col + 1 < n) 
            arr[row][col + 1] = 0;
          if (col - 1 >= 0)
            arr[row][col - 1] = 0;
          if (row - 1 >= 0) 
            arr[row - 1][col] = 0;
          if (row + 1 < n) 
            arr[row + 1][col] = 0;
        
    }

        printf("##########\n");
    for(int row =0;row < n;row++)
    {
        for(int col = 0;col < n;col++)
        {
            printf("%d ",arr[row][col]);
        }
        printf("\n");
    }
    


    return 0;
}
