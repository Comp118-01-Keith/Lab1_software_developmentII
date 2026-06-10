/**
 * \file Source.cpp
 * \brief Program for drawing different shapes using characters.
 * \details This program allows the user to draw horizontal lines, vertical lines,
 * squares, filled squares, rectangles, filled rectangles, random shapes, and
 * shapes stored in arrays. The user selects options from a menu.
 * \author Keith Kimani
 * \version 0.1
 * \date 2026
 * \copyright GNU Public License.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <limits>

using namespace std;

const int MAX_SHAPES = 10;

/**
 * Displays the main menu options to the user.
 */
void showMenu();

/**
 * Draws a horizontal line using the chosen character.
 * @param length The number of characters printed in the line.
 * @param ch The character used to draw the line.
 */
void drawHorizontalLine(const int length, const char ch);

/**
 * Draws a vertical line using the chosen character.
 * @param height The number of rows printed.
 * @param ch The character used to draw the line.
 */
void drawVerticalLine(const int height, const char ch);

/**
 * Draws a hollow square using the chosen character.
 * @param size The height and width of the square.
 * @param ch The character used to draw the square border.
 */
void drawSquare(const int size, const char ch);

/**
 * Draws a filled square using the chosen character.
 * @param size The height and width of the square.
 * @param ch The character used to fill the square.
 */
void drawSquareFilled(const int size, const char ch);

/**
 * Draws a hollow rectangle using the chosen character.
 * @param height The number of rows in the rectangle.
 * @param length The number of columns in the rectangle.
 * @param ch The character used to draw the rectangle border.
 */
void drawRectangle(const int height, const int length, const char ch);

/**
 * Draws a filled rectangle using the chosen character.
 * @param height The number of rows in the rectangle.
 * @param length The number of columns in the rectangle.
 * @param ch The character used to fill the rectangle.
 */
void drawRectangleFilled(const int height, const int length, const char ch);

/**
 * Randomly generates and draws a number of shapes.
 * @param numShapes The number of random shapes to generate and draw.
 */
void drawShapes(const int numShapes);

/**
 * Fills arrays with random shape types, lengths, and characters.
 * @param shapeTy Array storing shape types from 1 to 6.
 * @param shapeLen Array storing the size or length of each shape.
 * @param shapeCh Array storing the character used to draw each shape.
 * @param arrSize The size of the arrays.
 */
void initializeArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int arrSize);

/**
 * Draws shapes using information stored in arrays.
 * @param shapeTy Array storing shape types from 1 to 6.
 * @param shapeLen Array storing the size or length of each shape.
 * @param shapeCh Array storing the character used to draw each shape.
 * @param arrSize The size of the arrays.
 */
void drawArrays(const int shapeTy[], const int shapeLen[], const char shapeCh[], const int arrSize);

/**
 * Clears invalid input from the input stream.
 */
void clearInput();

/**
 * Main function of the program.
 * @return Returns 0 when the program finishes successfully.
 */
int main()
{
    srand(time(NULL));

    int choice = 0;
    int length = 0;
    int height = 0;
    int size = 0;
    char ch = '*';

    int shapeType[MAX_SHAPES];
    int shapeLength[MAX_SHAPES];
    char shapeCharacter[MAX_SHAPES];

    bool arraysInitialized = false;

    do
    {
        showMenu();

        cout << "Enter your option: ";
        cin >> choice;

        if (cin.fail())
        {
            clearInput();
            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter line length: ";
            cin >> length;

            cout << "Enter drawing character: ";
            cin >> ch;

            if (length > 0)
            {
                drawHorizontalLine(length, ch);
            }
            else
            {
                cout << "Length must be greater than 0.\n";
            }

            break;

        case 2:
            cout << "Enter line height: ";
            cin >> height;

            cout << "Enter drawing character: ";
            cin >> ch;

            if (height > 0)
            {
                drawVerticalLine(height, ch);
            }
            else
            {
                cout << "Height must be greater than 0.\n";
            }

            break;

        case 3:
            cout << "Enter square size: ";
            cin >> size;

            cout << "Enter drawing character: ";
            cin >> ch;

            if (size > 0)
            {
                drawSquare(size, ch);
            }
            else
            {
                cout << "Size must be greater than 0.\n";
            }

            break;

        case 4:
            cout << "Enter square size: ";
            cin >> size;

            cout << "Enter drawing character: ";
            cin >> ch;

            if (size > 0)
            {
                drawSquareFilled(size, ch);
            }
            else
            {
                cout << "Size must be greater than 0.\n";
            }

            break;

        case 5:
            cout << "Enter rectangle height: ";
            cin >> height;

            cout << "Enter rectangle length: ";
            cin >> length;

            cout << "Enter drawing character: ";
            cin >> ch;

            if (height > 0 && length > 0)
            {
                drawRectangle(height, length, ch);
            }
            else
            {
                cout << "Height and length must be greater than 0.\n";
            }

            break;

        case 6:
            cout << "Enter rectangle height: ";
            cin >> height;

            cout << "Enter rectangle length: ";
            cin >> length;

            cout << "Enter drawing character: ";
            cin >> ch;

            if (height > 0 && length > 0)
            {
                drawRectangleFilled(height, length, ch);
            }
            else
            {
                cout << "Height and length must be greater than 0.\n";
            }

            break;

        case 7:
            drawShapes(MAX_SHAPES);
            break;

        case 8:
            initializeArrays(shapeType, shapeLength, shapeCharacter, MAX_SHAPES);
            arraysInitialized = true;
            cout << "\nArrays initialized successfully.\n";
            break;

        case 9:
            if (arraysInitialized == false)
            {
                cout << "\nYou must initialize the arrays first. Choose option 8.\n";
            }
            else
            {
                drawArrays(shapeType, shapeLength, shapeCharacter, MAX_SHAPES);
            }

            break;

        case 10:
            cout << "\nGoodbye.\n";
            break;

        default:
            cout << "\nInvalid option. Try again.\n";
        }

        cout << endl;

    } while (choice != 10);

    return 0;
}

/**
 * Displays the main menu options to the user.
 */
void showMenu()
{
    cout << "\n========== SHAPE MENU ==========\n";
    cout << "1) Draw a horizontal line\n";
    cout << "2) Draw a vertical line\n";
    cout << "3) Draw a square\n";
    cout << "4) Draw a square Filled\n";
    cout << "5) Draw a rectangle\n";
    cout << "6) Draw a rectangle Filled\n";
    cout << "7) Draw random shapes\n";
    cout << "8) Initialize shape arrays\n";
    cout << "9) Draw shapes from arrays\n";
    cout << "10) Quit\n";
    cout << "================================\n";
}

/**
 * Draws a horizontal line using the chosen character.
 * @param length The number of characters printed in the line.
 * @param ch The character used to draw the line.
 */
void drawHorizontalLine(const int length, const char ch)
{
    assert(length > 0);

    cout << endl;

    for (int i = 0; i < length; i++)
    {
        cout << ch;
    }

    cout << endl;
}

/**
 * Draws a vertical line using the chosen character.
 * @param height The number of rows printed.
 * @param ch The character used to draw the line.
 */
void drawVerticalLine(const int height, const char ch)
{
    assert(height > 0);

    cout << endl;

    for (int i = 0; i < height; i++)
    {
        cout << ch << endl;
    }
}

/**
 * Draws a hollow square using the chosen character.
 * @param size The height and width of the square.
 * @param ch The character used to draw the square border.
 */
void drawSquare(const int size, const char ch)
{
    assert(size > 0);

    cout << endl;

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (row == 0 || row == size - 1 || col == 0 || col == size - 1)
            {
                cout << ch;
            }
            else
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}

/**
 * Draws a filled square using the chosen character.
 * @param size The height and width of the square.
 * @param ch The character used to fill the square.
 */
void drawSquareFilled(const int size, const char ch)
{
    assert(size > 0);

    cout << endl;

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            cout << ch;
        }

        cout << endl;
    }
}

/**
 * Draws a hollow rectangle using the chosen character.
 * @param height The number of rows in the rectangle.
 * @param length The number of columns in the rectangle.
 * @param ch The character used to draw the rectangle border.
 */
void drawRectangle(const int height, const int length, const char ch)
{
    assert(height > 0);
    assert(length > 0);

    cout << endl;

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < length; col++)
        {
            if (row == 0 || row == height - 1 || col == 0 || col == length - 1)
            {
                cout << ch;
            }
            else
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}

/**
 * Draws a filled rectangle using the chosen character.
 * @param height The number of rows in the rectangle.
 * @param length The number of columns in the rectangle.
 * @param ch The character used to fill the rectangle.
 */
void drawRectangleFilled(const int height, const int length, const char ch)
{
    assert(height > 0);
    assert(length > 0);

    cout << endl;

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < length; col++)
        {
            cout << ch;
        }

        cout << endl;
    }
}

/**
 * Randomly generates and draws a number of shapes.
 * @param numShapes The number of random shapes to generate and draw.
 */
void drawShapes(const int numShapes)
{
    assert(numShapes > 0);

    int shapeType;
    int shapeLength;
    char shapeCharacter;

    for (int i = 0; i < numShapes; i++)
    {
        shapeType = rand() % 6 + 1;
        shapeLength = rand() % 16 + 5;
        shapeCharacter = char(rand() % 94 + 33);

        cout << "\nRandom Shape " << i + 1 << endl;
        cout << "Shape type: " << shapeType << endl;
        cout << "Shape length: " << shapeLength << endl;
        cout << "Shape character: " << shapeCharacter << endl;

        switch (shapeType)
        {
        case 1:
            drawHorizontalLine(shapeLength, shapeCharacter);
            break;

        case 2:
            drawVerticalLine(shapeLength, shapeCharacter);
            break;

        case 3:
            drawSquare(shapeLength, shapeCharacter);
            break;

        case 4:
            drawSquareFilled(shapeLength, shapeCharacter);
            break;

        case 5:
            drawRectangle(shapeLength, shapeLength + 5, shapeCharacter);
            break;

        case 6:
            drawRectangleFilled(shapeLength, shapeLength + 5, shapeCharacter);
            break;
        }
    }
}

/**
 * Fills arrays with random shape types, lengths, and characters.
 * @param shapeTy Array storing shape types from 1 to 6.
 * @param shapeLen Array storing the size or length of each shape.
 * @param shapeCh Array storing the character used to draw each shape.
 * @param arrSize The size of the arrays.
 */
void initializeArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int arrSize)
{
    assert(arrSize > 0);

    for (int i = 0; i < arrSize; i++)
    {
        shapeTy[i] = rand() % 6 + 1;
        shapeLen[i] = rand() % 20 + 1;
        shapeCh[i] = char(rand() % 94 + 33);
    }
}

/**
 * Draws shapes using information stored in arrays.
 * @param shapeTy Array storing shape types from 1 to 6.
 * @param shapeLen Array storing the size or length of each shape.
 * @param shapeCh Array storing the character used to draw each shape.
 * @param arrSize The size of the arrays.
 */
void drawArrays(const int shapeTy[], const int shapeLen[], const char shapeCh[], const int arrSize)
{
    assert(arrSize > 0);

    for (int i = 0; i < arrSize; i++)
    {
        cout << "\nArray Shape " << i + 1 << endl;
        cout << "Shape type: " << shapeTy[i] << endl;
        cout << "Shape length: " << shapeLen[i] << endl;
        cout << "Shape character: " << shapeCh[i] << endl;

        switch (shapeTy[i])
        {
        case 1:
            drawHorizontalLine(shapeLen[i], shapeCh[i]);
            break;

        case 2:
            drawVerticalLine(shapeLen[i], shapeCh[i]);
            break;

        case 3:
            drawSquare(shapeLen[i], shapeCh[i]);
            break;

        case 4:
            drawSquareFilled(shapeLen[i], shapeCh[i]);
            break;

        case 5:
            drawRectangle(shapeLen[i], shapeLen[i] + 5, shapeCh[i]);
            break;

        case 6:
            drawRectangleFilled(shapeLen[i], shapeLen[i] + 5, shapeCh[i]);
            break;

        default:
            cout << "Invalid shape type.\n";
        }
    }
}

/**
 * Clears invalid input from the input stream.
 */
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}