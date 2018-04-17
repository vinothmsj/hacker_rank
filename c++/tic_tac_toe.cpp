#include <iostream>

using namespace std;


char board[10] = {'0' ,'1' ,'2' ,'3' , '4' ,'5' , '6' , '7' , '8' , '9' };
void draw_board()
{

    
    cout << "Player 1 : x" << endl;
    cout << "Player 2 : o" << endl;
    
    cout << "     |     |     " << endl;
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << endl;

    cout << "-----|-----|-----  " << endl;
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << endl;

    cout << "-----|-----|-----  " << endl;
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << endl;
}
int check_winner()
{

	if (board[1] == board[2] && board[2] == board[3])

		return 1;
	else if (board[4] == board[5] && board[5] == board[6])

		return 1;
	else if (board[7] == board[8] && board[8] == board[9])

		return 1;
	else if (board[1] == board[4] && board[4] == board[7])

		return 1;
	else if (board[2] == board[5] && board[5] == board[8])

		return 1;
	else if (board[3] == board[6] && board[6] == board[9])

		return 1;
	else if (board[1] == board[5] && board[5] == board[9])

		return 1;
	else if (board[3] == board[5] && board[5] == board[7])

		return 1;
	else if (board[1] != '1' && board[2] != '2' && board[3] != '3' 
			&& board[4] != '4' && board[5] != '5' && board[6] != '6' 
			&& board[7] != '7' && board[8] != '8' && board[9] != '9')

		return 0;
	else 
		return -1;

}
int main()
{

    int counter = 0;
    int user_in = 0;
    int player = 0;
	int	game = -1;
    draw_board();

    do {
        player = (counter % 2 == 0)?1:2;

        cout << "Player" << player << " Enter a position : " ;
        cin >> user_in;
        if(user_in <= 0 || user_in > 9)
        {
			cout << "Invalid Position" << endl;
			continue;
		}
		if(board[user_in] == 'x' || board[user_in] == 'o')
		{

			cout << "Position already alloted ";
			continue;
		}
        if(player == 1)
        {
            board[user_in] = 'x';
        }
        else
        {

            board[user_in] = 'o';
        }
		game = check_winner();
		if(game >=0)
		{
			cout << "Player" << player << " wins!!" << endl;
			break;
		} 
		counter++; 
			
        draw_board();
    }while(counter <= 9);
    return 0;

};
