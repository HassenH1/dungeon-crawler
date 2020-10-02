#include <iostream>
#include <string>

const int R = 7; 
const int C = 10;

void draw_board(char (&board)[R][C]){
    for(auto row = 0; row < 7; row++){
        for(auto col = 0; col < 10; col++){
            std::cout << board[row][col];
        }
        std::cout << std::endl;
    }
}

// TODO: write enemies into the program


bool winner(char (&board)[R][C], bool &win){
    for(int row = 0; row < 7; row++){
        for(int col = 0; col < 10; col++){
            if(board[row][col] == 'G' && row == 6 && col == 9){
                win = true;
            }
        }
    }
    return win;
}

void find_player_g(char (&board)[R][C],char input){
    int r{};
    int c{};
    for(auto row = 0; row < 7; row++){
        for(auto col = 0; col < 10; col++){
            if(board[row][col] == 'G'){
                if(input == 'r'){
                    if(col+1 < 10){
                        board[row][col+1] = 'G';
                        board[row][col] = '.';
                        break;
                    } else {
                        std::cout << "What are you doing trying to leave?!?" 
                            << std::endl;
                    }
                } 
                if(input == 'l'){
                    if(col-1 > -1){
                        board[row][col-1] = 'G';
                        board[row][col] = '.';
                        break;
                    } else {
                        std::cout << "What are you doing trying to leave?!?" 
                            << std::endl;
                    }
                }
                if(input == 'd'){
                    if(row+1 <= 6){
                        r = row;
                        c = col;
                        board[row][col] = '.';
                        break;
                    }
                }
                if(input == 'u'){
                    if(row-1 >= 0){
                        r = row;
                        c = col;
                        board[row][col] = '.';
                        break;
                    }
                }
            } 
        }
    }
    if(input == 'd'){
        if(r+1 <= 6){
            std::cout << "hitting this again??" << std::endl;
            board[r+1][c] = 'G';
        } else {
            std::cout << "Where you trying to go?!?" << std::endl;
        }
    }
    if(input == 'u'){
        if(r-1 >= 0){
            board[r-1][c] = 'G';
        } else { 
            std::cout << "Where you trying to go?!?" << std::endl;
        }
    }
}

void update_board(char input, char (&board)[R][C]){
    switch(input){
        case 'l':
            find_player_g(board, input);
            break;
        case 'r':
            find_player_g(board, input);
            break;
        case 'u':
            find_player_g(board, input);
            break;
        case 'd':
            find_player_g(board, input);
            break;
        default: 
            std::cout << "must pick from the letters L/R/U/D or press e to exit" 
                << std::endl;
            break;
    }
}

int main() {
    char board[R][C] = {
        {'G', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'X'},
    };

    char input{};
    bool win = false;
    do{
        update_board(input, board);
        win = winner(board, win);

        draw_board(board);
        if(win){
            std::cout << "WINNER!!" << std::endl;
            break;
        }

        std::cout << "make your move or press e to Exit:(L/R/U/D) ";
        std::cin >> input;
    } while(input != 'e');

    return 0;
}
