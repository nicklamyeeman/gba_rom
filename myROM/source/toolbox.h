/*
** EPITECH PROJECT, 2020
** ROM_GBA
** File description:
** toolbox
*/

#ifndef TOOLBOX_H
#define TOOLBOX_H

typedef unsigned char   u8;
typedef unsigned short  u16;
typedef u16 COLOR;

#define INLINE static inline
#define MEM_IO      0x04000000
#define MEM_VRAM    0x06000000

#define DCNT_MODE0     0x0000
#define DCNT_MODE1      0x0001
#define DCNT_MODE2      0x0002
#define DCNT_MODE3      0x0003
#define DCNT_MODE4      0x0004
#define DCNT_MODE5      0x0005

#define DCNT_BG0        0x0100
#define DCNT_BG1        0x0200
#define DCNT_BG2        0x0400
#define DCNT_BG3        0x0800
#define DCNT_OBJ        0x1000

#define M3_WIDTH       240
#define M3_SIZE        240
#define SCREEN_WIDTH   240
#define SCREEN_HEIGHT  160

#define vid_mem     ((u16*)MEM_VRAM)

#define CLR_BLACK   0x0000
#define CLR_RED     0x001F
#define CLR_LIME    0x03E0
#define CLR_YELLOW  0x03FF
#define CLR_BLUE    0x7C00
#define CLR_MAG     0x7C1F
#define CLR_CYAN    0x7FE0
#define CLR_WHITE   0x7FFF


INLINE COLOR RGB15(unsigned int red, unsigned int green, unsigned int blue)
{   return red | (green<<5) | (blue<<10);   }

void bmp16_line(int x1, int y1, int x2, int y2, unsigned int clr, void *dstBase, unsigned int dstPitch);
void bmp16_rect(int left, int top, int right, int bottom, unsigned int clr, void *dstBase, unsigned int dstPitch);
void bmp16_frame(int left, int top, int right, int bottom, unsigned int clr, void *dstBase, unsigned int dstPitch);
void m3_fill(COLOR clr);

INLINE void m3_plot(int x, int y, COLOR clr);
INLINE void m3_line(int x1, int y1, int x2, int y2, COLOR clr);
INLINE void m3_rect(int left, int top, int right, int bottom, COLOR clr);
INLINE void m3_frame(int left, int top, int right, int bottom, COLOR clr);

INLINE void m3_plot(int x, int y, COLOR clr)
{
    vid_mem[y * M3_WIDTH + x] = clr; 
}

INLINE void m3_line(int x1, int y1, int x2, int y2, COLOR clr)
{
    bmp16_line(x1, y1, x2, y2, clr, vid_mem, M3_WIDTH * 2);
}

INLINE void m3_rect(int left, int top, int right, int bottom, COLOR clr)
{
    bmp16_rect(left, top, right, bottom, clr, vid_mem, M3_WIDTH * 2);
}

INLINE void m3_frame(int left, int top, int right, int bottom, COLOR clr)
{
    bmp16_frame(left, top, right, bottom, clr, vid_mem, M3_WIDTH * 2);
}

#endif // TOOLBOX_H