#define CURL_STATICLIB
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <string>
#include <algorithm>
#include <windows.h>
#include <vector>

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
#define IDC_MAIN_DISPLAY1 111  
HWND Player1, Player2, Player3, Player4, Player5, Player6, Player7, Player8, Player9, legend;
HWND Player1D, Player2D, Player3D, Player4D, Player5D, Player6D, Player7D, Player8D, Player9D;


using namespace std;

void retrieveFile(string name)
{
    CURL *curl;
    CURLcode res;
    FILE *fp;

    string baseurl= "https://smite.guru/stats/";
    string final = baseurl + name;

    const char *url = final.c_str();    

    curl = curl_easy_init();
    if (curl)
    {
      fp = fopen("testing.txt","wb");

        curl_easy_setopt(curl, CURLOPT_URL, url);//opens the said url
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);//Follows redirect
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE);//Disable ssl
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);//checks for errors
        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        fclose(fp);
    }
}

string delUnnecessary(string &str)
{
    int size = str.length();
    for(int j = 0; j<=size; j++)
    {
        for(int i = 0; i <=j; i++)
        {
            if(str[i] == ' ' && str[i+1] == ' ')
            {
                str.erase(str.begin() + i);
            }
            else if(str[0]== ' ')
            {
                str.erase(str.begin());
            }
            else if(str[i] == '\0' && str[i-1]== ' ')
            {
                str.erase(str.end() - 1);
            }
        }
    }
    return str;
}

vector<string> retrievePlayerInfo(string playerName)
{
//conquest rank - 184, elo - 191, played - 203, win% - 209
//joust rank - 244, elo - 251, played - 263, win% - 269
//casual mmr - 1311
  vector<string> answer(9);
  string joustRank, conquestRank, line;
  int joustElo, joustPlayed, joustWinPercent, conquestElo, conquestPlayed, conquestWinPercent, casualMMR, lineCount, lineTracker, i;
  int positions[] = {183,190,202,208,243,250,262,268,1310};
  string::size_type s = 0;
  string deliminators[] = {"<small>", "</small>", "<strong>", "</strong>", "<br>"};
  lineTracker = 0;
  lineCount = 0;

  ifstream playerFile;
  playerFile.open("testing.txt");

  cout << playerName << endl;
  while(!playerFile.eof())
  {
    while(getline(playerFile, line))
    {
      if(lineCount == positions[lineTracker])
      {
        for(i = 0; i != 5; i++)
        {
          if((s = line.find(deliminators[i],s)) != string::npos)
          {
            line.erase(s,deliminators[i].size());
          }
          s = 0;
        }
        line = delUnnecessary(line);
        answer[lineTracker] = line;
        lineTracker++;
      }
      lineCount++;
    }
  }
  return answer;
}

const char g_szClassName[] = "myWindowClass";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
          DestroyWindow(hwnd);
          break;
        case WM_DESTROY:
          PostQuitMessage(0);
          break;
        default:
          return DefWindowProc(hwnd, msg, wParam, lParam);
    }
  return 0;
}

LRESULT CALLBACK WinProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
    int playerBoxWidth, playerBoxHeight, playerBoxX, playerBoxY, seperator, i;
    char player1[255], player2[255], player3[255], player4[255], player5[255], player6[255], player7[255], player8[255], player9[255], message[255];
    string definition[] = {"Conquest Rank: ","Elo: ","Played: ","Win%: ","Joust Rank: ","Elo: ","Played: ","Win%: ","Casual MMR: "};
    vector<string> temp;
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
          for(i = 0; i != 9; i++)
          {
            strcpy(message, definition[i].c_str());
            legend=CreateWindowEx(WS_EX_CLIENTEDGE,"STATIC",message,WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX+=150,25,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER9,GetModuleHandle(NULL),NULL);
          }
          playerBoxX = 10;
            Player1=CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","zapman",WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX,playerBoxY,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER1,GetModuleHandle(NULL),NULL);
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
                    SendMessage(Player1,WM_GETTEXT,sizeof(player1)/sizeof(player1[0]),reinterpret_cast<LPARAM>(player1));

                    if(player1[0] != '\0')
                    {
                      retrieveFile(player1);
                      temp = retrievePlayerInfo(player1);
                      for(i = 0; i != 9; i++)
                      {
                        strcpy(message, temp[i].c_str());
                        Player1D=CreateWindowEx(WS_EX_CLIENTEDGE,"STATIC", message, WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX+=playerBoxWidth,playerBoxY,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER9,GetModuleHandle(NULL),NULL);
                      }
                    }

                    playerBoxX = 10;
                    playerBoxY += seperator;

                    SendMessage(Player2,WM_GETTEXT,sizeof(player2)/sizeof(player2[0]),reinterpret_cast<LPARAM>(player2));
                    if(player2[0] != '\0')
                    {
                      retrieveFile(player2);
                      temp = retrievePlayerInfo(player2);
                      for(i = 0; i != 9; i++)
                      {
                        strcpy(message, temp[i].c_str());
                        Player1D=CreateWindowEx(WS_EX_CLIENTEDGE,"STATIC", message, WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX+=playerBoxWidth,playerBoxY,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER9,GetModuleHandle(NULL),NULL);
                      }
                    }
                    playerBoxX = 10;
                    playerBoxY += seperator;

                    SendMessage(Player3,WM_GETTEXT,sizeof(player3)/sizeof(player3[0]),reinterpret_cast<LPARAM>(player3));
                    if(player3[0] != '\0')
                    {
                      retrieveFile(player3);
                      temp = retrievePlayerInfo(player3);
                      for(i = 0; i != 9; i++)
                      {
                        strcpy(message, temp[i].c_str());
                        Player1D=CreateWindowEx(WS_EX_CLIENTEDGE,"STATIC", message, WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX+=playerBoxWidth,playerBoxY,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER9,GetModuleHandle(NULL),NULL);
                      }
                    }
                    playerBoxX = 10;
                    playerBoxY += seperator;

                    SendMessage(Player4,WM_GETTEXT,sizeof(player4)/sizeof(player4[0]),reinterpret_cast<LPARAM>(player4));
                    if(player4[0] != '\0')
                    {
                      retrieveFile(player4);
                      temp = retrievePlayerInfo(player4);
                      for(i = 0; i != 9; i++)
                      {
                        strcpy(message, temp[i].c_str());
                        Player1D=CreateWindowEx(WS_EX_CLIENTEDGE,"STATIC", message, WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX+=playerBoxWidth,playerBoxY,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER9,GetModuleHandle(NULL),NULL);
                      }
                    }
                    playerBoxX = 10;
                    playerBoxY += seperator;

                    SendMessage(Player5,WM_GETTEXT,sizeof(player5)/sizeof(player5[0]),reinterpret_cast<LPARAM>(player5));
                    if(player5[0] != '\0')
                    {
                      retrieveFile(player5);
                      temp = retrievePlayerInfo(player5);
                      for(i = 0; i != 9; i++)
                      {
                        strcpy(message, temp[i].c_str());
                        Player1D=CreateWindowEx(WS_EX_CLIENTEDGE,"STATIC", message, WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX+=playerBoxWidth,playerBoxY,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER9,GetModuleHandle(NULL),NULL);
                      }
                    }
                    playerBoxX = 10;
                    playerBoxY += seperator;

                    SendMessage(Player6,WM_GETTEXT,sizeof(player6)/sizeof(player6[0]),reinterpret_cast<LPARAM>(player6));
                    if(player6[0] != '\0')
                    {
                      retrieveFile(player6);
                      temp = retrievePlayerInfo(player6);
                      for(i = 0; i != 9; i++)
                      {
                        strcpy(message, temp[i].c_str());
                        Player1D=CreateWindowEx(WS_EX_CLIENTEDGE,"STATIC", message, WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX+=playerBoxWidth,playerBoxY,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER9,GetModuleHandle(NULL),NULL);
                      }
                    }
                    playerBoxX = 10;
                    playerBoxY += seperator;

                    SendMessage(Player7,WM_GETTEXT,sizeof(player7)/sizeof(player7[0]),reinterpret_cast<LPARAM>(player7));
                    if(player7[0] != '\0')
                    {
                      retrieveFile(player7);
                      temp = retrievePlayerInfo(player7);
                      for(i = 0; i != 9; i++)
                      {
                        strcpy(message, temp[i].c_str());
                        Player1D=CreateWindowEx(WS_EX_CLIENTEDGE,"STATIC", message, WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX+=playerBoxWidth,playerBoxY,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER9,GetModuleHandle(NULL),NULL);
                      }
                    }
                                        playerBoxX = 10;
                    playerBoxY += seperator;

                    SendMessage(Player8,WM_GETTEXT,sizeof(player8)/sizeof(player8[0]),reinterpret_cast<LPARAM>(player8));
                    if(player8[0] != '\0')
                    {
                      retrieveFile(player8);
                      temp = retrievePlayerInfo(player8);
                      for(i = 0; i != 9; i++)
                      {
                        strcpy(message, temp[i].c_str());
                        Player1D=CreateWindowEx(WS_EX_CLIENTEDGE,"STATIC", message, WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX+=playerBoxWidth,playerBoxY,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER9,GetModuleHandle(NULL),NULL);
                      }
                    }
                                        playerBoxX = 10;
                    playerBoxY += seperator;

                    SendMessage(Player9,WM_GETTEXT,sizeof(player9)/sizeof(player9[0]),reinterpret_cast<LPARAM>(player9));
                    if(player9[0] != '\0')
                    {
                      retrieveFile(player9);
                      temp = retrievePlayerInfo(player9);
                      for(i = 0; i != 9; i++)
                      {
                        strcpy(message, temp[i].c_str());
                        Player1D=CreateWindowEx(WS_EX_CLIENTEDGE,"STATIC", message, WS_CHILD|WS_VISIBLE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,playerBoxX+=playerBoxWidth,playerBoxY,playerBoxWidth,playerBoxHeight,hWnd,(HMENU)IDC_MAIN_PLAYER9,GetModuleHandle(NULL),NULL);
                      }
                    }

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

    HWND hWnd=CreateWindowEx(0,"Window Class","Smite",WS_OVERLAPPEDWINDOW,200,200,1525,400,0,0,hInst,0);

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
