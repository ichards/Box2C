#include "Body.h"

// WARNING - BODY CONSTRUCTOR IS NOT A SIMPLE ZERO SET
// keep in mind i have Body_init instead of a constructor

Body Body_init() {
	Body temp = {0};
	
	Vec2_set(&temp.position, 0.0f, 0.0f);
	temp.rotation = 0.0f;
	Vec2_set(&temp.velocity, 0.0f, 0.0f);
	temp.angularVelocity = 0.0f;
	Vec2_set(&temp.force, 0.0f, 0.0f);
	temp.torque = 0.0f;
	temp.friction = 0.2f;

	Vec2_set(&temp.width, 1.0f, 1.0f);
	temp.mass = FLOAT_MAX;
	temp.invMass = 0.0f;
	temp.I = FLOAT_MAX;
	temp.invI = 0.0f;

	return temp;
}


void Body_Set(Body* body, const Vec2* w, float m) {
	Vec2_set(&body->position, 0.0f, 0.0f);
	body->rotation = 0.0f;
	Vec2_set(&body->velocity, 0.0f, 0.0f);
	body->angularVelocity = 0.0f;
	Vec2_set(&body->force, 0.0f, 0.0f);
	body->torque = 0.0f;
	body->friction = 0.2f;

	body->width = *w;
	body->mass = m;

	if (mass < FLOAT_MAX) {
		body->invMass = 1.0f / body->mass;
		body->I = body->mass * (body->width.x * body->width*x + body->width.y * body->width.y) / 12.0f;
		body->invI = 1.0f / body->I;
	} else {
		body->invMass = 0.0f;
		body->I = FLOAT_MAX;
		body->invI = 0.0f;
	}
}

void Body_AddForce(Body* body, const Vec2* f) {
	body->force += *f;
}


