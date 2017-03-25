#include <iostream>

class IList {
    public:
        virtual int get(int index) = 0;
};

class ArrayList: public IList {
        int ar[5];
        int size;
    public:
        ArrayList();
        ~ArrayList();
        int get(int index);
};

ArrayList::ArrayList() {
    size = 0;
    for (int i = 0; i < 5; ++i, ++size)
        ar[i] = i + 1;
    cout << "ArrayList constructed with size: " << size << endl;
}

ArrayList::~ArrayList() {
    cout << "ArrayList destructor called!" << endl;
}

int ArrayList::get(int index = 0) {
    cout << "ArrayList.get() called with index: " << index << endl;
    return ar[index];
}

class LinkedList: public IList {
        int* ptr;
    public:
        LinkedList();
        ~LinkedList();
        int get(int index);
};

LinkedList::LinkedList() {
    ptr = new int;
    *ptr = 10;
    cout << "LinkedList constructed!" << endl;
}

LinkedList::~LinkedList() {
    delete ptr;
    cout << "LinkedList destroyed!" << endl;
}

int LinkedList::get(int index = 0) {
    cout << "LinkedList.get() called!" << endl;
    return *ptr;
}

void testList(IList* list) {
    cout << "Value: " << list->get(2) << endl;
}

int main() {
    ArrayList ar_list;
    LinkedList ld_list;
    testList(&ar_list);
    testList(&ld_list);
    return 0;
}
