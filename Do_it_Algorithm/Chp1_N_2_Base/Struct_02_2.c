#define VMAX 21
#include<stdio.h>

typedef struct{
    char name[20];
    int height;
    double vision;
} PhysCheck;

//키 평균값 구하는 함수
double Avg_Height(const PhysCheck * dat, int n)
{
    double sum = 0;
    for(int i=0; i<n; ++i)
    {
        sum += dat[i].height;
    }
    return sum / (double)n;
}

//시력 분포
void Dist_Vision(const PhysCheck * dat, int n, int * dist)
{
    //dist의 분포 초기화
    for(int i=0; i<VMAX; ++i)
    {
        dist[i] = 0;
    }

    for(int i=0; i<n; ++i)
    {
        if(dat[i].vision >= 0.0 && dat[i].vision <= VMAX/10.0)
        {
            dist[(int)(dat[i].vision * 10)]++;
        }
    }
}

int main()
{
    PhysCheck dat[] = {
        {"박현규", 162, 0.3},
        {"함진아", 173, 0.3},
        {"최윤미", 175, 2.0},
        {"홍연의", 171, 1.5},
        {"이수진", 168, 0.4},
        {"김영준", 174, 1.2},
        {"박용규", 169, 0.8},
    };

    int n_dat = sizeof(dat)/sizeof(PhysCheck);
    int vdist[VMAX];
    puts("------신체검사표------");
    puts("\t이름\t키\t시력");
    puts("----------------------");
    for(int i=0; i<n_dat; ++i)
    {
        printf("%-18.18s%4d%5.1f\n", dat[i].name, dat[i].height, dat[i].vision);
    }
    printf("\n 평균 키 : %5.1f cm\n", Avg_Height(dat, n_dat));
    Dist_Vision(dat, n_dat, vdist);
    puts("\n시력 분포");
    for(int i=0; i<VMAX; ++i)
    {
        //printf("%3.1f ~: %2d명\n", i/10.0, vdist[i]);
        printf("%3.1f ~ : ", i/10.0);
        for(int j=0; j<vdist[i];++j)
        {
            printf("*");
        }
        puts("");
    }
    
    return 0;

}