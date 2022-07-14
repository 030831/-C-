#include <stdio.h>

int main(){
    int T;

    scanf("%d"  , &T);
    char arr1[20]={} , arr2[16]={};

    int maxyear=0,maxmonth=0,maxday=0,minyear=10000,minmonth=100,minday=50;
    for (int i=0 ; i<T ; i++){
        char name[16] ; int day ; int month ; int year;

        scanf("%s %d %d %d", name , &day , &month , &year);
        if (year<minyear){
            minyear=year;
            minmonth=month;
            minday=day;

            for (int i=0 ; i<16 ; i++){
                    arr1[i]=name[i];

            }
        }

        else if (year==minyear){
            if (month<minmonth){
                minmonth=month;
                minday=day;
                for (int i=0 ; i<16 ; i++){
                    arr1[i]=name[i];
            }
            }
            
            else if(month==minmonth){
                if (day<minday){
                minday=day;
                for (int i=0 ; i<16 ; i++){
                        arr1[i]=name[i];
                }
            }
            }
        }

    
        if (year>maxyear){
            maxyear=year;
            maxmonth=month;
            maxday=day;
            for (int i=0 ; i<16 ; i++){
                arr2[i]=name[i];
            }
        }
        
        else if (year==maxyear){
            if (month>maxmonth){
            maxmonth=month;
            maxday=day;
            for (int i=0 ; i<16 ; i++){
                    arr2[i]=name[i];
            }
            }
        
            else if(month==maxmonth){
                if (day>maxday){
                maxday=day;
                for (int i=0 ; i<16 ; i++){
                        arr2[i]=name[i];
                }
                }
            }
        }
              
    }
    printf("%s\n%s",arr2,arr1);
    return 0; 
}