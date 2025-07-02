#include <iostream>
#include <cstdlib>
using namespace std;

void initializeMaps(int **mineMap, char **showingMap, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(mineMap + i) + j) = 0;
            *(*(showingMap + i) + j) = '-';
        }
    }
}

void placingMines(int **mineMap, int numOfmines, int rows, int cols)
{
    for (int i = 0; i < numOfmines; i++)
    {
        int coordX = rand() % rows;
        int coordY = rand() % cols;
        while (*(*(mineMap + coordX) + coordY) == -1)
        {
            coordX = rand() % rows;
            coordY = rand() % cols;
        }
        *(*(mineMap + coordX) + coordY) = -1;
    }
}

void displayUserMap(char **map, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << *(*(map + i) + j) << " ";
        }
        cout << endl;
    }
}

void adjacentMines(int **mineMap, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (*(*(mineMap + i) + j) != -1)
            {
                *(*(mineMap + i) + j) = 0;
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (*(*(mineMap + i) + j) == 0)
            {
                if (i == 0 && j == 0)
                { // Top Left corner Checking
                    if (*(*(mineMap + i + 1) + j) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i) + j + 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i + 1) + j + 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                }
                else if (i == 0 && j == cols - 1)
                {
                    if (*(*(mineMap + i + 1) + j) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i) + j - 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i + 1) + j - 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                }
                else if (i == rows - 1 && j == 0)
                { // bottom Left corner Checking
                    if (*(*(mineMap + i - 1) + j) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i) + j + 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i - 1) + j + 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                }
                else if (i == rows - 1 && j == cols - 1)
                { // bottom right corner
                    if (*(*(mineMap + i - 1) + j) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i) + j - 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i - 1) + j - 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                }

                else if (i == 0 && j != 0 && j != cols - 1)
                {
                    if (*(*(mineMap + i + 1) + j) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i) + j + 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i + 1) + j + 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i) + j - 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i + 1) + j - 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                }
                else if (i == rows - 1 && j != 0 && j != cols - 1)
                {
                    if (*(*(mineMap + i - 1) + j) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i) + j + 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i - 1) + j + 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i) + j - 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i - 1) + j - 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                }
                else
                {
                    if (*(*(mineMap + i - 1) + j) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i) + j + 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i - 1) + j + 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i) + j - 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i - 1) + j - 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i + 1) + j) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i + 1) + j + 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                    if (*(*(mineMap + i + 1) + j - 1) == -1)
                    {
                        (*(*(mineMap + i) + j))++;
                    }
                }
            }
        }
    }
}

bool validCoords(int row, int col, int numRows, int numCols)
{
    if (row < 0)
    {
        return false;
    }
    if (row >= numRows)
    {
        return false;
    }
    if (col < 0)
    {
        return false;
    }
    if (col >= numCols)
    {
        return false;
    }
    return true;
}

void safePlotReveal(int **mineMap, char **showMap, int rows, int cols, int x, int y, int &safePlots)
{
    if (!validCoords(x, y, rows, cols))
        return;

    if (*(*(showMap + x) + y) != '-')
        return; // Box to check should be unchecked before

    int val = *(*(mineMap + x) + y);
    safePlots--;

    char toShow;
    if (val == 0)
        toShow = ' ';
    else
        toShow = char('0' + val);

    *(*(showMap + x) + y) = toShow;

    if (val == 0)
    {
        for (int xChange = -1; xChange <= 1; xChange++)
        {
            for (int yChange = -1; yChange <= 1; yChange++)
            {
                if (xChange != 0 || yChange != 0)
                {
                    safePlotReveal(mineMap, showMap, rows, cols, x + xChange, y + yChange, safePlots);
                }
            }
        }
    }
}

int main()
{
    srand(time(0));
    int rows, cols, numOfmines, safePlots;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter number of mines: ";
    cin >> numOfmines;
    bool gameRunning = true;
    safePlots = rows * cols - numOfmines;

    int **mineMap = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        mineMap[i] = new int[cols];
    }
    char **showingMap = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        showingMap[i] = new char[cols];
    }
    initializeMaps(mineMap, showingMap, rows, cols);
    placingMines(mineMap, numOfmines, rows, cols);
    adjacentMines(mineMap, rows, cols);

    while (gameRunning && safePlots > 0)
    {
        displayUserMap(showingMap, rows, cols);
        int userRow, userCol;
        cout << "Enter Row and Column number to reveal: ";
        cin >> userRow >> userCol;
        while ((userRow < 0 || userRow > rows - 1) || (userCol < 0 || userCol > cols - 1))
        {
            cout << "Invalid coordinated, Enter Again: ";
            cin >> userRow >> userCol;
        }

        // Already clicked mine check
        if (*(*(showingMap + userRow) + userCol) != '-')
        {
            cout << "Already revealed, choose another cell" << endl
                 << endl;
            continue;
        }

        // If bomb clicked by player
        if (*(*(mineMap + userRow) + userCol) == -1)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (*(*(mineMap + i) + j) == -1)
                        *(*(showingMap + i) + j) = '*';
                }
            }
            displayUserMap(showingMap, rows, cols);
            cout << "You clicked a mine, game over" << endl;
            gameRunning = false;
        }

        else
        {
            if (*(*(mineMap + userRow) + userCol) == 0)
            {
                safePlotReveal(mineMap, showingMap, rows, cols, userRow, userCol, safePlots);
            }
            else
            {
                int val = *(*(mineMap + userRow) + userCol);
                char toShow;
                if (val < 0)
                {
                    toShow = '*';
                }
                else
                {
                    toShow = char('0' + val);
                }

                *(*(showingMap + userRow) + userCol) = toShow;
                safePlots--;
            }
        }

        if (safePlots == 0)
        {
            displayUserMap(showingMap, rows, cols);
            cout << "You have clicked all the safe plots, You win" << endl;
            gameRunning = false;
        }
    }
}
