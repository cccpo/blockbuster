#include <Windows.h>

const int SCREEN_WIDTH = 10;    // Level width in cells
const int SCREEN_HEIGHT = 20;   // Level height in cells 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow){

	static TCHAR szAppName[] = TEXT("BlockPiece");
	WNDCLASS wc; //WNDCLASS�\����:�E�B���h�E�N���X�̑�����\��
	HWND hwnd; //�E�B���h�E�n���h��

	//�E�B���h�E�N���X�̑�����ݒ�
	//wc.style
	//CS_HREDRAW:���������̃T�C�Y���ύX���ꂽ���ĕ`�� 
	//CS_VREDRAW:���������̃T�C�Y���ύX���ꂽ�Ƃ��ĕ`��
	wc.style = CS_HREDRAW | CS_VREDRAW;

	//���b�Z�[�W�{�b�N�X����
	MessageBox(NULL,
		TEXT("HEllo,WOrd;"),
		TEXT("TEst"),
		MB_OK);

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {

}