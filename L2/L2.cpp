#include <boost/format.hpp>
#include <iostream>
#include <iomanip>
#include<ctime>
using namespace boost;
using namespace std;
using boost::io::group;

int main() {
    cout << "示例\n";
    cout << format("%s:%d+%d=%d\n") % "sum" % 1 % 2 % (1 + 2);

    format fmt("(%1%+%2%)*%2%=%3%\n");
    fmt % 2 % 5;
    fmt % ((2 + 5) * 5);
    cout << fmt.str();

    cout << boost::format("%20T-")<<endl;

    cout << "使用printf风格格式化字符串\n";
    cout << boost::format("%10T*")<<endl;
    cout << boost::format("%s"
        "%1t 十进制 = %d\n"
        "%1t 格式化的十进制 = %5d\n"
        "%1t 格式化十进制，前补'0' = %05d\n"
        "%1t 格式化十进制，左对齐 = %-5d\n"
        "%1t 格式化十进制，居中对齐 = %=5d\n"
        "%1t 格式化十进制，内部对齐 = %_5d\n"
        "%1t 格式化十进制，显示符号 = %+5d\n"
        "%1t 十六进制 = %X\n"
        "%1t 十六进制，显示基数 = %#5X\n"
        "%1t 八进制 = %o\n"
        "%1t 浮点 = %f\n"
        "%1t 格式化的浮点 = %3.3f\n"
        "%1t 科学计数 = %e\n"
    ) % "example :\n" % 15 % 15 % 15 % 15 % 15 % 15 % 15 % 15 % 15 % 15 % 15.01 % 15.01 % 15.01 << endl;

    cout << boost::format("%20T-") << endl;

    cout << "高级用法\n";
    format fmtt("%1% %2% %3% %2% %1% \n");
    cout << fmtt % 1 % 2 % 3;

    fmtt.bind_arg(2, 20);
    cout << fmtt % 1 % 3;

    cout << fmtt % group(showbase, oct, 11) % 33;

    fmtt.clear_binds();

    fmtt.modify_item(1, group(hex, right, showbase, setw(8), setfill('*')));
    cout << fmtt % 21 % 22 % 23;

    cout << boost::format("%20T-") << endl;

    cout << "性能优化\n";
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 1000; ++i) {
        cout << format("%10d %020.8f %010X %10.5e\n") % 62 % 2.334 % 224 % 1.497;
    }
    end = clock();
    double use_time = (double)(end - start);
    cout << format("直接输出耗时%.3fms\n") % use_time;

    start = clock();
    const format fmt_s("%10d %020.8f %010X %10.5e\n");
    for (int i = 0; i < 1000; ++i) {
        cout<<format(fmt_s) % 62 % 2.334 % 224 % 1.497;
    }
    end = clock();
    use_time = (double)(end - start);
    cout << format("拷贝输出耗时%.3fms\n") % use_time;
}
