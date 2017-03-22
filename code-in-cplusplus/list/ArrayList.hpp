#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "IList.hpp"

namespace mylistns {

    class ArrayList: public IList {
            int* array;
            int array_size;
            int num_elements;
            void doubling();
        public:
            ArrayList();
            ~ArrayList();
            int get(int index);
            void add(int e);
            void display();
            int size();
    };

}

#endif
