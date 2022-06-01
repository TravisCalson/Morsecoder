#include "main.h"
#include "sign.h"
/**按键电平时间长短转换成字符*/
unsigned char sign_to_character(uint32_t * p)
{
	unsigned char character;
	if(*p == point 	&& *(p+1) == row && *(p+2) == null &&*(p+3) == null &&*(p+4) == null && *(p+5) == null) character = 'A';
	else if(*p == row 	&&*(p+1) == point &&*(p+2) == point &&*(p+3) == point &&*(p+4) == null  &&*(p+5) == null)	 character = 'B';
	else if(*p == row 	&&*(p+1) == point &&*(p+2) == row 	&&*(p+3) == point &&*(p+4) == null	&&*(p+5) == null)	 character = 'C';
	else if(*p == row 	&&*(p+1) == point &&*(p+2) == point &&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'D';
	else if(*p == point &&*(p+1) == null	&&*(p+2) == null	&&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'E';
	else if(*p == point &&*(p+1) == point &&*(p+2) == row 	&&*(p+3) == point &&*(p+4) == null	&&*(p+5) == null)	 character = 'F';
	else if(*p == row 	&&*(p+1) == row 	&&*(p+2) == point &&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'G';
	else if(*p == point &&*(p+1) == point &&*(p+2) == point &&*(p+3) == point &&*(p+4) == null	&&*(p+5) == null)	 character = 'H';
	else if(*p == point &&*(p+1) == point &&*(p+2) == null	&&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'I';
	else if(*p == point &&*(p+1) == row 	&&*(p+2) == row		&&*(p+3) == row		&&*(p+4) == null	&&*(p+5) == null)	 character = 'J';
	else if(*p == row 	&&*(p+1) == point &&*(p+2) == row		&&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'K';
	else if(*p == point &&*(p+1) == row 	&&*(p+2) == point &&*(p+3) == point &&*(p+4) == null	&&*(p+5) == null)	 character = 'L';
	else if(*p == row 	&&*(p+1) == row 	&&*(p+2) == null	&&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'M';
	else if(*p == row 	&&*(p+1) == point &&*(p+2) == null	&&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'N';
	else if(*p == row		&&*(p+1) == row 	&&*(p+2) == row		&&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'O';
	else if(*p == point &&*(p+1) == row 	&&*(p+2) == row		&&*(p+3) == point &&*(p+4) == null	&&*(p+5) == null)	 character = 'P';
	else if(*p == row		&&*(p+1) == row		&&*(p+2) == point &&*(p+3) == row 	&&*(p+4) == null	&&*(p+5) == null)	 character = 'Q';
	else if(*p == point &&*(p+1) == row 	&&*(p+2) == point	&&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'R';
	else if(*p == point &&*(p+1) == point &&*(p+2) == point &&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'S';
	else if(*p == row		&&*(p+1) == null	&&*(p+2) == null	&&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'T';
	else if(*p == point &&*(p+1) == point	&&*(p+2) == row 	&&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'U';
	else if(*p == point &&*(p+1) == point	&&*(p+2) == point	&&*(p+3) == row 	&&*(p+4) == null	&&*(p+5) == null)	 character = 'V';
	else if(*p == point &&*(p+1) == row 	&&*(p+2) == row 	&&*(p+3) == null	&&*(p+4) == null	&&*(p+5) == null)	 character = 'W';
	else if(*p == row		&&*(p+1) == point &&*(p+2) == point &&*(p+3) == row 	&&*(p+4) == null	&&*(p+5) == null)	 character = 'X';
	else if(*p == row		&&*(p+1) == point &&*(p+2) == row 	&&*(p+3) == row		&&*(p+4) == null	&&*(p+5) == null)	 character = 'Y';
	else if(*p == row		&&*(p+1) == row		&&*(p+2) == point &&*(p+3) == point &&*(p+4) == null	&&*(p+5) == null)	 character = 'Z';
	else if(*p == row		&&*(p+1) == row		&&*(p+2) == row 	&&*(p+3) == row 	&&*(p+4) == row 	&&*(p+5) == null)	 character = '0';
	else if(*p == point &&*(p+1) == row 	&&*(p+2) == row 	&&*(p+3) == row 	&&*(p+4) == row 	&&*(p+5) == null)	 character = '1';
	else if(*p == point &&*(p+1) == point &&*(p+2) == row		&&*(p+3) == row 	&&*(p+4) == row 	&&*(p+5) == null)	 character = '2';
	else if(*p == point &&*(p+1) == point &&*(p+2) == point &&*(p+3) == row 	&&*(p+4) == row 	&&*(p+5) == null)	 character = '3';
	else if(*p == point &&*(p+1) == point &&*(p+2) == point &&*(p+3) == point &&*(p+4) == row 	&&*(p+5) == null)	 character = '4';
	else if(*p == point &&*(p+1) == point &&*(p+2) == point &&*(p+3) == point &&*(p+4) == point &&*(p+5) == null)	 character = '5';
	else if(*p == row		&&*(p+1) == point &&*(p+2) == point &&*(p+3) == point &&*(p+4) == point &&*(p+5) == null)	 character = '6';
	else if(*p == row		&&*(p+1) == row 	&&*(p+2) == point &&*(p+3) == point &&*(p+4) == point &&*(p+5) == null)	 character = '7';
	else if(*p == row		&&*(p+1) == row 	&&*(p+2) == row 	&&*(p+3) == point &&*(p+4) == point &&*(p+5) == null)	 character = '8';
	else if(*p == row		&&*(p+1) == row 	&&*(p+2) == row 	&&*(p+3) == row 	&&*(p+4) == point &&*(p+5) == null)	 character = '9';
	else if(*p == point &&*(p+1) == point &&*(p+2) == row 	&&*(p+3) == row 	&&*(p+4) == point &&*(p+5) == point) character = '?';
	else if(*p == row 	&&*(p+1) == point &&*(p+2) == point &&*(p+3) == row 	&&*(p+4) == point &&*(p+5) == null)  character = '/';
	else if(*p == row 	&&*(p+1) == point &&*(p+2) == row 	&&*(p+3) == row 	&&*(p+4) == point	&&*(p+5) == row) 	 character = '(';
	else if(*p == row 	&&*(p+1) == point &&*(p+2) == point &&*(p+3) == point &&*(p+4) == point &&*(p+5) == row)   character = '-';
	else if(*p == point &&*(p+1) == row 	&&*(p+2) == point &&*(p+3) == row  	&&*(p+4) == point &&*(p+5) == row)   character = '.';
		else character = '\0';
		return character;
}