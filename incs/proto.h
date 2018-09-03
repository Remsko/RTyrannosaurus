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

void    raytracer_tracer(t_env *e, t_visu *v, t_color *c, int x, int y);

#endif