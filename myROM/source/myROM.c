/*
** EPITECH PROJECT, 2020
** ROM_GBA
** File description:
** myROM
*/

#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>

#include "toolbox.h"

int main()
{
	int i = 0;
	int j = 0;

    REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;

    m3_fill(RGB15(12, 12, 14));

    m3_rect( 12,  8, 108,  72, CLR_RED);
    m3_rect(108, 72, 132,  88, CLR_LIME);
    m3_rect(132, 88, 228, 152, CLR_BLUE);

    m3_frame(132,  8, 228,  72, CLR_CYAN);
    m3_frame(109, 73, 131,  87, CLR_BLACK);
    m3_frame( 12, 88, 108, 152, CLR_YELLOW);

    for (i = 0; i != 9; i ++)
    {
        j = 3 * i + 7;
        m3_line(132 + 11 * i, 9, 226, 12 + 7 * i, RGB15(j, 0, j));
        m3_line(226 - 11 * i, 70, 133, 69 - 7 * i, RGB15(j, 0, j));
    }

    for (i = 0; i != 9; i++)
    {
        j = 3 * i + 7;
        m3_line(15 + 11 * i, 88, 104 - 11 * i, 150, RGB15(0, j, j));
    }

    while (1);

    return 0;
}


