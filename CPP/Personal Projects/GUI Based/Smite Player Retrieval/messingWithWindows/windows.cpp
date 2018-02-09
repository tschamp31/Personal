#include <windows.h>

#define IDC_MAIN_BUTTON 101         // Button identifier
#define IDC_MAIN_PLAYER1   102         //Player 1
#define IDC_MAIN_PLAYER2   103         //Player 2
#define IDC_MAIN_PLAYER3   104         //Player 3
#define IDC_MAIN_PLAYER4   105         //Player 4
#define IDC_MAIN_PLAYER5   106         //Player 5
#define IDC_MAIN_PLAYER6   107         //Player 6
#define IDC_MAIN_PLAYER7   108         //Player 7
#define IDC_MAIN_PLAYER8   109         //Player 8
#define IDC_MAIN_PLAYER9   110         //Player 9  
HWND Player1;
HWND Player2;
HWND Player3;
HWND Player4;
HWND Player5;
HWND Player6;
HWND Player7;
HWND Player8;
HWND Player9;

LRESULT CALLBACK WinProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpCmdLine,int nShowCmd)
{
    WNDCLASSEX wClass;
    ZeroMemory(&wClass,sizeof(WNDCLASSEX));
    wClass.cbClsExtra=0;
    wClass.cbSize=sizeof(WNDCLASSEX);
    wClass.cbWndExtra=0;
    wClass.hbrBackground=(HBRUSH)COLOR_WINDOW;
    wClass.hCursor=LoadCursor(NULL,IDC_ARROW);
    wClass.hIcon=NULL;
    wClass.hIconSm=NULL;
    wClass.hInstance=hInst;
    wClass.lpfnWndProc=(WNDPROC)WinProc;
    wClass.lpszClassName="Window Class";
    wClass.lpszMenuName=NULL;
    wClass.style=CS_HREDRAW|CS_VREDRAW;

    if(!RegisterClassEx(&wClass))
    {
        int nResult=GetLastError();
        MessageBox(NULL,"Window class creation failed\r\n","Window Class Failed",MB_ICONERROR);
    }

    HWND hWnd=CreateWindowEx(0,"Window Class","Smite",WS_OVERLAPPEDWINDOW,200,200,640,480,0,0,hInst,0);

    if(!hWnd)
    {
        int nResult=GetLastError();

        MessageBox(NULL,"Window creation failed\r\n","Window Creation Failed",MB_ICONERROR);
    }

    ShowWindow(hWnd,nShowCmd);

    MSG msg;
    ZeroMemory(&msg,sizeof(MSG));

    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WinProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
    int playerBoxWidth, playerBoxHeight, playerBoxX, playerBoxY, seperator;
    playerBoxWidth = 150;
    playerBoxHeight = 20;
    playerBoxX = 10;
    playerBoxY = 50;
    seperator = 30;
    switch(msg)
    {
        case WM_CREATE:
        {
            // Create an edit box
            Player1=CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","",WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX,playerBoxY,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER1,GetModuleHandle(NULL),NULL);
            Player2=CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","",WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX,playerBoxY+=seperator,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER2,GetModuleHandle(NULL),NULL);
            Player3=CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","",WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX,playerBoxY+=seperator,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER3,GetModuleHandle(NULL),NULL);
            Player4=CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","",WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX,playerBoxY+=seperator,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER4,GetModuleHandle(NULL),NULL);
            Player5=CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","",WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX,playerBoxY+=seperator,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER5,GetModuleHandle(NULL),NULL);
            Player6=CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","",WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX,playerBoxY+=seperator,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER6,GetModuleHandle(NULL),NULL);
            Player7=CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","",WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX,playerBoxY+=seperator,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER7,GetModuleHandle(NULL),NULL);
            Player8=CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","",WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX,playerBoxY+=seperator,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER8,GetModuleHandle(NULL),NULL);
            Player9=CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","",WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX,playerBoxY+=seperator,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER9,GetModuleHandle(NULL),NULL);

            HGDIOBJ hfDefault=GetStockObject(DEFAULT_GUI_FONT);

            //SendMessage(hEdit,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));
            //SendMessage(hEdit,WM_SETTEXT,0,(LPARAM)"Insert text here...");
            SendMessage(Player1, WM_SIMPLE, FALSE, 0);
            SendMessage(Player1, WM_SETBKCOLOR, 0, RGB(0, 0, 0));

            // Create a push button
            HWND hWndButton=CreateWindowEx(0,"BUTTON","Submit",WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,10,playerBoxY+=seperator,100,24,hWnd,(HMENU)IDC_MAIN_BUTTON,GetModuleHandle(0),0);
            SendMessage(hWndButton,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));
        }
        break;

        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case IDC_MAIN_BUTTON:
                {
                    char player1[255], player2[255], player3[255], player4[255], player5[255], player6[255], player7[255], player8[255], player9[255];
                    SendMessage(Player1,WM_GETTEXT,sizeof(player1)/sizeof(player1[0]),reinterpret_cast<LPARAM>(player1));
                }
                break;
            }
            break;

        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
        break;
    }

    return DefWindowProc(hWnd,msg,wParam,lParam);
}