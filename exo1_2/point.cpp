#include"point.hpp"
using namespace std;


// 7. Surcharge de l'opérateur d'affectation (point = point)
const point& point::operator=(const point& p) {
    if (this != &p) { // Évite l'auto-affectation
        x = p.x;
        y = p.y;
    }
    return *this;
}
// 8. Surcharge de l'opérateur d'affectation (point = double)
const point& point::operator=(double xx) {
    x = xx;
    y = 0.0;
    return *this;
}
// 10. Surcharge de l'opérateur '-' 
const point operator-(const point& p) {
    return point(-p.x, -p.y);
}
// 10. Surcharge de l'opérateur '+'
const point operator+(const point& p){
    return p;
}
// 12. Surcharge de l'opérateur `+=` (point += point)
const point& point::operator+=(const point& p) {
    x += p.x;
    y += p.y;
    return *this;
}
// 13. Surcharge de l'opérateur `-=` (point += point)
const point& point::operator-=(const point& p) {
    x -= p.x;
    y -= p.y;
    return *this;
}
// 14 point+=double :
const point& point::operator+=(double xx){
    x += xx;
    return *this;
}
//15 point-=double :
const point& point::operator-=(double xx){
    x -= xx;
    return *this;
} // 16 p+q
const point operator+(const point& p, const point& q){
    return point(p.x + q.x, p.y + q.y);
}
// 17  p-q
const point operator-(const point& p, const point& q){
    return point(p.x - q.x, p.y - q.y);
}
// P+ double
const point operator+(const point& p, double xx){
    return point(p.x + xx, p.y);
}
// double - p :
const point operator-(double xx, const point& p){
    return point(xx - p.x, p.y);
}
ostream& operator<<(ostream& os, const point& p) {
    os << "(x, y) = (" << p.X() << ", " << p.Y() << ")";
    return os;
}