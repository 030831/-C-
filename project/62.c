#include <stdio.h>
#include <time.h>  // 시간 계산 헤더파일
#include <stdlib.h> // exit 사용



/*
물고기가 6마리 있습니다.
어항에 살고있는데 , 사막에서 살고있기 떄문에 물을 계속 줘야합니다.
물이 다 증발하기전에 물을 계속 어항에 넣어줘야합니다.
어항에 물이 비게되면 물고기가 죽게 됩니다. 최대한 오랜 시간동안 물고기를 살리세요
*/
// 51. 프로젝트 
int level;
void printfFished();  //물 크기 출력 함수
void initData();  //처음에 물을 최대로 채워주는 함수
void decreaseWater(long elapsedTime);  //시간당 물 감소해주는 함수
int checkFishAlive();  //물고기가 모두 죽었는지 확인해주는 함수
int arrayFish[6];   // 물고기 배열 선언
int *cursor;  //물고기 어항에 물을 주는 변수


int main()
{

    long startTime= 0; //게임 시작 시간

    long totaltime=0 ; //총 경과 시간

    long prevtime=0; // 직전 경과 시간 (최근에 물을 준 시간 간격)


    int num;

    initData();

    cursor=arrayFish; //cursor[0] ... cursor[1] ...

    startTime=clock(); // 현재 시간을  밀리세컨드 단위로 반환

    while (1)
    {
        printfFished();
        printf("몇번 어항에 물을 주시겠어요?" );
        scanf("%d" , &num);

        if (num<1 || num>6)
        {
            printf("\n 입력 값이 잘못되었습니다\n");
            continue;
        }


        // 총 경과 시간
        totaltime=(clock() - startTime)/CLOCKS_PER_SEC; //초 단위로 바꿔줌
        printf("총 경과시간 : %ld 초\n" , totaltime);

        // 직전 물을 준 시간
        prevtime=totaltime-prevtime;
        printf("최근 경과 시간 : %ld 초 \n" , prevtime);

        //어항의 물을 감소
        decreaseWater(prevtime);

        // 사용자가 입력한 어항에 물을 준다.

        if (cursor[num-1]<=0) // 어항에 물이 전혀 없을때
        {
            printf("%d 번 물고기는 이미 죽었습니다... 물을 줄 수 없습니다\n" , num);
        }

        // 어항의 물이 0이 아닌경우 , 100을 넘지 않은지 체크

        else if (cursor[num-1]+1 <=100)  // 물을 줬을때 100이하이므로 +1을 해줌
        {
            printf("%d 번 어항에 물을 줍니다\n\n" , num);

            cursor[num-1]+=1;  // 물을 줌


        }

        //레벨업을 할건지 확인 (레벨업은 20초마다 한번씩 수행)

        if (totaltime/20 > level-1)
        {
            level++; // 레벨 1 증가
            printf(" *** 축 레벨업 ! 기존 %d 레벨에서 %d 레벨로 업그레이드 했습니다! *** \n\n" ,level-1 , level);

            //최종 레벨이 5일때 종료

            if (level==5)
            {
                printf("\n\n 축하합니다. 최고 레벨을 달성하였습니다. 게임을 종료합니다\n\n");
                exit(0); // 프로그램 종료
            }
        }

        //물고기가 죽었는지 확인

        if (checkFishAlive()==0)
        {
            printf("모든 물고기가 죽었습니다 \n");
            exit(0);  //물고기가 없으므로 게임 종료
        }
        else
        {
            printf("물고기가 아직 살아있어요!\n"); // 최소 한마리 이상의 물고기는 살아 있음
        }

        prevtime=totaltime;  // 10초-> 15초 (5초: prevtime) - > 25초가 남음. 따라서 10초를 따로 계산해줘야함 , prevtime -> 15초로 , 25초-15초는 10초


    }

    return 0;

      
}




void initData()
{
    level=1 ; //게임레벨 1~5

    for (int i=0 ; i<6 ; i++)
    {
        arrayFish[i]=100; //어항의 물 높이 (0~100)
    }
}


void printfFished()
{
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n" , 1,2,3,4,5,6);
    for (int i=0 ; i<6 ; i++)
    {
        printf(" %4d" , arrayFish[i]);
    }
    printf("\n\n");
}


void decreaseWater(long elapsedTime)
{
    for (int i=0 ; i<6 ; i++)
    {
        arrayFish[i]-= (level*3* (int)elapsedTime);  //3 : 난이도 조절을 위한 값

        if (arrayFish[i]<0)
        {
            arrayFish[i]=0;
        }
    }
}

int checkFishAlive()
{
    for (int i=0 ; i<6 ; i++)
    {
        if (arrayFish[i]>0)
        {
            return 1; //1은 True를 의미함

        }

        return 0; // 0은 False를 의미함
    }
}