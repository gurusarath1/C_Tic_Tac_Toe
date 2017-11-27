#include<stdio.h>
#include<conio.h>

//tic tac to game v1.0
//By T.Guru Sarath EC B

int main()
{
int i,j,rowin,colin,X=1,count=0,win = 0;
char board[3][3],name[15];

PlayAgain:



// initialising board
for(i=0 ; i<3 ; i++)
{
for(j=0 ; j<3 ; j++)
board[i][j] = '.';
}

// initial board print
printf("\nTIC TAC TO \n\n");
for(i=0 ; i<3 ; i++)
{
for(j=0 ; j<3 ; j++)
printf(" %c ",board[i][j]);
printf("\n\n");
}

while(count < 9  && win == 0){


	if(X)printf("\n X's turn\n");
	else printf("\n O's turn\n");

//Input

	printf("\nRow ? - ");
	scanf("%d",&rowin);
	printf("Column ? - ");
	scanf("%d",&colin);
	rowin-- ; colin-- ;


// Input Validity check

if(board[rowin][colin] == '.')
{
	if(X)
	{ board[rowin][colin] = 'X'; X = 0; }
	else
	{ board[rowin][colin] = 'O'; X = 1; }

	count++;

}else{printf(" \n ********* Entry already taken :( *********\a\a\a");getch();}




	//printf new board
	system("cls");
	printf("\nTIC TAC TO \n\n");
	for(i=0 ; i<3 ; i++)
	{
		for(j=0 ; j<3 ; j++)
		printf(" %c ",board[i][j]);
	 printf("\n\n");
	}

	printf("\a");

//win check
for(i = 0; i<3 && win == 0 ; i++)
{
if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') win = 1;
else if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') win = 2;
}

for(i = 0; i<3 && win == 0 ; i++)
{
if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') win = 1;
else if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') win = 2;
}

if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') win = 1;
else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') win = 2;

if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') win = 1;
else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') win = 2;






// while count
}

if(win == 1)
	printf("\n   X WINS !!!!    \a\a\a\a\a\a");
	
else if(win == 2)
	printf("\n   O WINS !!!!    \a\a\a\a\a\a");
else 
	printf("\n   Tie Match !!!!    ");





printf("\n\n\n\t Game programmed by T.Guru Sarath ECE - B 2nd Sem");

getch();
return 0;
}

// Hare Krishna