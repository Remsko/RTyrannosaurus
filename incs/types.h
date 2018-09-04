#ifndef TYPES_H
#define TYPES_H

#include "rt.h"
#include "visu.h"
#include "utils.h"

typedef struct s_material
{
	t_color specular;
	t_color ambient;
	t_color diffuse;
} t_material;

typedef struct s_object
{
	t_material mater;
	t_vector pos;
	t_vector rot;
	t_object_type type;
	void *inter;
} t_object;

typedef struct s_events
{
	t_options options;
	const unsigned char *keys;
} t_events;

typedef struct s_ray
{
	t_vector ori;
	t_vector dir;
	int depth;
} t_ray;

typedef struct s_camera
{
	t_vector pos;
	t_vector rot;
	double dist;
	//t_vector	plane;
} t_camera;

typedef struct s_env
{
	t_camera *camera;
	t_events events;
	int samples;
	int rebound;
} t_env;

#endif
