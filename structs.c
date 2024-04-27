#include "structs.h"
#include "defs.h"

void AddVector(Vector2* add_target, Vector2* b)
{
	add_target->x = add_target->x + b->x;
	add_target->y = add_target->y + b->y;
}

void MultiplyVector(Vector2* v, double c)
{
	v->x = v->x * c;
	v->y = v->y * c;
}

float GetAngle(Vector2 v1, Vector2 v2)
{
	/*float angle = -90. + atan2(v1.y - v2.y, v1.x - v2.x) * (180. / PI);
	return angle >= 0. ? angle : 360. + angle;*/

	double dot = v1.x * v2.x + v1.y * v2.y;
	double det = v1.x * v2.y - v1.y * v2.x;
	return atan2(det, dot);
}