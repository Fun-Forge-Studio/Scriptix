#ifndef CONSOLE
#define CONSOLE
#include "../include/console.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char
{
    uint8_t character;
    uint8_t color;
};

struct Char *buffer = (struct Char *)0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t default_color = WHITE_COLOR | BLACK_COLOR << 4;

void clear_row(size_t row)
{
    struct Char empty = (struct Char){
        character : ' ',
        color : default_color,
    };

    for (size_t col = 0; col < NUM_COLS; col++)
    {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void clear_screen()
{
    for (size_t i = 0; i < NUM_ROWS; i++)
    {
        clear_row(i);
    }
}

void newline()
{
    col = 0;

    if (row < NUM_ROWS - 1)
    {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++)
    {
        for (size_t col = 0; col < NUM_COLS; col++)
        {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_COLS - 1);
}

void typec(char character)
{
    if (character == '\n')
    {
        newline();
        return;
    }

    if (col > NUM_COLS)
    {
        newline();
    }

    buffer[col + NUM_COLS * row] = (struct Char){
        character : (uint8_t)character,
        color : default_color,
    };

    col++;
}

void type(const char *str)
{
    for (size_t i = 0; 1; i++)
    {
        char character = (uint8_t)str[i];

        if (character == '\0')
        {
            return;
        }

        typec(character);
    }
}

void TypeLine(const char *str)
{
    type(str);
    newline();
}

void setcolor(uint8_t foreground, uint8_t background)
{
    default_color = foreground + (background << 4);
}

#endif