//76. 프로젝트


//비밀번호를 입력받아서 맞는 경우 일기를 읽고 작성하도록 합니다.
// 틀린 경우 경고 메세지를 표시하고 종료합니다

#include <stdio.h>
#include <conio.h> //getch 함수 사용을 위한 라이브러리
#include <string.h>    // strcmp 함수가 선언된 헤더 파일
#define MAX 10000 //일기 최대 길이는 10000으로 작성

int main()
{

    char line[MAX]; //파일에서 불러온 내용을 저장할 변수
    char contents[MAX]; //일기장에 입력할 내용
    char password[20]; //비밀번호 입력


   

    char c; // 비밀번호 입력할때 가리는 용도 (마스킹)

    printf("비밀 일기에 오신것을 환영합니다!\n");
    printf("비밀번호를 입력하세요 : ");

    int i=0;

    while (1)
    {
        c=getch(); // 키 입력시 바로 동작

        if (c==13)  //13번은 아스키코드로 Enter
        {
            break;
        }
        else
        {
            printf("*");
            password[i]=c;
        }
        i++;
    }

    //비밀번호 : 나도코딩(skehzheld)
    printf("\n\n == 비밀번호 확인중... ====\n\n");
    if (strcmp(password , "skehzheld")==0)  //strcmp를 통해 비밀번호 확인하기
    {
        printf("=== 비밀번호 확인 완료 ===\n\n");
        char *fileName="Note.txt";
        FILE *file=fopen(fileName , "a+b"); // 파일이 없으면 생성 , 파일이 있으면 뒤에서 부터 내용 추가

        if (file==NULL)
        {
            printf("파일 열기 실패\n");
            return 1;

        }

        while (fgets(line , MAX , file)!=NULL)  // 파일 읽기
        {
            printf( "%s" , line);
        }

        printf("\n\n 내용을 계속 작성하세요! 종료하실려면 EXIT를 입력하세요\n\n");

        while (1)
        {
            scanf("%[^\n]" , contents); // \n이 나오기 전까지 읽어들임
            getchar(); // Enter 입력 처리

            if (strcmp(contents, "EXIT")==0) // EXIT를 입력했다면 그만 작성
            {
                printf("비밀 일기 입력을 종료합니다\n\n");
                break;
            } 
            fputs(contents , file); //일기 작성
            fputs("\n" , file); // 파일에 줄바꿈 넣기
        }
        
        fclose(file); // 파일 닫기

    }
    else // 비밀번호가 틀린 경우
    {
        printf(" === 비밀번호가 틀렸습니다 ==\n\n");
        
    }

    return 0;
}