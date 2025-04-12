#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1000000

char input[MAXLENGTH + 1];
char bomb[37]; // 폭탄 문자열은 최대 36글자 (문제에 따라 조정)
char answer[MAXLENGTH + 1];

void Print_Input(int input_pos)
{
    printf("INPUT : ");
    for(int i=0; i<input_pos; ++i)
    {
        printf("%c",input[i]);
    }
    puts("");
}
void Print_Answer()
{
    printf("ANSWER : %s\n\n", answer);
}

int main() {
    scanf("%s %s", input, bomb);
    int input_len = strlen(input);
    int bomb_len = strlen(bomb);
    int input_pos = 0;

    for (int i = 0; i < input_len; ++i)
    {
        answer[input_pos++] = input[i];
        Print_Input(input_pos);
        if (input_pos >= bomb_len)
        {
            int isBomb = 1;
            for (int j = 0; j < bomb_len; ++j) 
            {
                if (answer[input_pos - bomb_len + j] != bomb[j])
                {
                    isBomb = 0;
                    break;
                }
            }
            if (isBomb)
            {
                input_pos -= bomb_len; // 폭탄 제거
            }
        }
        Print_Answer();

    }

    if (input_pos == 0)
    {
        printf("FRULA\n");
    } 
    else
    {
        answer[input_pos] = '\0'; // 문자열 끝 처리
        printf("%s\n", answer);
    }

    return 0;
}
