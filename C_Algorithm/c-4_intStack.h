//스택 : LIFO(Last In First Out)
//push 와 pop 을 사용하여 넣고 빼기 동작 실행
//함수 또한 push/pop을 사용하여 넣고 뺌

//스택을 구현하는 함수 제작


//int형 스택 IntStack(헤더)
#ifndef ___IntStack
#define ___IntStack

//스택 구현 구조체
typedef struct 
{
    int max;    //스택 용량
    int ptr;    //스택 포인터
    int *stk;   //스택의 첫 요소에 대한 포인터
}IntStack;

//스택 초기화
int Initialzie(IntStack *s, int max);

//스택에 데이터를 푸시
int Push(IntStack *s, int x);

//스택에서 데이터를 팝
int Pop(IntStack *s, int *x);

//스택에서 데이터를 피크
int Peek(const IntStack *s, int *x);

//스택 비우기
void Clear(IntStack *s);

//스택의 최대 용량
int Capacity(const IntStack *s);

//스택의 데이터 개수
int Size(const IntStack *s);

//스택이 비어있는지 확인해서 0 or 1을 반환
//c언어에서는 bool이 기본 자료형이 아니기 때문에 int로 반환
int IsEmpty(const IntStack *s);

//스택이 가득 차있는지 확인해서 0 or 1을 반환
int IsFull(const IntStack *s);

//스택에서 검색
int Search(const IntStack *s, int x);

//모든 데이터 출력
void Print(const IntStack *s);

//스택 종료
void Terminate(IntStack *s);

#endif