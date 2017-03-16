#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unordered_set>

using namespace std;

class FindCommonElements {
        void displayArray(int in[], const int size);
    public:
        int findCommonElements1(int in1[], int in2[], const int size);
        int findCommonElements2(int in1[], int in2[], const int size);
        int findCommonElements3(int in1[], int in2[], const int size);
        int findCommonElements4(int in1[], int in2[], const int size);
        void testMain(const int n);

};

void FindCommonElements::displayArray(int in[], const int size) {
    cout << endl;
    for (int i = 0; i < size; ++i) {
        cout << in[i] << " ";
    }
    cout << endl;
}

int FindCommonElements::findCommonElements1(int in1[], int in2[], const int size) {
    int count = 0;
    //<= n * n
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (in1[i] == in2[j])
                ++count;
        }
    }
    return count;
}

int FindCommonElements::findCommonElements2(int in1[], int in2[], const int size) {
    int count = 0;
    //nlogn
    sort(in1, in1 + size);
    //nlogn
    sort(in2, in2 + size);
    int i = 0, j = 0;
    //<= n
    while (i < size && j < size) {
        if (in1[i] < in2[j])
            ++i;
        else if (in1[i] > in2[j])
            ++j;
        else {
            ++count;
            ++i;
            ++j;
        }
    }
    return count;
}

int FindCommonElements::findCommonElements3(int in1[], int in2[], const int size) {
    int count = 0;
    //nlogn
    sort(in1, in1 + size);
    //nlogn
    for (int i = 0; i < size; ++i) {
        if (binary_search(in1, in1 + size, in2[i])) {
            ++count;
        }
    }
    return count;
}

int FindCommonElements::findCommonElements4(int in1[], int in2[], const int size) {
    int count = 0;
    unordered_set<int> hset;
    //constant
    for (int i = 0; i < size; ++i)
        hset.insert(in1[i]);
    //constant
    for (int i = 0; i < size; ++i) {
        if (hset.count(in2[i]))
            ++count;
    }
    return count;
}

void FindCommonElements::testMain(const int n) {
    int* in1 = new int[n];
    int* in2 = new int[n];

    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        in1[i] = rand() % (2 * n) + 1;
        in2[i] = rand() % (2 * n) + 1;
    }

    //displayArray(in1, n);
    //displayArray(in2, n);
    long start = time(NULL);
    int count = findCommonElements4(in1, in2, n);
    long end = time(NULL);
    
    cout << count << endl;
    cout << "Time taken: " << (end - start) << " seconds" << endl;

    delete[] in1;
    delete[] in2;
}


int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "Usage - ./<program name> <size_of_array>" << endl;
        return 1;
    }
    FindCommonElements testObj;
    testObj.testMain(atoi(argv[1]));
}


