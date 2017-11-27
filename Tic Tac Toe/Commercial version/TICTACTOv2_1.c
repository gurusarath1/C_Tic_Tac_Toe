#include<stdio.h>
#include<conio.h>
#define VER printf(" v2.1\n\n")
#define FLUSH while(getchar() != '\n')
#define BEEP printf("\a")

//tic tac to game v2.1 :)
//By T.Guru Sarath EC B

int printf_board(char board[3][3]);
int win_check(char board[3][3]);
int XOisOX(char board[3][3]);

int main()
{
int i,j,rowin,colin,X,count,win,PLAY_AGAIN,cheatR,cheatC;
char board[3][3],name[15],c;
FILE *fp;

system ("title Tic Tac Toe v2.1 (Programmed by T.Guru Sarath)");

do {

// Variable init

printf("\n>Initializing variables . . . . . . . . ");

X = 1;
count= 0;
win = 0;
PLAY_AGAIN = 0;

// initialising board
for(i=0 ; i<3 ; i++)
{
for(j=0 ; j<3 ; j++)
board[i][j] = '.';
}

// initial board print
CHEATER:
printf_board(board);

while(count < 9  && win == 0){


	if(X)printf("\n X's turn\n");
	else printf("\n O's turn\n");

//Input and TYPE check (to prevent non integer input)
	
	printf("\n Row ? - ");
	while(scanf("%d",&rowin) == 0)    {printf(">Invalid Input :(\n Row ? - "); FLUSH;BEEP;BEEP;BEEP;}
	
// CHEAT CODES ------------------------------------------------------------
	if(rowin == 4878)
	{
	system("cls");
	system ("title Tic Tac Toe v2.1 (Programmed by T.GURU SARATH) Source Code");
	fp = fopen("4878.guru","r");
	
	while((fscanf(fp,"%c",&c)) == 1)
	printf("%c",c);
	
	fclose(fp);	
	getch();
	return 0;
	}
	
	
	if(rowin == 1234)
	{
	system("cls");
	system ("title Tic Tac Toe v2.1 (Programmed by T.Guru Sarath) LIST");
	fp = fopen("1234.guru","r");
	
	while((fscanf(fp,"%c",&c)) == 1)
	printf("%c",c);
	
	fclose(fp);	
	getch();
	return 0;
	}
	
	if(rowin == 420)
	{
	system("cls");
	system ("title Tic Tac Toe v2.1 ****Not a Genuine Play****");
	printf("set R and C values - ");
	scanf("%d%d",&cheatR,&cheatC);
	board[cheatR][cheatC] = ((X==1)? 'X':'O');
	system("cls");
	goto CHEATER;
	}

	if(rowin == 10101)
	{
	system ("title Tic Tac Toe v2.1 ****Not a Genuine Play****");
	XOisOX(board);
	goto CHEATER;
	}
// CHEAT CODES END ------------------------------------------------------------


	
	FLUSH;

	printf(" Column ? - ");
	while(scanf("%d",&colin) == 0)    {printf(">Invalid Input :(\n Column ? - "); FLUSH;BEEP;BEEP;BEEP;}
	rowin-- ; colin-- ;

	FLUSH;


// Input Validity check (to prevent worng integer input)

if(board[rowin][colin] == '.')
{
	if(X)
	{ board[rowin][colin] = 'X'; X = 0; }
	else
	{ board[rowin][colin] = 'O'; X = 1; }

	count++;

}else{printf(" \n ********* Entry already taken :( *********");BEEP;BEEP;BEEP;getch();}




	//printf new board
	
	printf_board(board);

	BEEP;

//win check

win = win_check(board);



// while count
}

if(win == 1)
	printf("\n   X WINS !!!!    \a\a\a\a\a\a");
	
else if(win == 2)
	printf("\n   O WINS !!!!    \a\a\a\a\a\a");
else 
	printf("\n   Tie Match !!!!    \a\a");

getch();


if(win == 1 || win == 2)
{
	printf("\n\n\t Enter Your NAme -- ");
	scanf("%s",name);

	if((fp = fopen("tctato.guru","a")) == NULL) {printf("Cannot open file");}
	
	fprintf(fp,"%s  Won with %c \n",name,(win == 1)? 'X':'O');
	
	fclose(fp);
}


	system("cls");
	fp = fopen("tctato.guru","r");
	
	while((fscanf(fp,"%c",&c)) == 1)
	printf("%c",c);
	
	fclose(fp);







printf("\n\n\n\t Game programmed by T.Guru Sarath ECE - B 2nd Sem");


printf("\n\n\n        Play Again ??? 1(yes)/0(no)       > ");

while(scanf("%d",&PLAY_AGAIN) == 0){printf(">Invalid Input :(\n        Play Again ??? 1(yes)/0(no)       > "); FLUSH;BEEP;BEEP;BEEP;}

}

while (PLAY_AGAIN);







getch();
return 0;
}


// Board Print function

	int printf_board(char board[3][3]){

	int i,j;
	system("cls");
	printf("\t\t\t\t");
	printf("TIC TAC TOE %c",1); VER;
		for(i=0 ; i<3 ; i++)
			{	
				printf("\t\t\t\t  ");
				for(j=0 ; j<3 ; j++)
				printf(" %c ",board[i][j]);
				printf("\n\n");
			}

	}

// Win Check function

int win_check(char board[3][3]){

int i,j;

for(i = 0; i<3 ; i++)
{
if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') return(1);
else if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') return(2);
}

for(i = 0; i<3 ; i++)
{
if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') return(1);
else if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') return(2);
}

if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') return(1);
else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') return(2);

if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') return(1);
else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') return(2);

return 0;

}

//Cheater function XOisOX

int XOisOX(char board[3][3])
{
int i,j;

for(i=0;i<3;i++)
for(j=0;j<3;j++)
{
if(board[i][j] == 'X')board[i][j] = 'O';
else if(board[i][j] == 'O')board[i][j] = 'X';

}
return 0;


}










// Hare Krishna