#include <stdio.h>

char* strcpy_v2(char* dest, const char* src)
{
    if (dest == NULL || src == NULL)
        return NULL;
    if (dest == src)
        return dest;

    char* p = dest;
    while(*p++ = *src++)
        ;

    return dest;
}

int main()
{
    char str[4096], dest[4096];
    scanf("%s", str);

    strcpy_v2(dest, str);
    printf("dest: %s\n", dest);
}