#pragma once
//ʲô�� CGI��
//�������ؽӿڣ�CGI������һ�ױ�׼����������Ϣ������� Web �������Ϳͻ��˽ű�֮����н����ġ�
//CGI �淶Ŀǰ���� NCSA ά���ģ�NCSA ���� CGI ���£�
//�������ؽӿڣ�CGI������һ�������ⲿ���س�������Ϣ���������� HTTP ���������ԽӵĽӿڱ�׼��
//Ŀǰ�İ汾�� CGI / 1.1��CGI / 1.2 �汾�����ƽ��С�
//��������Ĵ��룬�ѿ�ִ���ļ�����Ϊ cplusplus.cgi����������ļ������� / var / www / cgi - bin Ŀ¼�С�
#include <iostream>
using namespace std;

int testCGI()
{

    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<title>Hello World - ��һ�� CGI ����</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "<h2>Hello World! �����ҵĵ�һ�� CGI ����</h2>\n";
    cout << "</body>\n";
    cout << "</html>\n";

    return 0;
}
//C++ CGI ����������κ������ⲿ��ϵͳ���� RDBMS�����н�����

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
    cout << "<title>CGI ��������</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "<table border = \"0\" cellspacing = \"2\">";

    for (int i = 0; i < 24; i++)
    {
        cout << "<tr><td>" << ENV[i] << "</td><td>";
        // ���Լ�������������ֵ
        /*char* value = getenv(ENV[i].c_str());
        if (value != 0) {
            cout << value;
        }
        else {
            cout << "�������������ڡ�";
        }*/
        cout << "</td></tr>\n";
    }
    cout << "</table><\n";
    cout << "</body>\n";
    cout << "</html>\n";

    return 0;
}