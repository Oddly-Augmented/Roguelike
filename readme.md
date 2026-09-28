# Roguelike (C++)

A small ASCII, grid-based roguelike built in C++ as a learning project. Scoped so that building it exercises everything from Chapters 3–5: classes/encapsulation, data structures & sorting, and inheritance/polymorphism.

## Concept

A single-dungeon crawler in the spirit of early Rogue/Nethack. Move a `@` player around a text-based map, fight enemies (each with different behavior via polymorphism), manage an inventory (a hand-built ADT), and reach the stairs down.

## Legend

```
#  wall
.  floor
@  player
e  enemy
!  item
>  stairs down
```

---

## Roadmap

### Phase 1 — Core loop (Ch 3: classes, encapsulation, streams)
- [x] `Map` class — grid storage (`vector<string>`), prints itself, carves a room
- [x] `Player` class — private data members, public accessors (`getX`/`getY`)
- [x] `Map::print` overload — draws `@` on top of the grid
- [ ] Keyboard input (WASD) to move the player
- [ ] Collision via `Map::isWalkable` — can't walk through walls
- [ ] Game loop — input → update → reprint → repeat
- [ ] **Constructor overloading** — e.g. `Player()` default spawn vs `Player(x, y)` explicit spawn
- [ ] **Constructor initializer lists** — used consistently across every class (`Player`, `Map`, ect.)
- [ ] **`this` pointer** — at least one deliberate, explicit use (e.g. a `Player::isAt(const Player& other)` style comparison, or chaining a setter that returns `*this`)
- [ ] **Operator overloading** — `operator<<` for `Player`/`Entity` so you can `cout << player` instead of calling a `toString()`-style method
- [ ] **Unit tests** — a `test_map.cpp` / `test_player.cpp` per class as you build, covering border cases (moving into a wall, moving off the map edge)

### Phase 2 — Inheritance & polymorphism (Ch 5)
- [ ] **Abstract `Entity` base class** — shared position/health, at least one **pure virtual function** (e.g. `virtual void attack(Entity& target) = 0;`)
- [ ] `Player : public Entity` and `Enemy : public Entity` — **is-a relationship**, `protected` health/position so subclasses can touch them directly
- [ ] At least two different `Enemy` subclasses (e.g. `Goblin`, `Skeleton`) that **override** `attack()` or `takeDamage()` differently — this is what actually demonstrates **runtime polymorphism** (calling `attack()` through an `Entity*`/`Entity&` and getting different behavior depending on the real object)
- [ ] A `std::vector<Entity*>` (or smart pointers) holding mixed `Player`/`Enemy` objects, proving the base-class pointer works polymorphically
- [ ] Abstract `Item` base class + `Weapon`, `Potion` subclasses (a second, smaller polymorphism example — `use()` behaves differently per item type)
- [ ] A one-page **UML class diagram** of the `Entity`/`Item` hierarchies (hand-drawn or a tool like draw.io — this is the Ch 5.10 topic, worth actually producing even though it's not code)

### Phase 3 — Data structures & sorting (Ch 4)
- [ ] **Inventory as a List/Bag ADT** — a hand-built class (same shape as your `Contestants` class from Ch 4) wrapping a dynamic array of `Item*`, with `add`/`remove`/`getSize` — this is the concrete List ADT topic, not just `std::vector` used blindly
- [ ] **Turn queue** — a `Queue` (or `std::queue`) of entities determining turn order each round
- [ ] **Priority queue** — upgrade the turn queue so faster entities (higher `speed` stat) act more often — this is the concrete use case for 4.4's priority queue topic
- [ ] **Big O commentary** — a short note (in code comments or this README) on the complexity of your Inventory's `add`/`remove`/`find` — same exercise as `Contestants`' BigO requirements
- [ ] **Sorting the inventory** — implement and compare at least 3 of: bubble, selection, insertion (you've done this one), shell, quicksort, merge sort — sort items by value or weight, and pick one as the "real" one the game uses, keeping the others as reference/comparison
- [ ] **Comparison operators** on `Item` (`operator<`, `operator==`) so those sorts have something to compare — same pattern as `Player`'s comparison operators from chpt04

### Phase 4 — Polish (stretch, pick what interests you)
- [ ] Procedurally generated map instead of a fixed rectangle
- [ ] Multiple rooms + corridors
- [ ] Save / load game state to file (you already know file I/O from `Contestants`/`Record`)
- [ ] Static member on `Entity` — e.g. a static counter assigning each entity a unique ID as it's created (Ch 3.13 static data members)

---

## Project structure

```
map.h / map.cpp           — the grid, printing, walkability checks
entity.h / entity.cpp      — abstract base class (Player, Enemy inherit from this)
player.h / player.cpp      — player-specific behavior
enemy.h / enemy.cpp        — Goblin, Skeleton, etc.
item.h / item.cpp          — abstract base class (Weapon, Potion inherit from this)
inventory.h / inventory.cpp — hand-built List/Bag ADT holding Item
main.cpp                   — game loop
```
