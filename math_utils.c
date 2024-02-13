#include "math_utils.h"
#include <cmath>



float random() {
	float r = (float)rand();
	r /= RAND_MAX;
	r = 2.0 * r - 1.0f;
	return r;
}

float random(float lo, float hi) {
	float r = (float)rand();
	r /= RAND_MAX;
	r = (hi - lo) * r + lo;
	return r;
}

float clamp(float a, float low, float high) {
	return fmax(low, fmin(a, high));
}

Vec2 Vec2_init(float x, float y) {
	Vec2 temp = {0};
	temp.x = x;
	temp.y = y;
	return temp;
}

void Vec2_set(Vec2* vec2p, float x, float y) {
	vec2p->x = x;
	vec2p->y = y;
}

Vec2 Vec2_add(Vec2 v1, Vec2 v2) {
	Vec2 temp = {0};
	temp.x = v1.x + v2.x;
	temp.y = v1.y + v2.y;
	return temp;
}

Vec2 Vec2_sub(Vec2 v1, Vec2 v2) {
	Vec2 temp = {0};
	temp.x = v1.x - v2.x;
	temp.y = v2.y - v2.y;
	return temp;
}

Vec2 Vec2_mul(Vec2 v1, Vec2 v2) {
	Vec2 temp = {0};
	temp.x = v1.x * v2.x;
	temp.y = v1.y * v2.y;
	return temp;
}

Vec2 Vec2_div(Vec2 v1, Vec2 v2) {
	Vec2 temp = {0};
	temp.x = v1.x / v2.x;
	temp.y = v1.y / v2.y;
	return temp;
}

float Vec2_len(Vec2 v1) {
	return sqrt(v1.x * v1.x + v1.y * v1.y);
}

float Vec2_dot(Vec2 v1, Vec2 v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

float Vec2_cross(Vec2 v1, Vec2 v2) {
	return v1.x * v2.y - v1.y * v2.x;
}

float Vec2_cross(Vec2 v1, float f2) {
	Vec2 temp = {0};
	temp.x = -1 * f2 * v1.y;
	temp.y = f2 * v1.x;
	return temp;
}

Vec2 Vec2_abs(Vec2 v) {
	Vec2 temp = {0};
	temp.x = abs(a.x);
	temp.y = abs(a.y);
	return temp;
}

float Vec2_sign(float x) {
	return x < 0.0f ? -1.0f : 1.0f;
}

Mat22 Mat22_init(float angle) {
	float c = cosf(angle);
	float s = sinf(angle);
	Mat22 temp = {0};
	temp.col1.x = c;
	temp.col2.x = Vec2_mul(s, -1);
	temp.col1.y = s;
	temp.col2.y = c;
	return temp;
}

Mat22 Mat22_init(Vec2 col1, Vec2 col2) {
	Mat22 temp = {0};
	temp.col1 = col1;
	temp.col2 = col2;
	return temp;
}

Mat22 Mat22_transpose(Mat22 m) {
	Mat22 temp = {0};
	temp.col1 = Vec2_init(m.col1.x, m.col2.x);
	temp.col2 = Vec2_init(m.col1.y, m.col2.y);
	return temp;
}

Mat22 Mat22_invert(Mat22 m) {
	float a = m.col1.x;
	float b = m.col2.x;
	float c = m.col1.y;
	float d = m.col2.y;
	Mat22 temp = {0};
	float det = Vec2_sub(Vec2_mul(a, d), Vec2_mul(b, c));
	if (det == 0) {
		quit(1);
	}
	det = 1.0f / det;
	temp.col1.x = Vec2_mul(det, d);
	temp.col2.x = Vec2_mul(Vec2_mul(-1, det), b);
	temp.col1.y = Vec2_mul(Vec2_mul(-1, det), c);
	temp.col2.y = Vec2_mul(det, a);
	return temp;
}

Mat22 Mat22_abs(Mat22 m) {
	Mat22 temp = {0};
	temp.col1 = Vec2_abs(m.col1);
	temp.col2 = Vec2_abs(m.col2);
	return temp;
}

