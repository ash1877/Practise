/**The below code reads multiple entries of data, each entry containing three lines: presumably a name, 
a status (either "In" or "Out"), and a timestamp. 
It then processes these entries to determine the count of people "In" at a specific given time.**/
/** the question is to accept N records of R people in an office.the input format is 
eg: name status 25hrtimeforamt
A IN 09:20
B IN 09:32
c IN 09:08
B OUT 12:32

so the program has to print the count of people inside the office under the specific time
NOTE: the people in / on the timne 

**/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int r,n;
    scanf("%d %d",&r,&n);
    char entry[r][5][60];
    
    for(int block = 0;block < r;block++)
    {
        for(int row = 0;row < 3;row++)
        {
            scanf("%s ",entry[block][row]);
        }
    }
    int hr,min;
    scanf("%d:%d",&hr,&min);
    
    
    
 
    int count = 0,in = 0,out= 0,i = 0, o = 0;
    for(int block = 0;block < r;block++)
    {
        char value[10];
        strcpy(value,entry[block][2]);
        char status[5];
        strcpy(status,entry[block][1]);
        
        //printf("%c %s %s\n",name,status,value);
        
        
        int hour = 0 ,m = 0,flag = 0;
        
        for(int index = 0;index < 5;index++)
        {
            if(value[index] == ':')
            {
                flag = 1;
                continue;
            }
            if(flag == 0)
            {
                hour = hour * 10 + (value[index] - 48);
            }
            if(flag == 1)
            {
                m = m * 10 + (value[index] - 48);
            }
            
        }
        
        if(status[0] == 'I' || status[0] =='i')
        {
           
            
            if(hour < hr)
            count++;
            else if(hour == hr && m <= min)
            count++;
            
            
        }
        else if(status[0] == 'O' || status[0] == 'o')
        {
            
            
            if(hour < hr)
            count--;
            else if(hour == hr && m <= min)
            count--;
            
            
        }
    }
    
    //printf("%d",in - out);
   printf("%d ",count);
    
}
