/*
문제
남극에 사는 김지민 선생님은 학생들이 되도록이면 많은 단어를 읽을 수 있도록 하려고 한다.
그러나 지구온난화로 인해 얼음이 녹아서 곧 학교가 무너지기 때문에, 김지민은 K개의 글자를 가르칠 시간 밖에 없다.
김지민이 가르치고 난 후에는, 학생들은 그 K개의 글자로만 이루어진 단어만을 읽을 수 있다.
김지민은 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지 고민에 빠졌다.

남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다.
남극언어에 단어는 N개 밖에 없다고 가정한다.
학생들이 읽을 수 있는 단어의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 단어의 개수 N과 K가 주어진다.
N은 50보다 작거나 같은 자연수이고, K는 26보다 작거나 같은 자연수 또는 0이다.
둘째 줄부터 N개의 줄에 남극 언어의 단어가 주어진다.
단어는 영어 소문자로만 이루어져 있고, 길이가 8보다 크거나 같고, 15보다 작거나 같다.
모든 단어는 중복되지 않는다.

출력
첫째 줄에 김지민이 K개의 글자를 가르칠 때, 학생들이 읽을 수 있는 단어 개수의 최댓값을 출력한다.


예제입력 1
3 6
antarctica
antahellotica
antacartica

예제출력 1
2

예제입력 2
2 3
antaxxxxxxxtica
antarctica

예제출력 2
0

예제입력 3
9 8
antabtica
antaxtica
antadtica
antaetica
antaftica
antagtica
antahtica
antajtica
antaktica

예제출력 3
3

*/

/*
우선 기본적으로 가르침을 받아야 하는 언어 5개
-> a, c, i, n, t

가르침을 받은 언어는 제외하고, 나머지 언어에서 선택해서 최대가 되는 경우를 찾아주어야 함

모든 조합을 대상으로 전부 확인하고, 그 중 최대가 되는 숫자를 찾아서 반환한다?
만약 최대로 동작하는 경우
N 50
K 25

-> 실제로는 뺄거 다 빼면 50개의 단어에 대해서 20개를 어떤 것을 선정해야 최선의 결과가 나오는지 볼 수 있는 것

21개 알파벳 중 조합상으로는 10개 고르는 경우가 제일 많은 것 같음, 21C10 =< 36만가지 => 36만 * 26 = 8MB
각 조합을 만들고 50개 단어에 대해서 계산한 뒤 나온 결과를 저장한다? 그러고 가장 큰 값 반환?

조합을 만드는 방법은?
char[360000][26] 으로 정의한 뒤, 각 조합을 만들어둔다

그 다음 그 조합에 따라 N개 단어를 비교한다.

~~~~~ 근데?!!?!! 이 아이디어를 가지고 GPT한테 물어보니, 더 좋은 방법을 추천받았다!
그것은 바로 비트마스크(Bit-Mask) 방식
어차피 int = 32bit 니까, 이걸 a~z까지 표현하는 것으로 대체 가능

*/
#include <stdio.h>
#include <string.h>

#define MAX_N 50
#define ALPHA 26

int N, K, max_count = 0;
char words[MAX_N][16]; // 단어 저장 (최대 길이 15)
int learned[ALPHA];    // 배운 글자 여부 (1: 배움, 0: 안 배움)

// 주어진 글자로 읽을 수 있는 단어 개수 계산
int count_readable_words()
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int readable = 1;
        for (int j = 0; words[i][j] != '\0'; j++)
        {
            if (!learned[words[i][j] - 'a'])
            {
                readable = 0;
                break;
            }
        }
        if (readable)
            count++;
    }
    return count;
}

// 백트래킹으로 조합을 찾으며 최대 단어 수 탐색
void dfs(int index, int selected)
{
    if (selected == K - 5)
    { // K-5개를 다 선택한 경우
        int count = count_readable_words();
        if (count > max_count)
            max_count = count;
        return;
    }

    for (int i = index; i < ALPHA; i++)
    {
        if (!learned[i])
        {
            learned[i] = 1;
            dfs(i + 1, selected + 1);
            learned[i] = 0;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &K);

    // 필수 문자 'a', 'c', 'i', 'n', 't' 학습
    if (K < 5)
    {
        printf("0\n");
        return 0;
    }

    learned['a' - 'a'] = 1;
    learned['c' - 'a'] = 1;
    learned['i' - 'a'] = 1;
    learned['n' - 'a'] = 1;
    learned['t' - 'a'] = 1;

    // 단어 입력받고 'anta', 'tica' 제거
    for (int i = 0; i < N; i++)
    {
        scanf("%s", words[i]);
        memmove(words[i], words[i] + 4, strlen(words[i]) - 8);
        words[i][strlen(words[i]) - 4] = '\0';
    }

    // 백트래킹 시작
    dfs(0, 0);

    // 결과 출력
    printf("%d\n", max_count);
    return 0;
}
