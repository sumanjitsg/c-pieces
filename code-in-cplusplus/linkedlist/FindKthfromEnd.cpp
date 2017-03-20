#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "TestLinkedList.hpp"

#define GET_CURR_TIME_IN_MILLIS ( gettimeofday(&t, NULL), t.tv_sec/1000.0 + t.tv_usec*1000.0 )

using namespace std;
using namespace mylinkedlist;

ListNode* findKthElementfromEnd1(ListNode* head, int k) {
    int size = 0;
    for (ListNode* current = head->next; current != NULL; current = current->next)
        ++size;

    ListNode* current = head->next;
    for (int i = 1; i <= (size - k); ++i)
        current = current->next;
    
    return current;
}

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    srand(100);

    ListNode* head = new ListNode();
    for (int i = 1; i <= n; ++i) {
        addFirst(head, rand()%n + 1);
    }
    cout << "Data generation complete" << endl;
    displayList(head);
    
    timeval t;
    double start = GET_CURR_TIME_IN_MILLIS;
    ListNode* result = findKthElementfromEnd1(head, k);
    double end = GET_CURR_TIME_IN_MILLIS;
    cout << "Time taken: " << (end - start)/1000.0 << " seconds" << endl;
    //cout << result->data << endl;
    
    deleteList(head);
    return 0;
}
