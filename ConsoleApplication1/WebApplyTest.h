#pragma once
//什么是 CGI？
//公共网关接口（CGI），是一套标准，定义了信息是如何在 Web 服务器和客户端脚本之间进行交换的。
//CGI 规范目前是由 NCSA 维护的，NCSA 定义 CGI 如下：
//公共网关接口（CGI），是一种用于外部网关程序与信息服务器（如 HTTP 服务器）对接的接口标准。
//目前的版本是 CGI / 1.1，CGI / 1.2 版本正在推进中。
//编译上面的代码，把可执行文件命名为 cplusplus.cgi，并把这个文件保存在 / var / www / cgi - bin 目录中。
#include <iostream>
using namespace std;

int testCGI()
{

    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<title>Hello World - 第一个 CGI 程序</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "<h2>Hello World! 这是我的第一个 CGI 程序</h2>\n";
    cout << "</body>\n";
    cout << "</html>\n";

    return 0;
}
//C++ CGI 程序可以与任何其他外部的系统（如 RDBMS）进行交互。

const string ENV[24] = {
        "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",
        "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",
        "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",
        "HTTP_HOST", "HTTP_USER_AGENT", "PATH",
        "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",
        "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
        "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",
        "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",
        "SERVER_SIGNATURE","SERVER_SOFTWARE" };

int testEnvironmet()
{

    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<title>CGI 环境变量</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "<table border = \"0\" cellspacing = \"2\">";

    for (int i = 0; i < 24; i++)
    {
        cout << "<tr><td>" << ENV[i] << "</td><td>";
        // 尝试检索环境变量的值
        /*char* value = getenv(ENV[i].c_str());
        if (value != 0) {
            cout << value;
        }
        else {
            cout << "环境变量不存在。";
        }*/
        cout << "</td></tr>\n";
    }
    cout << "</table><\n";
    cout << "</body>\n";
    cout << "</html>\n";

    return 0;
}