/**
 * @details: Exercise 17.34 编写一个程序，展示如何使用表17.17和表17.18的每个操纵符
 * @details: Exercise 17.35 打印2的平方根，按十六进制大写形式打印
 * @details: Exercise 17.36 修改17.35 打印不同的浮点型，按列显示
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    cout << "test boolalpha: "
         << true << " " << false
         << boolalpha << " "
         << true << " " << false
         << noboolalpha << endl;
    cout << "test showpoint: "
         << showpoint << 10.0 << " "
         << noshowpoint << 10.0 << endl;
    cout << "test showpos: "
         << showpos << 5 << " "
         << noshowpos << 5 << endl;
    cout << "test uppercase: "
         << hex
         << uppercase << 0xff << " "
         << nouppercase << 0xff << dec << endl;
    cout << "test dec hex oct: "
         << hex << 10 << " "
         << oct << 10 << " "
         << dec << 10 << endl;
    cout << "test left right internal setfill setw: "
         << setfill('%') << left << setw(10) << -10 << " "
         << right << setw(10) << -10 << " "
         << internal << setw(10) << -10
         << setfill(' ') << left << endl;
    cout << "test fixed scientific hexfloat defaultfloat; "
         << fixed << 125.458 << " "
         << scientific << 125.458 << " "
         << hexfloat << 125.458 << " "
         << defaultfloat << 125.458 << endl;
    char ch;
    int it_count = 0;
    cout << "test noskipws: ";
    // noskipws仅对字符有效，标准库底层将
    cin >> noskipws;
    cin >> ch;
    while (cin >> ch && ch != 'q') {
        ++it_count;
        cout << ch;
    }
    cout << endl << it_count << endl;
    cout << "test skipws: ";
    cin >> skipws;
    it_count = 0;
    while (cin >> ch && ch != 'q') {
        ++it_count;
        cout << ch;
    }
    cout << endl << it_count << endl;

    cout << hexfloat << uppercase << "hexfloat: " << sqrt(2) << dec << nouppercase << endl;
    cout << fixed << setw(15) << "fixed: " << sqrt(2) << dec << endl;
    cout << scientific << setw(15) << "scientific: " << sqrt(2) << dec << endl;
    cout << hexfloat << setw(15) << "hexfloat: " << sqrt(2) << dec << endl;
    cout << defaultfloat << setw(15) << "defaultfloat: " << sqrt(2) << dec << endl;


    return 0;
}

