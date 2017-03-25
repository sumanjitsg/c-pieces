#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "TestLinkedList.hpp"
#include "FindKthfromEnd.hpp"

#define GET_CURR_TIME_IN_MILLIS \
    ( gettimeofday(&t, NULL), t.tv_sec * 1000.0 + t.tv_usec / 1000.0 )

using namespace std;

ListNode* FindKthfromEnd::findKthElementfromEnd1(ListNode* head, int k) {
    int size = 0;
    for (ListNode* current = head->next; current != NULL; current = current->next)
        ++size;
    if (size < k)
        return head;
    ListNode* current = head->next;
    for (int i = 1; i <= (size - k); ++i)
        current = current->next;
    return current;
}

ListNode* FindKthfromEnd::findKthElementfromEnd2(ListNode* head, int k) {
    ListNode* first = head;
    ListNode* second = head;
    for (int i = 1; i <= k && second != NULL; ++i)
        second = second->next;
    while (second != NULL) {
        first = first->next;
        second = second->next;
    }
    return first;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./<prog_name> <k> <n>" << endl;
        return 1;
    }
    int k = atoi(argv[1]);
    int n = atoi(argv[2]);

    srand(1000000);
    ListNode* head = new ListNode();
    for (int i = 1; i <= n; ++i) {
        addFirst(head, rand() % n + 1);
    }
    cout << "Data generation complete" << endl;
    //displayList(head);

    timeval t;
    FindKthfromEnd obj;

    double start, end;
    ListNode* result;
    start = GET_CURR_TIME_IN_MILLIS;
    result = obj.findKthElementfromEnd1(head, k);
    end = GET_CURR_TIME_IN_MILLIS;
    cout << "Time taken: " << fixed << (end - start)/1000.0 << " seconds" << endl;
    cout << "Data: " << result->data << endl;
    
    start = GET_CURR_TIME_IN_MILLIS;
    result = obj.findKthElementfromEnd2(head, k);
    end = GET_CURR_TIME_IN_MILLIS;
    cout << "Time taken: " << fixed << (end - start)/1000.0 << " seconds" << endl;
    cout << "Data: " << result->data << endl;

    deleteList(head);
    return 0;
}
