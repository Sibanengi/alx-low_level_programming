#include <stdio.h>
#include "main.h"
#include <stdint.h>

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */

int get_endianness(void)
{
	uint32_t num = 1;
	uint8_t *byte_ptr = (uint8_t *) &num;

	return (*byte_ptr == 1) ? 1 : 0;
}
