/*
������ȣ���̱�

<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�.
1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����.

ö���� �� ������ ������ ����� ���� ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�.
���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�.
�밢���� ���� �ִ� ���� ����� ���� �ƴϴ�.

<�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�.
������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�,
�� ���� N�ٿ��� ���� N���� �ڷ�(0 Ȥ�� 1)�� �Էµȴ�.

���
ù ��° �ٿ��� �� �������� ����Ͻÿ�.
�׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.

���� �Է�
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

���� ���
3
7
8
9

*/

/*
�� ��������
0110100         0110200
0110101         0110202
1110101         1110202
0000111         0000222
0100000         0300000
0111110         0333330
0111000         0333000

��, ��ȭ �ȴٰ� �Ѵ�

IDEA
2���� �迭�� 2�� �����Ѵ�
1���� int, 1���� bool

���� ��ܿ��� �����Ͽ�, �� �ڸ��� 1�̰� false��� �� �ڸ����� ��/��/��/�� �˻�
�ش� �ڸ����� �α� �ڸ� �˻����� �� ���� ������? �� �ڸ����� �ٽ� ��/��/��/�� �˻�

�ð����⵵ �Ƹ� n^4? ���� �ƴұ�?
��� �غ��� �� 39�� ������� ���´�

�׷��ٸ� ��� ������ ī��������?

�Լ��� �����, �����ͷ� ���� ���ڸ� �Ѱܼ� ������ ��츶�� �����ֱ�
�׸��� ����Ʈ ������ �־��ֱ�
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;

//Number of Aparts Counter
vector<int> apart;

//is that apart visited?
vector<vector<bool> > visited;

// Direction,Down/Up/Right/Left
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void Count(int * count, int x, int y)
{
    //�� ��ġ�� visited�� false�� return
    if(!visited[y][x]) return;

    //true�� ī��Ʈ �߰��ϰ� false�� ������ֱ�(�ٽ� �湮 �� �ϰ�)
    *count += 1;
    visited[y][x] = false;

    //��/��/��/�� Ž��
    for(int i=0; i<4; ++i)
    {
        if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n)
        {
            int newX = x + dx[i], newY = y + dy[i];
            if(visited[newY][newX])
            {
                Count(count, newX, newY);
            }
        }
    }
}

int main()
{
    cin >> n;

    // Save Data of 2x2 Apart, pair is [isThereApart] and position of vector
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i)
    {
            //bool�� 0110100 ������ �̰� �׳� true�� �޾ƹ����⿡
            //string���� ���� �� char ������ �ɰ� ����
            string isThereApart;
            cin >> isThereApart;
            for(int j = 0; j < n; ++j)
            {
                //3�� �����ڷ�, char == '1' �� ��츸 true �־��ֱ�
                visited[j][i] = (isThereApart[j] == '1')? true : false;
            }
    }
    
    //���� �� ���� ���� Ž���� ����!
    //count, posY, posX �� �Ѱܼ� �����ϱ�
    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < n; ++x)
        {
            int count = 0;
            Count(&count, x, y);
            if(count != 0)
            {
                apart.push_back(count);
            }
        }
    }
    
    //�������� ����
    sort(apart.begin(), apart.end());

    cout<<apart.size()<<'\n';
    for(int i = 0; i < apart.size(); ++i)
    {
        cout<<apart[i]<<'\n';
    }
}
