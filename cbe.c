#include <windows.h>
#include <tchar.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR pCmdLine, int showCmd){
	HGLOBAL hText;
	char *pText;

	hText = GlobalAlloc(GMEM_MOVEABLE, 1);
	pText = GlobalLock(hText);
	lstrcpy(pText, "");
	GlobalUnlock(hText);

	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hText);
	CloseClipboard();

	GlobalFree(hText);
}
