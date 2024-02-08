#ifndef JOINT_H
#define JOINT_H

#include "math_util.h"
#include "Body.h"

typedef struct _Joint {
	Mat22 M;
	Vec2 localAnchor1, localAnchor2;
	Vec2 r1, r2;
	Vec2 bias;
	Vec2 P;
	Body* body1;
	Body* body2;
	float biasFactor;
	float softness;
} Joint;

Joint Joint_init();

void Joint_Set(Joint* joint, Body* body1, Body* body2, const Vec2* anchor);

