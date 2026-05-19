#pragma once
#include <iostream>
#include <cmath>

// 三维向量
struct Vec3
{
    float x, y, z;

    Vec3();
    Vec3(float x_, float y_, float z_);

    // 向量运算符重载
    Vec3 operator+(const Vec3& rhs) const;
    Vec3 operator-(const Vec3& rhs) const;
    Vec3 operator*(float s) const;
    float operator*(const Vec3& rhs) const;
    Vec3 operator/(float s) const;

    Vec3& operator+=(const Vec3& rhs);
    Vec3& operator-=(const Vec3& rhs);
    Vec3& operator*=(float s);
    Vec3& operator/=(float s);
};

// 向量全局运算
const float dot(const Vec3& a, const Vec3& b);
Vec3  cross(const Vec3& a, const Vec3& b);
std::ostream& operator<<(std::ostream& os, const Vec3& v);

// 4阶齐次矩阵
struct Mat4
{
    float m[4][4];

    Mat4();
    // 单位矩阵静态构造
    static Mat4 Identity();

    // 矩阵运算符重载
    Mat4 operator+(const Mat4& rhs) const;
    Mat4 operator-(const Mat4& rhs) const;
    Mat4 operator*(const Mat4& rhs) const;
    Mat4 operator*(float s) const;

    Mat4& operator+=(const Mat4& rhs);
    Mat4& operator-=(const Mat4& rhs);
    Mat4& operator*=(const Mat4& rhs);
    Mat4& operator*=(float s);
};

// 矩阵 × 向量
Vec3 operator*(const Mat4& m, const Vec3& v);
std::ostream& operator<<(std::ostream& os, const Mat4& m);

// 基础变换矩阵
Mat4 translate(float tx, float ty, float tz);
Mat4 scale(float sx, float sy, float sz);
Mat4 rotateX(float rad);
Mat4 rotateY(float rad);
Mat4 rotateZ(float rad);
class MyVec {
    float x, y, z;
    MyVec(float x, float y, float z) :x(x), y(y), z(z) {}
    MyVec operator +(const MyVec& vec) const;
};

std::ostream& operator<<(std::ostream& os, const MyVec& v);
void testVecAndMat();
void testJoin();
void testClassThread();
void testFunctor();
void testWithoutLock();
void testMutex1();
void testLockGuard();
void testAtomicTask();
