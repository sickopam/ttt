#include <iostream>
using namespace std;

char num[10] = {'.', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, mode;
int turn, r, temp;
string p1, p2;
void board();
int check();

void pvp()
{
	cout << "\nPlayer 1, enter your name: "; cin >> p1;
	cout << "Player 2, enter your name: "; cin >> p2;
	
	// deciding who goes first
	srand((unsigned int)time(NULL));
	turn = (rand() % 2) + 1;
	
	turns:
	
	// checks if there's a winner or not
	int w = check(); //recursive function
	if (w==1) {
		if (turn==2) {
			cout << "\n     " << p1 << " wins!" << endl;
			return;
		} else if (turn==1) {
			cout << "\n     " << p2 << " wins!" << endl;
			return;
		}
	} else if (w==0) {
		cout << "\n       Game draw!" << endl;
		return;
	}
	// player 1's turn
	if (turn==1) {
		cout << "\n\n\n\n\n\n";
		cout << "\n" << p1 << "'s turn [X], pick a square! "; cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (choice<1 || choice>9) {
			cout << "Beyond range (1-9), try again: "; cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		while (num[choice]=='X' || num[choice]=='O') {
			cout << "Square occupied, try again: "; cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			while (choice<1 || choice>9) {
				cout << "Beyond range (1-9), try again: "; cin >> choice;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		num[choice] = 'X';
		board();
		turn = 2;
		goto turns;
	// player 2's turn
	} else if (turn==2) {
		cout << "\n\n\n\n\n\n";
		cout << "\n" << p2 << "'s turn [O], pick a square! "; cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (choice<1 || choice>9) {
			cout << "Beyond range (1-9), try again: "; cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		while (num[choice]=='X' || num[choice]=='O') {
			cout << "Square occupied, try again: "; cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			while (choice<1 || choice>9) {
				cout << "Beyond range (1-9), try again: "; cin >> choice;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		num[choice] = 'O';
		board();
		turn = 1;
		goto turns;
	}
    
}

void pvc()
{
	// decides who goes first
	srand((unsigned int)time(NULL));
	turn = (rand() % 2) + 1;
	
	turns:
	
	// checking for winner
	int w = check();
	if (w==1) {
		if (turn==2) {
			cout << "\n       You win!" << endl;
			return;
		} else if (turn==1) {
			cout << "\n       You lose!" << endl;
			return;
		}
	} else if (w==0) {
		cout << "\n       Game draw!" << endl;
		return;
	}
	// player's turn
	if (turn==1) {
		cout << "\n\n\n\n\n\n";
		cout << "\nYour turn [X], pick a square! "; cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (choice<1 || choice>9) {
			cout << "Beyond range (1-9), try again: "; cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		while (num[choice]=='X' || num[choice]=='O') {
			cout << "Square occupied, try again: "; cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			while (choice<1 || choice>9) {
				cout << "Beyond range (1-9), try again: "; cin >> choice;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		num[choice] = 'X';
		board();
		turn = 2;
		goto turns;
	// computer's turn
	} else if (turn==2) {
		cout << "\n\n\n\n\n\n";
		cout << "\n   Computer's [O] turn! \n"; choice = (rand() % 9) + 1;
		while (num[choice]=='X' || num[choice]=='O') {
			choice = (rand() % 9) + 1;
		}
		num[choice] = 'O';
		board();
		turn = 1;
		goto turns;
	}
	
}

void board()
{	
	// game board
	cout << "       |       |       " << endl;
	cout << "   " << num[1] << "   |   " << num[2] << "   |   " << num[3] << endl;
	cout << "_______|_______|_______" << endl;
	cout << "       |       |       " << endl;
	cout << "   " << num[4] << "   |   " << num[5] << "   |   " << num[6] << endl;
	cout << "_______|_______|_______" << endl;
	cout << "       |       |       " << endl;
	cout << "   " << num[7] << "   |   " << num[8] << "   |   " << num[9] << endl;
	cout << "       |       |       " << endl;
	
}

int check()
{
	// all combinations of winning
    if (num[1] == num[2] && num[2] == num[3])

        return 1;
    else if (num[4] == num[5] && num[5] == num[6])

        return 1;
    else if (num[7] == num[8] && num[8] == num[9])

        return 1;
    else if (num[1] == num[4] && num[4] == num[7])

        return 1;
    else if (num[2] == num[5] && num[5] == num[8])

        return 1;
    else if (num[3] == num[6] && num[6] == num[9])

        return 1;
    else if (num[1] == num[5] && num[5] == num[9])

        return 1;
    else if (num[3] == num[5] && num[5] == num[7])

        return 1;
    else if (num[1] != '1' && num[2] != '2' && num[3] != '3' 
                    && num[4] != '4' && num[5] != '5' && num[6] != '6' 
                  && num[7] != '7' && num[8] != '8' && num[9] != '9')

        return 0;
    else
        return -1;
}

int main()
{
	cout << "\n\n\n====== TIC TAC TOE ======" << endl;
	board();
	cout << " 1. Player vs Computer \n 2. Player vs Player" << endl;
	cout << " Pick a mode: ";
	cin >> mode;
	cout << " " << endl;

	err: // wrong mode message 
	if (mode!=1 && mode!=2)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " Pick a correct mode: ";
		cin >> mode;
        goto err;
	}

	switch(mode)
	{
		case 1:
			pvc();
			break;
		case 2:
			pvp();
			break;
		default:
			goto err;
			break;
	}
	return 0;
}
