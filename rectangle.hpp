#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "pointT.hpp"
#include "forme.h"

template<typename T, typename U>
class rectangle;

template<typename T, typename U>
std::ostream& operator<<(std::ostream &, rectangle<T, U> const&);

template<typename T, typename U>
class rectangle : public forme_T<T, U> {
 
protected:
   U l;
   U h;

public:
   // constructor
   rectangle(pointT<T> p, U l, U h);

   // getters
   T getL()const {return this->l;}
   T getH()const {return this->h;}

   // methods
   U perimettre();
   U surface();
   friend std::ostream& operator<< (std::ostream &, rectangle<T, U> const&);
};

// constructor
template <typename T, typename U>
rectangle<T, U>::rectangle(pointT<T> p, U l, U h) : forme_T<T, U>::forme_T(p) {
   this->h = h;
   this->l = l;
}

// methods
template<typename T, typename U>
U rectangle<T, U>::perimettre() {
   return (2 * this->l + 2 * this->h);
}

template<typename T, typename U>
U rectangle<T, U>::surface() {
   return (this->h * this->l);
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream &o, rectangle<T, U> const &R) {
   o << "Rectangle (" << R.get().getX() << "," << R.get().getY() << "), " << R.getH() << ", " << R.getL() << std::endl;
   return o;
}
#endif