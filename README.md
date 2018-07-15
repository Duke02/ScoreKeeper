# ScoreKeeper
A program to keep score in simple games.

## How it works
The program first asks for the total number of players, then asks for each of those player's names.

Afterwards, simply input a player's identification and their latest addition to their score. 

### Player's Identification
A player's identification composes of their numerical id and their name.
 
Players can be identified by either their numerical id, the first character of their name, or their entire name.

Keep in mind that if your players have the same first initial, the program will add the inputted score addition to the 
player with the least numerical id.

#### Numerical ID
Numerical id's are equal to the order the user inputted each player.

Example: The user inputted John, Adam, and Susie in that order. John has a numerical id of 1, Adam 2, Susie 3.

Numerical id's are printed every time a player's score is printed.

### Other Cool Things
* To get a player's current score, input `p` then the player's identification, and the program will print their score.
* To get all player scores, input `print` and the program will print all player scores starting from the player with 
the least numerical id.

## Example Input
Assumes 4 players were inputted as Adam, John, Sally, Susan.

* `> A 4`
   ```
    Adam got 4 points!
    Player 1: Adam has score 4.
    ```
* `> John -2`
    ```
    John got -2 points!
    Player 2: John has score -2.
    ```
* `> p 4`
    ```
    Player 4: Susan has score 0.
    ```
* `print`
    ```
    Player 1: Adam has score 4.
    Player 2: John has score -2.
    Player 3: Sally has score 0.
    Player 4: Susan has score 0.
    ```

## Cool Things That Should Be Implemented
* Saving scores to a file inputted to the program.
* Adding players mid-game.
* Removing players mid-game.
* Setting a player's score initially.
* Having the option to set or add scores every turn. 
 
