#ifndef PROTO_H
# define PROTO_H

# include "rt.h"

void	sdl_destroy(t_visu *v);

void    sdl_draw(t_env *e, t_visu *v);

void	sdl_event(t_events *e);

void	sdl_fps(void);

void    sdl_init(t_visu *v);

void    sdl_loop(t_env *e, t_visu *v);

void    raytracer_core(t_env *e, t_visu *v);

void    raytracer_tracer(t_env *e, t_visu *v, t_ray *ray, t_color *c, int x, int y);

void    color_multiply(t_color *target, t_color *amount);

void    color_multiply_const(t_color *target, double amount);

void    color_divide(t_color *divident, t_color *divisor);

void    color_divide_const(t_color *divident, double amount);

void    color_add(t_color *target, t_color *amount);

void    color_add_const(t_color *target, double amount);

t_ray   new_ray(t_camera *cam, double x, double y);

t_bool  inter_algo(t_object *object, t_ray *ray, int object_nb);

double  inter_sphere(t_object *object, t_ray *ray);

double  solver_quadratic(double a, double b, double c);

t_vector    vector_add(t_vector a, t_vector b);

t_vector    vector_sub(t_vector a, t_vector b);

double      vector_dot(t_vector a, t_vector b);

t_vector    vector_mult(t_vector a, t_vector b);

#endif