//69.프로젝트 코드

#include <stdio.h>
#include <time.h>    // 시간 계산 헤더파일
#include <stdlib.h>  // 랜덤값 계산 헤더 파일

// 5마리의 고양이가 있습니다.
// 아무 키나 눌러서 랜덤으로 고양이를 뽑되 , 5마리 모두 뽑아서 키우는 게임입니다.
// 중복 발생 가능하며 고양이마다 서로 다른 특징이 있습니다.


//특징은 이름 , 나이 , 성격 , 키우기 난이도(레벨)이 존재합니다.


typedef struct
{
    char *name;   //이름
    int age;     //나이
    char *characrter; //성격
    int level;   //키우기 난이도 (1~5)
} CAT;  //구조체의 별명을 CAT로 정의


int collections[5]={0,0,0,0,0};  //현재 보유한 고양이
CAT cats[5]; //고양이 리스트
void initCats() ; //고양이 정보 초기화
void printCat(int selected); //고양이 정보 출력 함수
int checkCollection(); //고양이 모드 뽑았는지 확인 함수


int main()
{
    srand(time(NULL));

    initCats();

    while (1)
    {
        printf("두근두근~! 어느 고양이의 집사가 될까요? \n 아무키나 눌러서 확인하세요!");
        getchar();  //키 입력 대기

        int selected=rand()%5; // 0~4사이 숫자 반환
        printCat(selected); //뽑은 고양이 출력 함수
        collections[selected]=1;   // 고양이 뽑기 처리하기


        int collectAll= checkCollection(); //고양이를 모두 뽑았는지 확인
        if (collectAll==1) // 고양이를 다 모았다면 종료
        {
            break;
        }


    }
    return 0;
}

void initCats()
{
    cats[0].name="티티";
    cats[0].age=5;
    cats[0].characrter="온순함";
    cats[0].level=1;

    cats[1].name="모모";
    cats[1].age=3;
    cats[1].characrter="날카로움";
    cats[1].level=2;

    cats[2].name="루루";
    cats[2].age=7;
    cats[2].characrter="늘 잠만 잠";
    cats[2].level=3;

    cats[3].name="도도";
    cats[3].age=2;
    cats[3].characrter="시끄러움";
    cats[3].level=4;

    cats[4].name="라라";
    cats[4].age=1;
    cats[4].characrter="배고픔";
    cats[4].level=5;

}

void printCat(int selected)
{
    printf("\n\n 당신은 이 고양이 집사가 되었습니다! ====\n\n");
    printf("이름          : %s\n" , cats[selected].name);
    printf("나이          : %d\n" , cats[selected].age);
    printf("특징(성격)     : %s\n" , cats[selected].characrter);
    printf("레벨          : ");

    for (int i=0 ; i<=cats[selected].level ; i++)
    {
        printf("%s" , "★ ");
        
    }
    
    printf("\n\n");

}

int checkCollection()
{
    //현재 보유한 고양이 목록 출력 및 다모았는지 여부 확인

    int collectAll=1; //없는 고양이 체크

    printf("\n\n == 보유한 고양이 목록이에요 ==\n\n");

    for (int i=0; i<5 ; i++)
    {
        if (collections[i]==0)  //고양이가 없을떄 빈 박스 출력
        {
            printf("%10s" , "(빈 박스)");
            collectAll=0;  //다 모으지 못한 상태


        }
        else   //고양이를 수집했을때 이름 출력
        {
            printf("%10s" , cats[i].name);
        }


    }
    printf("\n==============================\n\n");

    if (collectAll) //모든 고양이를 모았을때
    {
        printf("\n\n 축하합니다! 모든 고양이를 다 모았습니다! 열심히 키워주세요~!\n\n");
    }


    return collectAll;
}