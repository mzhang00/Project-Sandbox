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
<ul>
  <li>Three Processes:
  <ul>
    <li>Player 1 Process- sends information to game process to affect game
    <li>Player 2 Process- sends information to game process to affect game
    <li>Game Process- controls map, and affects map from decisions made by players
  </ul>
</ul>
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
Key: M == Michael, R == Raymond, Ch == Chris, Ca == Caleb <br>
1/3/20:: Initialize the terminal with a custom size.- Ca<br>
1/6/20: Draw the stickmen and allow for their movement on the terminal- Ch<br>
1/6/20: Setup a rudimentary turn-by-turn system- M<br>
1/6/20: Start designing blocks and the static environment elements of the map- R<br>
1/7/20: Design a gun and allow the player to use a gun- Ca<br>
1/8/20: Design the weapons and allow the player use a weapon - Ca<br>
1/9/20: Iterate between multiple characters - M<br>
1/13/20: Refine the behaviours of the moveable characters to allow them to navigate the map - also limit distance - Ch<br>
1/13/20: Allow the weapons to interact with and affect the health of the characters - R<br>
1/13/20: Design an interface that zooms in on a portion of the map depending on which character is selected - M<br>
1/13/20 Add different weapons such as grenade or boot: Ca<br>
1/14/20: Design a main level screen to allow user to select different maps or or adjust the amount of characters each player starts with - Ch<br>
1/15/20: Implement different settings and modes, like easy/medium/hard. Ca <br>
1/16/20: Time to debug - Everyone<br>
1/17/20: Final Working product - Also everyone<br>
If Extra Time: <br>
Allow for multiple computers to play the game<br>
Have a multiplayer mode with more than just 2 players<br>
Animate fancy graphics, or at least sprites, of the projectiles and the characters<br>



