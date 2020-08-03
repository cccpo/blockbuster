#include <windows.h>
#include <iostream>

#include "GameWin32.h"
#include "DrawEngineWin32.h"

#include "../resource.h"

using std::cout;

const int gTetriminoSize = 25;//�e�g���~�m�̃T�C�Y
const int gScreenWidth= 20;
const int gScreenHeight = 20;


const int gTimerId = 1;

//�R�[���o�b�N�֐�
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow){

	static TCHAR szAppName[] = TEXT("BlockBuster");
	WNDCLASS wc; //WNDCLASS�\����:�E�B���h�E�N���X�̑�����\��
	HWND hwnd; //�E�B���h�E�n���h��
	MSG message;



	//�E�B���h�E�N���X�̑�����ݒ�
	
	//wc.cbSize = sizeof(WNDCLASSEX);
	//style:�X�^�C�����w�肷��
	//CS_HREDRAW:���������̃T�C�Y���ύX���ꂽ���ĕ`�� 
	//CS_VREDRAW:���������̃T�C�Y���ύX���ꂽ�Ƃ��ĕ`��
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;;
	//lpfnWndProc:�E�B���h�E�v���V�[�W��:�܂��E�B���h�E�v���V�[�W�����������Ă��Ȃ��̂�
	//�K���DefWindoProc��錾
	//wc.lpfnWndProc = DefWindowProc;
	wc.lpfnWndProc = WndProc;
	//�E�B���h�E�N���X�\���̂̌�Ɋm�ۂ���̈�̃o�C�g��
	wc.cbClsExtra = 0;
	//�E�B���h�E�C���X�^���X�̌�Ɋm�ۂ���̈�̃o�C�g��
	wc.cbWndExtra = 0;
	//
	//IpfnWndProc�Ŏw�肵���֐����܂܂��C���X�^���X�ւ̃n���h�����w��
	wc.hInstance = hInstance;
	//
	//�A�C�R���ւ̃n���h�����w��
	//wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	//�}�E�X�J�[�\���ւ̃n���h�����w��
	//IDC_ARROW:���
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//
	//�E�B���h�E�̔w�i��`�悷��u���V�ւ̃n���h��
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	//���j���[�̃��\�[�X��
	wc.lpszMenuName = NULL;
	//�E�B���h�E�N���X�Ɋ��蓖�Ă閼�O
	wc.lpszClassName = szAppName;
	
	//�E�B���h�E�N���X�̓o�^ �o�^���s����0��ԋp�@�v
	//#ToDO �o�^���s���̃G���[���b�Z�[�W�̍쐬
	if (!RegisterClass(&wc)) return 0;

	hwnd = CreateWindow(szAppName,
						TEXT("BlockBuster"),
						WS_OVERLAPPEDWINDOW,
	                    CW_USEDEFAULT, 
                        CW_USEDEFAULT,
						gScreenWidth * gTetriminoSize + 156,
						gScreenHeight * gTetriminoSize + 25,
			            NULL, 
                        NULL,
						hInstance, 
	                    NULL);
	
	if(!hwnd)return 0;

	//�E�B���h�E��\��
	ShowWindow(hwnd, nCmdShow);

	//�E�B���h�E���ĕ`��
	UpdateWindow(hwnd);

	//���b�Z�[�W���[�v
	while (GetMessage(&message, NULL, 0, 0)) {
		TranslateMessage(&message);//�L�[���̓��b�Z�[�W�𕶎����b�Z�[�W�ɕϊ�
		DispatchMessage(&message);//���b�Z�[�W���E�B���h�E�v���V�[�W���փf�B�X�p�b�`����
	}

	return message.wParam;

	
}


//�E�B���h�E�v���V�[�W��(���b�Z�[�W�ɑ΂���R�[���o�b�N�֐�

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {

	PAINTSTRUCT ps;
	HDC hdc;
	
	static GameWin32* game_win_32;
	static DrawEngineWin32* draw_engine_win32;

	switch (message) {
	
	//�E�B���h�E�j�����b�Z�[�W
	case WM_CREATE:
		hdc = GetDC(hwnd);

		draw_engine_win32 = new DrawEngineWin32(hdc, hwnd, gTetriminoSize);
		game_win_32 = new GameWin32(*draw_engine_win32);

		SetTimer(hwnd, gTimerId, 60, NULL);

		ReleaseDC(hwnd, hdc);//�f�o�C�X�R���e�L�X�g�̊J��
		return 0;
	
	//�L�[���̓��b�Z�[�W
	case WM_KEYDOWN:
		game_win_32->IsKeyPress(wParam);
		return 0;
	
	//���Ԍv�����b�Z�[�W
	case WM_TIMER:
		game_win_32->UpdateTime();

		return 0;

	//�t�H�[�J�X���������b�Z�[�W
	case WM_KILLFOCUS:
		KillTimer(hwnd, gTimerId);
		return 0;

	//�t�H�[�J�X���擾���郁�b�Z�[�W
	case WM_SETFOCUS:
		SetTimer(hwnd, gTimerId, 30, NULL);
		return 0;
	
	//�`����s�킹�郁�b�Z�[�W
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		game_win_32->PriorityDraw();
		EndPaint(hwnd, &ps);
		return 0;

	//�E�B���h�E�j�����b�Z�[�W
	case WM_DESTROY:
		delete draw_engine_win32;
		delete game_win_32;

		KillTimer(hwnd, gTimerId);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}