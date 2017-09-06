#include <iostream>
#include <algorithm>

using namespace std;
// 插入排序，保持array[0-i]已排序
void insertion_sort(int array[], int len)
{
    int tmp,j;
    for (int i = 1; i < len; ++i)
    {
        tmp = array[i]; 
        for (j = i-1; j >= 0 && array[j] > tmp; --j)
            array[j+1] = array[j];
        array[j+1] = tmp;
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
    insertion_sort(array, n);
    for_each(array, array+n, [](auto num) { cout << num << " "; });
}