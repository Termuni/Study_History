#include <stdio.h>

enum Cending
{
    None,
    Ascending,
    Descending,
    Mixed
};

int main(void)
{
    int dct;
    int cending = None; // if cending == 0 => X / cending == 1 => ascending / cending == 2 => descending / cending == 3 => mixed

    scanf("%d", &dct);

    for (int i = 0; i < 7; ++i)
    {
        int p_dct = dct;
        scanf("%d", &dct);
        switch (cending)
        {
        case None:
            cending = (p_dct > dct) ? Descending : Ascending;
            break;
        case Ascending:
            cending = (p_dct > dct) ? Mixed : Ascending;
            break;
        case Descending:
            cending = (p_dct > dct) ? Descending : Mixed;
            break;
        default:
            break;
        }
    }
    switch (cending)
    {
    case Ascending:
        printf("ascending");
        break;
    case Descending:
        printf("descending");
        break;
    default:
        printf("mixed");
        break;
    }

    return 0;
}