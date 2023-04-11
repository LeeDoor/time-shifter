#pragma once
#include <memory>
#include <cmath>

//standard two-dimentional vector
template<typename T>
class Vector2{
public:
    T x, y; // coordinates

    Vector2() {
        x = 0;
        y = 0;
    }
    Vector2(T x_, T y_) : x(x_), y(y_) {}

    static Vector2<float> Up; 
    static Vector2<float> Down;
    static Vector2<float> Right;
    static Vector2<float> Left;
    static Vector2<float> One;
    static Vector2<float> Zero;

    // normalizes current vector
    void normalize() {
        float inv_length = 1.0f / len();
        *this *= inv_length;
    }
    // length of vector
    float len() {
        return sqrt(lenpw2());
    } 
    // length of vector in second power. needed to compare two lengths without counting sqrt
    float lenpw2() {
        return x*x + y*y;
    } 

    /// operators
    Vector2 operator + (const Vector2& sec){
        return Vector2 { x + sec.x, y + sec.y };
    }
    Vector2 operator - (const Vector2& sec){
        return Vector2 { x - sec.x, y - sec.y };
    }
    Vector2 operator * (float m) {
        return Vector2 { x * m, y * m };
    }
    void operator += (const Vector2& sec) {
        x += sec.x;
        y += sec.y;
    }
    void operator -= (const Vector2& sec) {
        x -= sec.x;
        y -= sec.y;
    }
    void operator *= (float m) {
        x *= m;
        y *= m;
    }

    bool operator > (Vector2 sec) {
        return lenpw2() > sec.lenpw2();
    }
    bool operator < (Vector2 sec) {
        return lenpw2() < sec.lenpw2();
    }
    bool operator >= (Vector2 sec) {
        return lenpw2() >= sec.lenpw2();
    }
    bool operator <= (Vector2 sec) {
        return lenpw2() <= sec.lenpw2();
    }
    bool operator == (Vector2 sec) {
        return lenpw2() == sec.lenpw2();
    }
    bool operator != (Vector2 sec) {
        return lenpw2() != sec.lenpw2();
    }
};

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;
typedef std::unique_ptr<Vector2f> Vector2fPtr;
typedef std::unique_ptr<Vector2i> Vector2iPtr;

template<typename T>
Vector2<float> Vector2<T>::Up = Vector2<float>(0, 1); 
template<typename T>
Vector2<float> Vector2<T>::Down = Vector2<float>{0, -1};
template<typename T>
Vector2<float> Vector2<T>::Right = Vector2<float>{-1, 0};
template<typename T>
Vector2<float> Vector2<T>::Left = Vector2<float>{1, 0};
template<typename T>
Vector2<float> Vector2<T>::One = Vector2<float>{1, 1};
template<typename T>
Vector2<float> Vector2<T>::Zero = Vector2<float>{0, 0};
