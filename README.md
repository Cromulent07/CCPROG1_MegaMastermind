# Mega Mastermind

## Project Background
This game is the predecessor of the modern-day mobile game "Wordle". The code-breaking game Mastermind or Master Mind is for two players. It mimics an old game called Bulls and Cows played with a pencil and paper which dates approximately 100 years ago. (A Brief History of the Master Mind Board Game., 2022)

The classic game is played with:
- a board game with a shield covering a row of four large holes at one end and twelve (or ten, or eight, or six) further rows of four large holes adjacent to four little holes;
- Round-headed code pegs in six different colors will be inserted into the board's big holes; and
- The flat-headed, smaller key pegs, some of which are white and others of which are black, will be inserted into the board's tiny holes.

## Mechanics
The game play for Mastermind is as follows:
1. The game play for Mastermind is as follows:
   - The two players agree in advance to an even number of games that they will play. Number of games can be from 2 to 10 games maximum.
     - a. The role of codemaker and codebreaker is switched between the players.
     - b. For this project, the two players consist of a **human player** and a **pseudo-AI player**.
       - i. The pseudo-AI player will have the following abilities:
           1. Guess the pegs via randomization
           2. If the pegs guess by the pseudo-AI player is correct, it will have the ability to store the correct pegs and guess only the incorrect ones.

2. A pattern of four code pegs is selected by the codemaker.
   - a. In the traditional game, duplicate code pegs are allowed.
   - b. However, for this project, **duplication of code pegs will not be allowed.**

3. The chosen pattern is inserted into the four shield-covered holes by the codemaker, who can see it but not the codebreaker.

4. Within **ten turns (or based on the number of games agreed upon)**, the codebreaker tries to predict the pattern—in both sequence and color. The number of turns can vary if the student opts to do the bonus points.

5. A row of code pegs is placed on the decoding board for each guess.

6. The codemaker then inserts one to four key pegs into the tiny holes of the row that contains the guess to offer feedback.
   - a. For each code peg from the guess that is **accurate in both color and position, a black key peg** is inserted.
   - b. A **valid color code peg that has been misplaced is shown by a white key peg**.

7. Once feedback is provided, another guess is made; guesses and feedback continue to alternate until either the codebreaker guesses correctly, or all rows on the decoding board are full.

8. Players can only earn points when playing as the codemaker.
   - a. The codemaker **gets one point for each guess** the codebreaker makes.
   - b. An **extra point is earned by the codemaker if the codebreaker is unable to guess the exact pattern** within the given number of turns.

9. The winner is the one who has the most points after the agreed-upon number of games are played.

## Running the program

### Windows
Compile the program
```batch
gcc -Wall main.c -o main.exe
```

Run the program
```batch
main.exe
```