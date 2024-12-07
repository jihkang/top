#include "vector2.hpp"

Vector2::Vector2() : x(0.0), y(0.0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}

float Vector2::getX() {
    return x;
}

float Vector2::getY() {
    return y;
}