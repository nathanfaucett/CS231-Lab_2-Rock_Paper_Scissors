#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Winner {
	CPU = 1,
	YOU,
	TIE
};

enum Weapon {
	ROCK = 1,
	PAPER,
	SCISSORS,
	BAD_WEAPON
};

Weapon get_your_weapon(char ch) {
	switch(ch) {
		case 'r':
		case 'R':
			return ROCK;
		case 'p':
		case 'P':
			return PAPER;
		case 's':
		case 'S':
			return SCISSORS;
		default:
			return BAD_WEAPON;
	} 
}

Weapon get_cpu_weapon() {
	switch(rand() % 3) {
		case 0:
			return ROCK;
		case 1:
			return PAPER;
		case 2:
			return SCISSORS;
	} 
}

string get_weapon_string(Weapon weapon) {
	switch(weapon) {
		case ROCK:
			return "Rock";
		case PAPER:
			return "Paper";
		case SCISSORS:
			return "Scissors";
		case BAD_WEAPON:
			return "Bad Weapon";
	} 
}

Winner get_winner(Weapon you, Weapon cpu) {
	if (you == cpu) {
		return TIE;
	} else if (you == ROCK) {
		if (cpu == PAPER) {
			return CPU;
		} else {
			return YOU;
		}
	} else if (you == PAPER) {
		if (cpu == SCISSORS) {
			return CPU;
		} else {
			return YOU;
		}
	} else if (you == SCISSORS) {
		if (cpu == ROCK) {
			return CPU;
		} else {
			return YOU;
		}
	} else {
		return CPU;
	}
}

void print_winner(Winner winner) {
	if (winner == TIE) {
		cout << "TIE: ";
	} else if (winner == YOU) {
		cout << "PLAYER WINS: ";
	} else { // if (winner == CPU) {
		cout << "COMPUTER WON: ";
	}
}

void print_rule(Weapon a, Weapon b) {
	if (a == ROCK) {
		cout << get_weapon_string(a) << " crushes " << get_weapon_string(b) << "\n";
	} else if (a == SCISSORS) {
		cout << get_weapon_string(a) << " cuts " << get_weapon_string(b) << "\n";
	} else {
		cout << get_weapon_string(a) << " wraps " << get_weapon_string(b) << "\n";
	} 
}

void print_rules(Winner winner, Weapon you, Weapon cpu) {
	if (winner == TIE) {
		cout << get_weapon_string(you) << " ties with " << get_weapon_string(cpu) << "\n";
	} else if (winner == YOU) {
		print_rule(you, cpu);
	} else { // winner == CPU
		print_rule(cpu, you);
	}
}

bool play_again(char ch) {
	return ch == 'Y' || ch == 'y';
}

int main(int argc, char** argv) {
	bool playing = true;

	srand(time(NULL));
	
	cout << 
		"WELCOME TO PAPER-ROCK-SCISSORS!\n" << 
		"\n" <<
		"This is a game for two players, which you will be playing\n" <<
		"against the computer.  With each game, both players will\n" <<
		"select one of the following weapons: PAPER, ROCK, or SCISSORS.\n" <<
		"The winner is determined as follows:\n" <<
		"\n" <<
		"* If both players select the same weapon, the game is a tie.\n" <<
		"* ROCK blunts SCISSORS, so the player who selects ROCK wins.\n" <<
		"* PAPER wraps ROCK, so the player who selects PAPER wins.\n" <<
		"* SCISSORS cuts PAPER, so the player who selects SCISSORS wins.\n" <<
		"\n" <<
		"With each turn, select 'R' for ROCK, 'P' for PAPER, or 'S' for\n" <<
		"SCISSORS, and then press ENTER.  You may quit at any time.\n";
	
	while (playing) {
		cout << "\nChoose Weapon ('R', 'P', or 'S'): ";
		char weapon_choice;
		cin >> weapon_choice;
		
		Weapon your_weapon = get_your_weapon(weapon_choice);
		Weapon cpu_weapon = get_cpu_weapon();
		
		Winner winner = get_winner(your_weapon, cpu_weapon);
		
		cout << "\nPlayer Picked: " + get_weapon_string(your_weapon) << "\n";
		cout << "Computer Picked: " + get_weapon_string(cpu_weapon) << "\n\n";
		
		print_winner(winner);
		print_rules(winner, your_weapon, cpu_weapon);
		
		cout << "\nPLAY AGAIN? ('Y' or 'N'): ";
		char play_again_choice;
		cin >> play_again_choice;
		playing = play_again(play_again_choice);
	}
	
	return 0;
}

