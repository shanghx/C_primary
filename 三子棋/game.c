#define _CRT_SECURE_NO_DEPRECATE 1
#include"game.h"
int is_full(char board[ROW][COL]);
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int count = 0;
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j == col-1)
			{
				printf(" %c \n", board[i][j]); 
			}
			else printf(" %c |", board[i][j]);
		}
		for (j = 0; j < col; j++)
		{
			if (j == col-1)printf("---\n");
			else
				printf("---|");
		}
	}
	printf("\n");
}
void meau()
{
	int input= 0;
	printf("                         *********************************\n");
	printf("                         *** 1.Play            0.Exit  ***\n");
	printf("                         *********************************\n");
	printf("请选择:>");
	scanf("%d", &input);
	do
	{
		switch (input)
		{
		case 1:printf("游戏开始\n\n"); Playgame(); printf("\n继续游戏？(1.YES   0.NO)\n"); scanf("%d", &input); system("cls");
			break;
		case 0:
			break;
		default:printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}
void InitBoard(char board[ROW][COL], int row, int col)
{
	/*int i = 0, j = 0;
	for (i = 0; i < row ;i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}*/
	memset(board, ' ', row*col * sizeof(char));
}
int is_full(char board[ROW][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}return 1;
}
void PlayerMove(char board[ROW][COL])
{
	int i = 0,j = 0;
	printf("玩家走:>");
	while (1)
	{
		scanf("%d%d", &i, &j);
		printf("\n");
		if ((board[i-1][j-1]==' '&&(i<=ROW&&i>=1)&&(j<=COL&&j>=1)))
		{
			board[i-1][j-1] = 'O'; break;
		}
		else
		printf("非法输入,请重新输入-->");
	}	
}
void ComputerMove(char board[ROW][COL])
{
	
	int i = 0,j=0;
	printf("电脑走:>");
	srand((unsigned)time(NULL));
	while (1)
	{
		i = rand() % 3;
		j = rand() % 3; 
		if (board[i][j] ==  ' ')//if ((board[i][j] != ' O') && (board[i][j] != ' X'))
		{
			board[i][j] = 'X'; break;
		}		
	}printf("%d %d\n", i + 1, j + 1);
}
char CheckWin(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	char x='F',y='E';
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]&& board[i][2]!=' ')
			return  board[i][0];
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j]&& board[2][j]!=' ')
			return  board[0][j];
	}
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]&& board[2][2]!=' ') || (board[0][2] == board[1][1] && board[1][1] == board[2][0]) && board[2][0] != ' ')
		return board[1][1];
	else if(is_full(board) == 1)return x;
	else return y;
	
}

void Playgame()
{
	char board[ROW][COL] = { 0 };
	InitBoard( board,  ROW, COL);
	PrintBoard( board,  ROW, COL);
	char ret = 0;
	while(1)
	{
		PlayerMove(board);
		PrintBoard(board, ROW, COL);
		ret = CheckWin(board, ROW, COL); 
		if (ret!= 'E')
		{
			break;
		}
		ComputerMove(board);
		PrintBoard(board, ROW, COL);
		ret=CheckWin(board, ROW, COL);  
		if (ret!= 'E')
		{
			break;
		}
	}
		if (ret == 'O')
		{
			printf("玩家赢\n"); 
		}
		else if (ret == 'X')
		{
			printf("电脑赢\n"); 
		}else
		printf("平局\n");
		
}