/**
 * @file mazegen.c
 * @author Neha Gurnani
 * @brief Code for the maze gen for COMP1921 Assignment 2
 */

#include "mazegen.h"

int main(int argc, char *argv[])
{
    // Arg check
    if (argc != 4)
    {
        printf("Usage: ./maze <maze_file> <width> <height>\n");
        return EXIT_ARG_ERROR;
    }

    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    // Initialise maze ( cells = walls )
    char maze[202][202];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            maze[i][j] = WALL;
        }
    }

    srand(time(NULL));

    mazeGenerator(maze, width, height);

    FILE *mazeFile = fopen(argv[1], "w");
    if (!mazeFile)
    {
        printf("Error: Cannot open file.\n");
        return EXIT_FILE_ERROR;
    }

    printMaze(mazeFile, maze, width, height);

    fclose(mazeFile);
    return EXIT_SUCCESS;
}

// Functions

void stackPush(Coordinate neighbour)
{

    topOfStack++;
    stackPath[topOfStack] = neighbour;
}

Coordinate stackPop()
{

    Coordinate popped = stackPath[topOfStack];
    topOfStack--;
    return popped;
}

void Backtracking(char maze[202][202], int w, int h, int x, int y)
{
    // push starting coordinate onto the stack
    Coordinate currentP1 = {y, x};
    stackPush(currentP1);

    bool visited[202][202] = {false};
    visited[y][x] = true;
    maze[y][x] = SPACE;

    int xNeighbour;
    int yNeighbour;

    Neighbour Coord[] = {{0, 2}, {-2, 0}, {2, 0}, {0, -2}};

    while (1)
    {

        int found = 0;

        // Find a valid neighbouring cell
        for (int i = 0; i < 4; i++)
        {
            int index = rand() % 4;

            xNeighbour = x + Coord[index].dx;
            yNeighbour = y + Coord[index].dy;

            if (xNeighbour >= 0 && xNeighbour < w && yNeighbour >= 0 && yNeighbour < h && maze[yNeighbour][xNeighbour] == WALL && !visited[yNeighbour][xNeighbour])
            {
                found = 1;

                // The wall in between the current and neighbouring cell becomes a SPACE

                int middleX = (x + xNeighbour) / 2;
                int middleY = (y + yNeighbour) / 2;

                maze[middleY][middleX] = SPACE;
                maze[yNeighbour][xNeighbour] = SPACE;
                visited[yNeighbour][xNeighbour] = true;

                // Neighbour coordinate is pushed onto the stack

                Coordinate currentP2 = {yNeighbour, xNeighbour};
                stackPush(currentP2);

                x = xNeighbour;
                y = yNeighbour;
            }
        }

        // Dead end - if no more valid neighbours are found

        if (!found)
        {
            if (x == 0 && y == 0)
            {
                break;
            }

            // pop a coordinate off the stack and continue the process
            stackPop();
            y = stackPath[topOfStack].y;
            x = stackPath[topOfStack].x;
        }
    }
}

void mazeGenerator(char maze[202][202], int w, int h)
{

    // Maze dimension validation

    if (w < MIN_SIZE || w > MAX_SIZE || h < MIN_SIZE || h > MAX_SIZE)
    {
        printf("Error: Width and height must be between %d and %d\n", MIN_SIZE, MAX_SIZE);
        exit(1);
    }

    Backtracking(maze, w, h, 0, 0);

    // Start & end points

    maze[0][0] = START;

    int yEnd;
    int xEnd;

    // E is always at the bottom of the maze

    yEnd = h - 2;

    do
    {
        xEnd = rand() % w;
    } while (maze[yEnd][xEnd] != SPACE || (xEnd == 0));

    maze[yEnd][xEnd] = END;
}

void printMaze(FILE *mazeFile, char maze[202][202], int w, int h)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            fprintf(mazeFile, "%c", maze[i][j]);
        }
        fprintf(mazeFile, "\n");
    }
}
