/**
 * @details : Exercise 16.12 编写自己版本的Blob和BlobPtr模板
 * @details : Exercise 16.24 为Blob添加接受两个迭代器版本的构造函数
 */
#include <iostream>
#include <string>
#include <algorithm>

#include "../common/header/blob_ptr.h"


using namespace std;

int main() {

    Blob<string> blob_str, blob;
    blob_str.push_back("hello");
    blob_str.push_back("world");
    string str("today");
    blob_str.push_back(str);
    blob_str.print();
    cout << (blob_str != blob) << endl;
    Blob<double> blob_double;
    blob_double.push_back(3.3);
    blob_double.push_back(5.5);
    blob_double.push_back(4);
    blob_double.size();
    blob_double.print();
    blob_double.pop_back();
    blob_double.print();
    BlobPtr<string> p(blob_str), p2(blob_str);
    cout << (p == p2) << endl;
    cout << (p != p2) << endl;
    cout << *blob_str.begin() << endl;
    for_each(blob_str.begin(), blob_str.end(), [](const auto &cbs) { cout << cbs << " "; });
    cout << endl;
    vector<string> vs{"hello", "world"};
    Blob<string> blob_str2(vs.begin(), vs.end());
    blob_str2.print();

    return 0;
}

