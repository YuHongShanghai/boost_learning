#include<iostream>
#include<boost/filesystem.hpp>
using namespace std;
int main() {
	boost::filesystem::path dir("c:\\users");
	cout << dir << endl;//返回带有双引号的路径字符串
	cout << dir.string() << endl;//返回不带双引号的路径字符串
	cout << dir.root_name() << endl;//盘符名
	cout << dir.root_directory() << endl;//根目录
	cout << dir.root_path() << endl;//根路径

	cout << dir.relative_path() << endl;//相对路径
	cout << dir.parent_path() << endl;//上级目录
	cout << dir.filename() << endl;//文件名
	cout << dir.stem() << endl;//不带扩展的文件名
	cout << dir.extension() << endl;//文件扩展名
	boost::filesystem::exists("c:\\users\\86151\\desktop\\cpp\\bin");//判断文件存在性

	system("pause");
	return 0;
}

