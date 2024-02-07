#include "Body.h"

void Body_Set(const Vec2* w, float m) {
	// PUT SOMETHING HERE
}

void Body_AddForce(Body* body, const Vec2* f) {
	body->force += *f;
}


