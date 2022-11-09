#include <Windows.h>
#include <stdio.h>

#include "ctrl.h"


/**
* emergency exit: [ctrl]+[Shift]+[F4]
*/
void bugExit()
{
	/*
	Refference:
	https ://blog.csdn.net/jzqt_t/article/details/31423459
	*/

	HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);  //��ñ�׼�����豸���
	INPUT_RECORD keyrec;                                //���������¼��ṹ��
	DWORD res;                                          //���巵�ؼ�¼
	while (1)
	{
		ReadConsoleInput(handle_in, &keyrec, 1, &res);  //��ȡ�����¼�
		if ((keyrec.EventType == KEY_EVENT)
			&& (keyrec.Event.KeyEvent.dwControlKeyState & SHIFT_PRESSED)
			&& ((keyrec.Event.KeyEvent.dwControlKeyState & LEFT_CTRL_PRESSED)
				|| (keyrec.Event.KeyEvent.dwControlKeyState & RIGHT_CTRL_PRESSED))
			&& (keyrec.Event.KeyEvent.wVirtualKeyCode == VK_F4
				&& keyrec.Event.KeyEvent.bKeyDown == 1))
		{
			exit(0);
		}
	}
}


/**
* restart: [ctrl]+[R]
*/
short restart()
{
	HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);  //��ñ�׼�����豸���
	INPUT_RECORD keyrec;                                //���������¼��ṹ��
	DWORD res;                                          //���巵�ؼ�¼
	
	printf("long press [ctrl]+[R] to restart\n\n");
	while (1)
	{
		ReadConsoleInput(handle_in, &keyrec, 1, &res);  //��ȡ�����¼�
		if ((keyrec.EventType == KEY_EVENT)
			&& ((keyrec.Event.KeyEvent.dwControlKeyState & LEFT_CTRL_PRESSED)
				|| (keyrec.Event.KeyEvent.dwControlKeyState & RIGHT_CTRL_PRESSED))
			&& (keyrec.Event.KeyEvent.wVirtualKeyCode == 'R'
				|| keyrec.Event.KeyEvent.wVirtualKeyCode == 'r'
				&& keyrec.Event.KeyEvent.bKeyDown == 1))
		{
			return 1;
		}
	}
	
}