    #pragma once
    #define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
    #define _WIN32_WINNT 0x0500 // so the code would compile
    #include <windows.h>
    
     
    int main(int argc, char* argv[]){
    INPUT *buffer = new INPUT[3]; //allocate a buffer
    buffer->type = INPUT_MOUSE;
    buffer->mi.dx = 100;
    buffer->mi.dy = 100;
    buffer->mi.mouseData = 0;
    buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);
    buffer->mi.time = 0;
    buffer->mi.dwExtraInfo = 0;
    (buffer+1)->type = INPUT_MOUSE;
    (buffer+1)->mi.dx = 100;
    (buffer+1)->mi.dy = 100;
    (buffer+1)->mi.mouseData = 0;
    (buffer+1)->mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    (buffer+1)->mi.time = 0;
    (buffer+1)->mi.dwExtraInfo = 0;
    (buffer+2)->type = INPUT_MOUSE;
    (buffer+2)->mi.dx = 100;
    (buffer+2)->mi.dy = 100;
    (buffer+2)->mi.mouseData = 0;
    (buffer+2)->mi.dwFlags = MOUSEEVENTF_LEFTUP;
    (buffer+2)->mi.time = 0;
    (buffer+2)->mi.dwExtraInfo = 0;
    SendInput(3,buffer,sizeof(INPUT));
    delete (buffer); //clean up our messes.
    return 0;
    }
