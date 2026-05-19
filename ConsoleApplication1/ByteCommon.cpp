#include "ByteCommon.h"
#include <thread>    // 线程
#include <mutex>     // 互斥锁
#include <condition_variable> // 条件变量
#include <atomic>    // 原子变量
#include <future>    // 异步获取结果
#include <chrono>    // 延时

using namespace std;
#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

//==================== Vec3 实现 ====================
Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
Vec3::Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

Vec3 Vec3::operator+(const Vec3& rhs) const
{
    return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vec3 Vec3::operator-(const Vec3& rhs) const
{
    return Vec3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vec3 Vec3::operator*(float s) const
{
    return Vec3(x * s, y * s, z * s);
}
float Vec3::operator*(const Vec3& rhs) const
{
    return (x * rhs.x+ y * rhs.y+ z * rhs.z);
}

Vec3 Vec3::operator/(float s) const
{
    return Vec3(x / s, y / s, z / s);
}

Vec3& Vec3::operator+=(const Vec3& rhs)
{
    x += rhs.x; y += rhs.y; z += rhs.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& rhs)
{
    x -= rhs.x; y -= rhs.y; z -= rhs.z;
    return *this;
}

Vec3& Vec3::operator*=(float s)
{
    x *= s; y *= s; z *= s;
    return *this;
}

Vec3& Vec3::operator/=(float s)
{
    x /= s; y /= s; z /= s;
    return *this;
}

const float dot(const Vec3& a, const Vec3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 cross(const Vec3& a, const Vec3& b)
{
    return Vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

std::ostream& operator<<(std::ostream& os, const Vec3& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

//==================== Mat4 实现 ====================
Mat4::Mat4()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            m[i][j] = 0.0f;
}

Mat4 Mat4::Identity()
{
    Mat4 mat;
    mat.m[0][0] = 1.0f;
    mat.m[1][1] = 1.0f;
    mat.m[2][2] = 1.0f;
    mat.m[3][3] = 1.0f;
    return mat;
}

Mat4 Mat4::operator+(const Mat4& rhs) const
{
    Mat4 res;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            res.m[i][j] = m[i][j] + rhs.m[i][j];
    return res;
}

Mat4 Mat4::operator-(const Mat4& rhs) const
{
    Mat4 res;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            res.m[i][j] = m[i][j] - rhs.m[i][j];
    return res;
}

// 矩阵乘法 核心重载
Mat4 Mat4::operator*(const Mat4& rhs) const
{
    Mat4 res;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            res.m[i][j] =
                m[i][0] * rhs.m[0][j] +
                m[i][1] * rhs.m[1][j] +
                m[i][2] * rhs.m[2][j] +
                m[i][3] * rhs.m[3][j];
        }
    }
    return res;
}

Mat4 Mat4::operator*(float s) const
{
    Mat4 res;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            res.m[i][j] = m[i][j] * s;
    return res;
}

Mat4& Mat4::operator+=(const Mat4& rhs)
{
    *this = *this + rhs;
    return *this;
}

Mat4& Mat4::operator-=(const Mat4& rhs)
{
    *this = *this - rhs;
    return *this;
}

Mat4& Mat4::operator*=(const Mat4& rhs)
{
    *this = *this * rhs;
    return *this;
}

Mat4& Mat4::operator*=(float s)
{
    *this = *this * s;
    return *this;
}

// 矩阵左乘向量
Vec3 operator*(const Mat4& m, const Vec3& v)
{
    float x = v.x * m.m[0][0] + v.y * m.m[0][1] + v.z * m.m[0][2] + m.m[0][3];
    float y = v.x * m.m[1][0] + v.y * m.m[1][1] + v.z * m.m[1][2] + m.m[1][3];
    float z = v.x * m.m[2][0] + v.y * m.m[2][1] + v.z * m.m[2][2] + m.m[2][3];
    return Vec3(x, y, z);
}

std::ostream& operator<<(std::ostream& os, const Mat4& m)
{
    for (int i = 0; i < 4; ++i)
    {
        os << "| ";
        for (int j = 0; j < 4; ++j)
        {
            os << m.m[i][j] << "\t";
        }
        os << "|\n";
    }
    return os;
}

//==================== 变换矩阵实现 ====================
Mat4 translate(float tx, float ty, float tz)
{
    Mat4 mat = Mat4::Identity();
    mat.m[0][3] = tx;
    mat.m[1][3] = ty;
    mat.m[2][3] = tz;
    return mat;
}

Mat4 scale(float sx, float sy, float sz)
{
    Mat4 mat = Mat4::Identity();
    mat.m[0][0] = sx;
    mat.m[1][1] = sy;
    mat.m[2][2] = sz;
    return mat;
}

Mat4 rotateX(float rad)
{
    Mat4 mat = Mat4::Identity();
    float c = cosf(rad);
    float s = sinf(rad);
    mat.m[1][1] = c;
    mat.m[1][2] = -s;
    mat.m[2][1] = s;
    mat.m[2][2] = c;
    return mat;
}

Mat4 rotateY(float rad)
{
    Mat4 mat = Mat4::Identity();
    float c = cosf(rad);
    float s = sinf(rad);
    mat.m[0][0] = c;
    mat.m[0][2] = s;
    mat.m[2][0] = -s;
    mat.m[2][2] = c;
    return mat;
}

Mat4 rotateZ(float rad)
{
    Mat4 mat = Mat4::Identity();
    float c = cosf(rad);
    float s = sinf(rad);
    mat.m[0][0] = c;
    mat.m[0][1] = -s;
    mat.m[1][0] = s;
    mat.m[1][1] = c;
    return mat;
}

void testVecAndMat() {
    // ==========================
// 主函数：全部演示
// ==========================

    // 向量测试
    Vec3 v1(1, 2, 3);
    Vec3 v2(4, 5, 6);
    cout << "v1 + v2 = " << v1 + v2 << endl;
    cout << "点积: dot(v1, v2) " << dot(v1, v2) << endl;
    cout << "点积: v1*v2 " << v1*v2 << endl;
    cout << "叉积: " << cross(v1, v2) << endl;

    // 矩阵测试
    Mat4 I = Mat4::Identity();
    Mat4 T = translate(2, 3, 4);
    Mat4 S = scale(2, 2, 2);
    Mat4 R = rotateZ(M_PI / 2.0f);

    // 矩阵相乘组合变换：T * R * S
    Mat4 finalMat = T * R * S;
    cout << "\n组合变换矩阵:\n" << finalMat << endl;

    // 矩阵变换向量
    Vec3 pos(1, 0, 0);
    Vec3 newPos = finalMat * pos;
    cout << "变换后坐标: " << newPos << endl;
}

MyVec MyVec::operator+(const MyVec& vec) const
{
    return MyVec(x+vec.x,y+vec.y,z+vec.z);
}
void func(int num)
{
    cout << "线程执行：" << num << endl;
}
void testJoin() {
    thread t1(func, 1000); // 创建线程并启动
    t1.join();            // 阻塞等待线程结束
    // t1.detach();       // 分离线程，后台运行，无需等待
}
class Test
{
public:
    void work(int x)
    {
        cout << "成员函数线程：" << x << endl;
    }
};

void testClassThread()
{
    Test t;
    // 格式：&类名::函数名, 对象, 参数
    thread th(&Test::work, &t, 666);
    th.join();
}
struct Functor
{
    void operator()(int val)
    {
        cout << "函数对象线程：" << val << endl;
    }
};

void testFunctor()
{
    thread th(Functor(), 888);
    th.join();
}

mutex mtx1;
int cnt = 0;
int mutcnt = 0;

void addTaskWithoutLock()
{
    for (int i = 0; i < 100000; ++i)
    {
        cnt++;
    }
}
void addTask()
{
    for (int i = 0; i < 100000; ++i)
    {
        mtx1.lock();       // 加锁
        mutcnt++;
        mtx1.unlock();     // 解锁
    }
}
void testWithoutLock()
{
    thread t1(addTaskWithoutLock);
    thread t2(addTaskWithoutLock);
    t1.join();
    t2.join();
    cout << "testWithoutLock 结果：" << cnt << endl;
}
void testMutex1()
{
    thread t1(addTask);
    thread t2(addTask);
    t1.join();
    t2.join();
    cout << "testMutex1 结果：" << mutcnt << endl;
}
int guardCnt = 0;
void addTaskWithlock_guard()
{
    for (int i = 0; i < 10000; ++i)
    {
        lock_guard<mutex> lg(mtx1); // 自动加锁
        guardCnt++;
        // 离开作用域自动解锁
    }
}
void testLockGuard()
{
    thread t1(addTaskWithlock_guard);
    thread t2(addTaskWithlock_guard);
    t1.join();
    t2.join();
    cout << "testLockGuard 结果：" << guardCnt << endl;
}

atomic<int> atomic_num = 0;
void atomicTask()
{
    for (int i = 0; i < 10000; i++) atomic_num++;
}

void testAtomicTask()
{
    thread t1(atomicTask);
    thread t2(atomicTask);
    t1.join();
    t2.join();
    cout << "testAtomicTask 结果：" << atomic_num << endl;
}