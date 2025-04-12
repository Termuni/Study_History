#include <stdio.h>
#include <stdlib.h>

#define MAX_PEOPLE 500
#define MAX_KG 241

int kg[MAX_KG];
int max_kg = 40;
int min_kg = 240;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int solution(int people[], int people_size, int limit) {
    int answer = 0;
    int isDone = 0;

    for (int i = 0; i < MAX_KG; ++i)
        kg[i] = 0;

    for (int i = 0; i < people_size; ++i) {
        if (people[i] > max_kg) max_kg = people[i];
        if (people[i] < min_kg) min_kg = people[i];
        kg[people[i]] += 1;
    }

    while (!isDone) {
        int num = 0;
        
        // max_kg 갱신
        while (max_kg >= 40 && kg[max_kg] == 0)
            --max_kg;

        // min_kg 갱신
        while (min_kg <= 240 && kg[min_kg] == 0)
            ++min_kg;

        int left_kg = limit;
        int target_kg = max_kg;

        // 무게 빼기
        while ((left_kg >= min_kg) && (num != 2) && target_kg >= min_kg) {
            if ((kg[target_kg] > 0) && ((left_kg - target_kg) >= 0)) {
                ++num;
                left_kg -= target_kg;
                --kg[target_kg];
                continue;
            }
            --target_kg;
        }

        ++answer;

        if ((max_kg == min_kg) && (kg[min_kg] == 0))
            isDone = 1;
    }

    return answer;
}

int main() {
    int people[MAX_PEOPLE];
    int n, limit;

    printf("사람 수 입력: ");
    scanf("%d", &n);

    printf("무게 제한 입력: ");
    scanf("%d", &limit);

    printf("사람들의 몸무게 입력 (%d명):\n", n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &people[i]);

    int result = solution(people, n, limit);
    printf("필요한 보트 수: %d\n", result);

    return 0;
}
