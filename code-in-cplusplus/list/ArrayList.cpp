#include <iostream>
#include "ArrayList.hpp"

using namespace std;

namespace mylistns {

    ArrayList::ArrayList() {
        array = new int[10];
        array_size = 10;
        num_elements = 0;
        //cout << "ArrayList allocated!" << endl;
    }

    ArrayList::~ArrayList() {
        delete[] array;
        //cout << "ArrayList de-allocated!" << endl;
    }

    //O(1)
    int ArrayList::get(int index) {
        return array[index];
    }

    void ArrayList::doubling() {
        int* newarray = new int[2 * array_size];
        for (int i = 0; i < array_size; ++i)
            newarray[i] = array[i];
        delete[] array;
        array = newarray;
        array_size *= 2;
        //cout << "Array doubled!" << endl;
    }
    //O(1) am
    void ArrayList::add(int e) {
        if (num_elements == array_size)
            doubling();
        array[num_elements++] = e;
    }

    //O(n)
    void ArrayList::display() {
        for (int i = 0; i < num_elements; ++i)
            cout << array[i] << endl;
    }

    //O(1)
    int ArrayList::size() {
        return num_elements;
    }

}
