#define MAXNUM 10
#define TRUE '1'
#define FALSE '0'
#define SEQ_TIME_START 1
#define SEQ_TIME_END 2
#define CHARNUM "0000000000"
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    int place;
    int time;
    char is_Sit;
}Cy;

Cy cyclone[MAXNUM];
int times[MAXNUM];
int seats;

void Init();
void Get_Input_N_Disassemble();
int Char_To_Int(char num[MAXNUM], int max_pos);


void Init()
{
    for(int i=0; i<MAXNUM; ++i)
    {
        cyclone[i].place = i;
        cyclone[i].is_Sit = FALSE;
        times[i] = 0;
        seats = 0;
    }
}

void Get_Input_N_Disassemble()
{
    char input[100];
    char num_temp[MAXNUM];
    int time_pos = 0, num_pos = 0;
    int is_seat_phase = SEQ_TIME_START;  // 0이면 times, 1이면 seats

    scanf(" %[^\n]", input);  // 공백 포함해서 전체 한 줄 입력 받기

    for (int i = 0; i < strlen(input); ++i)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            num_temp[num_pos++] = input[i];
        }
        else if (input[i] == ',')
        {
            if (is_seat_phase == SEQ_TIME_START)
            {
                times[time_pos++] = Char_To_Int(num_temp, num_pos);
            }
            else
            {
                seats = Char_To_Int(num_temp, num_pos);
            }
            memset(num_temp, 0, sizeof(num_temp));
            num_pos = 0;
        }
        else if (input[i] == '}')
        {
            times[time_pos++] = Char_To_Int(num_temp, num_pos);
            memset(num_temp, 0, sizeof(num_temp));
            num_pos = 0;
            is_seat_phase = SEQ_TIME_END;  // 이제부터는 seat 값 파싱
        }
    }

    // 마지막 숫자가 남아있다면 (예: seats = 5)
    if (num_pos > 0)
    {
        seats = Char_To_Int(num_temp, num_pos);
    }
}


int Char_To_Int(char num[MAXNUM], int max_pos)
{
    int ans = 0;
    for(int i = 0; i < max_pos; ++i)
    {
        ans = ans * 10 + (num[i] - '0');
    }
    return ans;
}

int main()
{
    Init();

    Get_Input_N_Disassemble();
    
    

    return 0;
}