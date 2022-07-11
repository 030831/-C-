#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//43. 프로젝트

int main()
{
    printf("\n\n === 아빠는 대머리 게임 ==\n\n");
    int answer; //사용자 입력값

    int treatment=rand()%4; //발모제 선택

    int cntShowBottle=0; //이번 게임에 보여줄 병 개수

    int preCntShowBottle=0; //앞 게임에 보여준 병 개수

    for (int i=0 ; i<3 ; i++)
    {
        int bottle[4]={0,0,0,0}; // 4개의 병 생성

        do
        {
            cntShowBottle=rand()%2+2; // 보여줄 병개수 (0~1)+2 ->  2,3

        } while (cntShowBottle == preCntShowBottle);
        preCntShowBottle=cntShowBottle;
    
        int inIncluded=0; // 보여줄 병 중 발모제가 포함됬는지 여부
        printf(" > %d 번째 시도 "  , i ) ;

        for (int j=0 ; j<cntShowBottle ; j++)
        {
            int randBottle=rand()%4; // 0~3

            //아직 선택되지 않은 병이면 , 선택 처리

            if (bottle[randBottle]==0)
            {
                bottle[randBottle]=1;
                if (randBottle==treatment)
                {
                    inIncluded=1;
                }
            }

            // 이미  선택된 병이면 중복이므로 다시 선택
            else
            {
                j--;
            }
        }

        //사용자에게 문제 표시

        for (int k=0 ; k<4 ; k++)
        {
            if (bottle[k]==1)
            {
                printf("%d" , k+1);
            }

        }

        
        printf(" 물약을 머리에 바릅니다 \n\n");

        if (inIncluded==1)
        {
            printf(" >> 성공! 머리가 났어요 \n\n");
        }
        else 
        {
            printf(" >> 실패! 머리가 나지 않았어요\n\n");
        }

        printf("\n ... 계속하려면 아무 키나 누르세요...");
        getchar();

    }    

    printf("\n\n 발모제는 몇번일까요?");

    scanf("%d" , &answer);
    if (answer-1==treatment)
    {
        printf("\n >> 정답입니다! \n");
    }    

    else
    {
        printf("\n >> 땡! 틀렸어요,  정답은 %d 입니다" , treatment+1);
    }

    return 0;
}