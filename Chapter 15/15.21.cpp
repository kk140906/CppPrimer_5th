/*
 * Exercise 15.21 从下面一般性的概念中任选一个将其对应的一组关系组织成一个继承体系
 * (a) 图像文件格式(gif,tiff,jpeg,bmp)
 * (b) 图形基元(方格，圆，球，圆锥)
 * (c) C++语言的类型(类，函数，成员函数)
 * Exercise 15.22 对于15.21添加合适的虚函数及构造函数和受保护的成员
 */
#include <iostream>

using namespace std;

/*
 * 对于不同格式的图像，应该具有自己的压缩算法，而大部分的压缩算法通常都需要用到图像的长和宽、位深等信息
 */
class Image {
public:
    Image(const uint16_t &l, const uint16_t &w, const uint8_t &b) : width(w), length(l), bitDepth(b) {}

    virtual  ~Image() = default;

    std::pair<uint16_t, uint16_t> size() { return {length, width}; }

    // 未知格式前通常不需要进行压缩操作，也不需要对象操作，声明为纯虚函数，使类成为抽象基类
    virtual void compress() = 0;
// 对于需要在派生类使用而无需外部用户关心的成员我们定义成protected
protected:
    uint16_t width = 0, length = 0;
    uint8_t bitDepth = 8;
};

class Image_GIF : public Image {
public:
    Image_GIF(const uint16_t &l, const uint16_t &w, const uint8_t &b) : Image(l, w, b) {}

    void compress() override { std::cout << "GIF" << std::endl; }
};

class Image_TIFF : public Image {
public:
    Image_TIFF(const uint16_t &l, const uint16_t &w, const uint8_t &b) : Image(l, w, b) {}

    void compress() override { std::cout << "TIFF" << std::endl; }

};

class Image_JPEG : public Image {
public:
    Image_JPEG(const uint16_t &l, const uint16_t &w, const uint8_t &b) : Image(l, w, b) {}

    void compress() override { std::cout << "JPEG" << std::endl; }

};

class Image_BMP : public Image {
public:
    Image_BMP(const uint16_t &l, const uint16_t &w, const uint8_t &b) : Image(l, w, b) {}

    void compress() override { std::cout << "BMP" << std::endl; }

};

int main() {
    Image_GIF gif(3000, 16000, 16);
    gif.compress();
    return 0;
}

