/*
 * C
 *
 * Copyright 2023 MicroEJ Corp. All rights reserved.
 * This library is provided in source code for use, modification and test, subject to license terms.
 * Any modification of the source code will break MicroEJ Corp. warranties on the whole library.
 */

/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx.h"
#include "stm32f4xx_hal_uart.h"
#include <stdio.h>


/* Defines -------------------------------------------------------------------*/

#define UART_TRANSMIT_TIMEOUT 0xFFFF

/* Global --------------------------------------------------------------------*/



/* Private API ---------------------------------------------------------------*/



/* Public functions ----------------------------------------------------------*/

/* Global --------------------------------------------------------------------*/

UART_HandleTypeDef huart3;

// cppcheck-suppress [misra-c2012-8.9]: Global variable necessary to do only one init.
static int putchar_initialized = 0;

/* Private API ---------------------------------------------------------------*/

static void PUTCHAR_init(void)
{

	  huart3.Instance = USART3;
	  huart3.Init.BaudRate = 115200;
	  huart3.Init.WordLength = UART_WORDLENGTH_8B;
	  huart3.Init.StopBits = UART_STOPBITS_1;
	  huart3.Init.Parity = UART_PARITY_NONE;
	  huart3.Init.Mode = UART_MODE_TX_RX;
	  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
	  if (HAL_UART_Init(&huart3) != HAL_OK)
	  {
	    Error_Handler();
	  }
}

static int PUTCHAR(int ch)
{
    if (!putchar_initialized)
    {
        PUTCHAR_init();
        putchar_initialized = 1;
    }

    HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, UART_TRANSMIT_TIMEOUT);

    return ch;
}

/* Public functions ----------------------------------------------------------*/

// cppcheck-suppress [misra-c2012-21.2]: this reserved identifier is overriden on purpose.
int fputc(int ch, FILE *f)
{
	(void)(f);

	return PUTCHAR(ch);
}

int _write(int file, char *data, int len)
{
	(void)(file);
    int bytes_written;

    for (bytes_written = 0; bytes_written < len; bytes_written++)
    {
    	// cppcheck-suppress [misra-c2012-17.7]: returned value not used for performance purpose to avoid unnecessary checks
        PUTCHAR(*data);
        data++;
    }

    return bytes_written;
}

