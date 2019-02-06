#include <stdio.h>

#include "incs/scene.h"
#include "incs/camera.h"
#include "incs/color.h"
#include "incs/intersection.h"
#include "incs/light.h"
#include "incs/object.h"
#include "incs/ray.h"
#include "incs/scene.h"
#include "incs/solver.h"
#include "incs/vector.h"

int	main(void)
{
	printf("camera = *%zu %zu\n", sizeof(t_camera *), sizeof(t_camera));
	printf("color = *%zu %zu\n", sizeof(t_color *), sizeof(t_color));
	printf("mater = *%zu %zu\n", sizeof(t_material *), sizeof(t_material));
	printf("light = *%zu %zu\n", sizeof(t_light *), sizeof(t_light));
	printf("object = *%zu %zu\n", sizeof(t_object *), sizeof(t_object));
	printf("ray = *%zu %zu\n", sizeof(t_ray *), sizeof(t_ray));
	printf("viewplane = *%zu %zu\n", sizeof(t_viewplane *), sizeof(t_viewplane));
	printf("config = *%zu %zu\n", sizeof(t_config *), sizeof(t_config));
	printf("scene = *%zu %zu\n", sizeof(t_scene *), sizeof(t_scene));
	printf("double = *%zu %zu\n", sizeof(double *), sizeof(double));
	return (0);
}
