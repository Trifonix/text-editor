/* Программа имитирует простой текстовый редактор.
 * 
 * Автор - Trifonix.
 * Версия программы - 0.1.
 */

/* Заголовочные файлы */
#include <unistd.h>

/* Функция (точка) входа в программу */
int main(void)
{
	/* Активация "грубого" режима - чтение по 1 байту из стандартного потока ввода */
	/* При появлении символа 'e' и передаче ввода в программу клавишей 'Enter' цикл прерывается */
	char c;
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'e');

	return 0;
}
