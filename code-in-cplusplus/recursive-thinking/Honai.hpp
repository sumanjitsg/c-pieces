#ifndef HONAI_H
#define HONAI_H

class Honai {
        void auxhonai1(int n, char src, char aux, char target, long* counter);
    public:
        long honai1(int n, char src, char aux, char target);
        long honai2(int n, char src, char aux, char target);
};

#endif
