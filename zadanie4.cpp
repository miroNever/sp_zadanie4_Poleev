// zadanie4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "zadanie4.h"

using namespace std;
struct Triangle
{
    float a;
    float b;
    float c;
};
bool isEquilateral(Triangle triangle)
{
    bool res = (triangle.a == triangle.b && triangle.b == triangle.c);
    return res;
}
void openFile(Triangle triangle[], int& i)
{
    setlocale(LC_ALL, "ru");
    FILE* inputFile;
    if ((inputFile = fopen("file.txt", "r")) == NULL) {
        cout << "Файл невозможно создать или открыть" << endl;
        return;
    }
    while (!feof(inputFile))
    {
        fscanf(inputFile, "%f %f %f", &triangle[i].a, &triangle[i].b, &triangle[i].c);
        printf("%.1f %.1f %.1f\n", triangle[i].a, triangle[i].b, triangle[i].c); 
        i++;
    }
    fclose(inputFile);
}
void writeFile(Triangle triangle[], int i)
{
    FILE* oututFile;
    fopen_s(&oututFile,"Rezultat.txt", "w");
    if (oututFile != NULL)
    {
        for (int j = 0; j < i; j++)
        {
            if (isEquilateral(triangle[j]))
                fprintf(oututFile, "Теругольник %d %.1f, %.1f, %.1f\n", j + 1,triangle[j].a, triangle[j].b, triangle[j].c);
        }
        fclose(oututFile);
    }
    else
        printf("Не удалось открыть файл Rezultat");

}
int main()
{
    setlocale(LC_ALL, "ru");
    Triangle tritangle[100];
    int i = 0;
    openFile(tritangle, i);
    cout << "Прочитано треугольников " << i << endl;
    writeFile(tritangle, i);
}
