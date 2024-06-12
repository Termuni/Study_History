#include<iostream>
#include<stack>
using namespace std;

string str;
stack<char> s;
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	int tmp = 1;
	char pre = ' ';
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '[')
		{
			s.push(str[i]);
			if (str[i] == '(')
				tmp *= 2;
			else
				tmp *= 3;
		}
		else
		{
			if (str[i] == ')')
			{
				if (s.empty()) {
					ans = 0;
					break;
				}
				if (s.top()=='[') {
					ans = 0;
					break;
				}
				s.pop();

				if (pre == '(')	//ans에 값을 더해야 한다
				{
					ans += tmp;
					tmp /= 2;
				}
				else
					//이미 값이 더해져 있음
				{
					tmp /= 2;
				}
			}
			else
			{
				if (s.empty()) {
					ans = 0;
					break;
				}
				if (s.top() == '(') {
					ans = 0;
					break;
				}
				s.pop();

				if (pre == '[')
				{
					ans += tmp;
					tmp /= 3;
				}
				else
					tmp /= 3;
			}
		}
		pre = str[i];
	}

	if (!s.empty())
		ans = 0;

	cout << ans;

	return 0;
}