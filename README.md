# Project: Turn-Based Shooter
Chris Choi (Period 4), Caleb Kahan (Period 5), Ray Lee (Period 5), Michael Zhang (Period 5)

## Description
For our project, we created a 2-dimensional turn-based multi-unit shooter game, based on a flash game called Territory War. Players will play on the same machine and take turns controlling their units and attacking the other player’s units until one team reigns supreme. They will be able to use weapons to aim at the other units as well as move their own units around the map. When all units belonging to a player have been vanquished, the other player will be considered the winner. 

## User Interface
SIMPLE INSTRUCTIONS: 1. make 2. make run </br>
COMPLICATED INSTRUCTIONS: The players will be presented with menus at the bottom of the window that will guide them. Pressing the 1 key will let the players move their unit. The players will be able to use the arrow keys to move their units around. The left and right arrow keys control its left and right direction, and the up and down arrow keys can be used when there is an elevation the unit can ascend or descend. For example, if there is a platform above the unit, the up arrow key will teleport the unit to the higher platform. 

When they have travelled to a suitable location, they will be able to quit their movements and use weapons. The only usable weapon we have coded is the gun, which can be selected with the 2 key. The player can use arrow keys to control the aim of their weapon. Once they have chosen a setting that satisfies them, they can press space to fire the weapon and end their turn (or they can press X to go back to the weapon menu). Then, the next player will have access to the controls and will begin their turn. 

## Required Libraries 
This project uses SDL-2.0, a cross-platform software development library designed to provide a hardware abstraction layer for computer multimedia hardware components. It's mainly used for computer games and other multimedia applications. 
The line to intall it on linux is

```sudo apt install libsdl2-dev libsdl2-2.0-0 -y;```

Then, the include <SDL> dependencies in the header and main files in the program will work as intended.  
  
## Formal Apology 
We originally apportioned our tasks equally across every manner of the game. But as time went on and the project developed, a very clear inbalance of effort was emerging. This was due to it taking an entire week to get SDL installed, which ate up a lot of our time. Two of the members were heavily focused on learning the SDL lingo, while one assured that he would get the networking with sockets done on time. Eventually the project progressed beyond a point where one could easily jump in and assist with the coding, and there was a lack of communication between the SDL developers and the socket manager. In fact, it was only until 5 AM of the due date of the project when any communication was initiated by the socket developer. At which point, it was already too late to integrate any of the networking code into our game in any meaningful way. As a result, we only have the allocation of memory with malloc() that is used in the game.  

## Bugs
-Gun damages 95% of the time when properly aimed. <br />
-Gun sometimes flips around improperly during direcional use <br/>
-Some arrow keys, on the bottom screen, may not function- this was done purposefully due to scarcity of time.<br />
-Game takes a long time to render, could take up to a minute, once screen pops up.<br\>
-If the unit moves too far to the left or right of the map, the window will go past the edge of the map and show a solid block of colour.
