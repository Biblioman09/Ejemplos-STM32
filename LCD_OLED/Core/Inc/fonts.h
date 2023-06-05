#include <stdint.h>


#ifndef FONTS_H_
#define FONTS_H_

typedef struct {
	const uint8_t FontWidth;    /*Ancho en pixeles de la fuente */
	uint8_t FontHeight;   /*Alto en pixeles de la fuente*/
	const uint16_t *data; /*Puntero al arry de datos */
} FontDef;


extern FontDef Font_6x8;
extern FontDef Font_7x10;
extern FontDef Font_11x18;
extern FontDef Font_16x26;


#endif
