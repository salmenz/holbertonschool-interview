#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <stdio.h>
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1


int slide_line(int *line, size_t size, int direction);
int right_d(int *line, size_t size);
int right_s(int *line, size_t size);
int left_s(int *line, size_t size);
int left_d(int *line, size_t size);

#endif SLIDE_LINE_H