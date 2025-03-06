#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack *s, int max) // 스택의 초기화, 이때 최대 용량을 정해두고 초기화한다
{
    s->ptr = 0; // 초기 시작 위치는 0
    if ((s->stk = calloc(max, sizeof(int))) == NULL)
    {
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(IntStack *s, int x) // 스택에 데이터 푸시
{
    if(s->ptr >= s->max) //스택이 가득찬 경우
    {
        return -1;      //불가능하다고 반환
    }
    
    s->stk[s->ptr++] = x;   //stack의 포인터 위치에 x를 저장하고, 포인터 값을 +1 해주면서 다음 포인터 지정할 준비를 마침
    return 0;
}

int Pop(IntStack *s, int *x) // 스택에 데이터 팝, 스택에서 데이터를 가져오는 것이기에 포인터를 활용한다
{
    if(s->ptr <= 0) //스택이 비어있는 경우
    {
        return -1;
    }
    
    *x = s->stk[--s->ptr];  //stack의 포인터에서 미리 1을 뺀 위치에 있는 값을 가져오도록 시킴, 그래야 빈 공간이 아닌 최근의 값에서 가져올 수 있기 때문
    return 0;
}

int Peek(const IntStack *s, int *x) // 스택에서 데이터를 피크, 스택의 꼭대기 데이터를 몰래 엿보는 함수
{
    if(s->ptr <= 0) //스텍이 비어있는 경우
    {
        return -1;
    }

    *x = s->stk[s->ptr - 1];    //pop과 비슷하지만, 다른 점으로는 ptr을 변화시키지 않고 값만 본다는 차이점 존재
    return 0;
}

void Clear(IntStack *s) // 스택 모든 요소 삭제, 스택 자체는 유지
{
    s->ptr = 0; //포인터를 0으로 초기화 시키면, 직접 포인터를 움직이는 것이 아니니 사실상 초기화와 같은 동작이 됨
}

int Capacity(const IntStack *s) // 스택의 용량을 알려주는 것, max를 반환하게 된다
{
    return s->max;
}

int Size(const IntStack *s) // 스택의 데이터의 갯수를 알려주는 것, ptr을 반환하게 된다
{
    return s->ptr;
}

int IsEmpty(const IntStack *s) // 스택이 비었는지 검사하는 함수
{
    return s->ptr <= 0;
}

int IsFull(const IntStack *s) // 스택이 가득 찼는지 검사하는 함수
{
    return s->ptr >= s->max;
}

int Search(const IntStack *s, int x) // 스택에서 임의의 값 x가 스택의 어느 위치에 있는지 검사하는 함수, 위에서부터 검색해서 내려온다
{
    for(int i = s->ptr - 1; i >= 0; --i)
    {
        if(s->stk[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void Print(const IntStack *s) // 스택의 모든 데이터를 출력하는 함수
{    
    for(int i=0; i < s->ptr; ++i)
    {
        printf("%d ", s->stk[i]);
    }
    puts("");
}

void Terminate(IntStack *s) // 스택을 아예 삭제시키는 함수, Init으로 생성하고 확보한 공간을 Free시켜준다
{
    if(s->stk != NULL)
    {
        free(s->stk);
    }
    s->max = s->ptr = 0;
}
