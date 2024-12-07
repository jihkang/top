#ifndef VECTOR_2
#define VECTOR_2

class Vector2
{
private:
    float x, y;
private:
    Vector2(float x);
public:
    Vector2(float x, float y);
    Vector2();
    float getX();
    float getY();
};

#endif