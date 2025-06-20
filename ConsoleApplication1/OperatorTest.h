#pragma once
//�������� :��ͬһ���������ڣ��������������������Ƶ�ͬ��������������Щͬ����������ʽ������ָ�����ĸ��������ͻ���˳�򣩱��벻ͬ�������ܽ�ͨ���������͵Ĳ�ͬ�����غ�����
//���ص�������Ǵ����������Ƶĺ��������������ɹؼ��� operator �����Ҫ���ص���������Ź��ɵġ�����������һ���������������һ���������ͺ�һ�������б�

#include <iostream>
using namespace std;

class Box
{
public:

    double getVolume(void)
    {
        return length * breadth * height;
    }
    void setLength(double len)
    {
        length = len;
    }

    void setBreadth(double bre)
    {
        breadth = bre;
    }

    void setHeight(double hei)
    {
        height = hei;
    }
    // ���� + ����������ڰ����� Box �������
    Box operator+(const Box& b)
    {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }
private:
    double length;      // ����
    double breadth;     // ���
    double height;      // �߶�
};
// �����������
int testOperatorPlus()
{
    Box Box1;                // ���� Box1������Ϊ Box
    Box Box2;                // ���� Box2������Ϊ Box
    Box Box3;                // ���� Box3������Ϊ Box
    double volume = 0.0;     // ������洢�ڸñ�����

    // Box1 ����
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);

    // Box2 ����
    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);

    // Box1 �����
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume << endl;

    // Box2 �����
    volume = Box2.getVolume();
    cout << "Volume of Box2 : " << volume << endl;

    // ������������ӣ��õ� Box3
    Box3 = Box1 + Box2;

    // Box3 �����
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume << endl;

    return 0;
}
//�������������() ���Ա�����������Ķ��󡣵�����() ʱ�������Ǵ�����һ���µĵ��ú����ķ�ʽ���෴�أ����Ǵ���һ�����Դ���������Ŀ�����������������
class Distance
{
private:
    int feet;             // 0 ������
    int inches;           // 0 �� 12
public:
    // ����Ĺ��캯��
    Distance() {
        feet = 0;
        inches = 0;
    }
    Distance(int f, int i) {
        feet = f;
        inches = i;
    }
    // ���غ������������
    Distance operator()(int a, int b, int c)
    {
        Distance D;
        // �����������
        D.feet = a + c + 10;
        D.inches = b + c + 100;
        return D;
    }
    // ��ʾ����ķ���
    void displayDistance()
    {
        cout << "F: " << feet << " I:" << inches << endl;
    }

};

int testOperatorBracket()
{
    Distance D1(11, 10), D2;

    cout << "First Distance : ";
    D1.displayDistance();

    D2 = D1(10, 10, 10); // invoke operator()
    cout << "Second Distance :";
    D2.displayDistance();

    return 0;
}