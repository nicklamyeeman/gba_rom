/*
** EPITECH PROJECT, 2020
** ROM_GBA
** File description:
** toolbox
*/

#include "toolbox.h"

void bmp16_line(int x1, int y1, int x2, int y2, unsigned int clr, void *dstBase, unsigned int dstPitch)
{
    int i, dx, dy, xstep, ystep, dd;
    u16 *dst = (u16*)(dstBase + y1*dstPitch + x1 * 2);
    dstPitch /= 2;

    // Normalization
    if (x1 > x2) {
        xstep = -1;
        dx = x1 - x2;
    }
    else {
        xstep = 1;
        dx = x2 - x1;
    }
    if (y1 > y2) {
        ystep = -dstPitch;
        dy = y1 - y2;
    }
    else {
        ystep = dstPitch;
        dy = y2 - y1;
    }

    // Drawing
    if (dy == 0) {
        for (i = 0; i <= dx; i++)
            dst[i * xstep] = clr;
    }
    else if (dx == 0) {
        for (i = 0; i <= dy; i++)
            dst[i * ystep] = clr;
    }
    else if (dx >= dy) {
        dd = 2 * dy - dx;
        for (i = 0; i <= dx; i++) {
            *dst = clr;
            if (dd >= 0) {
                dd -= 2 * dx;
                dst += ystep;
            }
            dd += 2 * dy;
            dst += xstep;
        }               
    }
    else {
        dd = 2 * dx - dy;
        for (i = 0; i <= dy; i++) {
            *dst = clr;
            if (dd >= 0) {
                dd -= 2 * dy;
                dst += xstep;
            }
            dd += 2 * dx;
            dst += ystep;
        }       
    }
}

void bmp16_rect(int left, int top, int right, int bottom, unsigned int clr, void *dstBase, unsigned int dstPitch)
{
    int ix, iy;

    unsigned int width = right - left;
    unsigned int height = bottom - top;
    u16 *dst = (u16*)(dstBase+top*dstPitch + left * 2);
    dstPitch /= 2;

    // Draw
    for( iy = 0; iy != height; iy++)
        for(ix = 0; ix != width; ix++)
            dst[iy*dstPitch + ix] = clr;
}

void bmp16_frame(int left, int top, int right, int bottom, unsigned int clr, void *dstBase, unsigned int dstPitch)
{
    right--;
    bottom--;

    bmp16_line(left,  top,   right,  top,    clr, dstBase, dstPitch);
    bmp16_line(left,  bottom, right, bottom, clr, dstBase, dstPitch);

    bmp16_line(left,  top,   left,   bottom, clr, dstBase, dstPitch);
    bmp16_line(right, top,   right,  bottom, clr, dstBase, dstPitch);
}

void m3_fill(COLOR clr) 
{   
    int i;
    unsigned int *dst = (unsigned int *)vid_mem;
    unsigned int wd = (clr<<16) | clr;

    for (i = 0; i != M3_SIZE / 4; i++)
        *dst++ = wd;
}