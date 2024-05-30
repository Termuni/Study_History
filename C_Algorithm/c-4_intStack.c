#include<stdio.h>
#include<stdlib.h>
#include"c-4_intStack.h"

int Initialize(IntStack *s, int max){
    //구조체에서 해당 요소 호출 하는 방법 : "->"
    s->ptr = 0;     //배열 위한 메모리 공간 만들 때 스택은 비어 있어야 하므로 ptr = 0
    if((s->stk = calloc(max, sizeof(int))) == NULL){    
        //배열 생성 실패시, 즉 공간이 부족한 경우 : 내부 값의 stk가 NULL이 되면서 if가 True로 판단됨
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(IntStack *s, int x){
    if(s->ptr >= s->max){   //스택이 가득 찬 것을 확인하는 작업
        return -1;
    }
    s->stk[s->ptr++] = x;   //스택 포인터(정수)가 가르키는 자리의 배열? 포인터? 값에 받은 int값을 넣어주고, 그 다음줄에 ptr값 +1 예약
    return 0;
}

int Pop(IntStack *s, int x){
    if(s->ptr <= 0){        //스택이 비어있음
        return -1;
    }
    *x = s->stk[--s->ptr];
}