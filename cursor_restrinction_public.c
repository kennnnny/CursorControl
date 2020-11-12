#include <stdio.h>
#include <windows.h>
void ClipC(HWND hwnd);
BOOL EnumWindowsProc(HWND hWnd, long long lParam);

int main(void)
{
    RECT rcClip;           // new area for ClipCursor
    RECT rcOldClip;        // previous area for ClipCursor
    int count = 3;
    HWND hWnd = FindWindow("Notepad",NULL);

    // EnumWindows(EnumWindowsProc, 0);
    EnumChildWindows(hWnd, EnumWindowsProc, 0);
    while(count--)
    {
        if (IsWindowVisible(hWnd))
        {
            printf("Windows Found\n");
            ClipC(hWnd);
        }
        else
        {
            printf("Windows Not Found\n");
            hWnd = FindWindow("Edit",NULL);
        }
        Sleep(5000);
    }
    ClipCursor(NULL);
    return(0);
    // if (hWnd)
    // Record the area in which the cursor can move. 
    // GetClipCursor(&rcOldClip); 
    
    // Get the dimensions of the application's window. 
    // GetWindowRect(hwnd, &rcClip); 
    
    // Confine the cursor to the application's window. 
    // ClipCursor(&rcClip); 
    
    // 
    // Process input from the confined cursor. 
    // 
    
    // Restore the cursor to its previous area. 
    // ClipCursor(&rcOldClip);
}

BOOL EnumWindowsProc(HWND hWnd, long long lParam) {
    char buff[255];

    if (IsWindowVisible(hWnd)) {
        GetClassName(hWnd, (LPSTR) buff, 254);
        printf("%s\n", buff);
    }
    return TRUE;
}

void ClipC(HWND hwnd)
{
	RECT rt;
	POINT lt, rb;
	GetClientRect(hwnd,&rt);
    printf("RT: %lu,%lu,%lu,%lu", rt.left, rt.top, rt.right, rt.bottom);
	lt.x=rt.left;
	lt.y=rt.top;
	rb.x=rt.right;
	rb.y=rt.bottom;
	ClientToScreen(hwnd,&rb);
	rt.left=lt.x;
	rt.top=lt.y;
	rt.right=rb.x;
	rt.bottom=rb.y;
    printf("RT2: %lu,%lu,%lu,%lu", rt.left, rt.top, rt.right, rt.bottom);
	//GetWindowRect(hwnd,&rt);
	ClipCursor(&rt);
}

//GetWindowRect()
//Retrieves the dimensions of the bounding rectangle of the specified window. 
//The dimensions are given in screen coordinates that are relative to the upper-left corner of the screen.

//ClientToScreen()
//The ClientToScreen function converts the client-area coordinates of a specified point to screen coordinates.

//GetClientRect()
//Retrieves the coordinates of a window's client area. 
//The client coordinates specify the upper-left and lower-right corners of the client area. 
//Because client coordinates are relative to the upper-left corner of a window's client area, 
//the coordinates of the upper-left corner are (0,0).