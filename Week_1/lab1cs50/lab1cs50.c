#include <stdio.h>

int main(){
    int nStart, nEnd, ctYear = 0, nAdd = 0, nMinus = 0;
    do{
    printf("Start size: ");
    scanf("%d", &nStart);
    }
    while(nStart < 9);

    do{
    printf("End size: ");
    scanf("%d", &nEnd);
    }
    while(nEnd < nStart);

    while(nStart != nEnd && nStart < nEnd){
        nAdd = nStart/3;
        nMinus = nStart/4;
        nStart = nStart + (nAdd - nMinus);
        ctYear++;
    }

    printf("Year: %d", ctYear);

    return 0;
}