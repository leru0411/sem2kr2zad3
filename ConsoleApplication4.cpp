﻿//надо прошерстить все столбцы.
// сравнить элементы выше ГД с элементами ниже ГД в каждом и сложить те элементы, 
// находящиеся выше, которые больше любого, находящегося ниже ГД.
//
//2 2 2 2
//2 3 1 1
//2 1 4 0
//2 1 7 5 ГД - 2345. Возьмем второй столбец - 2 > 1 и 3 > 1 в итоге 2 + 3 записывается вместо тройки. .
//Возьмем третий столбец.Видно, что ни 2 ни 1 ни 4 не больше семерки, поэтому элемент ГД(4) остается неизменным.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(void) {
	setlocale(LC_ALL, "Russian"); // чтобы в консоли нормально отображалась кириллица
	int matri[7][7];
	int i, j, r, maxi = -1, n;
	printf("Введите диапозон чисел\n");
	scanf_s("%d", &r);
	//ниже просто создаем матрицу и заполняем ее числами от 0 до r включительно
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			matri[i][j] = rand() % r + 1;
			printf("%d ", matri[i][j]);
		}
		printf("\n");
	}
	//в цикле ниже мы проверяем поочередно !!СТОЛБЕЦ!!. Ищем максимальный элемент стобца, наход-ся ниже главной диагонали
	for (j = 0; j < 7; j++) {
		for (i = 0; i< 7; i++) {
			if (i > j and matri[i][j] > maxi) {
				maxi = matri[i][j];
			}
		} 			 
		printf("%d ", maxi); //выводим максимальный элемент столбца, находящийся ниже главной диагонали
		maxi = 0; //сразу же обнуляем эту переменную. В следующей итерации будем присваить макс. элемент следующего столбца
	} 		
	return 0;
}