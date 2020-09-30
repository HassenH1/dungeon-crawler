#include <iostream>

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

void find_player_g(char (&board)[R][C],char input){
    int r{};
    int c{};
    for(auto row = 0; row < 7; row++){
        for(auto col = 0; col < 10; col++){
            if(board[row][col] == 'G'){
                std::cout << "found the player on row: " << row << " and col: " 
                    << col << std::endl;
                if(input == 'r'){
                    if(col+1 < 10){
                        board[row][col+1] = 'G';
                        board[row][col] = '.';
                        break;
                    } else {
                        std::cout << "What are you doing trying to leave?!?" << std::endl;
                    }
                } 
                if(input == 'l'){
                    if(col-1 > -1){
                        board[row][col-1] = 'G';
                        board[row][col] = '.';
                        break;
                    } else {
                        std::cout << "What are you doing trying to leave?!?" << std::endl;
                    }
                }
                if(input == 'd'){
                    r = row;
                    c = col;
                    board[row][col] = '.';
                    break;
                }
                if(input == 'u'){
                    r = row;
                    c = col;
                    board[row][col] = '.';
                    break;
                }
            } 
        }
    }
    if(input == 'd'){
        board[r+1][c] = 'G';
    }
    if(input == 'u'){
        board[r-1][c] = 'G';
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
            std::cout << "must pick from the letters L/R/U/D or press e to exit" << std::endl;
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

    do{
        update_board(input, board);
        draw_board(board);
        std::cout << "make your move:(L/R/U/D) ";
        std::cin >> input;
    } while(input != 'e');

    return 0;
}
