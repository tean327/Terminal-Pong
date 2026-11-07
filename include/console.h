#ifndef CONSOLE_H
#define CONSOLE_H

void HandleSigint(int sig);
void PrepareConsole();
void RemadeConsoleNormal();
int ShouldQuit();
#endif