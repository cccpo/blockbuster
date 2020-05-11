#include <Windows.h>



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow){

	static TCHAR szAppName[] = TEXT("BlockPiece");
	WNDCLASS wc; //WNDCLASS�\����:�E�B���h�E�N���X�̑�����\��
	HWND hwnd; //�E�B���h�E�n���h��

	//�E�B���h�E�N���X�̑�����ݒ�
	
	//style:�X�^�C�����w�肷��
	//CS_HREDRAW:���������̃T�C�Y���ύX���ꂽ���ĕ`�� 
	//CS_VREDRAW:���������̃T�C�Y���ύX���ꂽ�Ƃ��ĕ`��
	wc.style = CS_HREDRAW | CS_VREDRAW;
	//lpfnWndProc:�E�B���h�E�v���V�[�W��:�܂��E�B���h�E�v���V�[�W�����������Ă��Ȃ��̂�
	//�K���DefWindoProc��錾
	wc.lpfnWndProc = DefWindowProc;
	//wc.lpfnWndProc = WndProc;
	//�E�B���h�E�N���X�\���̂̌�Ɋm�ۂ���̈�̃o�C�g��
	wc.cbClsExtra = 0;
	//�E�B���h�E�C���X�^���X�̌�Ɋm�ۂ���̈�̃o�C�g��
	wc.cbWndExtra = 0;
	//
	//IpfnWndProc�Ŏw�肵���֐����܂܂��C���X�^���X�ւ̃n���h�����w��
	wc.hInstance = hInstance;
	//
	//�A�C�R���ւ̃n���h�����w��
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//�}�E�X�J�[�\���ւ̃n���h�����w��
	//IDC_ARROW:���
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//
	//�E�B���h�E�̔w�i��`�悷��u���V�ւ̃n���h��
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	//���j���[�̃��\�[�X��
	wc.lpszMenuName = NULL;
	//�E�B���h�E�N���X�Ɋ��蓖�Ă閼�O
	wc.lpszClassName = szAppName;
	
	//�E�B���h�E�N���X�̓o�^ �o�^���s����0��ԋp�@�v
	//#ToDO �o�^���s���̃G���[���b�Z�[�W�̍쐬
	if (!RegisterClass(&wc)) return 0;

	hwnd = CreateWindow(szAppName,
						TEXT("BlcokBuster"),
						WS_OVERLAPPEDWINDOW,
	                    CW_USEDEFAULT, 
                        CW_USEDEFAULT,
                        CW_USEDEFAULT, 
                        CW_USEDEFAULT,
			            NULL, 
                        NULL,hInstance, 
	                    NULL);
	
	if(!hwnd)return 0;

	//�E�B���h�E��\��
	ShowWindow(hwnd, nCmdShow);

	//�E�B���h�E���ĕ`��
	UpdateWindow(hwnd);

	//���b�Z�[�W�{�b�N�X����
	MessageBox(NULL,
		TEXT("Create Window"),
		TEXT("Test"),
		MB_OK);

	return 0;
}

//LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
//
//}