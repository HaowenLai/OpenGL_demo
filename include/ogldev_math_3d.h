#ifndef OGLDEV_MATH_3D_H
#define OGLDEV_MATH_3D_H

struct Vector3f
{
    float x;
    float y;
    float z;
    Vector3f() {}
    Vector3f(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
};

// class Vector3f
// {
// public:
//     Vector3f(){}
//     Vector3f(float _x, float _y, float _z)
//     {
//         x = _x;
//         y = _y;
//         z = _z;
//     }
// 
//     float x;
//     float y;
//     float z;
// };

#endif