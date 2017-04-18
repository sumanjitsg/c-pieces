#include <iostream>
#include "NthFibonacci.hpp"
using namespace std;


//tc:O(2^n), sc:O(n)
int NthFibonacci::fib1(int n) {
    if (n <= 0) return 0;
    if (n <= 2) return 1;
    return fib1(n-1) + fib1(n-2);
}

//tc:O(n), sc:O(n) = n + n
int NthFibonacci::auxfib2(int n, int* mem) {
    if (n <= 2) return 1;
    // look-up memory
    if (mem[n] != 0) return mem[n];
    // fill memory with subproblem solutions
    return mem[n] = auxfib2(n-1, mem) + auxfib2(n-2, mem);
}
int NthFibonacci::fib2(int n) {
    if (n <= 0) return 0;
    int* mem = new int[n+1];
    int c = auxfib2(n, mem);
    delete[] mem;
    return c;
}

//tc:O(n), sc:O(n)
int NthFibonacci::fib3(int n) {
    if (n <= 0) return 0;
    int* mem = new int[n+1];
    mem[1] = mem[2] = 1;
    for (int i = 3; i <= n; ++i)
        mem[i] = mem[i-1] + mem[i-2];
    return mem[n];
}

//tc:O(n), sc:O(1)
int NthFibonacci::fib4(int n) {
    if (n <= 0) return 0;
    int x = 1, y = 0, sum = 0;
    while(n--) {
        sum = x + y;
        x = y;
        y = sum;
    }
    return sum;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: ./prog_name <n>" << endl;
        return 1;
    }
    int n = atoi(argv[1]);
    NthFibonacci obj;
    cout << obj.fib4(n) << endl;
    return 0;
}
