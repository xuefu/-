#include <cstring>
#include <algorithm>
#include <cstdio>

class String
{
public:
    String();
    String(const char* str);
    String(const String& rhs);
    String& operator=(const String& rhs);
    size_t size() const { return strlen(data_); }
    const char* c_str() const { return data_; }
    ~String();

private:
    char* data_;
};

String::String() : data_(new char[1])
{
    *data_ = '\0';
}
String::String(const char* str) 
{
    size_t len = 0;
    if (str != NULL)
    {
        len = strlen(str); // strlen(NULL)会出现段错误
    }
    data_ = new char[len+1];
    strcpy(data_, str);
}
String::String(const String& rhs) 
    : data_(new char[rhs.size()+1])
{
    strcpy(data_, rhs.c_str());
}
/*
String& String::operator=(String rhs)
{
    std::swap(data_, rhs.data_);
    return *this;
}
*/
String& String::operator=(const String& rhs)
{
    if (this != &rhs)
    {
        String tmp(rhs);
        std::swap(data_, tmp.data_);
    }
    return *this;
}
String::~String()
{
    delete[] data_;
    data_ = NULL;
}

int main()
{
    /*
        1. 无参构造函数测试
        2. 有参构造函数测试
        3. 赋值运算符测试
        4. 连续赋值
        5. 复制构造函数
        6. 析构函数
    */
    String s1;
    printf("s1: %s\n", s1.c_str());
    String s2("hello");
    printf("s2: %s\n", s2.c_str());
    String s3;
    s3 = s1 = s2;
    printf("s1: %s\n", s1.c_str());
    printf("s2: %s\n", s2.c_str());
    printf("s3: %s\n", s3.c_str());
    String s4(s3);
    printf("s4: %s\n", s4.c_str());
}