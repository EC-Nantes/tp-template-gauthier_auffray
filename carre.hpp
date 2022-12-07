#ifndef CARRE_H
#define CARRE_H

#include "pointT.hpp"
#include "rectangle.hpp"

template<typename T, typename U>
class carre_T : public rectangle<T, U> {

public:
    carre_T(pointT<T> p, U l);
};

template<typename T, typename U>
carre_T<T, U>::carre_T(pointT<T> p, U l) : rectangle<T, U>::rectangle(p, l, l) {;}

#endif