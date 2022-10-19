# Rock-Paper-Scissor

This program reads the content of two files (player1.txt and player2.txt), which contain the letters corresponding to the possible plays of the game Rock, Paper and Scissor (R, P and S), and checks who is the winner or if it's a draw.

The program was written both in C language and in Python, each one available inside the corresponding folder. The purpose of the program is to compare both programming languages in terms of efficiency. In oreder to do that I needed files with thousands of plays and to accomplish that I created another program in python called "Rock-Paper-Scissor-Plays-Generator.py" which creates files with the number of letters (R, P or S) indicated by the user.

Rock-Paper-Scissor-Plays-Generator.py usage:
  1 - Run the script;
  2 - A question will appear asking for the number of letters you want to generate. Insert a positive number of your choice;
  3 - A file called "output.txt" will appear in the same directory where the script is. This file will contain the quantity of letters (R, P or S) that you inserted;
  4 - Change the name of the file to "player1.txt" or "player2.txt" and copy and paste inside the folder of the language you want to test. You should run Rock-Paper-Scissor-Plays-Generator.py two times, one for each player, otherwise the result will be 100% draws. The number of letters for both players must be equal.
