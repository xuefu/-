#include <iostream>
#include <algorithm>

using namespace std;
// 希尔排序
void shell_sort(int array[], int len)
{
    int j, tmp, increment = len/2;

    for ( ; increment > 0; increment /= 2)
    {
        for (int i = increment; i < len; ++i)
        {
            tmp = array[i];
            for (j = i; j >= increment; j -= increment)
            {
                if (tmp < array[j-increment])
                    array[j] = array[j-increment];
                else
                    break;
            }
            array[j] = tmp;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }
    shell_sort(array, n);
    for_each(array, array+n, [](auto num) { cout << num << " "; });
}