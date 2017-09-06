#include <iostream>
#include <algorithm>

using namespace std;
// 选择排序
void selection_sort(int array[], int len)
{
    int smallest_index;

    for (int i = 0; i < len; ++i)
    {
        smallest_index = i;
        for (int j = i+1; j < len; ++j)
        {
            if (array[j] < array[smallest_index])
                smallest_index = j;
        }
        std::swap(array[smallest_index], array[i]);
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
    selection_sort(array, n);
    for_each(array, array+n, [](auto num) { cout << num << " "; });
}