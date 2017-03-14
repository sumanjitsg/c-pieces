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
	return (this->a + this->b);
}

int Dummy::mul() {
	return (this->a * this->b);
}

int main() {
	Dummy* d1 = new Dummy(10, 21);
	Dummy* d2 = new Dummy(3, 15);
	Dummy* d3 = new Dummy(14, 9);
	cout << d1->sum() << endl;
	cout << d2->sum() << endl;
	cout << d3->mul() << endl;
	delete d1, delete d2, delete d3;	
	return 0;
}
