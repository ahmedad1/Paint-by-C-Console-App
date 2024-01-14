#include <iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;
COORD c ={0,0};
void gotoxy(float x ,float y){
c.X=x;
c.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void fileF(){
ofstream file ;
file.open("Help.txt");
file<<"*Press The Space Bar To Enable The Pen To Drawing Stars\n*Press Left Click To Draw Stars\n*To Enable The Colors Without Stars You Should Make The Erase And The Stars Off\nR: Red Stars \nG: Green Stars\nB: Blue Stars\nW: White Stars\nP: Purple Stars\nY: Yellow Stars\nL: Light Blue Stars\nI: Gray Stars\nD: Eraser (PRESS D TO TURN ON THE ERASE AND AFTER FINISHING PRESS D TO TURN OFF IT\nDelete: Delete All Painted\nNUM 0 : RED ONLY\nNUM 1 : GREEN ONLY\nNUM 2 : YELLOW ONLY\nNUM 3 : LIGHT BLUE ONLY\nNUM 4 : PURBLE ONLY\nNUM 5 : BLUE ONLY\nNUM 6 : WHITE ONLY\nNUM 7 : GRAY ONLY\n ";

}

int main(){

   RECT r;
  POINT q;

keybd_event(VK_LWIN,0,0,0);
keybd_event(VK_UP,0,0,0);
keybd_event(VK_UP,0,KEYEVENTF_KEYUP,0);
keybd_event(VK_LWIN,0,KEYEVENTF_KEYUP,0);
Sleep (1);

POINT p ;

while (1){
if ((GetKeyState(0x44))){

        gotoxy(1,1);

    cout<< "ERASE : ON ";

}
else {gotoxy(1,1);
cout<< "ERASE : OFF   ";}
if(GetKeyState(VK_SPACE)&&(!GetKeyState(0x44))){
gotoxy(1,2);
cout<< "STARS : ON ";
}
    else {gotoxy(1,2);
cout<< "STARS : OFF";

}
if (GetKeyState(VK_SPACE)||GetKeyState(0x44)){
    gotoxy(1,3);
    cout<< "COLOR WITHOUT STARS : NOT ALLOWED TO ENABLE";
}
else  {gotoxy(1,3);
cout<< "COLOR WITHOUT STARS : ALLOWED TO ENABLE       ";}
gotoxy(1,4);
cout<< "PRESS H FOR HELP";
if(GetAsyncKeyState(0x48)){
    SwapMouseButton(0);
    fileF();
    system("call Help.txt");
}
    GetWindowRect(GetConsoleWindow(),&r);
    GetCursorPos(&q);
    if((q.x<=r.right-32&&q.x>=r.left+1)&&(q.y>=r.top+30&&q.y<=r.bottom-1)){
SwapMouseButton(1);
mouse_event(MOUSEEVENTF_WHEEL,0,0,50,0);
}
else {

        SwapMouseButton(0);

}

GetCursorPos(&p);
c.X=p.x/8;
c.Y=p.y/16-1.5;
gotoxy(c.X,c.Y);
if (GetAsyncKeyState(VK_LBUTTON)&&!(q.y<=r.top+30)&&!(q.x>=r.right-32)){

    if(!GetKeyState(0x44)){
            if(GetKeyState(VK_SPACE)){
cout << "*";
}
else cout << "    ";
}

else {
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
cout << "    ";

}

}

if(GetAsyncKeyState(0x52))
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
else if(GetAsyncKeyState(0x47))
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
else if(GetAsyncKeyState(0x42))
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
else if(GetAsyncKeyState(0x57))
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
     else if (GetAsyncKeyState(0x50))
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE);//purple
else if (GetAsyncKeyState(0x59)){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);}//yellow
else if (GetAsyncKeyState(0x4c)){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN);//light blue
}
else if (GetAsyncKeyState(0x49))
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
    else if (GetAsyncKeyState(VK_NUMPAD0)&&(!GetKeyState(VK_SPACE)))
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),70);//red
else if (GetAsyncKeyState(VK_NUMPAD1)&&(!GetKeyState(VK_SPACE)))
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),35);//green
else if (GetAsyncKeyState(VK_NUMPAD2)&&(!GetKeyState(VK_SPACE)))
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),100);//yellow
else if (GetAsyncKeyState(VK_NUMPAD3)&&(!GetKeyState(VK_SPACE)))
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),50);//light blue
else if (GetAsyncKeyState(VK_NUMPAD4)&&(!GetKeyState(VK_SPACE)))
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),80);//purble
else if (GetAsyncKeyState(VK_NUMPAD5)&&(!GetKeyState(VK_SPACE)))
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),20);//blue
else if (GetAsyncKeyState(VK_NUMPAD6)&&(!GetKeyState(VK_SPACE)))
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);//white
else if (GetAsyncKeyState(VK_NUMPAD7)&&(!GetKeyState(VK_SPACE)))
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),130);//gray
else if (GetAsyncKeyState(VK_DELETE)){
    system("cls");
    system ("color 7");

}

}

}
