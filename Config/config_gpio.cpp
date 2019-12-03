#include "config_gpio.hpp"

void GPIO_Init(void)
{
	__GPIOA_CLK_ENABLE();
	__GPIOD_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// user button
	GPIO_InitStructure.Pin = GPIO_PIN_0;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// LED pins
	GPIO_InitStructure.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
}