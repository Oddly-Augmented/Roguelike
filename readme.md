# Roguelike (C++)

A small ASCII, grid-based roguelike built in C++ as a learning project — no external libraries, just the console.

## Concept

A single-room dungeon crawler in the spirit of early Rogue/Nethack. Move a `@` player around a text-based map, fight simple enemies, pick up items, and reach the stairs down. Built incrementally, one feature at a time.

## Legend

```
#  wall
.  floor
@  player
```

## Progress

### Core (playable v1)
- [x] `Map` class — grid storage using `vector<string>`, prints itself, carves a rectangular room
- [x] `Player` class — tracks position (x, y)
- [x] `Map::print` overload that draws the player (`@`) on top of the grid
- [ ] Keyboard input (WASD) to move the player
- [ ] Collision — player can't walk through walls (`Map::isWalkable`)
- [ ] Game loop — read input, update position, reprint map, repeat

### Enemies
- [ ] `Entity` base class (shared position/health logic for player + enemies)
- [ ] Basic enemy that spawns on the map
- [ ] Simple enemy AI — wander or chase player
- [ ] Turn-based combat (attack when player moves into enemy)
- [ ] Player health, death/game over condition

### Items & progression
- [ ] Items on the floor (e.g. potions, weapons)
- [ ] Player inventory
- [ ] Pick up / use item
- [ ] Stairs down — win condition or next level

### Polish (stretch goals)
- [ ] Procedurally generated map instead of a fixed rectangle
- [ ] Multiple rooms + corridors
- [ ] Save / load game state to file
- [ ] Score tracking

## Project structure

```
map.h / map.cpp        — the grid, printing, walkability checks
player.h / player.cpp   — player position and state
main.cpp                 — game loop (not yet started)
```

## Build

```
g++ -std=c++17 -Wall main.cpp map.cpp player.cpp -o roguelike
./roguelike
```