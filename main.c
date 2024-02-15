#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
#include <mmsystem.h>
#include "Prototype.h"
#define ESC "\x1b["
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

//EventTab
int MainTabEvent;
int NewConsoleTabEvent;

int x;
int y;
int mode;
int Birda,Birdb;
int DeltaY;
int Oy1;
int Oy2;
int Otime;
int R,G,B;
int Count;

int BirdUp=1;
int BirdDown=0;

int MoveY;
int key;

int Numberx;
int Numbery;
int Scores;

//SetWall

int Wall1x;
int Wall1y;
int WallButton1;
int Wall2x;
int Wall2y;
int WallButton2;
int Wall3x;
int Wall3y;
int WallButton3;
int ScrollMode;
int ScrollUp;
int ScrollDown;
int Scrolly;
int Scrollbutton;
int ScrollStart;
int Scroll;
int PasteBackGround;

int WidthWall;
int HeightWall;
int LeftWall;
int RightWall;
int DeltaWall;
int SpeedLevel;
int SpeedCount;
int SpeedUp;
int ClrSwitch;

int Roadx;
int Roady;

int Cloudx;
int Cloudy;

int Start;
int STOP;
int SpeedWall;
int DelayWall;

int Delete;
int Draw;

int Up;
int Down;

int BreakTabMain;
int PlayZoom;
int TopZoom;

int LoadFinish;
HANDLE NewConsole,TabMain,BaseConsole,TabBackground,Loadingdata,TabParameter;
unsigned int seed1;
unsigned int seed2;
unsigned int seed3;

int Menu;
int Restart;
int Pause;
int OverGame;

int Switch1;
int Switch2;
int Switch3;

typedef struct
{
    int width;
    int height;
    int chars[15 * 15];
    int colors[15 * 15];
} _TEST;
typedef struct
{
    int width;
    int height;
    int chars[15 * 30];
    int colors[15 * 30];
} _CLOUD;

int main(int argc,char* argv[])
{
    //Set Parameter
    SetParameterWall();
    //Set Color Game


    //ColorTable


    //Create tab game
    BaseConsole= GetStdHandle(STD_OUTPUT_HANDLE);
    NewConsole = CreateConsoleScreenBuffer(GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);
    TabMain = CreateConsoleScreenBuffer(GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);
    TabBackground = CreateConsoleScreenBuffer(GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);
    Loadingdata = CreateConsoleScreenBuffer(GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);
    TabParameter = CreateConsoleScreenBuffer(GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);

    SetWindowBufferSize(550,300,BaseConsole);
    SetWindowBufferSize(550,300,NewConsole);
    SetWindowBufferSize(550,300,TabMain);
    SetWindowBufferSize(550,300,TabBackground);
    SetWindowBufferSize(550,300,Loadingdata);
    SetWindowBufferSize(550,300,TabParameter);


    SetWindowSize(325,115,BaseConsole);
    SetWindowSize(325,115,Loadingdata);
    SetWindowSize(325,115,TabMain);
    SetWindowSize(325,115,NewConsole);
    SetWindowSize(325,115,TabBackground);

    SetFontSizeTab(BaseConsole,4,6);
    SetFontSizeTab(Loadingdata,4,6);
    SetFontSizeTab(TabMain,4,6);
    SetFontSizeTab(TabBackground,4,6);
    SetFontSizeTab(NewConsole,4,6);
    SetFontSizeTab(TabParameter,4,6);

    ShowCurTab(0,TabMain);
    ShowCurTab(0,Loadingdata);
    ShowCurTab(0,TabParameter);
    ShowCurTab(0,BaseConsole);
    ShowCurTab(0,TabBackground);
    ShowCurTab(0,NewConsole);

    SetTabEditMode(BaseConsole,0);
    SetTabEditMode(Loadingdata,0);
    SetTabEditMode(TabMain,0);
    SetTabEditMode(TabBackground,0);
    SetTabEditMode(NewConsole,0);
    SetTabEditMode(TabParameter,0);

    SetColorConsole();

    SetConsoleActiveScreenBuffer(TabMain);


    //Loading data game

    pthread_t threadloading;

    pthread_create(&threadloading,NULL,DrawLoading,NULL);

    DrawPoint2(320,205,NewConsole);
    DrawPoint2(110,90,NewConsole);
    DrawPoint2(320,205,TabMain);
    DrawPoint2(110,90,TabMain);
    DrawPoint2(320,205,TabBackground);
    DrawPoint2(110,90,TabBackground);
    DrawPoint2(320,205,Loadingdata);
    DrawPoint2(110,90,Loadingdata);
    DrawPoint2(320,205,TabParameter);
    DrawPoint2(110,90,TabParameter);

    ArtLoading();
    CopyPixelTo2(400,180,511,195,155,150,BaseConsole,Loadingdata);
    DrawTableRoad(50,195,340,215,0,14);
    DrawBird(170,145);
    CopyPixelTo(164,145,180,156,164,20,NewConsole);//1
    DrawBird2(170,165);
    CopyPixelTo(164,165,180,176,164,35,NewConsole);//2
    LoadFinish=1;
    DrawBird3(170,125);
    CopyPixelTo(164,125,180,136,164,5,NewConsole);//3
    LoadFinish=1;

    ArtBackGroundGame();


    LoadFinish=1;
    DrawWall(20,Wall1y,WallButton1);

    LoadFinish=1;
    CopyPixelTo(8,35,33,270,8,35,NewConsole);
    LoadFinish=1;
    TextMain();
    LoadFinish=1;
    LoadFinish=1;
    int e;
    for(e=0; e<=9; e++)
    {
        PrintNumber(e);
        Numberx+=15;
    }



    LoadFinish=1;
    CopyPixelTo2(225,10,455,60,90,140,BaseConsole,TabMain);
    LoadFinish=1;
    LoadFinish=1;
    ArtNumber();
    LoadFinish=1;
    LoadFinish=1;
    DrawTable2(50,150,80,165,0,15);
    LoadFinish=1;
    PlayArt(63,152);
    LoadFinish=1;
    DrawTable2(49,173,81,190,0,15);
    PlayArt(63,176);
    LoadFinish=1;
    DrawTable2(50,130,80,145,0,15);
    LoadFinish=1;
    TopArt(63,132);
    LoadFinish=1;
    DrawTable2(49,108,81,125,0,15);
    TopArt(63,111);
    LoadFinish=1;
    GameOverArt(46,60);
    LoadFinish=1;

    LoadFinish=1;
    CopyPixelTo2(225,10,455,60,90,145,BaseConsole,NewConsole);
    LoadFinish=1;


    DrawOverTable();
    LoadFinish=1;
    LoadFinish=1;
    CopyPixelTo2(225,10,455,60,90,145,BaseConsole,TabBackground);
    LoadFinish=1;
    DrawCoin();
    LoadFinish=1;
    LoadFinish=1;

    ArtNew();
    LoadFinish=1;
    LoadFinish=1;

    ArtRestar();
    LoadFinish=1;
    ArtMenu();
    LoadFinish=1;
    ArtOk();
    LoadFinish=1;

    ArtPause();
    LoadFinish=1;

    /*
    COORD sizebuffer;
    COORD buffercoord= {0,0};
    SMALL_RECT RegionWrite1;
    SMALL_RECT RegionRead;

    CHAR_INFO buffer[100*100];
    _TEST test=
    {
        15,
        15,
        {
            255,255,255,255,255,255,255,177,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,177,255,255,255,177,255,255,255,177,255,255,255,
            255,255,255,255,177,255,255,255,255,255,177,255,255,255,255,
            255,255,255,255,255,255,177,177,177,255,255,255,255,255,255,
            255,255,255,255,255,177,178,219,178,177,255,255,255,255,255,
            255,255,255,255,177,178,219,219,219,178,177,255,255,255,255,
            177,255,177,255,177,219, 94,219, 94,219,177,255,177,255,177,
            255,255,255,255,177,178,219,126,219,178,177,255,255,255,255,
            255,255,255,255,255,177,178,219,178,177,255,255,255,255,255,
            255,255,255,255,255,255,177,177,177,255,255,255,255,255,255,
            255,255,255,255,177,255,255,255,255,255,177,255,255,255,255,
            255,255,255,177,255,255,255,177,255,255,255,177,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,177,255,255,255,255,255,255,255,
        },
        {
            0,  0,  0,  0,  0,  0,  0, 62,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0, 62,  0,  0,  0, 62,  0,  0,  0, 62,  0,  0,  0,
            0,  0,  0,  0, 62,  0,  0,  0,  0,  0, 62,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0, 62, 62, 62,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0, 62, 62, 14, 62, 62,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 62, 62, 14, 14, 14, 62, 62,  0,  0,  0,  0,
            62,  0, 62,  0, 62, 14,224, 14,224, 14, 62,  0, 62,  0, 62,
            0,  0,  0,  0, 62, 62, 14,224, 14, 62, 62,  0,  0,  0,  0,
            0,  0,  0,  0,  0, 62, 62, 14, 62, 62,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0, 62, 62, 62,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 62,  0,  0,  0,  0,  0, 62,  0,  0,  0,  0,
            0,  0,  0, 62,  0,  0,  0, 62,  0,  0,  0, 62,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0, 62,  0,  0,  0,  0,  0,  0,  0,
        }
    };

    _CLOUD cloud=
    {
        30,
        15,
        {
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,219,219,219,219,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,219,219,219,219,219,219,219,219,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,219,219,219,219,219,219,219,219,219,219,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,219,219,219,219,219,219,219,219,219,219,255,255,255,219,219,219,255,255,255,255,255,
            255,255,255,255,255,255,255,255,219,219,219,219,219,219,219,219,219,219,219,219,255,219,219,219,219,219,255,255,255,255,
            255,255,255,255,219,219,219,255,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,255,255,255,
            255,255,255,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,255,255,
            255,255,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,255,255,
            255,255,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,255,255,
            255,255,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,255,255,
            255,255,255,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
        },
        {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,16,16,255,255,255,255,16,16,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,16,255,255,255,255,255,255,255,255,16,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,16,255,255,255,255,255,255,255,255,16,0,0,0,16,16,16,0,0,0,0,0,
            0,0,0,0,0,0,0,0,16,255,255,255,255,255,255,255,255,255,255,16,0,16,255,255,255,16,0,0,0,0,
            0,0,0,0,16,16,16,0,16,255,255,255,255,255,255,255,255,255,255,255,255,16,255,255,255,255,16,0,0,0,
            0,0,0,16,255,255,255,16,16,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,16,0,0,
            0,0,16,1,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,1,16,0,0,
            0,0,16,1,1,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,1,1,16,0,0,
            0,0,16,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,16,0,0,
            0,0,0,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        }
    };



    sizebuffer.Y=100;
    sizebuffer.X=100;

    RegionRead.Top=100;
    RegionRead.Left=100;
    RegionRead.Bottom=199;
    RegionRead.Right=199;
    ReadConsoleOutputA(BaseConsole,buffer,sizebuffer,buffercoord,&RegionRead);

    int x,y;
    int xoffset=50;
    int yoffset=50;

    for(y=0; y<15; y++)
    {
        for(x=0; x<15; x++)
        {
            if(test.chars[x+15*y]!=(unsigned char)255)
            {
                buffer[(x+xoffset)+100*(y+yoffset)].Char.AsciiChar=test.chars[x+15*y];
                buffer[(x+xoffset)+100*(y+yoffset)].Attributes=test.colors[x+15*y];
            }
        }
    }

    int a=100;
    int b=100;

    RegionWrite1.Left=a;
    RegionWrite1.Top=b;
    RegionWrite1.Right=a+99;
    RegionWrite1.Bottom=b+99;

    WriteConsoleOutputA(TabParameter,buffer,sizebuffer,buffercoord,&RegionWrite1);


    int GetColor;

    while(TRUE)
    {
        RegionWrite1.Left=a;
        RegionWrite1.Top=b;
        RegionWrite1.Right=a+99;
        RegionWrite1.Bottom=b+99;

        WriteConsoleOutputA(TabParameter,buffer,sizebuffer,buffercoord,&RegionWrite1);

        ReadConsoleOutputA(BaseConsole,buffer,sizebuffer,buffercoord,&RegionRead);

        xoffset++;

        if(xoffset>=99)
        {
            xoffset=0;

        }

        GetColor=GetRandom(0,255,&seed1);

        for(y=0; y<15; y++)
        {
            for(x=0; x<15; x++)
            {
                if(test.chars[x+15*y]!=(unsigned char)255)
                {
                    buffer[(x+xoffset)+100*(y+yoffset)].Char.AsciiChar=test.chars[x+15*y];
                    buffer[(x+xoffset)+100*(y+yoffset)].Attributes=GetColor;
                }
            }
        }


        Sleep(10);
    }

    */

    pthread_cancel(threadloading);

    Sleep(500);


//while loop game

    pthread_t threadevent;
    pthread_t threadbird;
    pthread_t threadwall1;
    pthread_t threadwall2;
    pthread_t threadwall3;
    pthread_t threadanimationbird;
    pthread_t threadscores;
    pthread_create(&threadevent,NULL,EventCheck,NULL);//Event
    Delay(1000);

    pthread_create(&threadbird,NULL,Bird,NULL);
    pthread_create(&threadwall1,NULL,Wall1,NULL);
    pthread_create(&threadwall2,NULL,Wall2,NULL);
    pthread_create(&threadwall3,NULL,Wall3,NULL);
    pthread_create(&threadanimationbird,NULL,AnimationBird,NULL);
    pthread_create(&threadscores,NULL,PrintScores,NULL);

    while(TRUE)
    {
        DrawPoint2(150,150,TabParameter);
        if(Menu)
        {
            ResetParameter();
            MainTabEvent=1;
            SetConsoleActiveScreenBuffer(TabMain);
            PlaySound("audio game/Soundbackground",NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
        }
        else if(Restart)
        {
            ResetParameter();
            BreakTabMain=1;
        }

        int a=0,b=0;

        CopyPixelTo(200,140,314,170,152,110,TabMain);
        CopyPixelTo(70,195,335,220,70,190,TabMain);
        CopyPixelTo2(161,173,193,190,161,168,TabBackground,TabMain);
        CopyPixelTo2(225,173,257,190,225,168,TabBackground,TabMain);

        while(TRUE)//TabMain
        {
            DrawPoint2(150,150,TabParameter);
            if(PlayZoom)
            {
                CopyPixelTo(49,173,81,190,161,168,TabMain);
                a=1;
            }
            else
            {
                if(a)
                {
                    CopyPixelTo2(161,173,193,190,161,168,TabBackground,TabMain);
                    a=0;
                }
                CopyPixelTo(50,150,80,165,162,169,TabMain);
            }
            if(TopZoom)
            {
                CopyPixelTo(49,108,81,125,225,168,TabMain);
                b=1;
            }
            else
            {
                if(b)
                {
                    CopyPixelTo2(225,173,257,190,225,168,TabBackground,TabMain);
                    b=0;
                }
                CopyPixelTo(50,130,80,145,226,169,TabMain);
            }
            if(BreakTabMain)
            {
                PlaySoundA(NULL,0,0);
                MainTabEvent=0;
                NewConsoleTabEvent=1;
                SetConsoleActiveScreenBuffer(NewConsole);
                break;
            }
        }

        DrawTableRoad2(50,195,340,215,0,14);
        CopyPixelTo2(70,196,335,198,Roadx,196,BaseConsole,NewConsole);

        while(TRUE)//NewConsole
        {
            if(Roadx==55)
            {
                Roadx=73;
                CopyPixelTo2(70,196,335,198,Roadx,196,BaseConsole,NewConsole);
            }
            Roadx--;

            CopyPixelTo2(70,196,335,198,Roadx,196,BaseConsole,NewConsole);

            Sleep(DelayWall);

            if(STOP)
            {
                PlaySound("audio game/hit",NULL,SND_FILENAME|SND_ASYNC);
                NewConsoleTabEvent=0;
                Start=0;
                OverGame=1;
                break;
            }
        }
        while(TRUE)
        {
            DrawCoin();//Score
            DrawCicleOverGame();
            CopyPixelTo2(139,169,155,175,450,139,BaseConsole,BaseConsole);//New
            CopyPixelTo(47,60,224,89,120,100,NewConsole);//OverGame
            CopyPixelTo(370,100,480,150,150,135,NewConsole);//Table OverGame
            CopyPixelTo(105,116,149,129,155,189,NewConsole);//Restart
            CopyPixelTo(108,136,152,149,212,189,NewConsole);//Menu
            if(Restart||Menu)
            {
                DelConsole(NewConsole);
                CopyPixelTo2(225,10,455,60,90,145,BaseConsole,NewConsole);
                break;
            }
        }
    }
    pthread_cancel(threadbird);
    pthread_cancel(threadwall1);
    pthread_cancel(threadwall2);
    pthread_cancel(threadwall3);
    pthread_cancel(threadanimationbird);
    pthread_cancel(threadscores);
    pthread_cancel(threadevent);

    return 0;
}


void* Bird(void* arg)
{
    RemoteBird();
    return NULL;
}
void* Wall1(void* arg)
{
    int On;
    COORD sizebuffer1,sizebuffer2;
    COORD buffercoord= {0,0};
    SMALL_RECT RegionRead1,RegionRead2;
    SMALL_RECT RegionWrite1,RegionWrite2;
    CHAR_INFO buffer1[2828];
    CHAR_INFO buffer2[2828];
    sizebuffer1.Y=HeightWall;
    sizebuffer1.X=WidthWall;
    sizebuffer2.Y=HeightWall;
    sizebuffer2.X=WidthWall;

    RegionRead1.Left=8;
    RegionRead1.Top=75;
    RegionRead1.Right=33;
    RegionRead1.Bottom=135;

    RegionRead2.Left=8;
    RegionRead2.Top=170;
    RegionRead2.Right=32;
    RegionRead2.Bottom=270;

    ReadConsoleOutputA(NewConsole,buffer1,sizebuffer1,buffercoord,&RegionRead1);
    ReadConsoleOutputA(NewConsole,buffer2,sizebuffer2,buffercoord,&RegionRead2);

    RegionWrite1.Left=Wall1x-LeftWall;
    RegionWrite1.Top=Wall1y-60;
    RegionWrite1.Right=Wall1x+RightWall;
    RegionWrite1.Bottom=Wall1y;

    RegionWrite2.Left=Wall1x-LeftWall;
    RegionWrite2.Top=WallButton1;
    RegionWrite2.Right=Wall1x+RightWall-1;
    RegionWrite2.Bottom=205-11;

    WriteConsoleOutputA(NewConsole,buffer1,sizebuffer1,buffercoord,&RegionWrite1);
    WriteConsoleOutputA(NewConsole,buffer2,sizebuffer2,buffercoord,&RegionWrite2);

    CopyPixelTo2(Wall1x+RightWall-2,WallButton1+5,Wall1x+RightWall+3,194,Wall1x+RightWall-2,WallButton1+5,TabBackground,NewConsole);
    CopyPixelTo2(Wall1x+RightWall,WallButton1,Wall1x+RightWall+2,WallButton1+4,Wall1x+RightWall,WallButton1,TabBackground,NewConsole);

    while(TRUE)
    {
        DrawPoint2(150,150,TabParameter);
        if(Start)
            break;
    }

    while(TRUE)
    {
        if(Wall1x<=80)
        {
            if(ScrollMode==0)
            {
                ScrollStart=0;
            }
            //ClrWall

            Wall1x=350;

            Wall1y=GetRandom(95,145,&seed1);
            WallButton1=GetRandom(Wall1y+DeltaWall,189,&seed1);

            if(ScrollMode==1)
            {
                Scrolly=Wall1y;
                Scrollbutton=WallButton1;
                Wall1y=95;
                WallButton1=189;
                ScrollUp=1;
                ScrollStart=1;
            }

            RegionWrite1.Left=Wall1x-LeftWall;
            RegionWrite1.Top=Wall1y-60;
            RegionWrite1.Right=Wall1x+RightWall;
            RegionWrite1.Bottom=Wall1y;

            RegionWrite2.Left=Wall1x-LeftWall;
            RegionWrite2.Top=WallButton1;
            RegionWrite2.Right=Wall1x+RightWall-1;
            RegionWrite2.Bottom=205-11;

            WriteConsoleOutputA(NewConsole,buffer1,sizebuffer1,buffercoord,&RegionWrite1);
            WriteConsoleOutputA(NewConsole,buffer2,sizebuffer2,buffercoord,&RegionWrite2);

            ScrollMode=0;

        }

        Wall1x-=SpeedWall;

        ScrollWall();

        RegionWrite1.Left=Wall1x-LeftWall;
        RegionWrite1.Top=Wall1y-60;
        RegionWrite1.Right=Wall1x+RightWall;
        RegionWrite1.Bottom=Wall1y;


        RegionWrite2.Left=Wall1x-LeftWall;
        RegionWrite2.Top=WallButton1;
        RegionWrite2.Right=Wall1x+RightWall;
        RegionWrite2.Bottom=205-11;

        WriteConsoleOutputA(NewConsole,buffer1,sizebuffer1,buffercoord,&RegionWrite1);
        WriteConsoleOutputA(NewConsole,buffer2,sizebuffer2,buffercoord,&RegionWrite2);

        CopyPixelTo2(Wall1x+RightWall-2,WallButton1+5,Wall1x+RightWall+3,194,Wall1x+RightWall-2,WallButton1+5,TabBackground,NewConsole);
        CopyPixelTo2(Wall1x+RightWall,WallButton1,Wall1x+RightWall+2,WallButton1+4,Wall1x+RightWall,WallButton1,TabBackground,NewConsole);

        if(ScrollStart==1)
        {
            ClrLine2(Wall1x-LeftWall,Wall1x+RightWall+2,Wall1y+1,3);
            CopyPixelTo2(Wall1x-LeftWall,WallButton1-1,Wall1x+RightWall+2,WallButton1-1,Wall1x-LeftWall,WallButton1-1,TabBackground,NewConsole);
        }
        if(Scores%10==0&&Scores!=0&&SpeedUp==1)
        {
            SpeedUp=0;
            DelayWall-=2;
        }
        if(Scores%30==0&&Scores!=0&&SpeedUp==1)
        {
            SpeedUp=0;
            SpeedWall+=1;
        }
        if(Scores%5!=0)
        {
            SpeedUp=1;
        }

        Delay(DelayWall);

        if(STOP)
        {
            On=1;
            while(TRUE)
            {
                DrawPoint2(150,150,TabParameter);
                if(NewConsoleTabEvent&&On)
                {
                    Sleep(100);
                    RegionWrite1.Left=Wall1x-LeftWall;
                    RegionWrite1.Top=Wall1y-60;
                    RegionWrite1.Right=Wall1x+RightWall;
                    RegionWrite1.Bottom=Wall1y;

                    RegionWrite2.Left=Wall1x-LeftWall;
                    RegionWrite2.Top=WallButton1;
                    RegionWrite2.Right=Wall1x+RightWall;
                    RegionWrite2.Bottom=205-11;

                    WriteConsoleOutputA(NewConsole,buffer1,sizebuffer1,buffercoord,&RegionWrite1);
                    WriteConsoleOutputA(NewConsole,buffer2,sizebuffer2,buffercoord,&RegionWrite2);

                    CopyPixelTo2(Wall1x+RightWall-2,WallButton1+5,Wall1x+RightWall+3,194,Wall1x+RightWall-2,WallButton1+5,TabBackground,NewConsole);
                    CopyPixelTo2(Wall1x+RightWall,WallButton1,Wall1x+RightWall+2,WallButton1+4,Wall1x+RightWall,WallButton1,TabBackground,NewConsole);
                    On=0;
                }
                if(Start)
                    break;
            }

        }
    }
    return NULL;
}

void* Wall2(void* arg)
{
    int On;
    COORD sizebuffer3,sizebuffer4;
    COORD buffercoord2= {0,0};
    SMALL_RECT RegionRead3,RegionRead4;
    SMALL_RECT RegionWrite3,RegionWrite4;
    CHAR_INFO buffer3[2828];
    CHAR_INFO buffer4[2828];
    sizebuffer3.Y=HeightWall;
    sizebuffer3.X=WidthWall;

    sizebuffer4.Y=HeightWall;
    sizebuffer4.X=WidthWall;

    RegionRead3.Left=8;
    RegionRead3.Top=75;
    RegionRead3.Right=33;
    RegionRead3.Bottom=135;

    RegionRead4.Left=8;
    RegionRead4.Top=170;
    RegionRead4.Right=33;
    RegionRead4.Bottom=270;

    ReadConsoleOutputA(NewConsole,buffer3,sizebuffer3,buffercoord2,&RegionRead3);
    ReadConsoleOutputA(NewConsole,buffer4,sizebuffer4,buffercoord2,&RegionRead4);

    RegionWrite3.Left=Wall2x-LeftWall;
    RegionWrite3.Top=Wall2y-60;
    RegionWrite3.Right=Wall2x+RightWall;
    RegionWrite3.Bottom=Wall2y;

    RegionWrite4.Left=Wall2x-LeftWall;
    RegionWrite4.Top=WallButton2;
    RegionWrite4.Right=Wall2x+RightWall;
    RegionWrite4.Bottom=205-11;

    WriteConsoleOutputA(NewConsole,buffer3,sizebuffer3,buffercoord2,&RegionWrite3);
    WriteConsoleOutputA(NewConsole,buffer4,sizebuffer4,buffercoord2,&RegionWrite4);

    CopyPixelTo2(Wall2x+RightWall-2,WallButton2+5,Wall2x+RightWall+3,194,Wall2x+RightWall-2,WallButton2+5,TabBackground,NewConsole);
    CopyPixelTo2(Wall2x+RightWall,WallButton2,Wall2x+RightWall+2,WallButton2+4,Wall2x+RightWall,WallButton2,TabBackground,NewConsole);


    while(TRUE)
    {
        DrawPoint2(150,150,TabParameter);
        if(Start)
            break;
    }

    while(TRUE)
    {
        if(Wall2x<=80)
        {
            //ClrWall

            Wall2x=Wall1x+90;

            Wall2y=GetRandom(95,145,&seed2);
            WallButton2=GetRandom(Wall2y+DeltaWall,190,&seed2);

            RegionWrite3.Left=Wall2x-LeftWall;
            RegionWrite3.Top=Wall2y-60;
            RegionWrite3.Right=Wall2x+RightWall;
            RegionWrite3.Bottom=Wall2y;

            RegionWrite4.Left=Wall2x-LeftWall;
            RegionWrite4.Top=WallButton2;
            RegionWrite4.Right=Wall2x+RightWall;
            RegionWrite4.Bottom=205-11;

            WriteConsoleOutputA(NewConsole,buffer3,sizebuffer3,buffercoord2,&RegionWrite3);
            WriteConsoleOutputA(NewConsole,buffer4,sizebuffer4,buffercoord2,&RegionWrite4);

        }

        Wall2x-=SpeedWall;

        RegionWrite3.Left=Wall2x-LeftWall;
        RegionWrite3.Top=Wall2y-60;
        RegionWrite3.Right=Wall2x+RightWall;
        RegionWrite3.Bottom=Wall2y;

        RegionWrite4.Left=Wall2x-LeftWall;
        RegionWrite4.Top=WallButton2;
        RegionWrite4.Right=Wall2x+RightWall;
        RegionWrite4.Bottom=205-11;

        WriteConsoleOutputA(NewConsole,buffer3,sizebuffer3,buffercoord2,&RegionWrite3);
        WriteConsoleOutputA(NewConsole,buffer4,sizebuffer4,buffercoord2,&RegionWrite4);

        CopyPixelTo2(Wall2x+RightWall-2,WallButton2+5,Wall2x+RightWall+3,194,Wall2x+RightWall-2,WallButton2+5,TabBackground,NewConsole);
        CopyPixelTo2(Wall2x+RightWall,WallButton2,Wall2x+RightWall+2,WallButton2+4,Wall2x+RightWall,WallButton2,TabBackground,NewConsole);

        if(x>=Wall1x&&Switch1==1)
        {
            PlaySound("audio game/point",NULL,SND_FILENAME|SND_ASYNC);
            Scores++;
            Switch1=0;
            Switch2=1;
        }
        if(x>=Wall2x&&Switch2==1)
        {
            PlaySound("audio game/point",NULL,SND_FILENAME|SND_ASYNC);
            Scores++;
            Switch2=0;
            Switch3=1;
        }
        if(x>=Wall3x&&Switch3==1)
        {
            PlaySound("audio game/point",NULL,SND_FILENAME|SND_ASYNC);
            Scores++;
            Switch3=0;
            Switch1=1;
        }
        if(Scores%5==0&&Scores!=0)
        {
            ScrollMode=1;
        }
        Condition(Wall1x,Wall1y,WallButton1);
        Condition(Wall2x,Wall2y,WallButton2);
        Condition(Wall3x,Wall3y,WallButton3);

        Delay(DelayWall+10);

        if(STOP)
        {
            On=1;
            while(TRUE)
            {
                DrawPoint2(150,150,TabParameter);;
                if(NewConsoleTabEvent&&On)
                {
                    Sleep(100);
                    RegionWrite3.Left=Wall2x-LeftWall;
                    RegionWrite3.Top=Wall2y-60;
                    RegionWrite3.Right=Wall2x+RightWall;
                    RegionWrite3.Bottom=Wall2y;

                    RegionWrite4.Left=Wall2x-LeftWall;
                    RegionWrite4.Top=WallButton2;
                    RegionWrite4.Right=Wall2x+RightWall;
                    RegionWrite4.Bottom=205-11;

                    WriteConsoleOutputA(NewConsole,buffer3,sizebuffer3,buffercoord2,&RegionWrite3);
                    WriteConsoleOutputA(NewConsole,buffer4,sizebuffer4,buffercoord2,&RegionWrite4);

                    CopyPixelTo2(Wall2x+RightWall-2,WallButton2+5,Wall2x+RightWall+3,194,Wall2x+RightWall-2,WallButton2+5,TabBackground,NewConsole);
                    CopyPixelTo2(Wall2x+RightWall,WallButton2,Wall2x+RightWall+2,WallButton2+4,Wall2x+RightWall,WallButton2,TabBackground,NewConsole);
                    On=0;
                }
                if(Start)
                    break;
            }

        }
    }
    return NULL;
}
void* Wall3(void* arg)
{
    int On;
    COORD sizebuffer5,sizebuffer6;
    COORD buffercoord3= {0,0};
    SMALL_RECT RegionRead5,RegionRead6;
    SMALL_RECT RegionWrite5,RegionWrite6;
    CHAR_INFO buffer5[2828];
    CHAR_INFO buffer6[2828];
    sizebuffer5.Y=HeightWall;
    sizebuffer5.X=WidthWall;

    sizebuffer6.Y=HeightWall;
    sizebuffer6.X=WidthWall;

    RegionRead5.Left=8;
    RegionRead5.Top=75;
    RegionRead5.Right=33;
    RegionRead5.Bottom=135;

    RegionRead6.Left=8;
    RegionRead6.Top=170;
    RegionRead6.Right=33;
    RegionRead6.Bottom=270;

    ReadConsoleOutputA(NewConsole,buffer5,sizebuffer5,buffercoord3,&RegionRead5);
    ReadConsoleOutputA(NewConsole,buffer6,sizebuffer6,buffercoord3,&RegionRead6);

    RegionWrite5.Left=Wall3x-LeftWall;
    RegionWrite5.Top=Wall3y-60;
    RegionWrite5.Right=Wall3x+RightWall;
    RegionWrite5.Bottom=Wall3y;

    RegionWrite6.Left=Wall3x-LeftWall;
    RegionWrite6.Top=WallButton3;
    RegionWrite6.Right=Wall3x+RightWall;
    RegionWrite6.Bottom=205-11;

    WriteConsoleOutputA(NewConsole,buffer5,sizebuffer5,buffercoord3,&RegionWrite5);
    WriteConsoleOutputA(NewConsole,buffer6,sizebuffer6,buffercoord3,&RegionWrite6);

    CopyPixelTo2(Wall3x+RightWall-2,WallButton3+5,Wall3x+RightWall+3,194,Wall3x+RightWall-2,WallButton3+5,TabBackground,NewConsole);
    CopyPixelTo2(Wall3x+RightWall,WallButton3,Wall3x+RightWall+2,WallButton3+4,Wall3x+RightWall,WallButton3,TabBackground,NewConsole);

    while(TRUE)
    {
        DrawPoint2(150,150,TabParameter);
        if(Start)
            break;
    }

    while(TRUE)
    {
        if(Wall3x<=80)
        {
            //ClrWall

            Wall3x=Wall1x+180;

            Wall3y=GetRandom(95,145,&seed3);
            WallButton3=GetRandom(Wall3y+DeltaWall,190,&seed3);

            RegionWrite5.Left=Wall3x-LeftWall;
            RegionWrite5.Top=Wall3y-60;
            RegionWrite5.Right=Wall3x+RightWall;
            RegionWrite5.Bottom=Wall3y;

            RegionWrite6.Left=Wall3x-LeftWall;
            RegionWrite6.Top=WallButton3;
            RegionWrite6.Right=Wall3x+RightWall;
            RegionWrite6.Bottom=205-11;

            WriteConsoleOutputA(NewConsole,buffer5,sizebuffer5,buffercoord3,&RegionWrite5);
            WriteConsoleOutputA(NewConsole,buffer6,sizebuffer6,buffercoord3,&RegionWrite6);
        }

        Wall3x-=SpeedWall;

        RegionWrite5.Left=Wall3x-LeftWall;
        RegionWrite5.Top=Wall3y-60;
        RegionWrite5.Right=Wall3x+RightWall;
        RegionWrite5.Bottom=Wall3y;

        RegionWrite6.Left=Wall3x-LeftWall;
        RegionWrite6.Top=WallButton3;
        RegionWrite6.Right=Wall3x+RightWall;
        RegionWrite6.Bottom=205-11;

        WriteConsoleOutputA(NewConsole,buffer5,sizebuffer5,buffercoord3,&RegionWrite5);
        WriteConsoleOutputA(NewConsole,buffer6,sizebuffer6,buffercoord3,&RegionWrite6);

        CopyPixelTo2(Wall3x+RightWall-2,WallButton3+5,Wall3x+RightWall+3,194,Wall3x+RightWall-2,WallButton3+5,TabBackground,NewConsole);
        CopyPixelTo2(Wall3x+RightWall,WallButton3,Wall3x+RightWall+2,WallButton3+4,Wall3x+RightWall,WallButton3,TabBackground,NewConsole);

        Delay(DelayWall+10);

        if(STOP)
        {
            On=1;
            while(TRUE)
            {
                DrawPoint2(150,150,TabParameter);
                if(NewConsoleTabEvent&&On)
                {
                    Sleep(100);
                    RegionWrite5.Left=Wall3x-LeftWall;
                    RegionWrite5.Top=Wall3y-60;
                    RegionWrite5.Right=Wall3x+RightWall;
                    RegionWrite5.Bottom=Wall3y;

                    RegionWrite6.Left=Wall3x-LeftWall;
                    RegionWrite6.Top=WallButton3;
                    RegionWrite6.Right=Wall3x+RightWall;
                    RegionWrite6.Bottom=205-11;

                    WriteConsoleOutputA(NewConsole,buffer5,sizebuffer5,buffercoord3,&RegionWrite5);
                    WriteConsoleOutputA(NewConsole,buffer6,sizebuffer6,buffercoord3,&RegionWrite6);

                    CopyPixelTo2(Wall3x+RightWall-2,WallButton3+5,Wall3x+RightWall+3,194,Wall3x+RightWall-2,WallButton3+5,TabBackground,NewConsole);
                    CopyPixelTo2(Wall3x+RightWall,WallButton3,Wall3x+RightWall+2,WallButton3+4,Wall3x+RightWall,WallButton3,TabBackground,NewConsole);
                    On=0;
                }
                if(Start)
                    break;
            }

        }
    }

    return NULL;
}

void DrawWall(int Wallx,int Wally,int Button)
{
    //Wall Top
    DrawTableWall(Wallx-10,Wally-100,Wallx+10,Wally-4,0,2);
    DrawTableWall(Wallx-12,Wally-4,Wallx+12,Wally,0,2);

    //Wall Button
    DrawTableWall(Wallx-10,Button+4,Wallx+10,Button+100,0,2);
    DrawTableWall(Wallx-12,Button,Wallx+12,Button+4,0,2);

}
void ClrWall(int Wallx,int Wally,int Button)
{
    int h;
    for(h=Wally; h>=Wally-100; h--)
    {
        if(h==Wally)
        {
            ClrLine(Wallx-13,Wallx+13,h,3);
        }
        else
        {
            ClrLine(Wallx-12,Wallx+12,h,3);
        }
    }

    int k;
    for(k=Button; k<=Button+100; k++)
    {
        if(k==Button)
        {
            ClrLine(Wallx-13,Wallx+13,k,3);
        }
        else
        {
            ClrLine(Wallx-12,Wallx+12,k,3);
        }
    }



}
void ClrWall2(int Wallx,int Wally,int Button)
{
    int h;
    for(h=Wally; h>=Wally-100; h--)
    {
        if(h==Wally)
        {
            ClrLine2(Wallx+14,Wallx+17,h,3);
        }
        else
        {
            ClrLine2(Wallx+13,Wallx+16,h,3);
        }
    }

    int k;
    for(k=Button; k<=186-Button; k++)
    {
        if(k==Button)
        {
            ClrLine2(Wallx+14,Wallx+17,k,3);
        }
        else
        {
            ClrLine2(Wallx+13,Wallx+16,k,3);
        }
    }
}
void ClrWall3(int Wallx,int Wally,int WallButton)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD sizebuffer1,sizebuffer2;
    COORD buffercoord= {0,0};
    SMALL_RECT RegionRead1,RegionRead2;
    SMALL_RECT RegionWrite1,RegionWrite2;
    CHAR_INFO buffer1[1326];
    CHAR_INFO buffer2[1326];
    sizebuffer1.Y=102;
    sizebuffer1.X=13;
    sizebuffer2.Y=102;
    sizebuffer2.X=13;

    RegionRead1.Left=33;
    RegionRead1.Top=35;
    RegionRead1.Right=45;
    RegionRead1.Bottom=136;

    RegionRead2.Left=33;
    RegionRead2.Top=169;
    RegionRead2.Right=45;
    RegionRead2.Bottom=270;

    ReadConsoleOutputA(console,buffer1,sizebuffer1,buffercoord,&RegionRead1);
    ReadConsoleOutputA(console,buffer2,sizebuffer2,buffercoord,&RegionRead2);

    RegionWrite1.Left=Wallx+RightWall;
    RegionWrite1.Top=Wally-100;
    RegionWrite1.Right=Wallx+RightWall+12;
    RegionWrite1.Bottom=Wally+1;

    RegionWrite2.Left=Wallx+RightWall;
    RegionWrite2.Top=WallButton-1;
    RegionWrite2.Right=Wallx+RightWall+12;
    RegionWrite2.Bottom=205-11;

    WriteConsoleOutputA(NewConsole,buffer1,sizebuffer1,buffercoord,&RegionWrite1);
    WriteConsoleOutputA(NewConsole,buffer2,sizebuffer2,buffercoord,&RegionWrite2);
}

void ClrWallButton(int Wallx,int Button)
{
    int k;
    for(k=Button; k<=Button+100; k++)
    {
        if(k==Button)
        {
            ClrLine(Wallx-13,Wallx+13,k,51);
        }
        else
        {
            ClrLine(Wallx-12,Wallx+12,k,51);
        }
    }
}

void DrawBird(int x,int y)
{
    SetColor(0,0);
    DrawLine3(x,x+5,y);
    DrawPoint(x-1,y+1);
    DrawPoint(x-2,y+1);
    DrawPoint(x+3,y+1);
    DrawPoint(x+6,y+1);
    DrawPoint(x-3,y+2);
    DrawPoint(x+2,y+2);
    DrawPoint(x+7,y+2);
    DrawPoint(x-4,y+3);
    DrawPoint(x+2,y+3);
    DrawPoint(x+6,y+3);
    DrawPoint(x+8,y+3);
    DrawPoint(x-5,y+4);
    DrawPoint(x+2,y+4);
    DrawPoint(x+6,y+4);
    DrawPoint(x+8,y+4);
    DrawLine3(x-5,x-1,y+5);
    DrawPoint(x+3,y+5);
    DrawPoint(x+8,y+5);
    DrawPoint(x-6,y+6);
    DrawPoint(x,y+6);
    DrawLine3(x+4,x+9,y+6);
    DrawPoint(x-6,y+7);
    DrawPoint(x,y+7);
    DrawPoint(x+3,y+7);
    DrawPoint(x+10,y+7);
    DrawLine3(x-5,x-1,y+8);
    DrawPoint(x+2,y+8);
    DrawLine3(x+4,x+9,y+8);
    DrawPoint(x-4,y+9);
    DrawPoint(x+3,y+9);
    DrawPoint(x+9,y+9);
    DrawPoint(x-3,y+10);
    DrawPoint(x-2,y+10);
    DrawLine3(x+4,x+8,y+10);
    DrawLine3(x-1,x+3,y+11);

    SetColor(15,15);
    DrawLine3(x+4,x+5,y+1);
    DrawLine3(x+3,x+6,y+2);
    DrawLine3(x+4,x+5,y+3);
    DrawPoint(x+7,y+3);
    DrawLine3(x+4,x+5,y+4);
    DrawPoint(x+7,y+4);
    DrawLine3(x+5,x+7,y+5);
    DrawLine3(x-5,x-1,y+6);
    DrawLine3(x-4,x-2,y+7);

    SetColor(12,12);
    DrawLine3(x,x+1,y+8);
    DrawLine3(x-3,x+2,y+9);
    DrawLine3(x-1,x+3,y+10);

    SetColor(6,6);
    DrawLine3(x,x+1,y+2);
    DrawLine3(x-2,x+1,y+3);
    DrawLine3(x-4,x+1,y+4);
    DrawLine3(x,x+2,y+5);
    DrawLine3(x+1,x+3,y+6);
    DrawLine3(x+1,x+2,y+7);

    SetColor(14,14);
    DrawLine3(x,x+2,y+1);
    DrawLine3(x-2,x-1,y+2);
    DrawPoint(x-3,y+3);
    DrawPoint(x-5,y+7);
    DrawPoint(x-1,y+7);

    SetColor(11,11);
    DrawLine3(x+4,x+9,y+7);
    DrawPoint(x+3,y+8);
    DrawLine3(x+4,x+8,y+9);

    SetColor(1,1);
    DrawPoint(x+3,y+3);
    DrawPoint(x+3,y+4);
    DrawPoint(x+4,y+5);

}

void DrawBird2(int x,int y)
{
    SetColor(0,0);
    DrawLine3(x,x+5,y);
    DrawPoint(x-1,y+1);
    DrawPoint(x-2,y+1);
    DrawPoint(x+3,y+1);
    DrawPoint(x+6,y+1);
    DrawPoint(x-3,y+2);
    DrawPoint(x+2,y+2);
    DrawPoint(x+7,y+2);
    DrawPoint(x+2,y+3);
    DrawPoint(x+6,y+3);
    DrawPoint(x+8,y+3);
    DrawPoint(x-5,y+4);
    DrawPoint(x+2,y+4);
    DrawPoint(x+6,y+4);
    DrawPoint(x+8,y+4);
    DrawLine3(x-5,x-1,y+5);
    DrawPoint(x+3,y+5);
    DrawPoint(x+8,y+5);
    DrawPoint(x-6,y+6);
    DrawPoint(x,y+6);
    DrawLine3(x+4,x+9,y+6);
    DrawPoint(x+3,y+7);
    DrawPoint(x+10,y+7);
    DrawLine3(x-4,x-2,y+8);
    DrawPoint(x+2,y+8);
    DrawLine3(x+4,x+9,y+8);
    DrawPoint(x-4,y+9);
    DrawPoint(x+3,y+9);
    DrawPoint(x+9,y+9);
    DrawPoint(x-3,y+10);
    DrawPoint(x-2,y+10);
    DrawLine3(x+4,x+8,y+10);
    DrawLine3(x-1,x+3,y+11);

    SetColor(15,15);
    DrawLine3(x+4,x+5,y+1);
    DrawLine3(x+3,x+6,y+2);
    DrawLine3(x+4,x+5,y+3);
    DrawPoint(x+7,y+3);
    DrawLine3(x+4,x+5,y+4);
    DrawPoint(x+7,y+4);
    DrawLine3(x+5,x+7,y+5);
    DrawLine3(x-5,x-1,y+6);
    DrawLine3(x-4,x-2,y+7);

    SetColor(12,12);
    DrawLine3(x,x+1,y+8);
    DrawLine3(x-3,x+2,y+9);
    DrawLine3(x-1,x+3,y+10);

    SetColor(6,6);
    DrawLine3(x,x+1,y+2);
    DrawLine3(x-2,x+1,y+3);
    DrawLine3(x-4,x+1,y+4);
    DrawLine3(x,x+2,y+5);
    DrawLine3(x+1,x+3,y+6);
    DrawLine3(x+1,x+2,y+7);

    SetColor(14,14);
    DrawLine3(x,x+2,y+1);
    DrawLine3(x-2,x-1,y+2);
    DrawPoint(x-3,y+3);
    DrawPoint(x-5,y+7);
    DrawPoint(x-1,y+7);

    SetColor(11,11);
    DrawLine3(x+4,x+9,y+7);
    DrawPoint(x+3,y+8);
    DrawLine3(x+4,x+8,y+9);

    SetColor(1,1);
    DrawPoint(x+3,y+3);
    DrawPoint(x+3,y+4);
    DrawPoint(x+4,y+5);

    SetColor(0,0);
    DrawLine3(x-5,x-2,y+3);
    DrawPoint(x-1,y+4);
    DrawPoint(x-1,y+7);
    DrawPoint(x-5,y+7);
    DrawRow2(x-6,x-6,y+4,y+5);
    DrawRow2(x,x,y+5,y+6);

    SetColor(15,15);
    DrawLine3(x-5,x-2,y+4);
    DrawLine3(x-5,x-1,y+5);

    SetColor(6,6);
    DrawPoint(x,y+7);
    SetColor(12,12);
    DrawPoint(x-1,y+8);
    SetColor(14,14);
    DrawPoint(x-1,y+6);
    DrawPoint(x-5,y+6);
    DrawLine3(x-4,x-2,y+7);
}
void DrawBird3(int x,int y)
{
    DrawBird(x,y);
    SetColor(0,0);
    DrawRow2(x-6,x-6,y+7,y+9);
    DrawLine3(x-5,x-1,y+6);
    DrawLine3(x-5,x-2,y+10);
    DrawPoint(x-2,y+9);
    DrawPoint(x-1,y+8);
    SetColor(15,15);
    DrawRow2(x-5,x-3,y+7,y+9);
    DrawPoint(x-2,y+8);
    SetColor(3,3);
    DrawPoint(x-6,y+6);
    SetColor(6,6);
    DrawLine3(x-4,x,y+5);
    SetColor(14,14);
    DrawPoint(x-5,y+7);
    DrawPoint(x-3,y+9);

}


void gotoxy(int x,int y)//x,y là tọa điểm x,y trên màn hình
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD a = {x, y};
    SetConsoleCursorPosition(h, a);
}

void ShowCur(WINBOOL CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = CursorVisibility;

    SetConsoleCursorInfo(handle, &ConCurInf);
}
void ShowCur2(WINBOOL CursorVisibility)
{
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = CursorVisibility;

    SetConsoleCursorInfo(NewConsole, &ConCurInf);
}
void ShowCurTab(WINBOOL CursorVisibility,HANDLE Tab)
{
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = CursorVisibility;

    SetConsoleCursorInfo(Tab, &ConCurInf);
}
void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
void SetColor2(HANDLE tab,int backgound_color, int text_color)
{
    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(tab, color_code);
}
void ClrTable(int x0,int y0,int x,int y)//Hàm xóa bảng.
{
    SetColor(3,3);
    int g,h;
    for(h=y0; h<=y; h++)
    {
        for(g=x0; g<=x; g++)
        {
            gotoxy(g,h);
            printf(" ");
        }
    }
}
void RemoteBird()
{
    MoveY=2;
    Up=90;
    Down=170;
    while(TRUE)
    {
        DrawPoint2(150,150,TabParameter);
        if(NewConsoleTabEvent)
        {
            DrawPoint2(150,150,TabParameter);
        }
        if(Start)
        {
            break;
        }

    }
    while(TRUE)
    {

        if(MoveY==1)
        {
            Delay(Up);
            y--;
            Up+=8;

            if(Up>=120)
            {
                Down=170;
                Up=90;
                MoveY=0;
            }
        }
        else if(MoveY==2)
        {
            DrawPoint2(150,150,TabParameter);
        }
        else if(MoveY==0)
        {
            Delay(Down);
            y++;
            Down-=11;

            if(Down<=80)
                Down=80;
        }
        if(STOP)
        {
            while(TRUE)
            {
                DrawPoint2(150,150,TabParameter);
                if(Start)
                {
                    Sleep(50);
                    MoveY=1;
                    Up=90;
                    Down=170;
                    break;
                }

            }
        }
    }
}
void *AnimationBird(void* arg)
{
    while(TRUE)
    {
        DrawPoint2(150,150,TabParameter);
        if(MainTabEvent)
        {
            while(TRUE)
            {
                if(BreakTabMain)
                {
                    ClrBird4();
                    break;
                }

                BirdbMove();
                //2
                mode=2;
                DrawBird4();

                Delay(260);
                ClrBird4();

                BirdbMove();

                //3
                mode=3;
                DrawBird4();

                Delay(360);
                ClrBird4();

                BirdbMove();

                //2
                mode=2;
                DrawBird4();

                Delay(260);
                ClrBird4();

                BirdbMove();

                //1
                mode=1;
                DrawBird4();

                Delay(360);
                ClrBird4();

            }
        }
        if(NewConsoleTabEvent)
        {
            Birda=170;
            Birdb=y;
            while(TRUE)
            {
                if(Start)
                {
                    ClrBird5();
                    break;
                }
                BirdbMove();
                //2
                mode=2;
                DrawBird5();

                Delay(260);
                ClrBird5();

                BirdbMove();

                //3
                mode=3;
                DrawBird5();

                Delay(360);
                ClrBird5();

                BirdbMove();

                //2
                mode=2;
                DrawBird5();

                Delay(260);
                ClrBird5();

                BirdbMove();

                //1
                mode=1;
                DrawBird5();

                Delay(360);
                ClrBird5();

            }

            //2
            mode=2;
            Birda=170;
            Birdb=y;
            ClrBird5();

            DrawBird5();

            Sleep(20);

            ClrBird5();

            //3
            mode=3;

            Birda=170;
            Birdb=y;
            DrawBird5();

            Sleep(30);

            ClrBird5();


            //2
            mode=2;
            Birda=170;
            Birdb=y;
            DrawBird5();

            Sleep(20);

            ClrBird5();
            //1
            mode=1;
            Birda=170;
            Birdb=y;
            DrawBird5();

            Sleep(30);

            ClrBird5();
        }
        if(STOP)
        {
            ClrBird5();
            while(TRUE)
            {
                DrawPoint2(150,150,TabParameter);
                if(Menu)
                {
                    Birda=205;
                    Birdb=145;
                    break;
                }
                if(Restart)
                {
                    Birda=170;
                    Birdb=y;
                    Sleep(100);
                    break;
                }

            }
        }
    }

    return NULL;
}
void Delay(int ms)
{
    int h;
    int n=ms*100000;
    for(h=0; h<=n; h++)
    {

    }
}

void Condition(int Wallx,int Wally,int WallButton)
{
    if((x+11)==(Wallx-10)&&y<=Wally)
    {
        STOP=1;
    }
    if((x+11)==(Wallx-10)&&(y+10)>=WallButton)
    {
        STOP=1;
    }
    if((y<=Wally)&&((x>=Wallx-12)&&(x<=Wallx+12)))
    {
        STOP=1;
    }
    if((y<=Wally)&&((x+5>=Wallx-12)&&(x+5<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+1<=Wally)&&((x-2>=Wallx-12)&&(x-2<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+1<=Wally)&&((x+6>=Wallx-12)&&(x+6<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+2<=Wally)&&((x-3>=Wallx-12)&&(x-3<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+2<=Wally)&&((x+7>=Wallx-12)&&(x+7<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+3<=Wally)&&((x-5>=Wallx-12)&&(x-5<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+3<=Wally)&&((x+8>=Wallx-12)&&(x+8<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+4<=Wally)&&((x-6>=Wallx-12)&&(x-6<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+4<=Wally)&&((x+8>=Wallx-12)&&(x+8<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+6<=Wally)&&((x-6>=Wallx-12)&&(x-6<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+6<=Wally)&&((x+9>=Wallx-12)&&(x+9<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+7<=Wally)&&((x-5>=Wallx-12)&&(x-5<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+7<=Wally)&&((x+10>=Wallx-12)&&(x+10<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+11>=WallButton)&&((x+4>=Wallx-12)&&(x+4<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+11>=WallButton)&&((x+1>=Wallx-12)&&(x+1<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+10>=WallButton)&&((x-1>=Wallx-12)&&(x-1<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+10>=WallButton)&&((x+9>=Wallx-12)&&(x+9<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+8>=WallButton)&&((x-4>=Wallx-12)&&(x-4<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+8>=WallButton)&&((x+9>=Wallx-12)&&(x+9<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+7>=WallButton)&&((x-5>=Wallx-12)&&(x-5<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+7>=WallButton)&&((x+10>=Wallx-12)&&(x+10<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+6>=WallButton)&&((x-6>=Wallx-12)&&(x-6<=Wallx+12)))
    {
        STOP=1;
    }
    if((y+6>=WallButton)&&((x+9>=Wallx-12)&&(x+9<=Wallx+12)))
    {
        STOP=1;
    }
    if(y+11>=195)
    {
        STOP=1;
    }

}
void DrawPoint(int x,int y)
{
    HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
    char buffer=' ';
    DWORD write;

    gotoxy(x,y);
    WriteConsoleA(console,&buffer,1,&write,NULL);
}
void DrawPoint2(int a,int b,HANDLE Tab)
{
    char buffer=' ';
    DWORD write;
    COORD cursor= {a,b};
    SetConsoleCursorPosition(Tab,cursor);
    WriteConsoleA(Tab,&buffer,1,&write,NULL);
}
void DrawPoint3(char Ascii,int a,int b,HANDLE Tab)
{
    DWORD write;
    COORD cursor= {a,b};
    SetConsoleCursorPosition(Tab,cursor);
    WriteConsoleA(Tab,&Ascii,1,&write,NULL);
}
void ClrPoint(int x,int y)
{
    SetColor(3,3);
    gotoxy(x,y);
    printf(" ");
}
void ClrRow(int x1,int x2,int y1,int y2)
{
    COORD cursor;
    DWORD Write;
    int f;
    for(f=y1; f<=y2; f++)
    {
        cursor.X=x1;
        cursor.Y=f;
        FillConsoleOutputAttribute(NewConsole,51,x2-x1+1,cursor,&Write);
        FillConsoleOutputCharacterA(NewConsole,' ',x2-x1+1,cursor,&Write);

    }
}
void DrawRow(int x1,int x2,int y1,int y2)
{
    HANDLE Console=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursor;
    DWORD Write;
    int f;
    for(f=y1; f<=y2; f++)
    {
        cursor.X=x1;
        cursor.Y=f;
        FillConsoleOutputAttribute(Console,0,x2-x1+1,cursor,&Write);
        FillConsoleOutputCharacterA(Console,' ',x2-x1+1,cursor,&Write);

    }
}
void DrawRow2(int x1,int x2,int y1,int y2)
{
    int f;
    for(f=y1; f<=y2; f++)
    {
        DrawLine3(x1,x2,f);
    }
}

void ClrLine(int x1,int x2,int yline,int Color)
{
    Color=Color*16+Color;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cusor;
    DWORD Write;
    cusor.X=x1;
    cusor.Y=yline;
    FillConsoleOutputCharacterA(console,' ',x2-x1+1,cusor,&Write);
    FillConsoleOutputAttribute(console,Color,x2-x1+1,cusor,&Write);
}
void ClrLine2(int x1,int x2,int yline,int Color)
{
    Color=Color*16+Color;
    COORD cusor;
    DWORD Write;
    cusor.X=x1;
    cusor.Y=yline;
    FillConsoleOutputCharacterA(NewConsole,' ',x2-x1+1,cusor,&Write);
    FillConsoleOutputAttribute(NewConsole,Color,x2-x1+1,cusor,&Write);
}
void DrawLine(int x1,int x2,int yline,int Color)
{
    Color=Color*16+Color;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cusor;
    DWORD Write;
    cusor.X=x1;
    cusor.Y=yline;
    FillConsoleOutputCharacterA(console,' ',x2-x1+1,cusor,&Write);
    FillConsoleOutputAttribute(console,Color,x2-x1+1,cusor,&Write);

}
void DrawLine2(int x1,int x2,int yline,int Color)
{
    Color=Color*16+Color;
    COORD cusor;
    DWORD Write;
    cusor.X=x1;
    cusor.Y=yline;
    FillConsoleOutputCharacterA(NewConsole,' ',x2-x1+1,cusor,&Write);
    FillConsoleOutputAttribute(NewConsole,Color,x2-x1+1,cusor,&Write);
}
void DrawLine3(int x1,int x2,int yline)
{
    int m;
    for(m=x1; m<=x2; m++)
    {
        gotoxy(m,yline);
        printf(" ");
    }
}
void DrawTableRoad(int x1,int y1,int x2,int y2,int ColorRear,int ColorMain)
{
    int m;
    int Color=1;
    for(m=y1; m<=y2; m++)
    {
        if(m==y1)
        {
            Color=ColorRear*16+ColorRear;
            DrawLine(x1,x2,m,Color);
        }
        else if(m==y1+4)
        {
            Color=8;
            DrawLine(x1,x2,m,Color);
        }
        else if(m>y1&&m<y1+4)
        {

            Color=5;
            DrawLine(x1,x2,m,Color);
            if(m==y1+1)
            {
                DrawlineSpace(x1,x2,m);
            }
            else if(m==y1+2)
            {
                DrawlineSpace(x1-2,x2,m);
            }
            else if(m==y1+3)
            {
                DrawlineSpace(x1-4,x2,m);
            }

        }
        else
        {
            Color=ColorMain*16+ColorMain;
            DrawLine(x1,x2,m,Color);
        }
    }

}
void DrawTableRoad2(int x1,int y1,int x2,int y2,int ColorRear,int ColorMain)
{
    int m;
    int Color=1;
    for(m=y1; m<=y2; m++)
    {
        if(m==y1)
        {
            Color=ColorRear*16+ColorRear;
            DrawLine2(x1,x2,m,Color);
        }
        else if(m==y1+4)
        {
            Color=8;
            DrawLine2(x1,x2,m,Color);
        }
        else if(m>y1&&m<y1+4)
        {

            Color=5;
            DrawLine2(x1,x2,m,Color);
            if(m==y1+1)
            {
                DrawlineSpace2(x1,x2,m);
            }
            else if(m==y1+2)
            {
                DrawlineSpace2(x1-2,x2,m);
            }
            else if(m==y1+3)
            {
                DrawlineSpace2(x1-4,x2,m);
            }

        }
        else
        {
            Color=ColorMain*16+ColorMain;
            DrawLine2(x1,x2,m,Color);
        }
    }

}
void DrawTableWall(int x1,int y1,int x2,int y2,int ColorRear,int ColorMain)
{
    int m,n;
    for(m=y1; m<=y2; m++)
    {
        for(n=x1; n<=x2; n++)
        {
            if(m==y1||m==y2)
            {
                SetColor(ColorRear,ColorRear);
            }
            else
            {
                if(n==x1||n==x2)
                {
                    SetColor(ColorRear,ColorRear);
                }
                else if(n==x2-1||n==x2-2||n==x2-4)
                {
                    SetColor(7,7);
                }
                else if(n==x1+1||n==x1+2)
                {
                    SetColor(9,9);
                }
                else if(n==x1+3)
                {
                    SetColor(4,4);
                }
                else if(n==x1+4||n==x1+5)
                {
                    SetColor(5,5);
                }
                else if(n==x1+6)
                {
                    SetColor(2,2);
                }
                else if(n==x1+7||n==x1+8)
                {
                    SetColor(8,8);
                }
                else
                {
                    SetColor(ColorMain,ColorMain);
                }
            }

            DrawPoint(n,m);

        }
    }

}
int GetRandom(int MIN,int MAX,unsigned int *seed)//Hàm lấy random.
{
    return MIN + rand_r(seed) % (MAX + 1 - MIN);
}

void SetWindowSize(short width, short height,HANDLE to)
{
    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 120;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(to,1,&WindowSize);
}

int rand_r (unsigned int *seed)
{
    unsigned int next = *seed;
    int result;

    next *= 1103515245;
    next += 12345;
    result = (unsigned int) (next / 65536) % 2048;

    next *= 1103515245;
    next += 12345;
    result <<= 10;
    result ^= (unsigned int) (next / 65536) % 1024;

    next *= 1103515245;
    next += 12345;
    result <<= 10;
    result ^= (unsigned int) (next / 65536) % 1024;

    *seed = next;

    return result;
}
void DrawlineSpace(int x1,int x2,int yline)
{
    int space=x2/10-25;
    int g;
    int Color=7;
    for(g=x1; g<=x2; g+=2*space)
    {
        DrawLine(g,g+space,yline,Color);
    }
}
void DrawlineSpace2(int x1,int x2,int yline)
{
    int space=x2/10-25;
    int g;
    int Color=7;
    for(g=x1; g<=x2; g+=2*space)
    {
        DrawLine2(g,g+space,yline,Color);
    }
}
void DrawTable(int x1,int y1,int x2,int y2,int ColorRear,int ColorMain )
{
    int m,n;
    for(m=y1; m<=y2; m++)
    {
        for(n=x1; n<=x2; n++)
        {
            if(m==y1||m==y2)
            {
                SetColor(ColorRear,ColorRear);
                DrawPoint(n,m);
            }
            else
            {
                if(n==x1||n==x2)
                {
                    SetColor(ColorRear,ColorRear);
                    DrawPoint(n,m);
                }
                else
                {
                    SetColor(ColorMain,ColorMain);
                    DrawPoint(n,m);
                }
            }
        }
    }
}
void DrawTable2(int x1,int y1,int x2,int y2,int ColorRear,int ColorMain )
{
    int m,n;
    for(m=y1; m<=y2; m++)
    {
        for(n=x1; n<=x2; n++)
        {
            if(m==y1||m==y2)
            {
                if(n<=x1+3||n>=x2-3)
                {

                }
                else
                {
                    SetColor(ColorRear,ColorRear);
                    DrawPoint(n,m);
                }

            }
            else if(m==y1+1||m==y2-1)
            {
                if((n>=x1+2&&n<=x1+3)||(n<=x2-2&&n>=x2-3))
                {
                    SetColor(ColorRear,ColorRear);
                    DrawPoint(n,m);
                }
                else if(n>=x1+3&&n<=x2-3)
                {
                    SetColor(ColorMain,ColorMain);
                    DrawPoint(n,m);
                }
            }
            else if(m==y1+2||m==y2-2||m==y1+3||m==y2-3)
            {
                if(n==x1+1||n==x2-1)
                {
                    SetColor(ColorRear,ColorRear);
                    DrawPoint(n,m);
                }
                else if(n>=x1+1&&n<=x2-1)
                {
                    SetColor(ColorMain,ColorMain);
                    DrawPoint(n,m);
                }
            }
            else
            {
                if(n==x1||n==x2)
                {
                    SetColor(ColorRear,ColorRear);
                    DrawPoint(n,m);
                }
                else
                {
                    SetColor(ColorMain,ColorMain);
                    DrawPoint(n,m);
                }
            }
        }
    }
}
void DrawTable3(int x1,int y1,int x2,int y2,int rRear,int gRear,int bRear,int rMain,int gMain,int bMain)
{
    int m,n;
    for(m=y1; m<=y2; m++)
    {
        for(n=x1; n<=x2; n++)
        {
            if(m==y1||m==y2)
            {
                SetColorRGB(rRear,gRear,bRear);
                DrawPoint(n,m);
            }
            else
            {
                if(n==x1||n==x2)
                {
                    SetColorRGB(rRear,gRear,bRear);
                    DrawPoint(n,m);
                }
                else
                {
                    SetColorRGB(rMain,gMain,bMain);
                    DrawPoint(n,m);
                }
            }
        }
    }
}

void DrawCloud()
{
    DrawTable(70,175,340,194,15,15);
    int a,b,c;
    int f,g;
    f=GetRandom(3,4,&seed1);
    g=GetRandom(3,4,&seed2);
    for(a=Cloudy; a<=175; a++)
    {
        DrawLine(Cloudx-f,Cloudx+g,a,255);
        f+=GetRandom(3,4,&seed1);
        g+=GetRandom(3,4,&seed2);
    }
    Cloudx+=20;
    for(b=Cloudy-5; b<=175; b++)
    {
        DrawLine(Cloudx-f,Cloudx+g,b,255);
        f+=GetRandom(1,2,&seed1);
        g+=GetRandom(1,2,&seed2);
    }
    Cloudx+=20;
    for(c=Cloudy+3; c<=175; c++)
    {
        DrawLine(Cloudx-f,Cloudx+6+g,c,255);
        f+=GetRandom(1,2,&seed1);
        g+=GetRandom(1,2,&seed2);
    }
}
void DrawScores()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD sizebuffer[10];
    COORD buffercoord= {0,0};
    SMALL_RECT RegionRead[10];
    SMALL_RECT RegionWrite[10];
    CHAR_INFO buffer[11][88];

    Numberx=205;
    Numbery=100;

    Scores=0;

    int R;
    for(R=0; R<=9; R++)
    {
        sizebuffer[R].Y=11;
        sizebuffer[R].X=8;
        RegionRead[R].Left=Numberx;
        RegionRead[R].Top=Numbery;
        RegionRead[R].Right=Numberx+7;
        RegionRead[R].Bottom=Numbery+10;
        ReadConsoleOutputA(console,buffer[R],sizebuffer[R],buffercoord,&RegionRead[R]);
        Numberx+=15;
    }

    RegionWrite[0].Left=205;
    RegionWrite[0].Top=100;
    RegionWrite[0].Right=212;
    RegionWrite[0].Bottom=110;

    WriteConsoleOutputA(NewConsole,buffer[0],sizebuffer[0],buffercoord,&RegionWrite[0]);

    int Number=0;

    while(TRUE)
    {
        DrawPoint2(150,150,TabParameter);
        if(Scores<10)
        {
            Numberx=205;
            Numbery=100;
            Number=Scores;
            RegionWrite[Number].Left=Numberx;
            RegionWrite[Number].Top=Numbery;
            RegionWrite[Number].Right=Numberx+7;
            RegionWrite[Number].Bottom=Numbery+10;

            WriteConsoleOutputA(NewConsole,buffer[Number],sizebuffer[Number],buffercoord,&RegionWrite[Number]);

        }
        else if(Scores>=10)
        {
            Number=Scores%10;
            Numberx=205;
            RegionWrite[Number].Left=Numberx;
            RegionWrite[Number].Top=Numbery;
            RegionWrite[Number].Right=Numberx+7;
            RegionWrite[Number].Bottom=Numbery+10;

            WriteConsoleOutputA(NewConsole,buffer[Number],sizebuffer[Number],buffercoord,&RegionWrite[Number]);

            Number=Scores/10;
            Numberx=205-7;
            RegionWrite[Number].Left=Numberx;
            RegionWrite[Number].Top=Numbery;
            RegionWrite[Number].Right=Numberx+7;
            RegionWrite[Number].Bottom=Numbery+10;

            WriteConsoleOutputA(NewConsole,buffer[Number],sizebuffer[Number],buffercoord,&RegionWrite[Number]);
        }
        CopyPixelTo(110,100,122,111,301,94,NewConsole);
        Delay(1);

        if(STOP)
        {
            while(TRUE)
            {
                DrawPoint2(150,150,TabParameter);
                if(Start)
                {
                    WriteConsoleOutputA(NewConsole,buffer[0],sizebuffer[0],buffercoord,&RegionWrite[0]);
                    break;
                }

            }
        }

    }

}
void PrintNumber(int Number)
{
    switch(Number)
    {
    case 0:
        //0
        DrawTable(Numberx+1,Numbery+1,Numberx+7,Numbery+10,0,15);
        DrawTable(Numberx,Numbery,Numberx+6,Numbery+9,0,15);
        SetColor(0,0);
        DrawRow(Numberx+3,Numberx+3,Numbery+3,Numbery+6);
        break;

    case 1:
        //1
        DrawRow(Numberx+4,Numberx+7,Numbery+1,Numbery+10);
        DrawTable(Numberx+2,Numbery,Numberx+6,Numbery+3,0,15);
        DrawTable(Numberx+3,Numbery+3,Numberx+6,Numbery+9,0,15);
        ClrLine(Numberx+4,Numberx+5,Numbery+3,15);
        SetColor(0,0);

        break;
    case 2:
        //2
        DrawTable(Numberx+1,Numbery+1,Numberx+7,Numbery+10,0,15);
        DrawTable(Numberx,Numbery,Numberx+6,Numbery+9,0,15);
        DrawLine(Numberx+1,Numberx+3,Numbery+3,0);
        DrawLine(Numberx+3,Numberx+5,Numbery+6,0);
        break;
    case 3:
        //3
        DrawTable(Numberx+1,Numbery+1,Numberx+7,Numbery+10,0,15);
        DrawTable(Numberx,Numbery,Numberx+6,Numbery+9,0,15);
        DrawLine(Numberx+1,Numberx+3,Numbery+3,0);
        DrawLine(Numberx+1,Numberx+3,Numbery+6,0);
        break;
    case 4:
        //4
        DrawTable(Numberx+1,Numbery+1,Numberx+7,Numbery+10,0,15);
        DrawTable(Numberx,Numbery,Numberx+6,Numbery+9,0,15);
        SetColor(0,0);
        DrawPoint(Numberx+3,Numbery+1);
        DrawPoint(Numberx+3,Numbery+2);
        DrawPoint(Numberx+3,Numbery+3);
        DrawLine(Numberx+1,Numberx+3,Numbery+6,0);
        DrawPoint(Numberx+3,Numbery+7);
        DrawPoint(Numberx+3,Numbery+8);
        ClrPoint(Numberx,Numbery+7);
        ClrPoint(Numberx+3,Numbery+10);
        DrawLine(Numberx+1,Numberx+3,Numbery+7,0);
        ClrTable(Numberx,Numbery+8,Numberx+2,Numbery+10);
        break;
    case 5:
        DrawTable(Numberx+1,Numbery+1,Numberx+7,Numbery+10,0,15);
        DrawTable(Numberx,Numbery,Numberx+6,Numbery+9,0,15);
        DrawLine(Numberx+3,Numberx+5,Numbery+3,0);
        DrawLine(Numberx+1,Numberx+3,Numbery+6,0);
        break;
    case 6:
        DrawTable(Numberx+1,Numbery+1,Numberx+7,Numbery+10,0,15);
        DrawTable(Numberx,Numbery,Numberx+6,Numbery+9,0,15);
        DrawLine(Numberx+3,Numberx+5,Numbery+3,0);
        SetColor(0,0);
        DrawPoint(Numberx+3,Numbery+6);
        break;
    case 7:
        DrawTable(Numberx+1,Numbery+1,Numberx+7,Numbery+4,0,15);
        DrawTable(Numberx+4,Numbery+4,Numberx+7,Numbery+10,0,15);
        DrawTable(Numberx,Numbery,Numberx+6,Numbery+3,0,15);
        DrawTable(Numberx+3,Numbery+3,Numberx+6,Numbery+9,0,15);
        ClrLine(Numberx+4,Numberx+5,Numbery+3,15);
        break;
    case 8:
        DrawTable(Numberx+1,Numbery+1,Numberx+7,Numbery+10,0,15);
        DrawTable(Numberx,Numbery,Numberx+6,Numbery+9,0,15);
        SetColor(0,0);
        DrawPoint(Numberx+3,Numbery+6);
        DrawPoint(Numberx+3,Numbery+3);
        break;
    case 9:
        DrawTable(Numberx+1,Numbery+1,Numberx+7,Numbery+10,0,15);
        DrawTable(Numberx,Numbery,Numberx+6,Numbery+9,0,15);
        SetColor(0,0);
        DrawPoint(Numberx+3,Numbery+3);
        DrawLine(Numberx+1,Numberx+3,Numbery+6,0);
        break;
    }
}
void SetWindowBufferSize(int a,int b,HANDLE Tab)
{
    COORD buffersize= {a,b};
    SetConsoleScreenBufferSize(Tab,buffersize);
}
void ScrollWall()
{
    if(ScrollStart==1)
    {
        if(ScrollUp==1)
        {
            if(Wall1y>=Scrolly)
            {
                Wall1y+=0;
            }
            else
            {
                Wall1y++;
            }

            if(WallButton1<=Scrollbutton)
            {
                WallButton1-=0;
            }
            else
            {
                WallButton1--;
            }
            if(Wall1y==Scrolly&&WallButton1==Scrollbutton)
            {
                ScrollUp=0;
                ScrollDown=1;
            }
        }
        else if(ScrollDown==1)
        {
            if(Wall1y==95)
            {
                Wall1y-=0;
            }
            else
            {
                Wall1y--;
            }
            if(WallButton1==189)
            {
                WallButton1+=0;
            }
            else
            {
                WallButton1++;
            }

            if(Wall1y==95&&WallButton1==189)
            {
                ScrollDown=0;
                ScrollUp=1;
            }
        }
    }
}

void ClrBird(int Birdx,int Birdy)
{
    CopyPixelTo(164,175,180,186,Birdx-6,Birdy,NewConsole);
}
void TextMain()
{
    DrawTable(200,145,212,165,0,15);
    ClrLine(200,202,145,3);
    ClrLine(200,201,146,3);
    DrawPoint(202,146);
    ClrPoint(200,147);
    SetColor(0,0);
    DrawPoint(201,147);

    DrawLine(207,212,150,0);
    DrawLine(207,212,157,0);
    DrawLine(207,212,158,0);
    DrawLine(207,212,159,0);

    DrawLine(200,207,165,0);
    DrawLine(200,207,164,0);
    DrawLine(200,207,163,0);

    DrawRow(207,207,159,165);
    ClrTable(208,160,212,165);

    DrawTable(212,145,218,165,0,15);
    DrawLine(212,218,164,0);
    DrawLine(212,218,163,0);

    DrawTable(218,150,230,165,0,15);
    ClrLine(219,220,150,3);
    ClrPoint(219,151);
    ClrLine(219,220,165,3);
    ClrPoint(219,164);
    SetColor(0,0);
    DrawPoint(220,151);
    DrawPoint(219,152);
    DrawPoint(220,162);
    DrawLine(220,230,164,0);
    DrawLine(219,230,163,0);
    DrawRow(219,219,161,162);
    DrawRow(224,224,155,158);

    //P

    DrawTable(230,150,243,170,0,15);
    DrawRow(236,236,155,158);
    ClrLine(240,243,150,3);
    ClrLine(240,243,165,3);
    ClrLine(242,243,151,3);
    ClrLine(242,243,164,3);
    DrawLine(240,241,151,0);
    DrawLine(240,241,164,0);
    SetColor(0,0);
    DrawPoint(242,152);
    DrawPoint(242,163);
    DrawRow(236,236,165,170);
    DrawLine(230,236,170,0);
    DrawLine(230,236,169,0);
    DrawLine(230,236,168,0);
    DrawLine(236,239,165,0);
    DrawLine(236,239,164,0);
    DrawLine(236,243,163,0);
    DrawLine(240,241,162,0);
    DrawRow(242,242,161,162);
    ClrTable(237,166,243,170);

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD sizebuffer;
    COORD buffercoord= {0,0};
    SMALL_RECT RegionRead;
    SMALL_RECT RegionWrite;
    CHAR_INFO buffer[294];
    sizebuffer.Y=21;
    sizebuffer.X=14;
    RegionRead.Left=230;
    RegionRead.Top=150;
    RegionRead.Right=243;
    RegionRead.Bottom=170;
    ReadConsoleOutputA(console,buffer,sizebuffer,buffercoord,&RegionRead);
    RegionWrite.Left=243;
    RegionWrite.Top=150;
    RegionWrite.Right=256;
    RegionWrite.Bottom=170;
    WriteConsoleOutputA(console,buffer,sizebuffer,buffercoord,&RegionWrite);

    //Y
    DrawTable(256,149,269,170,0,15);
    DrawRow(262,262,150,156);
    DrawRow(259,259,164,170);
    DrawRow(259,262,161,163);
    DrawRow(257,257,159,162);
    DrawRow(258,258,160,163);
    ClrPoint(257,162);
    ClrTable(256,163,258,170);
    DrawRow(260,266,168,170);
    DrawRow(267,267,167,169);
    DrawRow(268,268,166,168);
    ClrLine(267,269,170,3);
    ClrLine(268,269,169,3);
    ClrPoint(269,168);

    //B
    DrawTable(269,144,282,165,0,15);
    DrawRow(275,275,150,151);
    DrawRow(275,275,157,158);
    DrawRow(269,279,163,165);
    ClrLine(280,282,144,3);
    ClrLine(281,282,145,3);
    ClrPoint(282,146);
    ClrLine(280,282,165,3);
    ClrLine(281,282,164,3);
    ClrPoint(282,163);
    SetColor(0,0);
    DrawPoint(280,145);
    DrawPoint(281,146);
    DrawRow(280,280,162,164);
    DrawRow(281,281,161,163);

    //I
    DrawTable(282,149,288,165,0,15);
    DrawLine(282,288,154,0);
    DrawRow(282,288,163,165);

    //R
    DrawTable(288,150,301,165,0,15);
    ClrLine(289,290,150,3);
    ClrPoint(289,151);
    SetColor(0,0);
    DrawPoint(290,151);
    DrawPoint(289,152);
    DrawRow(295,295,156,165);
    DrawRow(288,295,163,165);
    DrawRow(297,301,155,157);
    DrawRow(296,296,156,158);
    ClrLine(297,301,158,3);
    ClrTable(296,159,301,165);

    //D
    DrawTable(301,144,314,165,0,15);
    DrawRow(307,307,144,150);
    DrawRow(307,307,155,158);
    DrawRow(304,314,163,165);
    ClrTable(301,144,306,149);
    ClrLine(302,303,150,3);
    ClrPoint(302,151);
    ClrLine(301,303,165,3);
    ClrLine(301,302,164,3);
    ClrPoint(301,163);
    DrawLine(304,307,150,0);
    SetColor(0,0);
    DrawPoint(303,151);
    DrawPoint(302,152);
    DrawRow(303,303,162,164);
    DrawRow(302,302,161,163);
}
void CopyPixelTo(int x1,int y1,int x2,int y2,int x3,int y3,HANDLE To)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD sizebuffer;
    sizebuffer.Y=y2-y1+3;
    sizebuffer.X=x2-x1+3;
    COORD buffercoord= {0,0};
    SMALL_RECT RegionRead;
    SMALL_RECT RegionWrite;
    CHAR_INFO buffer[(x2-x1+3)*(y2-y1+3)];

    RegionRead.Left=x1;
    RegionRead.Top=y1;
    RegionRead.Right=x2;
    RegionRead.Bottom=y2;

    ReadConsoleOutputA(console,buffer,sizebuffer,buffercoord,&RegionRead);

    RegionWrite.Left=x3;
    RegionWrite.Top=y3;
    RegionWrite.Right=x3+(x2-x1);
    RegionWrite.Bottom=y3+(y2-y1);

    WriteConsoleOutputA(To,buffer,sizebuffer,buffercoord,&RegionWrite);

}
void CopyPixelTo2(int x1,int y1,int x2,int y2,int x3,int y3,HANDLE From,HANDLE To)
{
    COORD sizebuffer;
    sizebuffer.Y=y2-y1+3;
    sizebuffer.X=x2-x1+3;
    COORD buffercoord= {0,0};
    SMALL_RECT RegionRead;
    SMALL_RECT RegionWrite;
    CHAR_INFO buffer[(x2-x1+3)*(y2-y1+3)];

    RegionRead.Left=x1;
    RegionRead.Top=y1;
    RegionRead.Right=x2;
    RegionRead.Bottom=y2;

    ReadConsoleOutputA(From,buffer,sizebuffer,buffercoord,&RegionRead);

    RegionWrite.Left=x3;
    RegionWrite.Top=y3;
    RegionWrite.Right=x3+(x2-x1);
    RegionWrite.Bottom=y3+(y2-y1);

    WriteConsoleOutputA(To,buffer,sizebuffer,buffercoord,&RegionWrite);

}
void PlayArt(int x1,int y1)
{
    int k,h,m=1;
    for(k=y1; k<=y1+10; k++)
    {
        for(h=x1; h<=x1+6; h++)
        {
            if(h<=x1+m)
            {
                SetColor(7,7);
                DrawPoint(h,k);
            }
        }
        if(k<=y1+4)
        {
            m++;
        }
        else
        {
            m--;
        }
    }
}
void TopArt(int x1,int y1)
{
    DrawTable(x1,y1,x1+6,y1+9,12,12);
    DrawTable(x1-7,y1+3,x1,y1+9,12,12);
    DrawTable(x1+7,y1+2,x1+11,y1+9,12,12);
    DrawRow(x1+3,x1+3,y1+1,y1+4);
    DrawTable(x1+8,y1+3,x1+10,y1+7,0,0);
    DrawLine(x1+8,x1+9,y1+4,12);
    DrawLine(x1+9,x1+10,y1+6,12);
    DrawTable(x1-5,y1+4,x1-3,y1+8,0,0);
    DrawLine(x1-5,x1-3,y1+5,12);
    DrawLine(x1-5,x1-3,y1+7,12);
    DrawRow(x1-3,x1-3,y1+4,y1+8);
}
void MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif

    if(MainTabEvent)
    {
        if(mer.dwMousePosition.X>=158&&mer.dwMousePosition.X<=192&&mer.dwMousePosition.Y>=166&&mer.dwMousePosition.Y<=185)
        {
            if(mer.dwButtonState)
            {
                BreakTabMain=1;
            }
            PlayZoom=1;
        }
        else if(mer.dwMousePosition.X>=223&&mer.dwMousePosition.X<=257&&mer.dwMousePosition.Y>=166&&mer.dwMousePosition.Y<=185)
        {
            if(mer.dwButtonState)
            {

            }
            TopZoom=1;
        }
        else
        {
            PlayZoom=0;
            TopZoom=0;
        }

    }
    else if(NewConsoleTabEvent)
    {
        if(mer.dwButtonState)
        {
            PlaySound("audio game/flap",NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP);
            Up=4;
            MoveY=1;
            Start=1;
        }
    }
    else if(OverGame)
    {
        if(mer.dwMousePosition.X>=155&&mer.dwMousePosition.X<=199&&mer.dwMousePosition.Y>=189&&mer.dwMousePosition.Y<=202)
        {
            if(mer.dwButtonState)
            {
                Restart=1;
            }

        }
        else if(mer.dwMousePosition.X>=212&&mer.dwMousePosition.X<=256&&mer.dwMousePosition.Y>=189&&mer.dwMousePosition.Y<=202)
        {
            if(mer.dwButtonState)
            {
                Menu=1;
            }

        }
    }

}
void KeyEventProc(KEY_EVENT_RECORD ker)
{
    if(ker.bKeyDown)
    {
    }
    else
    {
    }

}
void* EventCheck(void* arg)
{
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD NumberRead=0,fdwmode;
    INPUT_RECORD inevent;
    Console=GetStdHandle(STD_INPUT_HANDLE);
    fdwmode=ENABLE_MOUSE_INPUT;
    SetConsoleMode(Console,fdwmode);
    while(TRUE)
    {
        DrawPoint2(150,150,TabParameter);
        ReadConsoleInputA(Console,&inevent,1,&NumberRead);

        if(inevent.EventType==MOUSE_EVENT)
        {
            MouseEventProc(inevent.Event.MouseEvent);
        }

    }

    return NULL;
}
void SetColorRGB(int r,int g,int b)
{
    HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD Mode=0;
    GetConsoleMode(console,&Mode);
    Mode|=ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(console,Mode);
    printf(ESC"48;2;%d;%d;%dm",r,g,b);
}

void GameOverArt(int x1,int y1)
{

    DrawTable(x1+1,y1+1,x1+22,y1+29,0,15);
    DrawTable(x1+22,y1+8,x1+71,y1+29,0,15);
    DrawTable(x1+71,y1+6,x1+90,y1+29,0,15);
    DrawTable(x1+100,y1+1,x1+121,y1+29,0,15);
    DrawTable(x1+121,y1+8,x1+139,y1+29,0,15);
    DrawTable(x1+139,y1+6,x1+157,y1+29,0,15);
    DrawTable(x1+156,y1+8,x1+176,y1+29,0,15);
    DrawTable(x1+3,y1+3,x1+20,y1+27,12,12);//G
    DrawTable(x1+22,y1+10,x1+40,y1+27,12,12);//a
    DrawTable(x1+42,y1+10,x1+68,y1+27,12,12);//m
    DrawTable(x1+71,y1+8,x1+88,y1+27,12,12);//e
    DrawTable(x1+102,y1+3,x1+119,y1+27,12,12);//O
    DrawTable(x1+121,y1+10,x1+138,y1+27,12,12);//v
    DrawTable(x1+140,y1+8,x1+157,y1+27,12,12);//e
    DrawTable(x1+159,y1+10,x1+174,y1+27,12,12);//r

    SetColor(15,15);
    DrawRow2(x1+11,x1+11,y1+9,y1+22);
    DrawRow2(x1+11,x1+20,y1+9,y1+11);
    DrawLine3(x1+3,x1+4,y1+3);
    DrawPoint(x1+3,y1+4);
    DrawLine3(x1+3,x1+4,y1+27);
    DrawPoint(x1+3,y1+26);
    DrawRow2(x1+22,x1+22,y1+9,y1+12);
    DrawLine3(x1+23,x1+24,y1+10);
    DrawLine3(x1+23,x1+24,y1+27);
    DrawRow2(x1+22,x1+22,y1+25,y1+27);
    DrawRow2(x1+30,x1+31,y1+15,y1+22);
    DrawRow2(x1+50,x1+50,y1+15,y1+27);
    DrawRow2(x1+60,x1+60,y1+15,y1+27);
    DrawRow2(x1+68,x1+68,y1+9,y1+12);
    DrawPoint(x1+67,y1+10);
    DrawRow2(x1+71,x1+71,y1+7,y1+10);
    DrawRow2(x1+72,x1+72,y1+7,y1+8);
    DrawRow2(x1+88,x1+88,y1+7,y1+10);
    DrawRow2(x1+87,x1+87,y1+7,y1+8);
    DrawRow2(x1+79,x1+79,y1+14,y1+17);
    DrawRow2(x1+80,x1+88,y1+22,y1+27);
    DrawRow2(x1+71,x1+71,y1+25,y1+27);
    DrawPoint(x1+72,y1+27);
    DrawLine3(x1+102,x1+103,y1+3);
    DrawPoint(x1+102,y1+4);
    DrawLine3(x1+102,x1+103,y1+27);
    DrawPoint(x1+102,y1+26);
    DrawLine3(x1+118,x1+119,y1+3);
    DrawPoint(x1+119,y1+4);
    DrawLine3(x1+118,x1+119,y1+27);
    DrawPoint(x1+119,y1+26);
    DrawRow2(x1+110,x1+110,y1+9,y1+22);
    DrawPoint(x1+121,y1+28);
    DrawPoint(x1+121,y1+9);
    DrawRow2(x1+129,x1+130,y1+9,y1+22);
    DrawRow2(x1+138,x1+138,y1+23,y1+26);
    DrawRow2(x1+136,x1+137,y1+24,y1+27);
    DrawRow2(x1+135,x1+135,y1+25,y1+28);
    DrawRow2(x1+134,x1+135,y1+26,y1+27);
    DrawPoint(x1+133,y1+27);
    DrawRow2(x1+139,x1+139,y1+9,y1+26);
    DrawRow2(x1+140,x1+140,y1+8,y1+10);
    DrawPoint(x1+141,y1+8);
    DrawPoint(x1+156,y1+8);
    DrawRow2(x1+157,x1+157,y1+8,y1+10);
    DrawRow2(x1+140,x1+140,y1+26,y1+27);
    DrawRow2(x1+141,x1+141,y1+27,y1+28);
    DrawRow2(x1+148,x1+148,y1+14,y1+17);
    DrawRow2(x1+149,x1+149,y1+22,y1+28);
    DrawLine3(x1+149,x1+157,y1+22);
    DrawRow2(x1+159,x1+159,y1+10,y1+12);
    DrawRow2(x1+160,x1+160,y1+9,y1+10);
    DrawRow2(x1+167,x1+167,y1+17,y1+28);
    DrawLine3(x1+167,x1+175,y1+17);

    SetColor(11,11);
    DrawLine3(x1+11,x1+20,y1+8);
    DrawLine3(x1+5,x1+20,y1+27);
    DrawPoint(x1+4,y1+26);
    DrawRow2(x1+3,x1+3,y1+24,y1+25);
    DrawLine3(x1+30,x1+31,y1+15);
    DrawPoint(x1+50,y1+15);
    DrawPoint(x1+60,y1+15);
    DrawLine3(x1+25,x1+40,y1+27);
    DrawLine3(x1+23,x1+24,y1+26);
    DrawRow2(x1+22,x1+22,y1+24,y1+25);
    DrawLine3(x1+42,x1+49,y1+27);
    DrawLine3(x1+51,x1+59,y1+27);
    DrawLine3(x1+61,x1+68,y1+27);
    DrawLine3(x1+80,x1+88,y1+22);
    DrawLine3(x1+73,x1+79,y1+27);
    DrawPoint(x1+72,y1+26);
    DrawPoint(x1+71,y1+25);
    DrawPoint(x1+79,y1+17);
    DrawPoint(x1+110,y1+9);
    DrawLine3(x1+104,x1+117,y1+27);
    DrawPoint(x1+103,y1+26);
    DrawPoint(x1+102,y1+25);
    DrawPoint(x1+118,y1+26);
    DrawPoint(x1+119,y1+25);
    DrawLine3(x1+121,x1+132,y1+27);
    DrawPoint(x1+133,y1+26);
    DrawPoint(x1+134,y1+25);
    DrawPoint(x1+135,y1+24);
    DrawLine3(x1+136,x1+137,y1+23);
    DrawPoint(x1+138,y1+22);
    DrawPoint(x1+140,y1+25);
    DrawPoint(x1+141,y1+26);
    DrawLine3(x1+142,x1+148,y1+27);
    DrawLine3(x1+149,x1+157,y1+21);
    DrawPoint(x1+148,y1+14);
    DrawLine3(x1+159,x1+166,y1+27);
    DrawLine3(x1+167,x1+174,y1+16);

    SetColor(3,3);
    DrawPoint(x1+1,y1+3);
    DrawPoint(x1+1,y1+27);
    DrawLine3(x1,x1+3,y1+1);
    DrawLine3(x1,x1+3,y1+29);
    DrawLine3(x1,x1+2,y1+2);
    DrawLine3(x1,x1+2,y1+28);
    DrawPoint(x1+71,y1+6);
    DrawLine3(x1+88,x1+90,y1+6);
    DrawLine3(x1+89,x1+90,y1+7);
    DrawRow2(x1+90,x1+90,y1+6,y1+9);
    DrawPoint(x1+100,y1+3);
    DrawPoint(x1+100,y1+27);
    DrawLine3(x1+100,x1+102,y1+1);
    DrawLine3(x1+100,x1+102,y1+29);
    DrawLine3(x1+100,x1+101,y1+2);
    DrawLine3(x1+100,x1+101,y1+28);
    DrawPoint(x1+121,y1+3);
    DrawLine3(x1+119,x1+121,y1+1);
    DrawLine3(x1+120,x1+121,y1+2);
    DrawRow2(x1+139,x1+139,y1+6,y1+7);
    DrawPoint(x1+140,y1+6);
    DrawRow2(x1+157,x1+157,y1+6,y1+7);
    DrawLine3(x1+136,x1+140,y1+29);
    DrawLine3(x1+137,x1+139,y1+28);
    DrawPoint(x1+138,y1+27);
    DrawPoint(x1+159,y1+8);

    SetColor(0,0);
    DrawPoint(x1+3,y1+2);
    DrawPoint(x1+3,y1+28);
    DrawPoint(x1+2,y1+3);
    DrawPoint(x1+2,y1+27);
    DrawPoint(x1+71,y1+7);
    DrawPoint(x1+88,y1+7);
    DrawRow2(x1+89,x1+89,y1+8,y1+9);
    DrawLine3(x1+69,x1+70,y1+9);
    DrawPoint(x1+102,y1+2);
    DrawPoint(x1+101,y1+3);
    DrawPoint(x1+102,y1+28);
    DrawPoint(x1+101,y1+27);
    DrawPoint(x1+119,y1+2);
    DrawPoint(x1+120,y1+3);
    DrawPoint(x1+119,y1+28);
    DrawPoint(x1+137,y1+27);
    DrawPoint(x1+136,y1+28);
    DrawPoint(x1+140,y1+7);
    DrawPoint(x1+157,y1+7);
    DrawPoint(x1+140,y1+28);
    DrawPoint(x1+139,y1+27);
    DrawPoint(x1+138,y1+26);
    DrawRow2(x1+150,x1+157,y1+23,y1+29);
    DrawLine3(x1+168,x1+176,y1+18);
    DrawRow2(x1+168,x1+168,y1+18,y1+29);
    DrawLine3(x1+158,x1+159,y1+9);
    DrawRow2(x1+81,x1+90,y1+24,y1+29);

    SetColor(3,3);
    DrawRow2(x1+151,x1+156,y1+24,y1+29);
    DrawRow2(x1+169,x1+176,y1+19,y1+29);
    DrawRow2(x1+82,x1+90,y1+25,y1+29);
}
void* PrintScores(void* arg)
{
    DrawScores();
    return NULL;
}
void DrawOverTable()
{
    DrawTable2(370,100,480,150,0,14);

    //Medal
    SetColor(12,12);
    DrawRow2(380,380,110,114);
    DrawRow2(384,384,110,114);
    DrawPoint(381,111);
    DrawPoint(383,111);
    DrawPoint(382,112);

    DrawRow2(386,386,110,114);
    DrawLine3(387,388,110);
    DrawLine3(387,388,112);
    DrawLine3(387,388,114);

    DrawRow2(390,390,110,114);
    DrawRow2(393,393,111,113);
    DrawLine3(391,392,110);
    DrawLine3(391,392,114);

    DrawRow2(395,395,111,114);
    DrawRow2(398,398,111,114);
    DrawLine3(396,397,110);
    DrawLine3(396,397,113);

    DrawRow2(400,400,110,114);
    DrawLine3(400,402,114);

    SetColor(13,13);
    DrawPoint(380,115);
    DrawPoint(384,115);
    DrawPoint(381,112);
    DrawPoint(382,113);
    DrawPoint(383,112);
    DrawLine3(386,388,115);
    DrawLine3(390,392,115);
    DrawPoint(393,114);
    DrawPoint(395,115);
    DrawLine3(396,397,114);
    DrawPoint(398,115);
    DrawLine3(400,402,115);


    CopyPixelTo(376,110,402,115,378,110,BaseConsole);

    //Score
    SetColor(12,12);
    DrawLine3(450,452,110);
    DrawLine3(449,451,114);
    DrawLine3(450,451,112);
    DrawPoint(449,111);
    DrawPoint(452,113);

    DrawLine3(455,456,110);
    DrawLine3(455,456,114);
    DrawRow2(454,454,111,113);

    DrawLine3(459,460,110);
    DrawLine3(459,460,114);
    DrawRow2(458,458,111,113);
    DrawRow2(461,461,111,113);

    DrawRow2(463,463,110,114);
    DrawLine3(464,465,110);
    DrawLine3(464,465,113);
    DrawRow2(466,466,111,112);
    DrawPoint(466,114);

    DrawRow2(468,468,110,114);
    DrawLine3(469,470,110);
    DrawLine3(469,470,112);
    DrawLine3(469,470,114);

    SetColor(13,13);
    DrawLine3(449,451,115);
    DrawPoint(452,114);
    DrawLine3(455,456,115);
    DrawPoint(454,114);
    DrawLine3(459,460,115);
    DrawPoint(458,114);
    DrawPoint(461,114);
    DrawLine3(464,465,114);
    DrawPoint(463,115);
    DrawPoint(466,115);
    DrawLine3(468,470,115);


    //Best

    SetColor(12,12);
    DrawRow2(450,450,130,134);
    DrawLine3(451,452,130);
    DrawLine3(451,452,132);
    DrawLine3(451,452,134);
    DrawPoint(453,131);
    DrawPoint(453,133);

    DrawRow2(455,455,130,134);
    DrawLine3(456,457,130);
    DrawLine3(456,457,132);
    DrawLine3(456,457,134);

    DrawLine3(460,462,130);
    DrawLine3(459,461,134);
    DrawLine3(460,461,132);
    DrawPoint(459,131);
    DrawPoint(462,133);

    DrawLine3(464,466,130);
    DrawRow2(465,465,131,134);

    SetColor(13,13);

    DrawLine3(450,452,135);
    DrawPoint(453,134);
    DrawLine3(455,457,135);
    DrawLine3(459,461,135);
    DrawPoint(462,134);
    DrawPoint(465,135);

    DrawCicleOverGame();

}
void DrawCicleOverGame()
{
    int ColorMain=0;
    int ColorRear=0;
    int Gold=6;
    int Silver=13;
    int Bronze=11;

    if(Scores<=10)
    {
        ColorMain=Bronze;
        ColorRear=0;
    }
    else if(Scores>=10&&Scores<=30)
    {
        ColorMain=Silver;
        ColorRear=10;
    }
    else
    {
        ColorMain=Gold;
        ColorRear=11;
    }
    SetColor(ColorMain,ColorMain);
    DrawRow2(385,401,123,136);
    DrawRow2(383,384,126,133);
    DrawRow2(402,403,126,133);
    DrawRow2(388,398,137,138);
    DrawLine(390,400,122,ColorMain);
    DrawLine(386,387,123,15);
    DrawLine(390,398,121,15);
    DrawLine(388,389,122,15);

    DrawLine(390,396,120,ColorRear);
    DrawLine(388,389,121,ColorRear);
    DrawLine(397,398,121,ColorRear);
    DrawLine(386,387,122,ColorRear);
    DrawLine(399,400,122,ColorRear);
    SetColor(ColorRear,ColorRear);
    DrawPoint(385,123);
    DrawPoint(401,123);
    DrawRow2(384,384,124,125);
    DrawRow2(402,402,124,125);
    DrawRow2(383,383,126,127);
    DrawRow2(403,403,126,127);

    DrawRow2(382,382,128,131);
    DrawRow2(404,404,128,131);

    DrawLine(390,396,139,ColorRear);
    DrawLine(388,389,138,ColorRear);
    DrawLine(397,398,138,ColorRear);
    DrawLine(386,387,137,ColorRear);
    DrawLine(399,400,137,ColorRear);
    SetColor(ColorRear,ColorRear);
    DrawPoint(385,136);
    DrawPoint(401,136);
    DrawRow2(384,384,134,135);
    DrawRow2(402,402,134,135);
    DrawRow2(383,383,132,133);
    DrawRow2(403,403,132,133);



    x=391,y=124;
    SetColor(ColorRear,ColorRear);
    DrawLine3(x,x+5,y);
    DrawPoint(x-1,y+1);
    DrawPoint(x-2,y+1);
    DrawPoint(x+3,y+1);
    DrawPoint(x+6,y+1);
    DrawPoint(x-3,y+2);
    DrawPoint(x+2,y+2);
    DrawPoint(x+7,y+2);
    DrawPoint(x-4,y+3);
    DrawPoint(x+2,y+3);
    DrawPoint(x+6,y+3);
    DrawPoint(x+8,y+3);
    DrawPoint(x-5,y+4);
    DrawPoint(x+2,y+4);
    DrawPoint(x+6,y+4);
    DrawPoint(x+8,y+4);
    DrawLine3(x-5,x-1,y+5);
    DrawPoint(x+3,y+5);
    DrawPoint(x+8,y+5);
    DrawPoint(x-6,y+6);
    DrawPoint(x,y+6);
    DrawLine3(x+4,x+9,y+6);
    DrawPoint(x-6,y+7);
    DrawPoint(x,y+7);
    DrawPoint(x+3,y+7);
    DrawPoint(x+10,y+7);
    DrawLine3(x-5,x-1,y+8);
    DrawPoint(x+2,y+8);
    DrawLine3(x+4,x+9,y+8);
    DrawPoint(x-4,y+9);
    DrawPoint(x+3,y+9);
    DrawPoint(x+9,y+9);
    DrawPoint(x-3,y+10);
    DrawPoint(x-2,y+10);
    DrawLine3(x+4,x+8,y+10);
    DrawLine3(x-1,x+3,y+11);

    SetColor(ColorMain,ColorMain);
    DrawLine3(x+4,x+5,y+1);
    DrawLine3(x+3,x+6,y+2);
    DrawLine3(x+4,x+5,y+3);
    DrawPoint(x+7,y+3);
    DrawLine3(x+4,x+5,y+4);
    DrawPoint(x+7,y+4);
    DrawLine3(x+5,x+7,y+5);
    DrawLine3(x-5,x-1,y+6);
    DrawLine3(x-4,x-2,y+7);

    SetColor(ColorMain,ColorMain);
    DrawLine3(x,x+1,y+8);
    DrawLine3(x-3,x+2,y+9);
    DrawLine3(x-1,x+3,y+10);

    SetColor(ColorMain,ColorMain);
    DrawLine3(x,x+1,y+2);
    DrawLine3(x-2,x+1,y+3);
    DrawLine3(x-4,x+1,y+4);
    DrawLine3(x,x+2,y+5);
    DrawLine3(x+1,x+3,y+6);
    DrawLine3(x+1,x+2,y+7);

    SetColor(15,15);
    DrawLine3(x,x+2,y+1);
    DrawLine3(x-2,x-1,y+2);
    DrawPoint(x-3,y+3);
    DrawPoint(x-5,y+7);
    DrawPoint(x-1,y+7);

    SetColor(ColorMain,ColorMain);
    DrawLine3(x+4,x+9,y+7);
    DrawPoint(x+3,y+8);
    DrawLine3(x+4,x+8,y+9);

    SetColor(ColorMain,ColorMain);
    DrawPoint(x+3,y+3);
    DrawPoint(x+3,y+4);
    DrawPoint(x+4,y+5);
}
void ArtNew()
{
    SetColor(11,11);
    DrawRow2(139,155,169,175);

    SetColor(15,15);

    DrawRow2(140,140,170,174);
    DrawRow2(143,143,170,174);
    DrawPoint(141,171);
    DrawPoint(142,172);

    DrawRow2(145,145,170,174);
    DrawLine3(146,147,170);
    DrawLine3(146,147,172);
    DrawLine3(146,147,174);

    DrawRow2(149,149,170,173);
    DrawRow2(152,152,171,173);
    DrawRow2(154,154,170,173);
    DrawPoint(153,174);
    DrawLine3(150,151,174);

}
void ArtRestar()
{
    SetColor(11,11);
    DrawRow2(105,149,116,129);
    SetColor(15,15);
    DrawRow2(106,148,117,127);
    SetColor(12,12);
    DrawRow2(107,147,118,126);

    SetColor(15,15);
    //R
    DrawRow2(112,112,120,124);
    DrawRow2(115,115,121,122);
    DrawLine3(113,114,120);
    DrawLine3(113,114,123);
    DrawPoint(115,124);
    //E
    DrawRow2(117,117,120,124);
    DrawLine3(118,119,120);
    DrawLine3(118,119,122);
    DrawLine3(118,119,124);
    //S
    DrawLine3(122,124,120);
    DrawLine3(122,123,122);
    DrawLine3(121,123,124);
    DrawPoint(121,121);
    DrawPoint(124,123);
    //T
    DrawLine3(126,128,120);
    DrawRow2(127,127,121,124);
    //A
    DrawRow2(130,130,121,124);
    DrawRow2(133,133,121,124);
    DrawLine3(131,132,120);
    DrawLine3(131,132,123);
    //R
    DrawRow2(135,135,120,124);
    DrawRow2(138,138,121,122);
    DrawLine3(136,137,120);
    DrawLine3(136,137,123);
    DrawPoint(138,124);
    //T
    DrawLine3(140,142,120);
    DrawRow2(141,141,121,124);

    SetColor(11,11);
    DrawPoint(112,125);
    DrawPoint(115,125);
    DrawLine3(113,114,124);
    DrawLine3(117,119,125);
    DrawLine3(121,123,125);
    DrawPoint(124,124);
    DrawPoint(127,125);
    DrawPoint(130,125);
    DrawLine3(131,132,124);
    DrawPoint(133,125);
    DrawPoint(135,125);
    DrawLine3(136,137,124);
    DrawPoint(138,125);
    DrawPoint(141,125);



}
void ArtMenu()
{
    SetColor(11,11);
    DrawRow2(108,152,136,149);
    SetColor(15,15);
    DrawRow2(109,151,137,147);
    SetColor(12,12);
    DrawRow2(110,150,138,146);

    SetColor(15,15);

    DrawRow2(120,120,140,144);
    DrawRow2(124,124,140,144);
    DrawPoint(121,141);
    DrawPoint(122,142);
    DrawPoint(123,141);

    DrawRow2(126,126,140,144);
    DrawLine3(127,128,140);
    DrawLine3(127,128,142);
    DrawLine3(127,128,144);

    DrawRow2(130,130,140,144);
    DrawRow2(133,133,140,144);
    DrawPoint(131,141);
    DrawPoint(132,142);

    DrawRow2(135,136,140,143);
    DrawRow2(139,139,140,143);
    DrawLine3(137,138,144);

    SetColor(11,11);
    DrawPoint(120,145);
    DrawPoint(124,145);
    DrawPoint(121,142);
    DrawPoint(122,143);
    DrawPoint(123,142);

    DrawPoint(126,145);
    DrawLine3(127,128,141);
    DrawLine3(127,128,143);
    DrawLine3(127,128,145);

    DrawPoint(130,145);
    DrawPoint(133,145);
    DrawPoint(131,142);
    DrawPoint(132,143);

    DrawLine3(135,136,144);
    DrawPoint(139,144);
    DrawLine3(137,138,145);



}
void ArtOk()
{
    HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);

    SetColor(11,11);
    DrawRow2(108,152,153,166);
    SetColor(15,15);
    DrawRow2(109,151,154,164);
    SetColor(12,12);
    DrawRow2(110,150,155,163);

    SetColor(15,15);
    DrawRow2(120,120,158,160);
    DrawRow2(123,123,158,160);
    DrawLine3(121,122,157);
    DrawLine3(121,122,161);

    DrawRow2(125,125,157,161);
    DrawPoint(126,159);
    DrawPoint(127,158);
    DrawPoint(127,160);
    DrawPoint(128,157);
    DrawPoint(128,161);

    SetColor(11,11);

    DrawPoint(120,161);
    DrawPoint(123,161);
    DrawLine3(121,122,158);
    DrawLine3(121,122,162);

    DrawPoint(125,162);
    DrawPoint(126,160);
    DrawPoint(127,159);
    DrawPoint(127,161);
    DrawPoint(128,158);
    DrawPoint(128,162);


    CopyPixelTo(115,157,128,162,120,157,console);

}

void ArtPause()
{
    SetColor(11,11);
    DrawRow2(110,122,100,111);
    SetColor(15,15);
    DrawRow2(111,121,101,109);
    SetColor(12,12);
    DrawRow2(112,120,102,108);

    SetColor(15,15);
    DrawRow2(114,115,104,106);
    DrawRow2(117,118,104,106);

}
void ArtBackGroundGame()
{
    SetColor(15,15);
    DrawRow2(225,455,25,55);

    ArtCloud(240,20);
    ArtCloud(260,23);
    ArtCloud(280,21);
    ArtCloud(300,20);
    ArtCloud(315,19);
    ArtCloud(332,18);
    ArtCloud(348,19);
    ArtCloud(368,20);
    ArtCloud(383,19);
    ArtCloud(403,20);
    ArtCloud(416,22);
    ArtCloud(428,21);
    ArtCloud(443,20);

    ArtTower(240,40);
    ArtTower(195,40);
    ArtTower(417,40);
    ArtTower(375,40);
    ArtTower(327,40);
    ArtTower(286,40);

    SetColor(2,2);
    DrawRow2(225,455,54,90);

    ArtTree(232,50);
    ArtTree(250,50);
    ArtTree(268,50);
    ArtTree(282,51);
    ArtTree(303,50);

    ArtTree(320,50);
    ArtTree(332,50);
    ArtTree(350,51);
    ArtTree(368,50);

    ArtTree(382,50);
    ArtTree(400,50);
    ArtTree(418,50);
    ArtTree(432,51);
    ArtTree(450,51);

    ArtTree(250-8,50+2);
    ArtTree(250+8,50+2);
    ArtTree(268+8,50+2);
    ArtTree(282+8,50+2);
    ArtTree(300+8,50+2);

    ArtTree(318+8,50+2);
    ArtTree(332+8,50+2);
    ArtTree(350+8,50+2);
    ArtTree(368+8,50+2);

    ArtTree(382+8,50+2);
    ArtTree(400+8,50+2);
    ArtTree(418+8,50+2);
    ArtTree(432+8,50+2);

    ArtTree(250,50+4);
    ArtTree(268,50+4);
    ArtTree(282,51+4);
    ArtTree(303,50+4);

    ArtTree(320,50+4);
    ArtTree(332,50+4);
    ArtTree(350,51+4);
    ArtTree(368,50+4);

    ArtTree(382,50+4);
    ArtTree(400,50+4);
    ArtTree(418,50+4);
    ArtTree(432,51+4);

    SetColor(2,2);
    DrawRow2(225,455,58,61);



}
void ArtTree(int a,int b)
{
    SetColor(7,7);
    DrawLine3(a,a+3,b);
    DrawLine3(a-2,a-1,b+1);
    DrawLine3(a+4,a+5,b+1);
    DrawLine3(a-4,a-3,b+2);
    DrawLine3(a+6,a+7,b+2);
    DrawRow2(a-5,a-5,b+3,b+4);
    DrawRow2(a+8,a+8,b+3,b+4);
    DrawRow2(a-6,a-6,b+5,b+6);
    DrawRow2(a+9,a+9,b+5,b+6);
    SetColor(2,2);
    DrawLine3(a,a+3,b+1);
    DrawLine3(a-2,a+5,b+2);
    DrawRow2(a-4,a+7,b+3,b+4);
    DrawRow2(a-5,a+8,b+5,b+6);
}
void ArtCloud(int a,int b)
{
    SetColor(15,15);
    DrawLine3(a,a+6,b);
    DrawLine3(a-2,a+8,b+1);
    DrawLine3(a-4,a+10,b+2);

    DrawLine3(a-5,a+11,b+3);
    DrawRow2(a-6,a+12,b+4,b+5);
    DrawRow2(a-7,a+13,b+6,b+7);
}
void ArtTower(int a,int b)
{
    SetColor(13,13);
    DrawRow2(a,a+6,b,b+15);
    DrawRow2(a+8,a+8,b-2,b+15);
    DrawRow2(a+9,a+9,b-3,b+15);
    DrawRow2(a+10,a+12,b-4,b+15);
    DrawRow2(a+13,a+19,b-5,b+15);

    DrawTable(a+30,b-7,a+35,b+15,13,4);
    DrawTable(a+18,b-3,a+26,b+15,3,4);
    DrawTable(a+15,b,a+26,b+15,3,4);
    DrawTable(a+24,b+4,a+30,b+15,3,4);
    DrawTable(a+37,b-3,a+41,b+15,3,4);
    DrawTable(a+37,b-1,a+45,b+15,3,4);
    DrawTable(a+35,b-7,a+39,b+15,3,4);
    DrawTable(a+28,b-5,a+39,b+15,3,4);

    //Window
    SetColor(14,14);
    DrawPoint(a+20,b-1);
    DrawRow2(a+17,a+17,b+2,b+3);
    DrawRow2(a+17,a+17,b+5,b+6);
    DrawRow2(a+17,a+17,b+8,b+9);

    DrawRow2(a+20,a+20,b+2,b+3);
    DrawRow2(a+20,a+20,b+5,b+6);
    DrawRow2(a+20,a+20,b+8,b+9);

    DrawRow2(a+22,a+22,b+2,b+3);
    DrawRow2(a+22,a+22,b+5,b+6);
    DrawRow2(a+22,a+22,b+8,b+9);

    DrawRow2(a+26,a+26,b+6,b+7);
    DrawRow2(a+26,a+26,b+9,b+10);

    DrawRow2(a+30,a+30,b-2,b-1);
    DrawRow2(a+30,a+30,b+1,b+2);
    DrawRow2(a+30,a+30,b+4,b+5);
    DrawRow2(a+30,a+30,b+7,b+8);

    DrawRow2(a+33,a+33,b-2,b-1);
    DrawRow2(a+33,a+33,b+1,b+2);
    DrawRow2(a+33,a+33,b+4,b+5);
    DrawRow2(a+33,a+33,b+7,b+8);

    DrawRow2(a+36,a+36,b-2,b-1);
    DrawRow2(a+36,a+36,b+1,b+2);
    DrawRow2(a+36,a+36,b+4,b+5);
    DrawRow2(a+36,a+36,b+7,b+8);

    DrawRow2(a+41,a+41,b+1,b+2);
    DrawRow2(a+41,a+41,b+4,b+5);
    DrawRow2(a+41,a+41,b+7,b+8);

    DrawRow2(a+43,a+43,b+1,b+2);
    DrawRow2(a+43,a+43,b+4,b+5);
    DrawRow2(a+43,a+43,b+7,b+8);
}
void DrawBird4()
{
    int a1=0,a2=1;
    CopyBirdAction1(a1,TabMain);
    CopyBirdAction1(a2,TabMain);
}
void DrawBird5()
{
    int a1=0,a2=1;
    CopyBirdAction1(a1,NewConsole);
    CopyBirdAction1(a2,NewConsole);
}

void CopyBirdAction1(int Copy,HANDLE To)
{
    switch(Copy)
    {
    case 0:
        if(mode==2)
        {
            CopyPixelTo2(170,145,175,145,Birda,Birdb,BaseConsole,To);
            CopyPixelTo2(168,146,176,146,Birda-2,Birdb+1,BaseConsole,To);
            CopyPixelTo2(167,147,177,147,Birda-3,Birdb+2,BaseConsole,To);
            CopyPixelTo2(166,148,178,148,Birda-4,Birdb+3,BaseConsole,To);
            CopyPixelTo2(165,149,178,150,Birda-5,Birdb+4,BaseConsole,To);
        }
        else if(mode==1)
        {
            CopyPixelTo2(170,125,175,125,Birda,Birdb,BaseConsole,To);
            CopyPixelTo2(168,126,176,126,Birda-2,Birdb+1,BaseConsole,To);
            CopyPixelTo2(167,127,177,127,Birda-3,Birdb+2,BaseConsole,To);
            CopyPixelTo2(166,128,178,128,Birda-4,Birdb+3,BaseConsole,To);
            CopyPixelTo2(165,129,178,130,Birda-5,Birdb+4,BaseConsole,To);
        }

        else if(mode==3)
        {
            CopyPixelTo2(170,165,175,165,Birda,Birdb,BaseConsole,To);
            CopyPixelTo2(168,166,176,166,Birda-2,Birdb+1,BaseConsole,To);
            CopyPixelTo2(167,167,177,167,Birda-3,Birdb+2,BaseConsole,To);
            CopyPixelTo2(165,168,178,168,Birda-5,Birdb+3,BaseConsole,To);
            CopyPixelTo2(164,169,178,170,Birda-6,Birdb+4,BaseConsole,To);
        }

        break;
    case 1:
        if(mode==2)
        {
            CopyPixelTo2(164,151,179,151,Birda-6,Birdb+6,BaseConsole,To);
            CopyPixelTo2(164,152,180,152,Birda-6,Birdb+7,BaseConsole,To);
            CopyPixelTo2(165,153,179,153,Birda-5,Birdb+8,BaseConsole,To);
            CopyPixelTo2(166,154,179,154,Birda-4,Birdb+9,BaseConsole,To);
            CopyPixelTo2(167,155,178,155,Birda-3,Birdb+10,BaseConsole,To);
            CopyPixelTo2(169,156,173,156,Birda-1,Birdb+11,BaseConsole,To);
        }
        else if(mode==1)
        {

            CopyPixelTo2(165,131,179,131,Birda-5,Birdb+6,BaseConsole,To);
            CopyPixelTo2(164,132,180,132,Birda-6,Birdb+7,BaseConsole,To);
            CopyPixelTo2(164,133,179,133,Birda-6,Birdb+8,BaseConsole,To);
            CopyPixelTo2(164,134,179,134,Birda-6,Birdb+9,BaseConsole,To);
            CopyPixelTo2(165,135,178,135,Birda-5,Birdb+10,BaseConsole,To);
            CopyPixelTo2(169,136,173,136,Birda-1,Birdb+11,BaseConsole,To);
        }

        else if(mode==3)
        {

            CopyPixelTo2(164,171,179,171,Birda-6,Birdb+6,BaseConsole,To);
            CopyPixelTo2(165,172,180,172,Birda-5,Birdb+7,BaseConsole,To);
            CopyPixelTo2(166,173,179,173,Birda-4,Birdb+8,BaseConsole,To);
            CopyPixelTo2(166,174,179,174,Birda-4,Birdb+9,BaseConsole,To);
            CopyPixelTo2(166,175,178,175,Birda-4,Birdb+10,BaseConsole,To);
            CopyPixelTo2(169,176,173,176,Birda-1,Birdb+11,BaseConsole,To);
        }

        break;
    }
}
void ClrBird4()
{
    int b1=0,b2=1;
    ClrBirdAction1(b1,TabMain);
    ClrBirdAction1(b2,TabMain);
}
void ClrBird5()
{
    int b1=0,b2=1;
    ClrBirdAction1(b2,NewConsole);
    ClrBirdAction1(b1,NewConsole);

}
void ClrBirdAction1(int Del,HANDLE To)
{
    switch(Del)
    {
    case 0:
        if(mode==2)
        {
            CopyPixelTo2(Birda,Birdb,Birda+5,Birdb,Birda,Birdb,TabBackground,To);
            CopyPixelTo2(Birda-2,Birdb+1,Birda+6,Birdb+1,Birda-2,Birdb+1,TabBackground,To);
            CopyPixelTo2(Birda-3,Birdb+2,Birda+7,Birdb+2,Birda-3,Birdb+2,TabBackground,To);
            CopyPixelTo2(Birda-4,Birdb+3,Birda+8,Birdb+3,Birda-4,Birdb+3,TabBackground,To);
            CopyPixelTo2(Birda-5,Birdb+4,Birda+8,Birdb+5,Birda-5,Birdb+4,TabBackground,To);
            CopyPixelTo2(Birda-6,Birdb+6,Birda+9,Birdb+6,Birda-6,Birdb+6,TabBackground,To);
        }
        else if(mode==1)
        {
            CopyPixelTo2(Birda,Birdb,Birda+5,Birdb,Birda,Birdb,TabBackground,To);
            CopyPixelTo2(Birda-2,Birdb+1,Birda+6,Birdb+1,Birda-2,Birdb+1,TabBackground,To);
            CopyPixelTo2(Birda-3,Birdb+2,Birda+7,Birdb+2,Birda-3,Birdb+2,TabBackground,To);
            CopyPixelTo2(Birda-4,Birdb+3,Birda+8,Birdb+3,Birda-4,Birdb+3,TabBackground,To);
            CopyPixelTo2(Birda-5,Birdb+4,Birda+8,Birdb+5,Birda-5,Birdb+4,TabBackground,To);
            CopyPixelTo2(Birda-6,Birdb+6,Birda+9,Birdb+6,Birda-5,Birdb+6,TabBackground,To);
        }

        else if(mode==3)
        {
            CopyPixelTo2(Birda,Birdb,Birda+5,Birdb,Birda,Birdb,TabBackground,To);
            CopyPixelTo2(Birda-2,Birdb+1,Birda+6,Birdb+1,Birda-2,Birdb+1,TabBackground,To);
            CopyPixelTo2(Birda-3,Birdb+2,Birda+7,Birdb+2,Birda-3,Birdb+2,TabBackground,To);
            CopyPixelTo2(Birda-5,Birdb+3,Birda+8,Birdb+3,Birda-5,Birdb+3,TabBackground,To);
            CopyPixelTo2(Birda-6,Birdb+4,Birda+8,Birdb+5,Birda-6,Birdb+4,TabBackground,To);
        }

        break;
    case 1:
        if(mode==2)
        {
            CopyPixelTo2(Birda-6,Birdb+7,Birda+10,Birdb+7,Birda-6,Birdb+7,TabBackground,To);
            CopyPixelTo2(Birda-5,Birdb+8,Birda+9,Birdb+8,Birda-5,Birdb+8,TabBackground,To);
            CopyPixelTo2(Birda-4,Birdb+9,Birda+9,Birdb+9,Birda-4,Birdb+9,TabBackground,To);
            CopyPixelTo2(Birda-3,Birdb+10,Birda+8,Birdb+10,Birda-3,Birdb+10,TabBackground,To);
            CopyPixelTo2(Birda-1,Birdb+11,Birda+3,Birdb+11,Birda-1,Birdb+11,TabBackground,To);
        }

        else if(mode==1)
        {
            CopyPixelTo2(Birda-6,Birdb+7,Birda+10,Birdb+7,Birda-6,Birdb+7,TabBackground,To);
            CopyPixelTo2(Birda-6,Birdb+8,Birda+9,Birdb+8,Birda-6,Birdb+8,TabBackground,To);
            CopyPixelTo2(Birda-6,Birdb+9,Birda+9,Birdb+9,Birda-6,Birdb+9,TabBackground,To);
            CopyPixelTo2(Birda-5,Birdb+10,Birda+8,Birdb+10,Birda-5,Birdb+10,TabBackground,To);
            CopyPixelTo2(Birda-1,Birdb+11,Birda+3,Birdb+11,Birda-1,Birdb+11,TabBackground,To);
        }

        else if(mode==3)
        {
            CopyPixelTo2(Birda-6,Birdb+6,Birda+9,Birdb+6,Birda-6,Birdb+6,TabBackground,To);
            CopyPixelTo2(Birda-5,Birdb+7,Birda+10,Birdb+7,Birda-5,Birdb+7,TabBackground,To);
            CopyPixelTo2(Birda-4,Birdb+8,Birda+9,Birdb+8,Birda-4,Birdb+8,TabBackground,To);
            CopyPixelTo2(Birda-4,Birdb+9,Birda+9,Birdb+9,Birda-4,Birdb+9,TabBackground,To);
            CopyPixelTo2(Birda-4,Birdb+10,Birda+8,Birdb+10,Birda-4,Birdb+10,TabBackground,To);
            CopyPixelTo2(Birda-1,Birdb+11,Birda+3,Birdb+11,Birda-1,Birdb+11,TabBackground,To);
        }
        break;
    }
}
void SetParameterWall()
{
    //SetWall

    x=170;
    y=145;

    Count=0;

    Birda=205;
    Birdb=145;

    Wall1x=350;
    Wall1y=135;
    WallButton1=170;
    Wall2x=440;
    Wall2y=120;
    WallButton2=160;
    Wall3x=530;
    Wall3y=148;
    WallButton3=188;
    ScrollMode=0;
    ScrollUp=0;
    ScrollDown=0;
    ScrollStart=0;
    Scroll=0;

    WidthWall = 28;
    HeightWall = 101;
    LeftWall = 12;
    RightWall = 13;
    DeltaWall=30;
    SpeedLevel=0;
    SpeedCount=0;
    SpeedUp=0;
    ClrSwitch=0;

    Roadx=70;
    Roady=196;

    Cloudx=210;
    Cloudy=165;

    Start = 0;
    STOP = 0;
    SpeedWall=1;
    DelayWall=70;

    Delete=0;
    Draw=0;

    Up=10;
    Down=100;

    BreakTabMain=0;
    PlayZoom=0;
    TopZoom=0;

    seed1=100;
    seed2=50;
    seed3=90;

    Scores=0;
    Numberx=205;
    Numbery=100;

    PasteBackGround=0;

    LoadFinish=0;

    Menu=1;
    Restart=0;
    Pause=0;
    OverGame=0;
}

void ArtNumber()
{
    //Number 0:200,120,120,125
    SetColor(0,0);
    DrawRow2(200,205,120,126);
    SetColor(15,15);
    DrawRow2(201,204,121,125);
    SetColor(0,0);
    DrawRow2(202,203,122,124);
    //Number 1:
    SetColor(0,0);
    DrawRow2(213,215,120,126);
    SetColor(15,15);
    DrawRow2(214,214,121,125);
    SetColor(14,14);
    DrawRow2(210,212,120,126);
    //Number 2:
    SetColor(0,0);
    DrawRow2(220,225,120,126);
    SetColor(15,15);
    DrawRow2(221,224,121,125);
    SetColor(0,0);
    DrawLine3(221,223,122);
    DrawLine3(222,224,124);
    //Number 3:
    SetColor(0,0);
    DrawRow2(230,235,120,126);
    SetColor(15,15);
    DrawRow2(231,234,121,125);
    SetColor(0,0);
    SetColor(0,0);
    DrawLine3(231,233,122);
    DrawLine3(231,233,124);
    //Number 4:
    SetColor(0,0);
    DrawRow2(240,245,120,126);
    SetColor(14,14);
    DrawRow2(240,242,125,126);
    SetColor(15,15);
    DrawRow2(241,244,121,123);
    DrawRow2(244,244,121,125);
    SetColor(0,0);
    DrawRow2(242,243,121,122);
    //Number 5:
    SetColor(0,0);
    DrawRow2(250,255,120,126);
    SetColor(15,15);
    DrawRow2(251,254,121,125);
    SetColor(0,0);
    DrawLine3(252,254,122);
    DrawLine3(251,253,124);
    //Number 6:
    SetColor(0,0);
    DrawRow2(260,265,120,126);
    SetColor(15,15);
    DrawRow2(261,264,121,125);
    SetColor(0,0);
    DrawLine3(262,264,122);
    DrawLine3(262,263,124);
    //Number 7:
    SetColor(0,0);
    DrawRow2(270,275,120,122);
    DrawRow2(273,275,120,126);
    SetColor(15,15);
    DrawLine3(271,273,121);
    DrawRow2(274,274,121,125);
    SetColor(14,14);
    DrawRow2(270,272,123,126);
    //Number 8:
    SetColor(0,0);
    DrawRow2(280,285,120,126);
    SetColor(15,15);
    DrawRow2(281,284,121,125);
    SetColor(0,0);
    DrawLine3(282,283,122);
    DrawLine3(282,283,124);
    //Number 9:
    SetColor(0,0);
    DrawRow2(290,295,120,126);
    SetColor(15,15);
    DrawRow2(291,294,121,125);
    SetColor(0,0);
    DrawLine3(292,293,122);
    DrawLine3(291,293,124);

}
void DrawCoin()
{
    COORD sizebuffer[10];
    COORD buffercoord= {0,0};
    SMALL_RECT RegionRead[10];
    SMALL_RECT RegionWrite[10];
    CHAR_INFO buffer[10][42];

    int Pointx=200;
    int Pointy=120;

    int R;
    for(R=0; R<=9; R++)
    {
        sizebuffer[R].Y=7;
        sizebuffer[R].X=6;
        RegionRead[R].Left=Pointx;
        RegionRead[R].Top=Pointy;
        RegionRead[R].Right=Pointx+5;
        RegionRead[R].Bottom=Pointy+6;
        ReadConsoleOutputA(BaseConsole,buffer[R],sizebuffer[R],buffercoord,&RegionRead[R]);
        Pointx+=10;
    }

    int Number=0;
    if(Scores<10)
    {
        Pointx=460;
        Pointy=119;
        Number=Scores;
        RegionWrite[Number].Left=Pointx;
        RegionWrite[Number].Top=Pointy;
        RegionWrite[Number].Right=Pointx+5;
        RegionWrite[Number].Bottom=Pointy+6;

        WriteConsoleOutputA(BaseConsole,buffer[Number],sizebuffer[Number],buffercoord,&RegionWrite[Number]);

    }
    else if(Scores>=10)
    {
        Number=Scores%10;
        Pointx=460;
        Pointy=119;
        RegionWrite[Number].Left=Pointx;
        RegionWrite[Number].Top=Pointy;
        RegionWrite[Number].Right=Pointx+5;
        RegionWrite[Number].Bottom=Pointy+6;

        WriteConsoleOutputA(BaseConsole,buffer[Number],sizebuffer[Number],buffercoord,&RegionWrite[Number]);

        Number=Scores/10;
        Pointx=460-6;
        Pointy=119;
        RegionWrite[Number].Left=Pointx;
        RegionWrite[Number].Top=Pointy;
        RegionWrite[Number].Right=Pointx+5;
        RegionWrite[Number].Bottom=Pointy+6;

        WriteConsoleOutputA(BaseConsole,buffer[Number],sizebuffer[Number],buffercoord,&RegionWrite[Number]);

    }
}
void ArtLoading()
{
    DrawTable2(400,180,511,187,0,15);
    SetColor(7,7);
    DrawRow2(404,407,182,185);

    int Lx=404;
    int Ly;

    //Loading...
    Lx=436;
    Ly=190;
    //L
    SetColor(0,0);
    DrawRow2(Lx,Lx,Ly,Ly+4);
    DrawLine3(Lx,Lx+2,Ly+4);
    //O
    SetColor(0,0);
    DrawRow2(Lx+4,Lx+4,Ly+1,Ly+3);
    DrawRow2(Lx+7,Lx+7,Ly+1,Ly+3);
    DrawLine3(Lx+5,Lx+6,Ly);
    DrawLine3(Lx+5,Lx+6,Ly+4);
    //A
    SetColor(0,0);
    DrawRow2(Lx+9,Lx+9,Ly+1,Ly+4);
    DrawRow2(Lx+12,Lx+12,Ly+1,Ly+4);
    DrawLine3(Lx+10,Lx+11,Ly);
    DrawLine3(Lx+10,Lx+11,Ly+2);
    //D
    SetColor(0,0);
    DrawRow2(Lx+14,Lx+14,Ly,Ly+4);
    DrawRow2(Lx+17,Lx+17,Ly+1,Ly+3);
    DrawLine3(Lx+15,Lx+16,Ly);
    DrawLine3(Lx+15,Lx+16,Ly+4);
    //I
    SetColor(0,0);
    DrawRow2(Lx+20,Lx+20,Ly,Ly+4);
    DrawLine3(Lx+19,Lx+21,Ly);
    DrawLine3(Lx+19,Lx+21,Ly+4);
    //N
    SetColor(0,0);
    DrawRow2(Lx+23,Lx+23,Ly,Ly+4);
    DrawRow2(Lx+26,Lx+26,Ly,Ly+4);
    DrawPoint(Lx+24,Ly+1);
    DrawPoint(Lx+25,Ly+2);
    //G
    SetColor(0,0);
    DrawRow2(Lx+28,Lx+28,Ly+1,Ly+3);
    DrawRow2(Lx+31,Lx+31,Ly+2,Ly+3);
    DrawLine3(Lx+29,Lx+31,Ly);
    DrawLine3(Lx+29,Lx+30,Ly+4);
    DrawLine3(Lx+30,Lx+31,Ly+2);
    //.
    DrawPoint(Lx+33,Ly+4);
    DrawPoint(Lx+35,Ly+4);
    DrawPoint(Lx+37,Ly+4);

}
void* DrawLoading(void* arg)
{
    int Lx=159;
    int Ly=152;
    int Loadnumber=0;
    while(Loadnumber<=19)
    {
        if(LoadFinish)
        {
            Lx+=5;
            Loadnumber++;
            CopyPixelTo2(404,182,407,185,Lx,Ly,BaseConsole,Loadingdata);
            LoadFinish=0;
        }
    }
    return NULL;
}
void *CheckParameter(void* arg)
{
    char kytu='A';
    DWORD written;
    COORD toado;
    toado.X=150;
    toado.Y=150;
    SetConsoleCursorPosition(TabParameter,toado);
    WriteConsoleA(TabParameter,&kytu,1,&written,NULL);
    while(TRUE)
    {
        PrintParameter();
        CopyPixelTo(50,10,160,30,160,120,TabParameter);
        Delay(500);
    }

    return NULL;
}
void PrintParameter()
{
    SetColor(3,0);
    gotoxy(50,10);
    printf("MainTabEvent = %d",MainTabEvent);
    gotoxy(50,12);
    printf("NewConsoleTabEvent = %d",NewConsoleTabEvent);
    gotoxy(50,14);
    printf("x = %d",x);
    gotoxy(50,16);
    printf("y = %d",y);
    gotoxy(50,18);
    printf("mode = %d",mode);
    gotoxy(50,20);
    printf("Birda = %d",Birda);
    gotoxy(50,22);
    printf("Birdb = %d",Birdb);
    gotoxy(50,24);
    printf("DeltaY = %d",DeltaY);
    gotoxy(50,26);
    printf("MoveY = %d",MoveY);
    gotoxy(50,28);
    printf("key; = %d",key);
    gotoxy(50,30);
    printf("Scores = %d",Scores);
    gotoxy(80,10);
    printf("Wall1x = %d",Wall1x);
    gotoxy(80,12);
    printf("Wall1y; = %d",Wall1y);
    gotoxy(80,14);
    printf("WallButton1 = %d",WallButton1);
    gotoxy(80,16);
    printf("Wall2x = %d",Wall2x);
    gotoxy(80,18);
    printf("Wall2y = %d",Wall2y);
    gotoxy(80,20);
    printf("WallButton2; = %d",WallButton2);
    gotoxy(80,22);
    printf("Wall3x = %d",Wall3x);
    gotoxy(80,24);
    printf("Wall3y = %d",Wall3y);
    gotoxy(80,26);
    printf("WallButton3 = %d",WallButton3);
    gotoxy(80,28);
    printf("ScrollMode = %d",ScrollMode);
    gotoxy(80,30);
    printf("Start = %d",Start);
    gotoxy(110,10);
    printf("STOP = %d",STOP);
    gotoxy(110,12);
    printf("SpeedWall = %d",SpeedWall);
    gotoxy(110,14);
    printf("DelayWall = %d",DelayWall);
    gotoxy(110,16);
    printf("Up = %d",Up);
    gotoxy(110,18);
    printf("Down = %d",Down);
    gotoxy(110,20);
    printf("BreakTabMain = %d",BreakTabMain);
    gotoxy(110,22);
    printf("seed1 = %d",seed1);
    gotoxy(110,24);
    printf("seed2 = %d",seed2);
    gotoxy(110,26);
    printf("seed3 = %d",seed3);
    gotoxy(110,28);
    printf("Menu = %d",Menu);
    gotoxy(110,30);
    printf("Restart = %d",Restart);
    gotoxy(140,10);
    printf("Pause = %d",Pause);
    gotoxy(140,12);
    printf("OverGame = %d",OverGame);
}
void DelConsole(HANDLE console)
{
    int Color=3*16+3;
    COORD cusor;
    DWORD Write;
    cusor.X=50;
    cusor.Y=50;
    FillConsoleOutputCharacterA(console,' ',1000000,cusor,&Write);
    FillConsoleOutputAttribute(console,Color,1000000,cusor,&Write);
}
void ResetParameter()
{
    x=170;
    y=145;

    Switch1=1;
    Switch2=0;
    Switch3=0;

    Birda=205;
    Birdb=145;

    BirdUp=1;
    BirdDown=0;

    Wall1x=350;
    Wall1y=135;
    WallButton1=170;
    Wall2x=440;
    Wall2y=120;
    WallButton2=160;
    Wall3x=530;
    Wall3y=148;
    WallButton3=188;
    ScrollMode=0;
    ScrollUp=0;
    ScrollDown=0;
    ScrollStart=0;
    Scroll=0;

    WidthWall = 28;
    HeightWall = 101;
    LeftWall = 12;
    RightWall = 13;
    DeltaWall=30;
    SpeedLevel=0;
    SpeedCount=0;
    SpeedUp=0;
    ClrSwitch=0;

    Roadx=70;
    Roady=196;

    Cloudx=210;
    Cloudy=165;

    Start = 0;
    STOP = 0;
    SpeedWall=1;
    DelayWall=70;

    Delete=0;
    Draw=0;

    Up=90;
    Down=170;

    BreakTabMain=0;
    PlayZoom=0;
    TopZoom=0;

    seed1=100;
    seed2=50;
    seed3=90;

    Scores=0;
    Numberx=205;
    Numbery=100;

    PasteBackGround=0;

    LoadFinish=0;

    Menu=0;
    Restart=0;
    Pause=0;
    OverGame=0;

    MainTabEvent=0;
    NewConsoleTabEvent=0;


}
void BirdbMove()
{
    if(BirdUp)
    {
        Birdb--;
        if(Birdb<=141)
        {
            BirdUp=0;
            BirdDown=1;
        }
    }
    else if(BirdDown)
    {
        Birdb++;
        if(Birdb>=148)
        {
            BirdDown=0;
            BirdUp=1;
        }
    }
}
void SetFontSizeTab(HANDLE tab,int width,int height)
{
    CONSOLE_FONT_INFOEX font= {sizeof(font)};
    GetCurrentConsoleFontEx(tab,0,&font);
    wcscpy(font.FaceName,L"Terminal");
    font.dwFontSize.X=width;
    font.dwFontSize.Y=height;
    SetCurrentConsoleFontEx(tab,0,&font);
}
void SetTabEditMode(HANDLE tab,int Boolmode)
{
    tab=GetStdHandle(STD_INPUT_HANDLE);
    DWORD TabMode;
    GetConsoleMode(tab,&TabMode);
    if(!Boolmode)
        TabMode=ENABLE_EXTENDED_FLAGS;
    else
        TabMode=ENABLE_QUICK_EDIT_MODE;
    SetConsoleMode(tab,TabMode);
}
void SetColorConsole()
{
    CONSOLE_SCREEN_BUFFER_INFOEX Color= {sizeof(Color)};
    GetConsoleScreenBufferInfoEx(BaseConsole,&Color);
    Color.ColorTable[0]=RGB(12,12,12);
    Color.ColorTable[1]=RGB(204,255,255);
    Color.ColorTable[2]=RGB(102,204,0);
    Color.ColorTable[3]=RGB(0,213,255);
    Color.ColorTable[4]=RGB(178,255,102);
    Color.ColorTable[5]=RGB(153,255,51);
    Color.ColorTable[6]=RGB(255,198,9);
    Color.ColorTable[7]=RGB(0,153,0);
    Color.ColorTable[8]=RGB(128,255,0);
    Color.ColorTable[9]=RGB(204,255,153);
    Color.ColorTable[10]=RGB(128,128,128);
    Color.ColorTable[11]=RGB(204,0,0);
    Color.ColorTable[12]=RGB(255,128,0);
    Color.ColorTable[13]=RGB(224,224,224);
    Color.ColorTable[14]=RGB(255,229,204);
    Color.ColorTable[15]=RGB(242,242,242);

    SetConsoleScreenBufferInfoEx(BaseConsole,&Color);
}

void RGBChange()
{
    if(Count>=5)
        Count=1;
    switch(Count)
    {
    case 1:
        R=255;
        G=160;
        B=122;
        break;
    case 2:
        R=240;
        G=128;
        B=218;
        break;
    case 3:
        R=65;
        G=105;
        B=255;
        break;
    case 4:
        R=147;
        G=112;
        B=219;
        break;
    case 5:
        R=25;
        G=25;
        B=112;
        break;
    }
}


