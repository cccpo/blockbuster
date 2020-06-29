#include <Windows.h>
#include "../Game.h"
#include "../board/GameBoard.h"
#include "../board/DrawEngine.h"

#include "../resource.h"

//�R�[���o�b�N�֐�
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow){
//
//	static TCHAR szAppName[] = TEXT("BlockPiece");
//	WNDCLASS wc; //WNDCLASS�\����:�E�B���h�E�N���X�̑�����\��
//	HWND hwnd; //�E�B���h�E�n���h��
//	MSG msg;
//
//
//
//	//�E�B���h�E�N���X�̑�����ݒ�
//	
//	//style:�X�^�C�����w�肷��
//	//CS_HREDRAW:���������̃T�C�Y���ύX���ꂽ���ĕ`�� 
//	//CS_VREDRAW:���������̃T�C�Y���ύX���ꂽ�Ƃ��ĕ`��
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	//lpfnWndProc:�E�B���h�E�v���V�[�W��:�܂��E�B���h�E�v���V�[�W�����������Ă��Ȃ��̂�
//	//�K���DefWindoProc��錾
//	//wc.lpfnWndProc = DefWindowProc;
//	wc.lpfnWndProc = WndProc;
//	//�E�B���h�E�N���X�\���̂̌�Ɋm�ۂ���̈�̃o�C�g��
//	wc.cbClsExtra = 0;
//	//�E�B���h�E�C���X�^���X�̌�Ɋm�ۂ���̈�̃o�C�g��
//	wc.cbWndExtra = 0;
//	//
//	//IpfnWndProc�Ŏw�肵���֐����܂܂��C���X�^���X�ւ̃n���h�����w��
//	wc.hInstance = hInstance;
//	//
//	//�A�C�R���ւ̃n���h�����w��
//	//wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
//	//�}�E�X�J�[�\���ւ̃n���h�����w��
//	//IDC_ARROW:���
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	//
//	//�E�B���h�E�̔w�i��`�悷��u���V�ւ̃n���h��
//	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
//	//���j���[�̃��\�[�X��
//	wc.lpszMenuName = NULL;
//	//�E�B���h�E�N���X�Ɋ��蓖�Ă閼�O
//	wc.lpszClassName = szAppName;
//	
//	//�E�B���h�E�N���X�̓o�^ �o�^���s����0��ԋp�@�v
//	//#ToDO �o�^���s���̃G���[���b�Z�[�W�̍쐬
//	if (!RegisterClass(&wc)) return 0;
//
//	hwnd = CreateWindow(szAppName,
//						TEXT("BlcokBuster"),
//						WS_OVERLAPPEDWINDOW,
//	                    CW_USEDEFAULT, 
//                        CW_USEDEFAULT,
//                        CW_USEDEFAULT, 
//                        CW_USEDEFAULT,
//			            NULL, 
//                        NULL,hInstance, 
//	                    NULL);
//	
//	if(!hwnd)return 0;
//
//	//�E�B���h�E��\��
//	ShowWindow(hwnd, nCmdShow);
//
//	//�E�B���h�E���ĕ`��
//	UpdateWindow(hwnd);
//
//	//���b�Z�[�W���[�v
//	//while (GetMessage(&msg, NULL, 0, 0)) {
//	//	TranslateMessage(&msg);//�L�[���̓��b�Z�[�W�𕶎����b�Z�[�W�ɕϊ�
//	//	DispatchMessage(&msg);//���b�Z�[�W���E�B���h�E�v���V�[�W���փf�B�X�p�b�`����
//	//}
//
//	//���b�Z�[�W�{�b�N�X����
//	MessageBox(NULL,
//		TEXT("Create Window"),
//		TEXT("Test"),
//		MB_OK);
//
//	
//
//	
//
//	return 0;
//}
//

//�E�B���h�E�v���V�[�W��(���b�Z�[�W�ɑ΂���R�[���o�b�N�֐�

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {

	PAINTSTRUCT ps;
	HDC hdc;
	

	switch (message) {
	
	//�E�B���h�E�j�����b�Z�[�W
	case WM_CREATE:
		hdc = GetDC(hwnd);
		return 0;

	case WM_KEYDOWN:
		
		return 0;

	case WM_TIMER:
		
		return 0;

	case WM_KILLFOCUS:
	
		return 0;

	case WM_SETFOCUS:
		
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}