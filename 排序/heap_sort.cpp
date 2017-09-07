#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

inline int left_child(int i) { return 2*i+1; }

// 下滤，维护最大堆性质
void perc_down(int array[], int i, int n)
{
    int child;
    int tmp;

    for( tmp = array[i]; left_child(i) < n; i = child )
    {
        child = left_child(i);
        if(child != n - 1 && array[child + 1] > array[child])
            child++;
        if(tmp < array[child])
            array[i] = array[child];
        else
            break;
    }
    array[i] =tmp;
}
// 堆排序
void heap_sort(int array[], int len)
{
    for(int i = len / 2; i >= 0; i--)  /* BuildHeap */
        perc_down(array, i, len);
    for(int i = len - 1; i > 0; i--)
    {
        std::swap(array[0], array[i]);  /* DeleteMax */
        perc_down(array, 0, i);
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
    heap_sort(array, n);
    for_each(array, array+n, [](auto num) { cout << num << " "; });
}



