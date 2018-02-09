#define _WIN32_WINNT 0x0601
#include <iostream>
#include <Windows.h>
#include <limits>
#include <tesseract\baseapi.h>
#include <leptonica\allheaders.h>

using namespace std;

// void GetScreenShot(void)
// {
//     int x1, y1, x2, y2, w, h;

//     // get screen dimensions
//     x1  = GetSystemMetrics(SM_XVIRTUALSCREEN);
//     y1  = GetSystemMetrics(SM_YVIRTUALSCREEN);
//     x2  = GetSystemMetrics(SM_CXVIRTUALSCREEN);
//     y2  = GetSystemMetrics(SM_CYVIRTUALSCREEN);
//     w   = x2 - x1;
//     h   = y2 - y1;

//     // copy screen to bitmap
//     HDC     hScreen = GetDC(NULL);
//     HDC     hDC     = CreateCompatibleDC(hScreen);
//     HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, w, h);
//     HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
//     BOOL    bRet    = BitBlt(hDC, 0, 0, w, h, hScreen, x1, y1, SRCCOPY);

//     // save bitmap to clipboard
//     OpenClipboard(NULL);
//     EmptyClipboard();
//     SetClipboardData(CF_BITMAP, hBitmap);
//     CloseClipboard();   

//     // clean up
//     SelectObject(hDC, old_obj);
//     DeleteDC(hDC);
//     ReleaseDC(NULL, hScreen);
//     DeleteObject(hBitmap);
// }


void GetScreenShot()
{ 
    RECT rc;
    HWND hwnd = FindWindow(NULL ,TEXT("Smite (32-bit, DX9)"));    //the window can't be min
    if (hwnd == NULL)
    {
        std::cout << "Window was not found." << std::endl;
    }

    else
    {
        GetClientRect(hwnd, &rc);

        //create
        HDC hdcScreen = GetDC(NULL);
        HDC hdc = CreateCompatibleDC(hdcScreen);
        HBITMAP hbmp = CreateCompatibleBitmap(hdcScreen, 
            rc.right - rc.left, rc.bottom - rc.top);
        SelectObject(hdc, hbmp);

        //Print to memory hdc
        PrintWindow(hwnd, hdc, PW_CLIENTONLY);

        //copy to clipboard
        OpenClipboard(NULL);
        EmptyClipboard();
        SetClipboardData(CF_BITMAP, hbmp);
        CloseClipboard();

        //release
        DeleteDC(hdc);
        DeleteObject(hbmp);
        ReleaseDC(NULL, hdcScreen);

        std::cout << "success copy to clipboard, please paste it to the 'mspaint'" << std::endl;
    }
}

void TessTest()
{
    tesseract::TessBaseAPI api;
    api.Init("", "eng", tesseract::OEM_DEFAULT);
    api.SetPageSegMode(static_cast<tesseract::PageSegMode>(7));
    api.SetOutputName("out");

    cout<<"File name:";
    char image[256];
    cin>>image;
    PIX   *pixs = pixRead(image);

    STRING text_out;
    api.ProcessPages(image, NULL, 0, &text_out);

    cout<<text_out.string();


}

int main(int argc, char const *argv[])
{

    TessTest();
	//GetScreenShot();

    cin.get();
	return 0;
}