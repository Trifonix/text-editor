/* Программа имитирует простой текстовый редактор.
 * 
 * Автор - Trifonix.
 * Версия программы - 0.1.
 */

/* Заголовочные файлы */
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios;

void disableRawMode()
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

/* Активация "грубого" режима - отключение вывода введенных символов в консоль */
void enableRawMode(void)
{
	tcgetattr(STDIN_FILENO, &orig_termios);
	atexit(disableRawMode);

	struct termios raw = orig_termios;
	raw.c_lflag &= ~(ECHO);

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

/* Функция (точка) входа в программу */
int main(void)
{
	enableRawMode();

	/* Чтение по 1 байту из стандартного потока ввода */
	/* При появлении символа 'e' и передаче ввода в программу клавишей 'Enter' цикл прерывается */
	char c;
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'e');

	return 0;
}
