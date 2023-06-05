#ifndef __SSD1306_H__
#define __SSD1306_H__

//#include "stm32f4xx_hal.h"
#include "fonts.h"
#include "main.h"
#include <stdlib.h>
#include <string.h>

// OLED resolution in pixels
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

//Fuente utilizada
//#define SSD1306_INCLUDE_FONT_6x8
#define SSD1306_INCLUDE_FONT_7x10

// I2C address of the OLED display
#define SSD1306_I2C_ADDRESS   0x3C<<1 // 011110+SA0+RW - 0x3C or 0x3D (Address for 128x64 is 0x3C) (0x3C<<1 = 0x78)

// SSD1306 commands
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETSTARTLINE 0x40
#define SSD1306_CHARGEPUMP 0x8D
#define SSD1306_MEMORYMODE 0x20
#define SSD1306_SEGREMAP 0xA0
#define SSD1306_COMSCANDEC 0xC8
#define SSD1306_COMSCANINC 0xC0
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETCONTRAST 0x81
#define SSD1306_SETPRECHARGE 0xD9
#define SSD1306_SETVCOMDETECT 0xDB
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_DISPLAYON 0xAF


//Definition del puerto i2c definido en main
extern I2C_HandleTypeDef hi2c1;

// Enumeración para color LCD
typedef enum {
	Black = 0x00, // Black color, no pixel
	White = 0x01,  //Pixel encendido. El Color depende de cada LCD
	Inverse = 0x02
} SSD1306_COLOR;

//Estructura configuración LCD
typedef struct {
	uint16_t CurrentX;
	uint16_t CurrentY;
	uint8_t Inverted;
	SSD1306_COLOR Color;
	uint8_t Initialized;
} SSD1306_t;


//Prototipos de funciones
void ssd1306_Init(void);
void ssd1306_command(uint8_t command);
void ssd1306_SetCursor(uint8_t x, uint8_t y);
void ssd1306_UpdateScreen_DMA(void);
char ssd1306_WriteChar(char ch, FontDef Font);
char ssd1306_WriteString(char* str, FontDef Font);
void ssd1306_DrawPixel(uint8_t x, uint8_t y);
void ssd1306_Clear(void);
void ssd1306_Fill();
SSD1306_COLOR ssd1306_GetColor(void);
void ssd1306_SetColor(SSD1306_COLOR color);
uint16_t ssd1306_GetWidth(void);
uint16_t ssd1306_GetHeight(void);
#endif /* __SSD1306_H__ */

