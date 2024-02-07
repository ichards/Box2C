#ifndef ARBITER_H
#define ARBITER_H

#include "MathUtils.h"

struct Body;

typedef union _feature_pair {
	struct edges {
		char inEdge1;
		char outEdge1;
		char inEdge2;
		char outEdge2;
	} e;
	int value;
} FeaturePair;

typedef struct _contact {
	Vec2 position;
	Vec2 normal;
	Vec2 r1, r2;
	float seperation;
	float Pn;
	float Pt;
	float Pnb;
	float massNormal, massTangent;
	float bias;
	FeaturePair feature;
} Contact;

Contact Contact_init(); 

typedef struct _ArbiterKey {
	Body* body1;
	Body* body2;
} ArbiterKey;

ArbiterKey ArbiterKey_init(Body* b1, Body* b2); 

typedef struct _Arbiter {
	
	enum {MAX_POINTS = 2};

	Contact contacts[MAX_POINTS];
	int numContacts;

	Body* body1;
	Body* body2;

	float friction;
}

void Arbiter_init(Body* b1, Body* b2);
void Arbiter_Update(Contact* contacts, int numContacts);

void Arbiter_PreStep(float inv_dt);
void Arbiter_ApplyImpulse();

int ArbiterKey_compare(const ArbiterKey* a1, const ArbiterKey* a2);

int Collide(Contact* contacts, Body* body1, Body* body2);

#endif


		



