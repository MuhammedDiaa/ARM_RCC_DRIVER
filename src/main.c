/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "RCC_interface.h"

#define PORTA_CRL    *((volatile u32*)0x40010800)
#define PORTA_ODR    *((volatile u32*)0x4001080C)

void UTIL_DelayMS(unsigned int delay_ms)
{
    unsigned int x;
    unsigned int y;

    for (x = 0; x < delay_ms; x++)
    {
        for(y = 0; y <delay_ms; y++)
        {
        	asm("NOP");
        }
    }

}

void main()
{
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2,RCC_IOPA);

	PORTA_CRL = 0x00000002;
	PORTA_ODR = 0x00000000;

  while (1)
    {
	  PORTA_ODR = 0x00000001;
	  UTIL_DelayMS(500);
	  PORTA_ODR = 0x00000000;
	  UTIL_DelayMS(500);
    }
}

