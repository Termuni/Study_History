#include <iostream>

using namespace std;

int test_point_func(int* test)
{
    *test = *test+1;
}

int test_func(int tester)
{
    test_point_func(&tester);
    return tester;
}

int main()
{
    cout<<test_func(2);
}