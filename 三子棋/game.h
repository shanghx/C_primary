#ifndef __GAME_H__
#define __GAME_H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ROW 3
#define COL 3
void meau();/*菜单函数*/
void Playgame();/*Play游戏函数*/
void PrintBoard(char board[ROW][COL],int row, int col);/*打印棋盘函数*/
void InitBoard(char board[ROW][COL], int row, int col);/*棋盘初始化函数*/
void PlayerMove(char board[ROW][COL]);/*玩家落子函数*/
void ComputerMove(char board[ROW][COL]);/*电脑落子函数*/
void CheckWin(char board[ROW][COL], int row, int col);
#endif;