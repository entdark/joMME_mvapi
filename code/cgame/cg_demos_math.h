// Copyright (C) 2009 Sjoerd van der Berg ( harekiet @ gmail.com )

#ifndef CG_DEMOS_MATH_H
#define CG_DEMOS_MATH_H

typedef enum {
	posLinear,
	posCatmullRom,
	posBezier,
	posLast,
} posInterpolate_t;

typedef enum {
	angleLinear,
	angleQuat,
	angleLast,
} angleInterpolate_t;

typedef float Quat_t[4];
void QuatFromAngles( const vec3_t angles, Quat_t dst );
void QuatFromAnglesClosest( const vec3_t angles, const Quat_t qc, Quat_t dst);
void QuatToAngles( const Quat_t q, vec3_t angles);
void QuatToAxis( const Quat_t q, vec3_t axis[3]);
void QuatSquad( float t, const Quat_t q0, const Quat_t q1, const Quat_t q2, const Quat_t q3, Quat_t qr);
void QuatTimeSpline( float t, const int times[4], const Quat_t quats[4], Quat_t qr);

void VectorTimeSpline( float t, const int times[4], float *control, float *result, int dim);

float QuatDot( const Quat_t q0, const Quat_t q1);
void QuatCopy( const Quat_t src, Quat_t dst);
void QuatNegate( const Quat_t src, Quat_t dst);
void QuatConjugate( const Quat_t src, Quat_t dst);
void QuatAdd( const Quat_t q0, const Quat_t q1, Quat_t qr);
void QuatSub( const Quat_t q0, const Quat_t q1, Quat_t qr);
void QuatScale( const Quat_t q0, float scale,Quat_t qr);
void QuatScaleAdd( const Quat_t q0, const Quat_t q1, float scale, Quat_t qr);
float QuatDistanceSquared( const Quat_t q1, const Quat_t q2 );
float QuatLengthSquared( const Quat_t q );
float QuatLength( const Quat_t q );
void QuatClear( Quat_t q );
float QuatNormalize( Quat_t q );

void posMatrix( float t, posInterpolate_t type, vec4_t matrix);
void posGet( float t, posInterpolate_t type, const vec3_t control[4], vec3_t out);

vec_t VectorDistanceSquared ( const vec3_t v1, const vec3_t v2 );
vec_t VectorDistance( const vec3_t v1, const vec3_t v2 );
void AnglesNormalize360( vec3_t angles);
void AnglesNormalize180( vec3_t angles);

#define VectorAddDelta(a,b,c)	((c)[0]=(b)[0]+((b)[0]-(a)[0]),(c)[1]=(b)[1]+((b)[1]-(a)[1]),(c)[2]=(b)[2]+((b)[2]-(a)[2]))
#define VectorSubDelta(a,b,c)	((c)[0]=(a)[0]-((b)[0]-(a)[0]),(c)[1]=(a)[1]-((b)[1]-(a)[1]),(c)[2]=(a)[2]-((b)[2]-(a)[2]))

qboolean CylinderTraceImpact( const vec3_t start, const vec3_t forward, const vec3_t container, vec3_t result );
qboolean BoxTraceImpact(const vec3_t start, const vec3_t forward, const vec3_t container, vec3_t result );

void GetPerpendicularViewVector( const vec3_t point, const vec3_t p1, const vec3_t p2, vec3_t up );

float dsplineCalc(float x, vec3_t dx, vec3_t dy, float*deriv );

void demoLimitDrawDistance( const qboolean limit);
void demoDrawSetupVerts( polyVert_t *verts, const vec4_t color );
void demoDrawRawLine(const vec3_t start, const vec3_t end, float width, polyVert_t *verts );
void demoDrawLine( const vec3_t p0, const vec3_t p1, const vec4_t color);
void demoDrawCross( const vec3_t origin, const vec4_t color );
void demoDrawBox( const vec3_t origin, const vec3_t container, const vec4_t color );

void demoRotatePoint(vec3_t point, const vec3_t matrix[3]);
void demoCreateRotationMatrix(const vec3_t angles, vec3_t matrix[3]);

int fxRand( int r );
float fxRandom( int r );
int fxRandomSign( int r );

#endif
