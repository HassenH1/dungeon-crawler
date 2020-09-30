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


//Not working right now
bool winner(char (&board)[R][C]){
	bool resp = false;
	/*std::cout << "Does this function ever hit" << std::endl;
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 10; j++){
			if(board[i][j] == 'X'){
				std::cout << "row: " << i << std::endl;
				std::cout << "col: " << j << std::endl;
				std::cout << "whats in board: " << board[i][j] << std::endl;
			}
		}
	}
	return resp;*/
	
	if(board[6][9] == 'G'){
		std::cout << "=================================" << std::endl;
		std::cout << "Winner!" << std::endl;
		std::cout << "=================================" << std::endl;
		resp = true;
	}
	return resp;
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
					if(row+1 < 7){
						r = row;
						c = col;
						board[row][col] = '.';
						break;
					} else {
						std::cout << "What are you doing trying to leave?!?" 
							<< std::endl;
						break;
					} 
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
		draw_board(board);
		std::cout << "make your move:(L/R/U/D) ";
		std::cin >> input;
		win = winner(board);
		if(win){
			break;
		}
		// std::cout << std::string(50, '\n'); //clear screen illusion 
	} while(input != 'e');

	return 0;
}
