# Ice Cream Pac-Man

Ice Cream Pac-Man is a C++ project developed using the Imagine++ graphics library. It is a variation of the classic Pac-Man game where the player controls an ice cream character navigating through a procedurally generated labyrinth. The objective is to collect cherries while avoiding enemies.
#Demo of the game
(demo.gif)
## Features

- Procedurally generated labyrinths with adjustable size and density
- Player-controlled ice cream character with smooth movement
- Enemies with autonomous movement and collision detection
- Collectible cherries placed randomly in free spaces
- Level completion upon collecting enough cherries and reaching the goal
- Game-over conditions when colliding with an enemy

## Requirements

- C++17 or later
- [Imagine++ library](http://imagine.enpc.fr/~monasse/Imagine++/)
- A C++ compiler supporting standard libraries (e.g., g++, clang++)

## Compilation

Clone the repository and compile using your preferred compiler. Example with g++:

```bash
g++ -std=c++17 main.cpp labyrinth.cpp icecreamguy.cpp ennemi.cpp cherry.cpp -o icecreampacman -lImagine
```

Make sure the Imagine++ library is correctly installed and linked on your system.

## Usage

Run the compiled binary:

```bash
./icecreampacman
```

- Use the arrow keys to move the ice cream character.
- Collect cherries scattered in the labyrinth.
- Avoid enemies at all costs.
- Reach the goal after collecting the required number of cherries.

## Project Structure

- `labyrinthe.*`: Labyrinth generation and display
- `icecreamguy.*`: Player character logic and drawing
- `ennemi.*`: Enemy logic and movement
- `cherry.*`: Cherry collectible logic
- `outils.*`: Utility functions
- `main.cpp`: Entry point of the program

=
