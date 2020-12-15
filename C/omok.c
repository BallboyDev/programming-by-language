// ������� �ҽ��Դϴ�. �迭�� ���� �������� �����Ͽ���, ������ �迭�� �ּڰ��� Ŀ�� �迭(X, Y)�� �� ��ǩ���� �������Ѽ� Ŀ���� �����߽��ϴ�. ����ĭ ���̻����� ���̰� ���� �����ǰ� ���� �������� ������ �̴� �ּ�ó���� ���� ���ϴ� ������ �׸��� �Լ��� �����ν� ��缱���� �� �ֽ��ϴ�. ���� �̻��� ������ �¸��� �������� ������, 3-3������ ���� �������� ���߽��ϴ�.
// omok.c
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
?
#define UP 72
#define LEFT 75
#define DOWN 80
#define RIGHT 77
#define SPACE 32
#define ENTER 13
#define X 0
#define Y 1
?
#defineW_SIZE15// ������ ���� ������
#defineH_SIZE15// ������ ���� ������
?
char turn = 0, 
	bwin = 0, 
	wwin = 0;
int chk = 0;
int board[W_SIZE+2][H_SIZE+2] = {0};
int cursor[2] = {W_SIZE / 2, H_SIZE / 2};
?
voiddraw_board(void); // ����ĭ �׸��� �Լ�
voidwinchk(void); // �¸� ���� �Լ�
voidmove_cursor(void); // Ű �Է� - Ŀ�� �̵�
voidreset_quit(void); // Ű �Է� - Ŀ�� �̵�, �����, ����
voidclear_board(void); // �ʱ�ȭ
?
intmain(void)
{
	while(1)
	{
		if(chk == 1) clear_board(); 
		draw_board();
		winchk();
		if(bwin > 0 || wwin > 0) // ����
		{
			while(chk == 0)
			{
				cursor[X] = 99;
				draw_board();
				if(wwin == 99 && bwin == 99) printf("���� �ºΰ� ���� �ʾҽ��ϴ�.\n\n");
?
				elseif(turn == 1) printf("���� ���� �¸�! ��\n\n");
				elseprintf("���� ���� �¸�! ��\n\n");
				printf("��(�ٽ� ���� : r, R)\n��(���� ���� : q, Q)\n");
?
				reset_quit();
				if(chk > 0) break;
			}
			clear_board();
			draw_board();
		}
		if(chk == 2) break; // ���� �� �ݺ��� ������ Ż��
		chk = 0;

		if(turn == 0) printf("���� ���� ���� ��\n\n");
		elseprintf("���� ���� ���� ��\n\n");
		printf("��(�ٽ� ���� : r, R)\n��(���� ���� : q, Q)\n");
		move_cursor();
	}
	return0;
}
?
/* ĭ ���̿� ������ ���� ���� ĭ
void draw_board(void)
{
	int bx, by, i;
	system("cls");
	for(by = 1 ; by <= H_SIZE ; by++)
	{
		printf("��");
		for(bx = 1 ; bx <= W_SIZE ; bx++) 
		{
			if(cursor[X] == bx && cursor[Y] == by) // Ŀ�� ǥ��
			{
				if(by != 1 && by != H_SIZE)
				{
					switch(board[by][bx]) 
					{
						case 0 : 
							if(bx == 1) printf("��"); 
							else printf("����");	
							break;
						case 1 : 
							if(bx == 1) printf("��"); 
							else printf("����");
							break;
						case 2 : 
							if(bx == 1) printf("��"); 
							else printf("����");
							break;
					}	
				} else if(by == H_SIZE) {
					switch(board[by][bx]) 
					{
						case 0 : 
							if(bx == 1) printf("��"); 
							else printf("����");	
							break;
						case 1 : 
							if(bx == 1) printf("��"); 
							else printf("����");
							break;
						case 2 : 
							if(bx == 1) printf("��"); 
							else printf("����");
							break;
					}	
				} else {
					switch(board[by][bx]) 
					{
						case 0 : 
							if(bx == 1) printf("��"); 
							else printf("����");	
							break;
						case 1 : 
							if(bx == 1) printf("��"); 
							else printf("����");
							break;
						case 2 : 
							if(bx == 1) printf("��"); 
							else printf("����");
							break;
					}	
				}
			} else {
				if(by != 1 && by != H_SIZE)
				{
					switch(board[by][bx]) // ����� ǥ��
					{
						case 0 : 
							if(bx == 1) printf("��"); 
							else if(bx == W_SIZE)  printf("����"); 
							else printf("����");	
							break;
						case 1 : 
							if(bx == 1) printf("��"); 
							else printf("����");
							break;
						case 2 : 
							if(bx == 1) printf("��"); 
							else printf("����");
							break;
					}
				} else if(by == H_SIZE) {
					switch(board[by][bx])
					{
						case 0 : 
							if(bx == 1) printf("��");
							else if(bx == W_SIZE)  printf("����"); 
							else printf("����");	
							break;
						case 1 : 
							if(bx == 1) printf("��"); 
							else printf("����");
							break;
						case 2 : 
							if(bx == 1) printf("��"); 
							else printf("����");
							break;
					}
				} else {
					switch(board[by][bx])
					{
						case 0 : 
							if(bx == 1) printf("��"); 
							else if(bx == W_SIZE)  printf("����"); 
							else printf("����");	
							break;
						case 1 : 
							if(bx == 1) printf("��"); 
							else printf("����");
							break;
						case 2 : 
							if(bx == 1) printf("��"); 
							else printf("����");
							break;
					}
				}
			}
		}
		printf("\n");
		if(by != H_SIZE) 
		{
			printf("����");
			for(i = 0 ; i < W_SIZE-2 ; i++) printf("����");
			printf("����\n");
		}
	}
}
*/
?
/* ĭ ������ ������ ���� ������ */
voiddraw_board(void)
{
	int bx, by, i;
?
	system("cls");
	for(by = 1 ; by <= H_SIZE ; by++)
	{
		printf("��");
		for(bx = 1 ; bx <= W_SIZE ; bx++) 
		{
			if(cursor[X] == bx && cursor[Y] == by) // Ŀ�� ǥ��
			{
				if(by != 1 && by != H_SIZE)
				{
					switch(board[by][bx]) 
					{
						case0 : 
							printf("��");	
							break;
						case1 : 
							printf("��"); 
							break;
						case2 : 
							printf("��");
							break;
					}	
				} elseif(by == H_SIZE) {
					switch(board[by][bx]) 
					{
						case0 : 
							printf("��");	
							break;
						case1 : 
							printf("��");
							break;
						case2 : 
							printf("��");
							break;
					}	
				} else {
					switch(board[by][bx]) 
					{
						case0 : 
							printf("��"); 
							break;
						case1 : 
							printf("��"); 
							break;
						case2 : 
							printf("��"); 
							break;
					}	
				}
			} else {
				if(by != 1 && by != H_SIZE)
				{
					switch(board[by][bx]) // ����� ǥ��
					{
						case0 : 
							if(bx == 1) printf("��"); 
							elseif(bx == W_SIZE)  printf("��"); 
							elseprintf("��");	
							break;
						case1 : 
							printf("��"); 
							break;
						case2 : 
							printf("��"); 
							break;
					}
				} elseif(by == H_SIZE) {
					switch(board[by][bx])
					{
						case0 : 
							if(bx == 1) printf("��");
							elseif(bx == W_SIZE)  printf("��"); 
							elseprintf("��");	
							break;
						case1 : 
							printf("��");
							break;
						case2 : 
							printf("��");
							break;
					}
				} else {
					switch(board[by][bx])
					{
						case0 : 
							if(bx == 1) printf("��"); 
							elseif(bx == W_SIZE)  printf("��"); 
							elseprintf("��");	
							break;
						case1 : 
							printf("��");
							break;
						case2 : 
							printf("��");
							break;
					}
				}
			}
		}
		printf("\n");
	}
}
//*/
?
voidwinchk(void)
{
	int fullcount = 0;
	int i, j;
?
	bwin = 0;
	wwin = 0;
?
	for(j = 1 ; j < H_SIZE+1 ; j++) // ������ ����
	{
		for(i = 1 ; i < W_SIZE+1 ; i++)
		{
			if(board[j][i] != 0) fullcount++;
		}
	}
?
	if(fullcount == W_SIZE * H_SIZE) 
	{
		bwin = 99;
		wwin = 99;
	}
?
	for(j = 1 ; j < H_SIZE+1 ; j++) // �� ��� ����
	{
		for(i = 1 ; i < W_SIZE-3 ; i++)
		{
			if(board[j][i] == 1
			&& board[j][i+1] == 1
			&& board[j][i+2] == 1
			&& board[j][i+3] == 1
			&& board[j][i+4] == 1
?
			&& board[j][i-1] != 1
			&& board[j][i+5] != 1) bwin = 1;
?
			elseif(board[j][i] == 2
				 && board[j][i+1] == 2
				 && board[j][i+2] == 2
				 && board[j][i+3] == 2
				 && board[j][i+4] == 2
?
				 && board[j][i-1] != 2
				 && board[j][i+5] != 2) wwin = 1;
		}
	}
?
	for(i = 1 ; i < W_SIZE+1 ; i++) // �� ��� ����
	{
		for(j = 1 ; j < H_SIZE-3 ; j++)
		{
			if(board[j][i] == 1
			&& board[j+1][i] == 1
			&& board[j+2][i] == 1
			&& board[j+3][i] == 1
			&& board[j+4][i] == 1
?
			&& board[j-1][i] != 1
			&& board[j+5][i] != 1) bwin = 1;
?
			elseif(board[j][i] == 2
				 && board[j+1][i] == 2
				 && board[j+2][i] == 2
				 && board[j+3][i] == 2
				 && board[j+4][i] == 2
?
				 && board[j-1][i] != 2
				 && board[j+5][i] != 2) wwin = 1;
		}
	}
?
	for(j = 1 ; j < H_SIZE-3 ; j++) // �� ��� ����
	{
		for(i = 1 ; i < W_SIZE-3 ; i++)
		{
			if(board[j][i] == 1
			&& board[j+1][i+1] == 1
			&& board[j+2][i+2] == 1
			&& board[j+3][i+3] == 1
			&& board[j+4][i+4] == 1
?
			&& board[j-1][i-1] != 1
			&& board[j+5][i+5] != 1) bwin = 1;
?
			elseif(board[j][i] == 2
				 && board[j+1][i+1] == 2
				 && board[j+2][i+2] == 2
				 && board[j+3][i+3] == 2
				 && board[j+4][i+4] == 2
?
				 && board[j-1][i-1] != 2
				 && board[j+5][i+5] != 2) wwin = 1;
		}
	}
?
	for(i = 1 ; i < W_SIZE-3 ; i++) // / ��� ����
	{
		for(j = 5 ; j < H_SIZE+1 ; j++)
		{
			if(board[j][i] == 1
			&& board[j-1][i+1] == 1
			&& board[j-2][i+2] == 1
			&& board[j-3][i+3] == 1
			&& board[j-4][i+4] == 1
?
			&& board[j-5][i+5] != 1
			&& board[j+1][i-1] != 1) bwin = 1;
?
			elseif(board[j][i] == 2
				 && board[j-1][i+1] == 2
				 && board[j-2][i+2] == 2
				 && board[j-3][i+3] == 2
				 && board[j-4][i+4] == 2
?
				 && board[j-5][i+5] != 2
				 && board[j+1][i-1] != 2) wwin = 1;
		}
	}
}
?
voidmove_cursor(void)
{
	char ch;
?
	ch = getch();
	switch(ch) // ȭ��ǥŰ �ν�
	{
	case UP : // ��
		if(cursor[Y] != 1) cursor[Y]--;
		else cursor[Y] = H_SIZE;
		break;
	case LEFT : // ��
		if(cursor[X] != 1) cursor[X]--;
		else cursor[X] = W_SIZE;
		break;
	case RIGHT : // ��
		if(cursor[X] != W_SIZE) cursor[X]++;
		else cursor[X] = 1;
		break;
	case DOWN : // ��			
		if(cursor[Y] != H_SIZE) cursor[Y]++;
		else cursor[Y] = 1;
		break;
	case ENTER :
		if(turn == 0 && board[cursor[Y]][cursor[X]] == 0) 
		{
			board[cursor[Y]][cursor[X]] = 1;
			turn = 1;
		}
		elseif(turn == 1 && board[cursor[Y]][cursor[X]] == 0) 
		{
			board[cursor[Y]][cursor[X]] = 2;
			turn = 0;
		}
		break;
	case SPACE :
		if(turn == 0 && board[cursor[Y]][cursor[X]] == 0) 
		{
			board[cursor[Y]][cursor[X]] = 1;
			turn = 1;
		}
		elseif(turn == 1 && board[cursor[Y]][cursor[X]] == 0)
		{
			board[cursor[Y]][cursor[X]] = 2;
			turn = 0;
		}
		break;
	case'r':
		chk = 1;
		break;	
	case'R':
		chk = 1;
		break;
	case'q' :
		chk = 2;
		break;
	case'Q' :
		chk = 2;
		break;
	default :
		chk = 0;
		break;
	}
}
?
voidreset_quit(void)
{
	char ch;
?
	ch = getch();
	switch(ch) // �����, ���� ����
	{
	case'r':
		chk = 1;
		break;	
	case'R':
		chk = 1;
		break;
	case'q' :
		chk = 2;
		break;
	case'Q' :
		chk = 2;
		break;
	default :
		chk = 0;
		break;
	}
}
?
voidclear_board(void)
{
	int i, j;
?
	turn = 0;
	wwin = 0;
	bwin = 0;
	cursor[X] = W_SIZE / 2;
	cursor[Y] = H_SIZE / 2;
	for(i = 1 ; i < W_SIZE ; i++) 
	{
		for(j = 1 ; j < H_SIZE ; j++) board[j][i] = 0;
	}
}