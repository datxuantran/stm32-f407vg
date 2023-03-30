/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*
 * Gruppe 11
 * Dat Tran
 * Jonah Koller
 */

#include <stddef.h>
#include <stdint.h>

void delay(void){
	for(volatile uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
	// enable clock for portD,
	// on AHB1ENR at GPIODEN bit
	*((volatile uint32_t*)(0x40023800U + 0x30U)) |= (1 << 3);

	// PD12 LD4 Green
	// PD13 LD3 Orange

	/* Configure PD14 LD5 Red */
	// set PD14's direction as output
	// on GPIOD_MODER at MODER14 bit
	*((volatile uint32_t*)(0x40020C00U + 0x00U)) &= ~(1 << 29);
	*((volatile uint32_t*)(0x40020C00U + 0x00U)) |= (1 << 28);

	// set PD14's output modus as push-pull
	// on GPIOD_OTYPER at OT14 bit
	*((volatile uint32_t*)(0x40020C00U + 0x04U)) &= ~(1<<14);


	/* Configure PD15 LD6 Blue */
	// set PD15's direction as output
	// on GPIOD_MODER at MODER15 bit
	*((volatile uint32_t*)(0x40020C00U + 0x00U)) &= ~(1 << 31);
	*((volatile uint32_t*)(0x40020C00U + 0x00U)) |= (1 << 30);

	// set PD15's output modus as push-pull
	// on GPIOD_OTYPER at OT15 bit
	*((volatile uint32_t*)(0x40020C00U + 0x04U)) &= ~(1<<15);



    /* Loop forever */
	while(1){
		// activate PD14
		*((volatile uint32_t*)(0x40020C00U + 0x14U)) |= (1<<14);
		// activate PD15
		*((volatile uint32_t*)(0x40020C00U + 0x14U)) |= (1<<15);
		delay();

		// deactivate PD14
		*((volatile uint32_t*)(0x40020C00U + 0x14U)) &= ~(1<<14);
		// deactivate PD15
		*((volatile uint32_t*)(0x40020C00U + 0x14U)) &= ~(1<<15);
		delay();
	}
}
