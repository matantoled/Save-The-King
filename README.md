# Author
- **Matan Toledano**
* If you have any questions or encounter any issues with this project, feel free to contact me at matantoled@gmail.com. I'll be more than happy to help!

# Save-The-King
Save The King is a game in which the player must guide a king to his throne. The game features three distinct levels, each presenting unique challenges. To complete a level, navigate the king to his throne within the given time limit. Some levels feature a time constraint, while others do not. If time runs out, the level will automatically restart. Upon completing the game, players have the option to return to the main menu to play again or exit the game.

## Getting Started
These instructions will help you get a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites
This project uses the SFML graphics library. Make sure you have it installed or follow the SFML installation instructions:
https://www.sfml-dev.org/tutorials/2.6/start-linux.php

## Installing
1. Clone the repository to your local machine: `git clone <repository_url>`
2. Navigate to the project directory: `cd Save-The-King-master/Save The King`
3. Compile the project using CMake: `cmake . && make`
4. Run the game: `./SaveTheKing`

## How to Play
The game consists of several levels where the objective is to guide the king to his throne. Players can move characters using the arrow keys and switch characters with the `P` key. Some levels have a time limit, while others do not. If time runs out, the level will restart.

## Creating Custom Levels

You can create custom levels for the game by adding new text files to the `levels` directory. Each level should be represented by a grid of characters, where each character corresponds to a game element:

- King: `K`
- Mage: `M`
- Warrior: `W`
- Thief: `T`
- Dwarf: `^`
- Wall: `=`
- Gate: `#`
- Fire: `*`
- Orc: `!`
- Key: `F`
- Teleport: `X`
- Throne: `@`
- Time Gift: `$`
- Dwarf Elimination Gift: `&`
- Empty Tile: `' '` (space)

Levels are stored in the `resources` folder with names like `Board1.txt`, `Board2.txt`, and so on. To add a new level, create a text file in this folder with the name of the next level in sequence (e.g., if there are already three levels, name the new level `Board4.txt`). Additionally, you need to add its name to the CMake file. In the `Save The King/resources/CMakeLists.txt` file, add the following line if the new level is `Board4.txt`:

```
configure_file ("Board4.txt" ${CMAKE_BINARY_DIR} COPYONLY)
```

To properly create a level file, follow these procedures:

1. Start by writing the number of rows and columns for the game board, followed by the time budget for the current stage (if you do not want a time limit, write 0). Separate these numbers with spaces and then start a new line.
2. Create the game board using the character symbols listed above.

Here's an example of a custom level:

```
12 24 150
========================
=!^!T  X ^$ ^ X  W**^* =
=!!!!!!!!!!!!!!!!!!!!!!=
=*********&**####X#####=
========= @ ============
=!!!!!!!!!&!!!!!!!!!!!!=
====X##################=
=****##################=
=**********************=
=^$K##X!!!!!!!!X##M ^  =
=                      =
========================
```

In this example, the game board has 12 rows and 24 columns. Players have 150 seconds to complete the level.

## Source Code Structure

The source code is organized into several files, each responsible for different aspects of the game.

### Characters

- `Mage.cpp`, `Mage.h`: Implementations of the mage character.
- `King.cpp`, `King.h`: Implementations of the king character.
- `Warrior.cpp`, `Warrior.h`: Implementations of the warrior character.
- `Thief.cpp`, `Thief.h`: Implementations of the thief character.

### Game Objects

- `Key.cpp`, `Key.h`: Implementations of the key object.
- `Wall.cpp`, `Wall.h`: Implementations of the wall object.
- `Gate.cpp`, `Gate.h`: Implementations of the gate object.
- `Fire.cpp`, `Fire.h`: Implementations of the fire object.
- `Teleport.cpp`, `Teleport.h`: Implementations of the teleport object.
- `Throne.cpp`, `Throne.h`: Implementations of the throne object.

### Gameplay



- `Dwarf.cpp`, `Dwarf.h`: Implementations of the dwarf object.
- `Orc.cpp`, `Orc.h`: Implementations of the orc object.
- `Player.cpp`, `Player.h`: Implementations of the player class that handles all characters.
- `Board.cpp`, `Board.h`: Implementations of the game board.
- `Controller.cpp`, `Controller.h`: Management of real-time events on the screen.

### User Interface

- `Toolbar.cpp`, `Toolbar.h`: Implementations of the game's toolbar.
- `Menu.cpp`, `Menu.h`: Implementations of the game's main menu.

### Resources

- `Resources.cpp`, `Resources.h`: Singleton design pattern for loading and accessing resources like textures and music.

## Acknowledgments
- Special thanks to my partner, Yitzhak Halevi, for his invaluable contributions to this project.
- A heartfelt thank you to Hadassah College for providing the resources and support that made this project possible.