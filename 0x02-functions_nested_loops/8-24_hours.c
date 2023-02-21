#include "main.h"

/**
 * jack_bauer - pprints every minute of the day
 * of Jack Bauer, starting from 00:00 to 23:59
 *  Return: void
 */

void jack_bauer(void)
{
	int dig1;
	int dig2;
	int dig3;
	int dig4;

	for (dig1 = 0; dig1 < 3; dig1++)
	{
		for (dig2 = 0; dig2 < 10; dig2++)
		{
			if (dig1 == 2 && dig2 == 4)
			{
				break;
			}

			for (dig3 = 0; dig3 < 6; dig3++)
			{
				for (dig4 = 0; dig4 < 10; dig4++)
				{
					_putchar('0' + dig1);
					_putchar('0' + dig2);
					_putchar(':');
					_putchar('0' + dig3);
					_putchar('0' + dig4);
					_putchar('\n');
				}
			}
		}
	}
}
