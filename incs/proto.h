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

void    color_multiply(t_color target, t_color amount);

void    color_multiply_const(t_color target, Uint8 amount);

void    color_divide(t_color divident, t_color divisor);

void    color_divide_const(t_color divident, Uint8 divisor);

void    color_add(t_color target, t_color amount);

void    color_add_const(t_color target, Uint8 amount);

t_ray   new_ray(t_camera *cam, double x, double y);

#endif