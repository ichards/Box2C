#ifndef WORLD_H
#define WORLD_H

#include "MathUtils.h"
#include "Arbiter.h"

#include "Body.h"
#include "Joint.h"

typedef struct _World {

	// instead of vectors, we are just gonna do static arrays for now
	Body* bodies;
	Joint* joints;

	// can't do arbiters yet since it requires a key, lmao
	
	Vec2 gravity;
	int iterations;
	// static struct ints aren't a thing (neither are bools), so yeah it's a little different
	int accumulateImpulses;
	int warmStarting;
	int positionCorrection;
} World;

void World_init(World* world, Vec2 gravity, int iterations);
void World_Add(World* world, Body* body);
void World_Add(World* world, Joint* joint);
void World_Clear(World* world);

void World_Step(World* world, float dt);

void BroadPhase(World* world);

#endif
