#include<iostream>
using namespace std;
class A {
public:
	A() { cout << "A"<<endl; }
	~A() { cout << "~A"<<endl; }
};
class B:public A {
public:
	B() { cout << "B with no parameter" << endl; }
	B(const A &a) :_a(a) { cout << "B with copy"<<endl; }
	B& B::operator =(const B &obj) { cout << "B with =" << endl;  return *this; }
	~B() { cout << "B"<<endl; }

private:
	A _a;
};
int main() {
	A a;
		cout << "****************"<<endl;
	B b;
		cout << "****************" << endl;
	B c(a);
		cout << "****************" << endl;
	B d = b;
		cout << "****************" << endl;
	B e;
		cout << "****************" << endl;
	e = b;
	return 0;
}
/*
输出：
A
****************A的构造函数
A
A
B with no parameter
****************先继承，输出A，再创建私有对象_a,输出A，再构造B的对象，输出B
A
B with copy
****************先继承，输出A，此时是调用的默认构造函数对_a进行初始化，所以不输出A，再构造B的对象，输出B
****************不知道为啥没输出
A
A
B with no parameter
****************
B with =
*/
