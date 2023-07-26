#!/usr/bin/python3
""" This module defines island_perimeter """


def island_perimeter(grid):
    """
    Returns the perimiter of an island based on a grid
    of 0s(water) & 1s(land).

    In the grid pattern, there are no lakes. The grid
    cells are never connected diagonally and the grid
    is completely surrounded by water.
    """

    # We can determine the perimeter based on how many sides
    # of each land cell is exposed to water based on the rules
    perimeter = 0
    for row in range(len(grid)):  # for each row
        for col in range(len(grid[row])):  # for each column
            # search for land cells
            if grid[row][col] == 1:
                land_cell = grid[row][col]
                # check how many neighbours are water cells

                # check if land_cell is at boundary of grid
                # top or bottom boundary
                if row == 0 or row == len(grid) - 1:
                    perimeter += 1

                # left or right boundary
                if col == 0 or col == len(grid[row]) - 1:
                    perimeter += 1

                # check if non-boundary land_cell has water cell neighbours
                # top water cell neighbour
                if row != 0 and grid[row - 1][col] == 0:
                    perimeter += 1

                # bottom water cell neighbour
                if row != len(grid) - 1 and grid[row + 1][col] == 0:
                    perimeter += 1

                # left water cell neighbour
                if col != 0 and grid[row][col - 1] == 0:
                    perimeter += 1

                # right water cell neighbour
                if col != len(grid[row]) - 1 and grid[row][col + 1] == 0:
                    perimeter += 1
    return perimeter
