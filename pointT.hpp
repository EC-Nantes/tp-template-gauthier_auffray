#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>

template<typename T>
class pointT;

template<typename T>
std::ostream& operator<<(std::ostream &, pointT<T> const&);

template<typename T>
class pointT {
protected:
   T x;
   T y;
public:
   // constructors
   pointT();
   pointT(T x,T y);
   pointT(const pointT<T>& pt);

   // getters
   T getX()const {return x;}
   T getY()const {return y;}

   // setters
   void setX(T x) {this->x = x;}
   void setY(T x) {this->y = y;}

   // methods
   // T norm2() const;
   void translater(T& abs, T& ord);
   friend std::ostream& operator<<(std::ostream &, pointT<T> const&);
};

// constructors
template<typename T> 
pointT<T>::pointT(){
   this->x = T();
   this->y = T();
}
template<typename T> 
pointT<T>::pointT(T x,T y) {
   this->x = x;
   this->y = y;
}
template<typename T>
pointT<T>::pointT(const pointT<T>& pt) {
   this->x = pt.getX();
   this->y = pt.getY();
}

// methods
// template<typename T>
// T pointT<T>::norm2()const {
//    return x * x + y * y;
// }
template<typename T>
void pointT<T>::translater(T& abs, T& ord) {
   this->x += abs;
   this->y += ord;
}

template<> void pointT<std::string>::translater(std::string& abs, std::string& ord) {
   this->x.swap(abs);
   this->y.swap(ord);
}

template<typename T>
std::ostream& operator<<(std::ostream& o, pointT<T> const& pt) {
   o << "x : " << pt.getX() << "\ty : " << pt.getY() << std::endl;
   return o;
}

#endif