#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

/*
    1. 带+符号的正数
    2. 带-符号的负数
    3. 不带符号的正数
    4. 溢出(上溢和下溢)
    5. 无法转换
    6. 不规则输入但是有效：'-33333xer'
*/
int str2int(const char *str)
{
    int num = 0; 
    int sign = 1;
    const int n = strlen(str);
    int i = 0;

    while (str[i] == ' ' && i < n) ++i;

    if (str[i] == '+')
    {
        ++i;
    } else if (str[i] == '-') {
        sign = -1;
        ++i;
    }
    for (; i < n; ++i)
    {
        if (str[i] < '0' || str[i] > '9') break;
        if (num > INT_MAX/10 || 
            (num == INT_MAX/10 && (str[i]-'0') > INT_MAX%10))
        {
            return sign==-1 ? INT_MIN : INT_MAX;
        }
        num = num*10 + str[i] - '0';
    }
    return num*sign;
}

int main(int argc, char *argv[])
{
    assert(argc > 1);
    printf("%s => %d\n", argv[1], str2int(argv[1]));
}