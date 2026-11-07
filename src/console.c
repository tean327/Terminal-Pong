#include "../include/console.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include<stdlib.h>


static volatile sig_atomic_t g_quit = 0;

void HandleSigint(int sig) {
    (void)sig;
    g_quit = 1;
}

typedef struct termios TerminalSettings;

//Store the normal terminal settings
TerminalSettings oldt;
static int consoleReady = 0;


void PrepareConsole()
{
    if (consoleReady) return; 

    signal(SIGINT, HandleSigint);

    TerminalSettings newt;

    //Store the current terminal settings into oldt
    tcgetattr(STDIN_FILENO, &oldt);

    //Copy the oldt terminal settings in the new so that we keep all the settings we need but can still modifiy the others
    newt = oldt;

    newt.c_lflag &= ~(ECHO | ICANON);
    newt.c_cc[VMIN] = 0;
    newt.c_cc[VTIME] = 0;   
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    printf("\033[?25l");    // hide cursor
    
    consoleReady = 1;
    atexit(RemadeConsoleNormal);  // also restores on exit(1) and normal return
}

void RemadeConsoleNormal() 
{
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\033[?25h");    // show cursor
    consoleReady = 0;
}

int ShouldQuit(){return g_quit;}