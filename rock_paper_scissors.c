#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "rock_paper_scissors.h"

int main(void)
{
	int moves[2];
	pipe(moves);
	int player2;
	int player2_move;
	int player1_move;
	int result;

	player2 = fork();

	if (player2 == 0)
		{
			srand(time(0));
			player2_move = rand() % 3;
			close(moves[0]);
			write(moves[1], &player2_move, sizeof(int));
			close(moves[1]);	
		}
	else
		{
			wait((void *)0);
			srand(time(0));
			rand(); //we have to run this rand() else the values of the child and parent will be the same
			player1_move = rand() % 3;
			close(moves[1]);
			read(moves[0], &player2_move, sizeof(int));
			close(moves[0]);
			switch (player1_move)
			{
			case 0:
				write(1, "Player1 played rock\n", 21);
				break;
			case 1:
				write(1, "Player1 played paper\n", 22);
				break;
			case 2:
				write(1, "Player1 played scissor\n", 24);
				break;
			default:
				break;
			}
			switch (player2_move)
			{
			case 0:
				write(1, "Player2 played rock\n", 21);
				break;
			case 1:
				write(1, "Player2 played paper\n", 22);
				break;
			case 2:
				write(1, "Player2 played scissor\n", 24);
				break;
			default:
				break;
			}
			result = player1_move - player2_move;
			if ( result  == -1 )
				write(1, "Player2 won!\n", 14);
			else if ( result  == 0 )
				write(1, "It was a tie...\n", 17);
			else 
				write(1, "Player1 won!\n", 14);
		}
	return 0;
}
