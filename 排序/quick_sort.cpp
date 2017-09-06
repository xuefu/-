#include <iostream>
#include <algorithm>

using namespace std;
// 快速排序
void quick_sort(int array[], int left, int right)
{
    int i, j;
    int pivot;
 
    if( left <= right )
    {
        pivot = array[right];
        i = left ; j = right-1;
        for( ; ; )
        {
            while( array[i] < pivot ){ ++i; }
            while( array[j] > pivot ){ --j; }
            if( i < j )
                std::swap(array[i], array[j]);
            else
                break;
        }
        std::swap(array[i], array[right]);  /* Restore pivot */

        quick_sort(array, left, i-1);
        quick_sort(array, i+1, right);
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
    quick_sort(array, 0, n-1);
    for_each(array, array+n, [](auto num) { cout << num << " "; });
}

