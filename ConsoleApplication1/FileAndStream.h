#pragma once
#include "CommonInclude.h"

void testFileStream() {

    char data[100];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("afile.dat");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // 向文件写入用户输入的数据
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // 再次向文件写入用户输入的数据
    outfile << data << endl;

    // 关闭打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream infile;
    infile.open("afile.dat");

    cout << "Reading from the file" << endl;
    infile >> data;

    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;

    // 关闭打开的文件
    infile.close();

}
//fstream类是iostream库中的一个类，它继承自istream和ostream类，这意味着它既可以用于输入也可以用于输出。
void testFStreamOut() {

    std::fstream file;
    file.open("example.txt", std::ios::out); // 以输出模式打开文件

    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return;
    }

    file << "Hello, World!" << std::endl; // 写入文本
    file.close(); // 关闭文件

}

void testFStreamIn() {

    std::fstream file;
    file.open("example.txt", std::ios::in); // 以输入模式打开文件

    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return; // 文件打开失败
    }

    std::string line;
    while (getline(file, line)) { // 逐行读取
        std::cout << line << std::endl;
    }

    file.close(); // 关闭文件
}

void testFStreamAppend() {

    std::fstream file;
    file.open("example.txt", std::ios::app); // 以追加模式打开文件

    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return; // 文件打开失败
    }

    file << "Appending this line to the file." << std::endl; // 追加文本
    file.close(); // 关闭文件
}