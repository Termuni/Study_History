//문제 후기 : C언어 공부 제대로 해야겠는걸?

#include <stdio.h>

int main(void)
{
    int h_in, h_out, m_in, m_out, m_tot = 0;
    char time_in[6], time_out[6];
    for (int i = 0; i < 5; ++i)
    {
        scanf("%s", &time_in);
        scanf("%s", &time_out);

        // Hour
        h_in = (time_in[0] - '0') * 10 + (time_in[1] - '0');
        h_out = (time_out[0] - '0') * 10 + (time_out[1] - '0');

        // Minute
        m_in = (time_in[3] - '0') * 10 + (time_in[4] - '0');
        m_out = (time_out[3] - '0') * 10 + (time_out[4] - '0');

        m_tot += (h_out - h_in) * 60 + (m_out - m_in);
    }
    printf("%d", m_tot);

    return 0;
}