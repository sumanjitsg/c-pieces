#include <iostream>

using namespace std;

class Dummy {
		int a;
		int b;
	public:
		Dummy(int a, int b);
		int sum(void);
		int mul(void);
};

Dummy::Dummy(int a, int b) {
	this->a = a;
	this->b = b;
}

int Dummy::sum() {
	return (a + b);
}

int Dummy::mul() {
	return (a * b);
}

int main() {
	Dummy d1(10, 21);
	Dummy d2(3, 15);
	Dummy d3(14, 9);
	cout << d1.sum() << endl;
	cout << d2.sum() << endl;
	cout << d3.mul() << endl;
	return 0;
}
