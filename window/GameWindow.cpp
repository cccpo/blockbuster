#include <windows.h>
#include <thread>
#include <chrono>

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpszCmdLine, int nCmdShow){
//    TCHAR szAppName[] = TEXT("first contact");
//    WNDCLASS wc;
//    HWND hwnd;
//
//     �E�B���h�E�N���X�̑�����ݒ�
//    wc.style = CS_HREDRAW | CS_VREDRAW;
//    wc.lpfnWndProc = DefWindowProc;
//    wc.cbClsExtra = 0;
//    wc.cbWndExtra = 0;
//    wc.hInstance = hInstance;
//    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//    wc.lpszMenuName = NULL;
//    wc.lpszClassName = szAppName;
//
//     �E�B���h�E�N���X��o�^
//    if (!RegisterClass(&wc)) return 0;
//
//     �E�B���h�E���쐬
//    hwnd = CreateWindow(szAppName, TEXT("Title"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT,CW_USEDEFAULT, CW_USEDEFAULT,NULL, NULL,hInstance, NULL);
//
//    if (!hwnd) return 0;
//
//     �E�B���h�E��\��
//    ShowWindow(hwnd, nCmdShow);
//
//     �E�B���h�E���ĕ`��
//    UpdateWindow(hwnd);
//
//    MessageBox(hwnd, TEXT("Create window"), TEXT(""), MB_OK);
//
//    return 0;
//}