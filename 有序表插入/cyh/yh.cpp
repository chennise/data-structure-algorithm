#include<windows.h>
#include<string.h>	
#include"resource.h"



HINSTANCE hInstance;

LRESULT CALLBACK _ProcDlgMain(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	BOOL szBuffer;
	int a1;
	short a2;
	int b1, b2, b3, b4, b5, b6, b7, b8;

	HICON hc;
	if (uMsg == WM_CLOSE)
		EndDialog(hwnd, NULL);
	else if (uMsg == WM_COMMAND)
	{
		a1 = wParam;
		a2 = a1;
		if (a2 == T2)
			EndDialog(hwnd, NULL);
		else if (a2 == T1)
		{

			b1 = GetDlgItemInt(hwnd, B1, &szBuffer, TRUE);
			b2 = GetDlgItemInt(hwnd, B2, &szBuffer, TRUE);
			b3 = GetDlgItemInt(hwnd, B3, &szBuffer, TRUE);
			b4 = GetDlgItemInt(hwnd, B4, &szBuffer, TRUE);
			b5 = GetDlgItemInt(hwnd, B5, &szBuffer, TRUE);
			b6 = GetDlgItemInt(hwnd, B6, &szBuffer, TRUE);
			b7 = GetDlgItemInt(hwnd, B7, &szBuffer, TRUE);
			b8 = GetDlgItemInt(hwnd, B8, &szBuffer, TRUE);
			
			int array[] = { b1, b2, b3, b4, b5, b6, b7, b8 };
			int c = 7;
			__asm{// 嵌入式汇编代码部分
				xor ebx, ebx
				output : //外循环
				cmp ebx, c
					jz done
					mov ecx, ebx
				input :  //内循环
				cmp ecx, c
					jz past //等于0
					mov eax, [array + ebx * 4]
					cmp eax, [array + ecx * 4 + 4]
					jb change
					inc ecx
					jmp input
				change :
				xchg eax, [array + ecx * 4 + 4]
					mov[array + ebx * 4], eax
					inc ecx
					jmp input
				past :
				inc ebx
					jmp output
				done :
			}
			SetDlgItemInt(hwnd, B1, array[0], TRUE);
			SetDlgItemInt(hwnd, B2, array[1], TRUE);
			SetDlgItemInt(hwnd, B3, array[2], TRUE);
			SetDlgItemInt(hwnd, B4, array[3], TRUE);
			SetDlgItemInt(hwnd, B5, array[4], TRUE);
			SetDlgItemInt(hwnd, B6, array[5], TRUE);
			SetDlgItemInt(hwnd, B7, array[6], TRUE);
			SetDlgItemInt(hwnd, B8, array[7], TRUE);
			
		}
	}
	else
		return FALSE;

	return TRUE;
}


int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	hInstance = GetModuleHandle(NULL);
	DialogBoxParam(hInstance, (LPWSTR)D1, NULL, (DLGPROC)_ProcDlgMain, NULL);
	ExitProcess(NULL);
}