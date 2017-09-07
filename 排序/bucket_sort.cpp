#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define BUCKETS_NUM 4096
int buckets[BUCKETS_NUM];

// 桶排序
void bucket_sort(int array[], int len)
{
    int idx = 0;

    memset(buckets, 0, sizeof(buckets));
    for (int i = 0; i < len; ++i)
    {
        ++buckets[array[i]];
    }

    for (int i = 0; i < BUCKETS_NUM; ++i)
    {
        for (int j = 1; j < buckets[i]+1; ++j)
        {
            array[idx++] = i;
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
    bucket_sort(array, n);
    for_each(array, array+n, [](auto num) { cout << num << " "; });
}