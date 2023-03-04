#include <iostream>
#include <conio.h>

// Tic tac toe
// by NextDev

void play(int& turn, int board[3][3])
{
    int player_turn;
    if(turn % 2 == 0)
        player_turn = 1;
    else
        player_turn = 2;

    std::cout << "Player " << player_turn << " turn" << std::endl;
    
    int move_x = 0;
    std::cin >> move_x;
    move_x--;

    int move_y = 0;
    std::cin >> move_y;
    move_y--;

    if(board[move_x][move_y] == -1)
    {
        board[move_x][move_y] = player_turn-1;
        turn++;
    }
    else std::cout << "Invalid move" << std::endl;
}

bool win_check_condition(const int board[3][3], const int& player)
{
    // 0 == player 0
    // 1 == player 1
    // -1 == blank

    //   0 1 2
    // 0 x|x|x
    // 1 x|x|x
    // 2 x|x|x

    bool win = false;

    win = board[0][0] == player && board[0][1] == player && board[0][2] == player;
    if(!win) win = board[1][0] == player && board[1][1] == player && board[1][2] == player;
    if(!win) win = board[2][0] == player && board[2][1] == player && board[2][2] == player;
    if(!win) win = board[2][0] == player && board[2][1] == player && board[1][1] == player;
    if(!win) win = board[0][0] == player && board[1][1] == player && board[2][2] == player;
    if(!win) win = board[0][2] == player && board[1][1] == player && board[2][0] == player;
    if(!win) win = board[0][0] == player && board[1][0] == player && board[2][0] == player;
    if(!win) win = board[0][1] == player && board[1][1] == player && board[2][1] == player;
    if(!win) win = board[0][2] == player && board[1][2] == player && board[2][2] == player;
    
    return win;
}

void draw_board(const int board[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int pos = board[i][j];
            const char* pos_str = "";
            switch (pos)
            {
                case -1:
                    pos_str = " ";
                    break;
                case 0:
                    pos_str = "O";
                    break;
                case 1:
                    pos_str = "X";
                    break;
                default: break;
            }
            
            if(j != 2)
                std::cout << pos_str << " | ";
            else std::cout << pos_str;
        }
        if(i != 2)  
            std::cout << std::endl << "--+---+--" << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Tic tac toe!" << std::endl;
    bool playing = true;
    /*
     * 0 = O
     * 1 = X
     * -1 = blank
     */
    int board[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
    int turn = 0;

    std::cout << "Here's how to play: " << std::endl << "Write a number between 1 and 9 and it will put your move\n" << std::endl << std::endl;

    while (playing){
        // Print the board
        draw_board(board);
        std::cout << std::endl;

        // Play the game
        play(turn, board);

        system("cls");

        for(int i = 0; i < 2; i++)
            if(win_check_condition(board, i))
            {
               draw_board(board);
                std::cout << "Player " << i << " won!" << std::endl;
                playing = false;
            }
    }

    std::cin >> turn;
    return NULL;
}
