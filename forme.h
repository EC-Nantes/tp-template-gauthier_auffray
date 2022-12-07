#ifndef FORME_H
#define FORME_H

#include "pointT.hpp"

template<typename T, typename U>
class forme_T;

template<typename T, typename U>
std::ostream& operator<<(std::ostream &, forme_T<T, U> const&);

template<typename T, typename U>
class forme_T {
private:
    pointT<T> centre;
public:
    // constructors
    forme_T();
    forme_T(const pointT<T>&);
    
    // methods
    pointT<T> get()const {return centre;}
    virtual U perimettre() = 0;
    virtual U surface() = 0;
};

// constructors
template<typename T, typename U>
forme_T<T, U>::forme_T() {
    centre.setX(0);
    centre.setY(0);
}
template<typename T, typename U>
forme_T<T, U>::forme_T(const pointT<T>& pt) {
    centre.setX(pt.getX());
    centre.setY(pt.getY());
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream & o, forme_T<T, U> const& fm) {
    o << "centre de la forme x : " << fm.get().getX() << "\ty : " << fm.get().getY();
    return o;
}

#endif