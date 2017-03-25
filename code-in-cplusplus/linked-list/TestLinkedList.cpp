#include <iostream>
#include <cstdlib>
#include "TestLinkedList.hpp"

using namespace std;

namespace mylinkedlist {

	void addFirst(ListNode* head, int e) {
		ListNode* tmp = new ListNode(e);
		tmp->next = head->next;
		head->next = tmp;
	}
    
    void deleteList(ListNode* head) {
        ListNode* tmp = head;
        while (head != NULL) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    
    void displayList(ListNode* head) {
        for (ListNode* current = head->next; current != NULL; current = current->next)
            cout << current->data << endl;
    }

}
