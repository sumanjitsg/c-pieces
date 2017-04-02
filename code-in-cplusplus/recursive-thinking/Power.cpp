#include <iostream>
using namespace std;

// TC - O(n), SC - O(1)
long pow1(int x, int n) {
    long res = 1;
    for (int i = 1; i <= n; ++i)
        res *= x;
    return res;
}

// TC <= O(logn), SC - O(logn)
long pow2(int x, int n) {
    if (n <= 0)
        return 1;
    else if (n == 1)
        return x;
    long tmp = pow2(x, n/2);
    if (n % 2 == 0)
        return tmp * tmp;
    else
        return tmp * tmp * x;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./prog_name <x> <n>" << endl;
        return 1;
    }
    int x = atoi(argv[1]);
    int n = atoi(argv[2]);
    cout << pow1(x, n) << endl;
    cout << pow2(x, n) << endl;
    return 0;
}
