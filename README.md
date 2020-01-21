# Project: Turn-Based Shooter
Chris Choi (Period 4), Caleb Kahan (Period 5), Ray Lee (Period 5), Michael Zhang (Period 5)

## Description
For our project, we created a 2-dimensional turn-based multi-unit shooter game, based on a flash game called Territory War. Players will play on the same machine and take turns controlling their units and attacking the other player’s units until one team reigns supreme. They will be able to use weapons to aim at the other units as well as move their own units around the map. When all units belonging to a player have been vanquished, the other player will be considered the winner. 

## User Interface
The players will be presented with menus at the bottom of the window that will guide them. Pressing the 1 key will let the players move their unit. The players will be able to use the arrow keys to move their units around. The left and right arrow keys control its left and right direction, and the up and down arrow keys can be used when there is an elevation the unit can ascend or descend. For example, if there is a platform above the unit, the up arrow key will teleport the unit to the higher platform. 

When they have travelled the maximum distance allotted per turn, they will be able to quit their movements and use weapons. The only usable weapon we have coded is the gun, which can be selected with the 2 key. The player can use arrow keys to control the aim of their weapon. Once they have chosen a setting that satisfies them, they can press space to fire the weapon and end their turn. Then, the next player will have access to the controls and will begin their turn. 

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
  <li>Game process will read map file and set up map with SDL.
  <li>Game Process will create Player 1 Process and Player 2 Process
  <li>The Player processes will create the stickmen and send the coordinates to the game process. Game Process will display players and turn the game over to Player 1
  <li>Player 1 or Player 2 will constant communicate, via pipes,  with Game Process to move character, shoot , and to limit distance
  <li>Game Process will continue switching turns until the game is over. 
</ul>
