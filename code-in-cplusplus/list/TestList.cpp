#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "ArrayList.hpp"
#include "LinkedList.hpp"

#define GET_CURR_TIME_IN_MILLIS \
    ( gettimeofday(&t, NULL), \
      t.tv_sec * 1000.0 + t.tv_usec / 1000.0 )

using namespace std;
using namespace mylistns;

void testList(IList* list, const int n) {
    timeval t;
    srand(1000000);
    double start = GET_CURR_TIME_IN_MILLIS;
    for (int i = 0; i < n; ++i) {
        list->add(rand() % n + 1);
    }
    double end = GET_CURR_TIME_IN_MILLIS;
    cout << "Time taken: " << fixed << (end - start) / 1000.0 << " seconds" << endl;
    //list->display();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: ./<prog_name> <num_elements>" << endl;
        return 1;
    }
    ArrayList* arraylist = new ArrayList();
    testList(arraylist, atoi(argv[1]));
    delete arraylist;
    LinkedList* linkedlist = new LinkedList();
    testList(linkedlist, atoi(argv[1]));
    delete linkedlist;
    
    return 0;
}

