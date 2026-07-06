# Casino Game

A terminal-based casino game built in C++ using object-oriented programming concepts.

## Overview

This project is a console casino game where the player starts with a gambling balance and can choose from multiple games. Each game has its own rules, payout system, and input validation.

## Games

### 1. Guess the Number

The system generates a random number between 1 and 10.  
If the player guesses the exact number, they win 3 times their bet amount. Otherwise, they lose the bet amount.

### 2. Lucky 7

The system generates a random number between 1 and 10.  
The player predicts whether the number will be less than 7, exactly 7, or greater than 7. A correct prediction gives 2 times the bet amount.

### 3. Even or Odd

The system generates a random number between 1 and 10.  
The player predicts whether the number will be even or odd. A correct prediction gives 2 times the bet amount.

### 4. Big Gamble

The system generates a random number between 1 and 100.  
The player must guess the exact number. This game uses the player's entire current balance as the bet amount. A correct guess gives 10 times the bet amount, while a wrong guess loses the entire balance.

## Features

- Four playable casino games
- Player balance management
- Win/loss stat tracking
- Input validation for invalid number and alphabet inputs
- Retry limits for invalid choices
- Main menu navigation
- Object-oriented structure using inheritance and virtual inheritance

## Technologies Used

- C++
- Object-Oriented Programming
- Inheritance
- Virtual Inheritance

## How to Run

### Compile

```bash
g++ Casino.cpp -o Casino
```

### Run

For Windows:

```bash
.\Casino.exe
```

For Linux/Mac:

```bash
./Casino
```

## Project Structure

```text
Casino.cpp      # Main source code
README.md       # Project documentation
.gitignore      # Files ignored by Git
```

## Note

This is a beginner-friendly C++ project created to practice object-oriented programming, input validation, control flow, and game logic.