#ifndef ___IntStack
#define ___IntStack

typedef struct
{
    int max;
    int ptr;
    int *stk;
} IntStack;

int Initialize(IntStack *s, int max); // 스택의 초기화, 이때 최대 용량을 정해두고 초기화한다

int Push(IntStack *s, int x); // 스택에 데이터 푸시

int Pop(IntStack *s, int *x); // 스택에 데이터 팝, 스택에서 데이터를 가져오는 것이기에 포인터를 활용한다

int Peek(const IntStack *s, int *x); // 스택에서 데이터를 피크, 스택의 꼭대기 데이터를 몰래 엿보는 함수

void Clear(IntStack *s); // 스택 모든 요소 삭제, 스택 자체는 유지

int Capacity(const IntStack *s); // 스택의 용량을 알려주는 것, max를 반환하게 된다

int Size(const IntStack *s); // 스택의 데이터의 갯수를 알려주는 것, ptr을 반환하게 된다

int IsEmpty(const IntStack *s); // 스택이 비었는지 검사하는 함수

int IsFull(const IntStack *s); // 스택이 가득 찼는지 검사하는 함수

int Search(const IntStack *s, int x); // 스택에서 임의의 값 x가 스택의 어느 위치에 있는지 검사하는 함수, 위에서부터 검색해서 내려온다

void Print(const IntStack *s); // 스택의 모든 데이터를 출력하는 함수

void Terminate(IntStack *s); // 스택을 아예 삭제시키는 함수, Init으로 생성하고 확보한 공간을 Free시켜준다

#endif