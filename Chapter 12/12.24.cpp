/*
 * Exercise 12.24 编写一个程序从标准输入中读取一个字符串并存入一个动态分配的字符数组中，
 * 描述程序如何处理变长输入，使用一个超出分配的字符数组长度的字符串进行测试
 *
 * 处理变长输入的策略：统计已经读取的字符个数，并与提前分配的内存大小进行比较，
 * 如果读取字符个数与提前分配的内存大小一致时重新分配一个原来2倍大小的空间，
 * 然后将已经读取的字符复制到新的内存区域，释放之前分配的内存。
 *
 * */

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>


using namespace std;


int main(int argc, char **argv) {
    // size的初始分配一个较大的空间，可以减少后续重新分配空间的次数
    size_t size = 4, count = 0;
    char *p = new char[size + 1], *tmp = p;
    char c;
    cout << "请输入超过4个字符的字符串:" << endl;
    while ((c = getchar()) != EOF) {
        if (count++ == size) {
            size *= 2;
            char *newP = new char[size + 1];
            // 注意拷贝源空间的内容时采用安全拷贝strcpy_s或者memcpy_s，
            strcpy_s(newP, size / 2, p);
            memcpy_s(newP, size / 2, p, size / 2);
            // strcpy依赖字符串的结束标识符'\0'，strcpy会在内存中一直查找直至找到'\0'为止,
            // 直接复制会引起堆的破坏，导致第二次delete时释放了不能释放的区域
            // 在需要拷贝的字符之后手动添加一个'\0'字符保证释放的空间区域正确
//            *tmp = '\0';
//            strcpy(newP, p);
            delete[]p;
            p = newP;
            tmp = p + count - 1;
        }
        *tmp++ = c;
    }
    // 结尾再添加一个字符，标识字符串的结尾
    *tmp = '\0';
    cout << p << endl;
    delete[]p;

    return 0;
}




