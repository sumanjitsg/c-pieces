#ifndef ILIST_H
#define ILIST_H

namespace mylistns {

    class IList {
        public:
            virtual int get(int index) = 0;
            virtual void add(int e) = 0;
            virtual void display() = 0;
            virtual int size() = 0;
    };

}

#endif
