#ifndef MATH_UTILS_H
#define MATH_UTILS_H

const float k_pi = 3.14159265358979323846264f;

// place holder
#define FLOAT_MAX 1000.0f

typedef struct _Vec2 {
	float x, y;
} Vec2;

typedef struct _Mat22 {
	Vec2 col1, col2;
} Mat22;

#endif
