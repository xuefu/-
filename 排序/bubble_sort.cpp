#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
// 冒泡排序
void bubble_sort(int array[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        for (int j = i+1; j < len; ++j)
        {
            if (array[i] > array[j])
                swap(array[i], array[j]);
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
    bubble_sort(array, n);
    for_each(array, array+n, [](auto num) { cout << num << " "; });
}
