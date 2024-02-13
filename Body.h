#ifndef BODY_H
#define BODY_H

#include "MathUtils.h"

typedef struct _Body {
	Vec2 position;
	float rotation;

	Vec2 velocity;
	float angularVelocity;

	Vec2 force;
	float torque;

	Vec2 width;

	float friction;
	float mass, invMass;
	float I, invI;
} Body;

Body Body_init(); 

void Body_Set(Body* body, const Vec2* w, float m);

void Body_AddForce(Body* body, const Vec2* f);

#endif
