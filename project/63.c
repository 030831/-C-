#include <stdio.h>
#include <time.h>    // 시간 계산 헤더파일
#include <stdlib.h>  // 랜덤값 계산 헤더 파일


//59.프로젝트 

/*
10마리의 서로 다른 동물 (각 카드 2장씩)
사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
모든 동물 쌍을 찾으면 게임 종료
총 실패 횟수 마지막에 알려주기
*/


int arrayAnimal[4][5];   // 전체 카드 20장 선언
int checkAnimal[4][5];  //뒤집혔는지 여부 확인 배열
void initAnimalArray();
char *strAnimal[10];  //포인터형 캐릭터 10개 생성
void initAnimalName(); // 동물 이름 선언 함수
void shuffleAnimal(); // 동물 무작위 배치 함수
int getEmptyPosition(); // 카드를 만들때 비어있는 카드 배치 함수
int conv_pos_x(int x);  // 랜덤숫자가 19일때 (3,4)로 변환해주는 함수 
int conv_pos_y(int y);
void printAnimals(); //동물 위치 출력
void printQuestions(); // 문제 출력 (카드 지도)
int foundAllAnimal(); //모든 동물을 다 찾았는지 찾는 함수

int main()
{

    srand(time(NULL));

    initAnimalArray();
    initAnimalName();

    shuffleAnimal(); 

    int failCount=0; // 실패횟수

    while (1)
    {
        int select1=0 ; //사용자가 처음 선택한 수
        int select2=0 ; //사용자가 두번쨰로 선택한 수

        // printAnimals(); //동물 위치 출력
        printQuestions(); // 문제 출력 (카드 지도)
        printf("뒤집을 카드 2개를 고르세요");
        scanf("%d %d" , &select1 , &select2);

        if (select1==select2) // 같은 카드 선택시 무효
            continue;

        int firstSelect_x=conv_pos_x(select1);   //처음 선택한 카드의 x좌표
        int firstSelect_y=conv_pos_y(select1);    //처음 선택한 카드의 y좌표

        int secondSelect_x=conv_pos_x(select2);  //두번쨰로 선택한 카드의 x좌표  
        int secondSelect_y=conv_pos_y(select2);  //두번쨰로 선택한 카드의 y좌표

        if ( checkAnimal[firstSelect_x][firstSelect_y]==0 && checkAnimal[secondSelect_x][secondSelect_y]==0 // 카드가 뒤집히지 않았는지
            && arrayAnimal[firstSelect_x][firstSelect_y]==arrayAnimal[secondSelect_x][secondSelect_y])   // 두 동물이 같은지

        {
            printf("\n\n 빙고! : %s 발견 \n\n" , strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            checkAnimal[firstSelect_x][firstSelect_y]=1;  //정답 카드는 중복되지않게 하기위해서 확인 처리
            checkAnimal[secondSelect_x][secondSelect_y]=1; 
        }
        else
        {
            printf("\n\n 땡!! 틀렸거나 이미 뒤집힌 카드입니다 \n");
            printf("%d : %s\n" , select1 , strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d : %s\n" , select2 , strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
            printf("\n\n");

            failCount++; // 실패 횟수 1 추가
        }

        if (foundAllAnimal()==1)  // 모든 동물을 다 찾았는지 여부 , 1은 참 0은 거짓
        {
            printf("\n\n 축하합니다 ! 모든 동물을 다 찾았습니다!\n");
            printf("지금까지 총 %d번 실수하였습니다 \n" , failCount);
            break;
        }
    }

}


void initAnimalArray()
{
    for (int i=0 ; i<4 ; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            arrayAnimal[i][j]=-1;

        }
    }
}

void initAnimalName()
{
    strAnimal[0]= "원숭이";
    strAnimal[1]= "하마";
    strAnimal[2]= "강아지";
    strAnimal[3]= "고양이";
    strAnimal[4]= "돼지";
    strAnimal[5]= "코끼리";
    strAnimal[6]= "기린";
    strAnimal[7]= "낙타";
    strAnimal[8]= "타조";
    strAnimal[9]= "호랑이";


}

void shuffleAnimal()
{
    for (int i=0 ; i<10 ; i++)
    {
        for (int j=0 ; j<2 ; j++)
        {
            int pos=getEmptyPosition();
            int x=conv_pos_x(pos);
            int y=conv_pos_y(pos);

            arrayAnimal[x][y]=i;

        }
    }
}


int getEmptyPosition() // 좌표에서 빈공간 찾기
{

    while (1)
    {
        int randPos=rand()%20; //0~19사이의 숫자 반환
        int x=conv_pos_x(randPos);
        int y=conv_pos_y(randPos); 

        if (arrayAnimal[x][y]==-1)
        {
            return randPos;
        }

    }

    return 0;
}



int conv_pos_x(int x) 
{
    return x/5;
}


int conv_pos_y(int y)

{
    return y%5; // 19일때 몫은 3 나머지는 4 이므로 (3,4)가 됨
}


void printAnimals() //동물 위치 출력
{

    for (int i=0 ; i<4 ; i++)
    {
        for (int j=0 ; j<5 ; j++)
        {
            printf("%8s" , strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n============================'\n\n");
}

void printQuestions() // 문제 출력 (카드 지도)
{


    printf("\n\n(문제)\n");
    int seq=0; //  카드 체크 확인변수


    for (int i=0 ; i<4 ; i++)
    {
        for (int j=0 ; j<5 ; j++)  //카드를 뒤집어서 정답이면 동물 이름 출력 , 아직 뒤집지 못했으면 뒷면은 숫자로 출력
        {
            if (checkAnimal[i][j]!=0)
            {
                printf("%8s" , strAnimal[arrayAnimal[i][j]]);
            }
            else
            {
                printf("%8d" , seq);
            }
            seq++;
        }
        printf("\n");
    }


}

int foundAllAnimal()
{
    for (int i=0 ; i<4 ; i++)
    {
        for (int j=0 ; j<5 ; j++)
        {
            if (checkAnimal[i][j]==0)
            {
                return 0;
            }
        }
    }

    return 1;
}