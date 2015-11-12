We have recently been discussing control statements, input/output, and functions in C++.  In this assignment, you will be using all of these to write a simple program which implements the classic game of "Rock, Paper, Scissors."  For those unfamiliar with the game: two players (yourself and the computer, in this case) choose at random from among three "weapons": a piece of paper, a rock, and a pair of scissors.  Both players present their weapons, and depending on the weapons selected, one player is declared a winner, or else the game is declared a draw:

If both players select the same weapon, the game is a tie.
ROCK blunts SCISSORS, so the player who selects ROCK wins.
PAPER wraps ROCK, so the player who selects PAPER wins.
SCISSORS cuts PAPER, so the player who selects SCISSORS wins.
Your version of this game should select one of the three weapons at random (this is the computer's weapon), and then prompt the player to select his or her weapon by entering either "P", "R", or "S" at the console.  The game should then compare weapons, determine the winner (if any), and print the outcome to the screen.  The outcome should indicate which player is the winner, and should also explain why the winner was chosen (see the rules outlined above and the sample output for examples).

Your program should use an enumeration called Weapon to define the numeric values corresponding to each of the three weapon choices.  You might also find it useful to write a "helper function" which converts each Weapon value into the corresponding weapon name (a string value), to make them more convenient to print to the screen.

Your output should resemble the following:
```bash
WELCOME TO PAPER-ROCK-SCISSORS!

This is a game for two players, which you will be playing
against the computer.  With each game, both players will
select one of the following weapons: PAPER, ROCK, or SCISSORS.
The winner is determined as follows:

* If both players select the same weapon, the game is a tie.
* ROCK blunts SCISSORS, so the player who selects ROCK wins.
* PAPER wraps ROCK, so the player who selects PAPER wins.
* SCISSORS cuts PAPER, so the player who selects SCISSORS wins.

With each turn, select 'R' for ROCK, 'P' for PAPER, or 'S' for
SCISSORS, and then press ENTER.  You may quit at any time.

Choose Weapon ('R', 'P', or 'S'): r

Player Picked: ROCK
Computer Picked: PAPER
COMPUTER WINS: PAPER WRAPS ROCK

PLAY AGAIN? ('Y' or 'N'): y
Choose Weapon ('R', 'P', or 'S'): p

Player Picked: PAPER
Computer Picked: ROCK
PLAYER WINS: PAPER WRAPS ROCK

PLAY AGAIN? ('Y' or 'N'): y
Choose Weapon ('R', 'P', or 'S'): s

Player Picked: SCISSORS
Computer Picked: PAPER
PLAYER WINS: SCISSORS CUTS PAPER

PLAY AGAIN? ('Y' or 'N'): y
Choose Weapon ('R', 'P', or 'S'): p

Player Picked: PAPER
Computer Picked: SCISSORS
COMPUTER WINS: SCISSORS CUTS PAPER

PLAY AGAIN? ('Y' or 'N'): y
Choose Weapon ('R', 'P', or 'S'): r

Player Picked: ROCK
Computer Picked: SCISSORS
PLAYER WINS: ROCK BLUNTS SCISSORS

PLAY AGAIN? ('Y' or 'N'): n

You won 3 out of 5 game(s)!
THANKS FOR PLAYING!
```


A few tips and hints to get you started:

Do not begin by immediately opening the editor and writing code!  You should start by working out a design for your program, to help you to understand the problem thoroughly and to determine the sequence of logic that your program will need to implement (flowcharts and pseudocode, discussed in CS230, will be helpful here). In designing your programs, you should look for opportunities to take a modular approach.  Dividing a program into separate modules, each performing a single well-defined task, can make your program more understandable and easier to debug. Consider the basic steps of this game:

Print a set of instructions for the user
Get the player's choice of weapon
Select the computer's weapon
For every possible weapon choice by the computer, determine the weapon that the player would need to defeat it.
Determine the winner of the game
Compare the player's weapon to the computer's weapon; if they match, the game is a draw.
If the player's weapon and computer's weapon do NOT match, compare the player's weapon to the winning weapon from Step #4; if they match, the player wins.
If the player's weapon does NOT match the winning weapon from Step #4, the player loses.
Display an appropriate message.
If the game is a draw, print a message indicating that the game is a draw.
If the player wins, print an appropriate winning message for the player's weapon.
If the player loses, print an appropriate losing message for the player's weapon.
If the player wishes to continue playing, go back to Step #2 and repeat.

Most of these steps would be best implemented using functions.  Here are some suggested function prototypes:

print_instructions();                // (Step 1)
Weapon get_player_weapon();          // (Step 2)
Weapon get_computer_weapon();        // (Step 3)
Weapon get_winning_weapon(Weapon);   // (Step 4)
string get_winning_message(Weapon);  // (Step 6b)
string get_losing_message(Weapon);   // (Step 6c)

This program will involve the creation of random numbers, so we will use the same random number generation function, randint(), that we used in our previous lab assignment.  Refer back to the instructions for Lab #1B for more details.

Notice that, for each of the three possible weapons, only one other weapon is able to defeat it.  This will make your get_winning_weapon(), get_winning_message(), and get_losing_message() functions easier to write.

In writing your functions, you may use any of the selection statements we have discussed in class for comparing a variable value to a range of constant values, but you may find it most convenient to use a switch statement.

To parse the player’s input, you may find it convenient to convert lowercase characters to uppercase.  To do this, use the library function toupper(); for example, if the variable player_input is a char variable, you can convert it to uppercase: player_input = toupper(player_input).  If the player’s input is already in uppercase, it will be unchanged.
This assignment is worth 100 points and is due by the end of the day on Friday, September 25th Friday, October 2nd.
