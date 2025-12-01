#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int rotate(int curr, char dir, int move) {
  if (dir == 'L') {
    curr = curr - move;
    if (curr < 0) {
      curr = curr % 100;
      if (curr != 0)  curr = curr + 100;
    }
  } else {
    curr = curr + move;
    if (curr > 99) curr = curr % 100;
  }

  return curr;
}

int getRotations(int curr, char dir, int numOfMoves) {
  int toZero = (dir == 'L') ? curr : 100 - curr;
  int zeroCount = 0;

  if (toZero == 0) {
    if (numOfMoves < 100) return 0;
    toZero = 100;
  }

  while (numOfMoves > toZero) {
    numOfMoves -= toZero;
    toZero = 100;
    zeroCount += 1;
  }

  return zeroCount;
}

int main(void) {
  ifstream file("inputs/input1.txt");
  string  str;
  int position = 50;
  int zero_counter = 0;
  int zero_rotations = 0;

  printf("Day 1: Secret Entrance\n");

  while (getline(file, str)) {
    char dir = str[0];
    int rotations = stoi(str.substr(1, str.length()));

    // Part 2
    zero_rotations += getRotations(position, dir, rotations);

    position = rotate(position, dir, rotations);
    if (position == 0) zero_counter += 1;
  }

  // 1023, 5899
  printf("  Solution 1: %d\n", zero_counter);
  printf("  Solution 2: %d\n", zero_rotations + zero_counter);

  return 0;
}
