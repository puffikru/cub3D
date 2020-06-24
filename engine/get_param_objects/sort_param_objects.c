#include "../../cub.h"

static void		push_param_object(char **param, char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '.' && line[i + 1] == '/')
		*param = line;
	else
		error("Incorrect path to the texture (*_*)");
}

static void		get_resolution(char *line, t_ptr *ptr)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	ptr->param->x = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	ptr->param->y = ft_atoi(&line[i]);
}

static void		get_texture(char *line, t_ptr *ptr, char *flags, int i)
{
	if (flags[i] == 'N' && flags[i + 1] == 'O')
	{
		push_param_object(&(ptr->param->north), line);
		ptr->check->check_no++;
	}
	else if (flags[i] == 'S' && flags[i + 1] == 'O')
	{
		push_param_object(&(ptr->param->south), line);
		ptr->check->check_so++;
	}
	else if (flags[i] == 'W' && flags[i + 1] == 'E')
	{
		push_param_object(&(ptr->param->west), line);
		ptr->check->check_we++;
	}
	else if (flags[i] == 'E' && flags[i + 1] == 'A')
	{
		push_param_object(&(ptr->param->east), line);
		ptr->check->check_ea++;
	}
	else if (flags[i] == 'S' && flags[i + 1] == '\0')
	{
		push_param_object(&(ptr->param->sprite), line);
		ptr->check->check_s++;
	}
}

static void		get_f_c(char *line, int *rgb)
{
	int r;
	int g;
	int b;
	int i;

	i = 0;
	r = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	g = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	b = ft_atoi(&line[i]);
	if (!((r >= 0 && r <= 255) && ((g >= 0 && g <= 255)) && ((b >= 0 && b <= 255))))
		error("RGB within [0-255] (6_6)");
	*rgb = r;
	*rgb = (*rgb << 8) + g;
	*rgb = (*rgb << 8) + b;
}

void			sort_param_objects(char *line, t_ptr *ptr)
{
	int i;

	i = 0;
	if (line[i] == '\0' || line[i] == 13)
		return ;
	if (line[i] == 'R' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		get_resolution(&line[i + 1], ptr);
	else if (((line[i] == 'N' && line[i + 1] == 'O') ||
	(line[i] == 'S' && line[i + 1] == 'O') ||
	(line[i] == 'W' && line[i + 1] == 'E') ||
	(line[i] == 'E' && line[i + 1] == 'A')) &&
	(line[i + 2] == ' ' || line[i + 2] == '\t'))
		get_texture(&line[i + 2], ptr, &line[i], 0);
	else if (line[i] == 'S' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		get_texture(&line[i + 1], ptr, "S", 0);
	else if (line[i] == 'F' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		get_f_c(&line[i + 1], ptr->param->f_rgb);
	else if (line[i] == 'C' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		get_f_c(&line[i + 1], ptr->param->c_rgb);
	else
		error("Unknow identifier (!_!)");
}