#ifndef __GAME_H__
#define __GAME_H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ROW 3
#define COL 3
void meau();/*�˵�����*/
void Playgame();/*Play��Ϸ����*/
void PrintBoard(char board[ROW][COL],int row, int col);/*��ӡ���̺���*/
void InitBoard(char board[ROW][COL], int row, int col);/*���̳�ʼ������*/
void PlayerMove(char board[ROW][COL]);/*������Ӻ���*/
void ComputerMove(char board[ROW][COL]);/*�������Ӻ���*/
void CheckWin(char board[ROW][COL], int row, int col);
#endif;