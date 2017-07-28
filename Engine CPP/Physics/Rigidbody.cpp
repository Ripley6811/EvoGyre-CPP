#include "Rigidbody.h"
#include "../Engine.h"

Rigidbody::Rigidbody() : friction(1), gravity(0) {}

void Rigidbody::Init(float _friction, float _gravity, Vector3 * _pos, float * _rot, Vector3 * _scale, Vector3 * _size)
{
	friction = _friction;
	gravity = _gravity;

	pos = _pos;
	rot = _rot;
	scale = _scale;
	size = _size;
}

void Rigidbody::Update()
{
	vel.x *= friction;  // slow down
	vel.y += gravity;  // fall down
	if (pos->y < 0)
	{
		pos->y = 0;
		vel.y *= 0;
	}

	*pos = *pos + (vel * Engine::GetDT());
}

void Rigidbody::Render(Vector3 color)
{
	glLoadIdentity();

	glTranslatef(pos->x, pos->y, pos->z);
	glRotatef(*rot, 0, 0, 1);
	glScalef(scale->x, scale->y, scale->z);

	glColor4f(color.x, color.y, color.z, 1);
	glBegin(GL_LINES);
	{
		glVertex2i(-size->x / 2, -size->y / 2);
		glVertex2i(size->x / 2, -size->y / 2);

		glVertex2i(size->x / 2, -size->y / 2);
		glVertex2i(size->x / 2, size->y / 2);

		glVertex2i(size->x / 2, size->y / 2);
		glVertex2i(-size->x / 2, size->y / 2);

		glVertex2i(-size->x / 2, size->y / 2);
		glVertex2i(-size->x / 2, -size->y / 2);
	}
	glEnd();

}

void Rigidbody::AddForce(Vector3 force)
{
	vel = vel + force;
}

void Rigidbody::SetVel(Vector3 _vel)
{
	vel = _vel;
}