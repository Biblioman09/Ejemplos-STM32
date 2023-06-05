#include "SSD1306.h"
#include "fonts.h"

//I2C_HandleTypeDef* SSD1306_hi2c1;

static SSD1306_t SSD1306;

uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];


//Funciones privadas. No accesibles desde main()
static void ssd1306_WriteData(uint8_t* data, uint16_t size);
//  Get a width and height screen size
//
static const uint16_t width(void){
	return SSD1306_WIDTH;
};
static const uint16_t height(void){
	return SSD1306_HEIGHT;
};

//Función de inicialización del LCD-OLE
void ssd1306_Init() {

	    //Chequea si el LCD está conectado al BUS I2C
		if (HAL_I2C_IsDeviceReady(&hi2c1, SSD1306_I2C_ADDRESS, 5, 1000) != HAL_OK)
		{
			SSD1306.Initialized = 0;
			/*Si no devuelve 0 */

		}


  HAL_Delay(100);

  ssd1306_command(SSD1306_DISPLAYOFF);                    // 0xAE
  ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
  ssd1306_command(0xF0);                                  // the suggested ratio 0x80
  ssd1306_command(SSD1306_SETMULTIPLEX);                  // 0xA8
  ssd1306_command(SSD1306_HEIGHT - 1);
  ssd1306_command(SSD1306_SETDISPLAYOFFSET);              // 0xD3
  ssd1306_command(0x0);                                   // no offset
  ssd1306_command(SSD1306_SETSTARTLINE);                  // 0x40
  ssd1306_command(SSD1306_CHARGEPUMP);                     // 0x8D

  if (SSD1306_HEIGHT == 32) {
    ssd1306_command(0x10);  // 0x10 is for 32 rows display
  } else {
    ssd1306_command(0x14);  // 0x14 is for 64 rows display
  }

  ssd1306_command(SSD1306_MEMORYMODE);                     // 0x20
  ssd1306_command(0x00);                                   // 0x0 act like ks0108
  ssd1306_command(SSD1306_SEGREMAP);                       //0xA0
  ssd1306_command(SSD1306_COMSCANINC);                     //0xC0

  #if SSD1306_HEIGHT == 64
  ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
  ssd1306_command(0x12);
  ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
  ssd1306_command(0xCF);
  #elif SSD1306_HEIGHT == 32
  ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
  ssd1306_command(0x02);
  ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
  ssd1306_command(0x8F);
  #endif

  ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xd9
  ssd1306_command(0xF1);
  ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
  ssd1306_command(0x40);
  ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
  ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6
  ssd1306_command(0x2E);

  ssd1306_command(SSD1306_DISPLAYON);                     // 0xAF

    //Inicialización posición de la pantalla por defecto
  	SSD1306.CurrentX = 0;
  	SSD1306.CurrentY = 0;
  	SSD1306.Color = Black;//Black

  	// Borramos pantalla--> apagamos pixeles
  	ssd1306_Clear();

  	//Refrescamos la pantalla con los datos del Búfer
  	ssd1306_UpdateScreen();

    //flag de inicialización =1
    SSD1306.Initialized = 1;

 }

// Envía un comando al bus I2C con la función HAL_I2C_Mem_Write_DMA, el parámetro 0x00 indica que se va a enviar un comando
void ssd1306_command (uint8_t command)
{
	while(HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY);
	HAL_I2C_Mem_Write_DMA(&hi2c1, SSD1306_I2C_ADDRESS, 0x00, 1, &command, 1);
}

// Envía el contenido de los datos del Buffer a través del bus I2C,el parámetro 0x40 indica que se va a enviar un dato
static void ssd1306_WriteData(uint8_t* data, uint16_t size){

	while(HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY);
	HAL_I2C_Mem_Write_DMA(&hi2c1, SSD1306_I2C_ADDRESS, 0x40, 1, data, size);

}

//Actualiza la función del cursor
void ssd1306_SetCursor(uint8_t x, uint8_t y) {
	SSD1306.CurrentX = x;
    SSD1306.CurrentY = y;
}

/* la función ssd1306_UpdateScreen() actualiza la pantalla enviando cada dato del Buffer a la función ssd1306_WriteData que se
 * encargará de enviarlo al bus I2C a través de la función HAL_I2C_Mem_Write_DMA
 */
void ssd1306_UpdateScreen(void) {

    uint8_t i;

      for (i = 0; i < 8; i++) {
        ssd1306_command(0xB0 + i);
        ssd1306_command(0x00);
        ssd1306_command(0x10);
        ssd1306_WriteData(&SSD1306_Buffer[SSD1306_WIDTH * i], width());

       }
}

/* ssd1306_WriteString

Esta función recibe un puntero a una cadena de caracteres (char*) y una estructura FontDef que contiene información sobre la fuente que se utilizará para escribir la cadena. La función itera sobre la cadena y llama a la función ssd1306_WriteChar para escribir cada carácter en la pantalla. Si la función ssd1306_WriteChar devuelve un valor diferente a cero, significa que hubo un error al escribir el carácter y la función devuelve ese carácter. Si la escritura de todos los caracteres se realiza correctamente, la función devuelve el valor nulo (\0).
*/

char ssd1306_WriteString(char* str, FontDef Font)
{
	// Write until null-byte
		while (*str)
		{
			if (ssd1306_WriteChar(*str, Font) != *str)
			{
				// Char could not be written
				return *str;
			}

			// Next char
			str++;
		}

		// Everything ok
		return *str;
}


char ssd1306_WriteChar(char ch, FontDef Font)
{
	uint32_t i, b, j;

	    // Comprueba el espacio que queda en la línea actual
		if (width() <= (SSD1306.CurrentX + Font.FontWidth) ||
			height() <= (SSD1306.CurrentY + Font.FontHeight))
		{
			// No hay suficiente espacio en la línea actual
			return 0;
		}

		// Usa la fuente seleccionada para escribir
		for (i = 0; i < Font.FontHeight; i++)
		{
			b = Font.data[(ch - 32) * Font.FontHeight + i];
			for (j = 0; j < Font.FontWidth; j++)
			{
				if ((b << j) & 0x8000)
				{
					ssd1306_DrawPixel(SSD1306.CurrentX + j, SSD1306.CurrentY + i);
				}
				else
				{
					SSD1306.Color = !SSD1306.Color;
					ssd1306_DrawPixel(SSD1306.CurrentX + j, SSD1306.CurrentY + i);
					SSD1306.Color = !SSD1306.Color;
				}
			}
		}


		SSD1306.CurrentX += Font.FontWidth;

		// Devuelve al caracter escrito
		return ch;
}


/*ssd1306_DrawPixel

Esta función toma como argumentos las coordenadas x e y del píxel que se desea dibujar, así como el color del mismo (0 para apagado, 1 para encendido). Primero se verifica si las coordenadas están dentro de los límites del display, y luego se verifica si el display está invertido. Si lo está, se invierte el color del píxel. Finalmente, se establece el bit correspondiente en el búfer del display.

*/

void ssd1306_DrawPixel(uint8_t x, uint8_t y)
{
	SSD1306_COLOR color = SSD1306.Color;

		if (x >= ssd1306_GetWidth() || y >= ssd1306_GetHeight())
		{
			// Don't write outside the buffer
			return;
		}

		// Check if pixel should be inverted
		if (SSD1306.Inverted)
		{
			color = (SSD1306_COLOR) !color;
		}

		// Draw in the right color
		if (color == White)
		{
			SSD1306_Buffer[x + (y / 8) * width()] |= 1 << (y % 8);
		}
		else
		{
			SSD1306_Buffer[x + (y / 8) * width()] &= ~(1 << (y % 8));
		}
}
/*  función ssd1306_Clear

La función recorre todo el buffer de memoria del display, y establece el valor de todos los bits a 0, es decir, apaga todos los píxeles. Luego, llama a la función ssd1306_UpdateScreen para que se reflejen los cambios en el display.
*/

void ssd1306_Clear(void) {

	memset(SSD1306_Buffer, 0, sizeof (SSD1306_Buffer));
 }


// Función Callback. Si no se refresca la instancia del puerto abierto no funciona
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if(hi2c->Instance == hi2c1.Instance)
	{
		//TODO:
	}
}






//###################################################################################################
//
//  Fill the whole screen with the given color
//
void ssd1306_Fill()
{
	/* Set memory */
	uint32_t i;

	for(i = 0; i < sizeof(SSD1306_Buffer); i++)
	{
		SSD1306_Buffer[i] = (SSD1306.Color == Black) ? 0x00 : 0xFF;
	}
}


///############################################################

//Funciones públicas
uint16_t ssd1306_GetWidth(void)
{
  return SSD1306_WIDTH;
}

uint16_t ssd1306_GetHeight(void)
{
  return SSD1306_HEIGHT;
}

SSD1306_COLOR ssd1306_GetColor(void)
{
	return SSD1306.Color;
}

void ssd1306_SetColor(SSD1306_COLOR color)
{
	SSD1306.Color = color;
}

