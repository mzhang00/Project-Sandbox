# Project: Turn-Based Shooter
Chris Choi (Period 4), Caleb Kahan (Period 5), Ray Lee (Period 5), Michael Zhang (Period 5)

## Description
For our project, we are planning to create a 2-dimensional turn-based multi-unit shooter game, based on games like Territory War, Worms, and Wild Ones. Players will play on the same machine and take turns controlling their units and attacking the other player’s units until one team reigns supreme. They will be able to use weapons to aim at the other units as well as move around their own units around the map. When all units belonging to a player have been vanquished, the other player will be considered the winner. 

## User Interface
The players will be able to use the arrow keys to manipulate their units' movements. When they have travelled the maximum distance allotted per turn, they will be able to use the arrow keys to control the aim of their weapon, as well as using number keys to control the power of the projectile that is fired from their weapon. Once they have chosen a setting that satisfies them, they hit enter and end their turn. Then, the next player will have access to the controls and will begin their turn. 

## Technical Design
Topics Used: Allocating Memory:
<ul>
  <li>Memory for stickmen
  <li>Memory for weapons
  <li>Memory for map/board
</ul> 
Working with files:
<ul>
  <li>Maps we will be build will be stored in files
  <li>We will create the file/map by hand and then retrieve it towards shared memory during the game.
</ul>
Processes:
Three Processes:
<ul>
  <li>Player 1 Process
  <li>Player 2 Process
</ul>
Game Process
Signals: 
<ul>
  <li>Killing off players or games
  <li>Starting off a process and switching turns
</ul>
Pipes: 
<ul>
  <li>Communicating information such as bullets and death of players from games to processes and vice versa. 
</ul>
Data structures:
<ul>
  <li>Strings- to store both static environmental elements and display of stickman and weapons
  <li>Ints- for player count, distance limit, strength of projectile, current turn
  <li>Structs - to store various attributes of stickmen (like health, distance traveled), weapons(angle of launch, power)
</ul>
Algorithms:
<ul>
  <li>Game process will read map file and set up map with ncurses.
  <li>Game Process will create Player 1 Process and Player 2 Process
  <li>The Player processes will create the stickmen and send the coordinates to the game process. Game Process will display players and turn the game over to Player 1
  <li>Player 1 or Player 2 will constant communicate, via pipes,  with Game Process to move character, shoot , and to limit distance
  <li>Game Process will continue switching turns until the game is over. 
</ul>

## Timeline
M == Michael, R == Raymond, Ch == Chris, Ca == Caleb /n
1/3/20:: Initialize the terminal with a custom size.- Ca /n
1/6/20: Draw the stickmen and allow for their movement on the terminal- Ch /n
1/6/20: Setup a rudimentary turn-by-turn system- M /n
1/6/20: 
1/6/20: 
1/9/20:
1/9/20:
1/9/20:
1/9/20:
1/13/20:
1/13/20:
1/13/20:
1/13/20:
1/14/20-1/16/20- Extra credit or debugging- Everyone
1/17/20: Final Working Product: Everyone
1/7/20: Start designing the static environment elements of the map- R
1/8/20: Design the weapons and allow the player use a weapon - Ca
1/9/20: Implement the selection of multiple characters - M
1/13/20: Refine the behaviours of the moveable characters to allow them to navigate the map - Ch
1/13/20: Allow the weapons to interact with and affect the health of the characters - R
1/13/20: Design an interface that zooms in on a portion of the map depending on which character is selected - M
1/14/20: Design a main level screen to allow user to select different maps or or adjust the amount of characters each player starts with - Ch
1/15/20: Implement different settings and modes, like easy/medium/hard. Ca 
1/16/20: Time to debug - Everyone
1/17/20: Final Working product - Also everyone
If Extra Time: 
Allow for multiple computers to play the game
Have a multiplayer mode with more than just 2 players
Animate fancy graphics, or at least sprites, of the projectiles and the characters
