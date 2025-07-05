/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 14:57:19 by spenning      #+#    #+#                 */
/*   Updated: 2024/12/16 14:27:39 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

void	parse_add_object(t_world *world, t_parse *parse)
{
	debugger(BLU "%s:%d - %s\nadd object:\t%sobject type:\t%d\n\n" RESET, \
	__FILE__, __LINE__, __FUNCTION__, parse->str, parse->type);
	if (parse->type == ambient)
		parse_add_ambient(world, parse->str);
	else if (parse->type == camera)
		parse_add_camera(world, parse->str);
	else if (parse->type == light)
		parse_add_light(world, parse->str);
	else if (parse->type == sphere)
		parse_add_sphere(world, parse->str);
	else if (parse->type == plane)
		parse_add_plane(world, parse->str);
	else if (parse->type == cyl)
		parse_add_cyl(world, parse->str);
	free(parse->str);
	parse->str = NULL;
}

void	parse_lines_str(t_world *world, t_parse *parse, int fd)
{
	parse->str = get_next_line(fd, 0);
	if (parse->str == NULL)
		set_error(world, 1, GNL, NULL);
	if (world->exit_code)
		return ;
	parse->type = parse_check_identify(parse->str);
	parse_check_identifier(world, parse);
	if (!world->exit_code && parse_check_correctness(parse))
		set_error(world, 1, INC_FORMAT, NULL);
	if (world->exit_code)
		return ;
	parse_add_object(world, parse);
}

void	parse_count_identifiers(t_world *world, t_parse *parse)
{
	if (world->exit_code)
		return ;
	if (!parse->a_identifier)
		set_error(world, 1, no_a, NULL);
	if (!parse->c_identifier)
		set_error(world, 1, no_c, NULL);
	if (!parse->l_identifier)
		set_error(world, 1, no_l, NULL);
}

void	parse_lines(t_world *world, int line_count, char *file)
{
	int		i;
	int		fd;
	t_parse	parse;

	i = 0;
	ft_bzero(&parse, sizeof(t_parse));
	fd = parse_open_file(file);
	while (i < line_count && !world->exit_code)
	{
		parse_lines_str(world, &parse, fd);
		i++;
	}
	if (close(fd))
		set_error(world, 1, CLOSE, NULL);
	free(parse.str);
	parse.str = NULL;
	get_next_line(0, 2);
	parse_count_identifiers(world, &parse);
}

void	parse(t_world *world, int argc, char **argv)
{
	int		line_count;

	if (argc < 2 || argc > 2)
		exit_err("wrong arguments", 1);
	parse_check_extension(argv[1]);
	line_count = parse_line_count(argv[1]);
	debugger(BLU "%s:%d - %s\nline count:\t%d\n\n" RESET, \
	__FILE__, __LINE__, __FUNCTION__, line_count);
	parse_lines(world, line_count, argv[1]);
}
