#include "ConstructorTest.h"


void testContructor() {
	MainWindow::MainWindow();
}
// ͷ�ļ��������˵�δʵ��
QMainWindow::QMainWindow() {
};

QMainWindow::QMainWindow(string name) {
	this->name = name;
}
QMainWindow::~QMainWindow() {};
//�޷��������ⲿ���� ����������ˣ�����û�н��ж��壬�ͻ����
MainWindow::MainWindow() {

}
//��C++�У�Ĭ�Ϲ��캯�����޲ι��죩�����г�ʼ���б������
MainWindow::MainWindow(string name):QMainWindow("QMainWindow"), name("sunwindow") {//MainWindow::MainWindow(QWidget *parent) �����ð�źͶ����﷨�ǳ�Ա��ʼ���б�
	/*2��Ҫ����
	��ʼ�� const ��Ա
	��ʼ�����ó�Ա
	��ʼ��û��Ĭ�Ϲ��캯�������Ա
	��ʼ�����ࣨ�籾����*/
	/*3ִ��˳��
		��ʼ����������˳��ִ�У��ǳ�ʼ���б�˳��*/
	cout << "MainWindow name" << name << endl;

}