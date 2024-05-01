#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define EXIT_SUCCESS 0
#define EXIT_ARG_ERROR 1
#define EXIT_FILE_ERROR 2
#define EXIT_MAZE_ERROR 3

#define MAX_SIZE 100
#define MIN_SIZE 5

#define WALL '#'
#define SPACE ' '
#define START 'S'
#define END 'E'

// To store neighbouring coordinates
typedef struct
{
    int dy;
    int dx;
} Neighbour;

// Stack
typedef struct
{
    int y;
    int x;
} Coordinate;

Coordinate stackPath[MAX_SIZE * 2];
int topOfStack = -1;

FILE *mazeFile;

/**
 * @brief Increases the top of the stack index and assigns the provided coordinate to the new top position in the stack.
 *
 * @param neighbour The coordinate to be pushed onto the stack.
 */
void stackPush(Coordinate neighbour);

/**
 * @brief Removes the top element from the stack and returns it.
 *
 * @return Coordinate The coordinate popped from the stack.
 */
Coordinate stackPop();

/**
 * @brief Implements a backtracking algorithm to generate a maze within the given dimensions.
 *
 * @param maze The maze grid.
 * @param w Width of the maze.
 * @param h Height of the maze.
 * @param x Starting x-coordinate.
 * @param y Starting y-coordinate.
 */

void Backtracking(char maze[202][202], int w, int h, int x, int y);

/**
 * @brief Generates a maze using a backtracking algorithm and marks the start and end points.
 *
 * @param maze The maze grid.
 * @param w Width of the maze.
 * @param h Height of the maze.
 */

void mazeGenerator(char maze[202][202], int w, int h);

/**
 * @brief Prints the maze grid to a specified file.
 *
 * @param mazeFile Pointer to the file where the maze will be printed.
 * @param maze The maze grid.
 * @param w Width of the maze.
 * @param h Height of the maze.
 */
void printMaze(FILE *mazeFile, char maze[202][202], int w, int h);




