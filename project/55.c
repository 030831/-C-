#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//26 번 프로젝트



int main()
{
    srand(time(NULL));

    int num=rand()%100+1; //0~2반환


    printf("%d", num);

    int answer=0; //정답

    int chance=5; //기회


    while (1)

    {
        printf("남은 기회는 %d번 남았습니다\n" , chance--);
        printf("숫자를 맞춰보세요 (1~100): \n") ;
        scanf("%d" , &answer);

        if (answer>num)
        {
            printf("Down \n");
        }

        else if (answer<num)
        {
            printf("UP \n");

        }

        else if (answer==num)
        {
            printf("정답입니다! \n");
            break;
        }

        else
        {
            printf("알수없는 오류가 발생했습니다. \n ");
        }

        if (chance==0)
        {
            printf("모든 기회를 다 사용하셨네요 , 아쉽게 패배했습니다. \n");
            break;
        }
    }


    return 0;
}