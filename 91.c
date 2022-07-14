#include <stdio.h>

int main()

{

    int a;
    scanf("%d" , &a);
    int b=1;                       

    for (int i=a-1 ; i>=0 ; i--)

    { 

        for (int j=i-1 ; j>=0; j--) 

        { printf(" "); 

        } 

        for (int k=1 ; k<=b ; k++ )

        { printf("*"); 

        } 

        b+=2; 



        printf("\n"); 
        

     } 

return 0;

}

