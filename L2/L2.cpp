#include <boost/format.hpp>
#include <iostream>
#include <iomanip>
#include<ctime>
using namespace boost;
using namespace std;
using boost::io::group;

int main() {
    cout << "ʾ��\n";
    cout << format("%s:%d+%d=%d\n") % "sum" % 1 % 2 % (1 + 2);

    format fmt("(%1%+%2%)*%2%=%3%\n");
    fmt % 2 % 5;
    fmt % ((2 + 5) * 5);
    cout << fmt.str();

    cout << boost::format("%20T-")<<endl;

    cout << "ʹ��printf����ʽ���ַ���\n";
    cout << boost::format("%10T*")<<endl;
    cout << boost::format("%s"
        "%1t ʮ���� = %d\n"
        "%1t ��ʽ����ʮ���� = %5d\n"
        "%1t ��ʽ��ʮ���ƣ�ǰ��'0' = %05d\n"
        "%1t ��ʽ��ʮ���ƣ������ = %-5d\n"
        "%1t ��ʽ��ʮ���ƣ����ж��� = %=5d\n"
        "%1t ��ʽ��ʮ���ƣ��ڲ����� = %_5d\n"
        "%1t ��ʽ��ʮ���ƣ���ʾ���� = %+5d\n"
        "%1t ʮ������ = %X\n"
        "%1t ʮ�����ƣ���ʾ���� = %#5X\n"
        "%1t �˽��� = %o\n"
        "%1t ���� = %f\n"
        "%1t ��ʽ���ĸ��� = %3.3f\n"
        "%1t ��ѧ���� = %e\n"
    ) % "example :\n" % 15 % 15 % 15 % 15 % 15 % 15 % 15 % 15 % 15 % 15 % 15.01 % 15.01 % 15.01 << endl;

    cout << boost::format("%20T-") << endl;

    cout << "�߼��÷�\n";
    format fmtt("%1% %2% %3% %2% %1% \n");
    cout << fmtt % 1 % 2 % 3;

    fmtt.bind_arg(2, 20);
    cout << fmtt % 1 % 3;

    cout << fmtt % group(showbase, oct, 11) % 33;

    fmtt.clear_binds();

    fmtt.modify_item(1, group(hex, right, showbase, setw(8), setfill('*')));
    cout << fmtt % 21 % 22 % 23;

    cout << boost::format("%20T-") << endl;

    cout << "�����Ż�\n";
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 1000; ++i) {
        cout << format("%10d %020.8f %010X %10.5e\n") % 62 % 2.334 % 224 % 1.497;
    }
    end = clock();
    double use_time = (double)(end - start);
    cout << format("ֱ�������ʱ%.3fms\n") % use_time;

    start = clock();
    const format fmt_s("%10d %020.8f %010X %10.5e\n");
    for (int i = 0; i < 1000; ++i) {
        cout<<format(fmt_s) % 62 % 2.334 % 224 % 1.497;
    }
    end = clock();
    use_time = (double)(end - start);
    cout << format("���������ʱ%.3fms\n") % use_time;
}
