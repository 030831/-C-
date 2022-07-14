#include <stdio.h>

int main(){
    int T;
    scanf("%d" , &T);
    for (int i=0 ; i<T ; i++){
        char arr[101][21]={ };
        int a,max=0, index;
        scanf("%d" , &a);

        for (int j=0; j<a; j++){
            long long int value;
            scanf("%lld %s" , &value, &arr[j]);
            if (value>max){
                index=j;
                max=value;
            }
            
            
        }

    printf("%s\n" , arr[index]);
    }
 6
    return 0;
}
