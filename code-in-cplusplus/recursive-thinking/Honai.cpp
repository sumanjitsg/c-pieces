#include <iostream>
using namespace std;

void auxhonai(int n, char src, char aux, char target, int* counter) {
    if (n <= 0) return;
    auxhonai(n-1, src, target, aux, counter);
    ++(*counter);
    //cout << src << "->" << target << endl;
    auxhonai(n-1, aux, src, target, counter);
}

// TC = 2^n-1 = O(2^n), SC = n+1 = O(n)
int honai1(int n, char src, char aux, char target) {
    int* counter = new int;
    auxhonai(n, src, aux, target, counter);
    int c = *counter;
    delete counter;
    return c;
}

// TC = O(n), SC = O(n)
long honai2(int n, char src, char aux, char target) {
    if (n <= 0) return 0;
    long* count_array = new long[n+1];
    count_array[0] = 0;
    for (int i = 1; i <= n; ++i)
        count_array[i] = 2 * count_array[i-1] + 1;
    long c = count_array[n];
    delete[] count_array;
    return c;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: ./prog_name <n>" << endl;
        return 1;
    }
    int n = atoi(argv[1]);
    cout << honai2(n, 'A', 'B', 'C') << endl;
    return 0;
}
