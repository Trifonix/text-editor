#include <unistd.h>

int main(void)
{
	char c;
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'e');
	return 0;
}
