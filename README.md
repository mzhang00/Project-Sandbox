# Project: Turn-Based Shooter
Chris Choi (Period 4), Caleb Kahan (Period 5), Ray Lee (Period 5), Michael Zhang (Period 5)

## Description
For our project, we created a 2-dimensional turn-based multi-unit shooter game, based on a flash game called Territory War. Players will play on the same machine and take turns controlling their units and attacking the other player’s units until one team reigns supreme. They will be able to use weapons to aim at the other units as well as move their own units around the map. When all units belonging to a player have been vanquished, the other player will be considered the winner. 

## User Interface
The players will be presented with menus at the bottom of the window that will guide them. Pressing the 1 key will let the players move their unit. The players will be able to use the arrow keys to move their units around. The left and right arrow keys control its left and right direction, and the up and down arrow keys can be used when there is an elevation the unit can ascend or descend. For example, if there is a platform above the unit, the up arrow key will teleport the unit to the higher platform. 

When they have travelled the maximum distance allotted per turn, they will be able to quit their movements and use weapons. The only usable weapon we have coded is the gun, which can be selected with the 2 key. The player can use arrow keys to control the aim of their weapon. Once they have chosen a setting that satisfies them, they can press space to fire the weapon and end their turn. Then, the next player will have access to the controls and will begin their turn. 

## Required Libraries 
This project uses SDL-2.0, a 
The line to intall it on linux is ```sudo apt install libsdl2-dev libsdl2-2.0-0 -y;```
Then, the include <SDL> dependencies in the header and main files in the program will work as intended.  
