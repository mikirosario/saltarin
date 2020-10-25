/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 02:49:42 by miki              #+#    #+#             */
/*   Updated: 2020/10/25 04:52:34 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "saltarin.h"

#define RED		0x00FF0000
#define BLACK	0x00000000

int	draw_dot(t_programdata *program)
{
	unsigned int	color;
	int				x;
	int				y;

	x = 400;
	if (program->key.space)
		color = BLACK;
	else
		color = RED;
	while (x < 450)
	{
		y = 300;
		while (y < 350)
		{
			program->buffer.bufaddr[y * 800 + x] = color;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(program->window.mlx_ptr, program->window.mlx_win, program->buffer.img_ptr, 0, 0);
	return (0);
}

int	launch_window(t_programdata *program)
{
	program->window.mlx_ptr = mlx_init();
	if (program->window.mlx_ptr)
	{
		program->window.mlx_win = mlx_new_window(program->window.mlx_ptr, 800, 600, "Saltarin!");
		return (1);
	}
	return (0);
}

int	create_buffer(t_programdata *program)
{
	program->buffer.img_ptr = mlx_new_image(program->window.mlx_ptr, 800, 600);
	if (program->buffer.img_ptr)
	{
		program->buffer.bufaddr = (unsigned int *)mlx_get_data_addr(program->buffer.img_ptr, \
		&program->buffer.bpp, &program->buffer.size_line, &program->buffer.endian);
		return (1);
	}
	return (0);
}

int	configure(t_programdata *program)
{
	if (launch_window(program) && create_buffer(program))
		return (1);
	return (0);
}

int	close_program(t_programdata *program)
{
	mlx_destroy_image(program->window.mlx_ptr, program->buffer.img_ptr);
	mlx_destroy_window(program->window.mlx_ptr, program->window.mlx_win);
	exit (EXIT_SUCCESS);
}

int	keypress(int keycode, t_programdata *program)
{
	if (keycode == 0x20)
		program->key.space = 1;
	return (0);
}

int	keyrelease(int keycode, t_programdata *program)
{
	if (keycode == 0x20)
		program->key.space = 0;
	return (0);
}

int	main(void)
{
	t_programdata	program;
	int				success;

	success = configure(&program);
	if (success)
	{
		mlx_hook(program.window.mlx_win, 17, 1L << 17, close_program, &program);
		mlx_hook(program.window.mlx_win, 2, 1L << 0, keypress, &program);
        mlx_hook(program.window.mlx_win, 3, 1L << 1, keyrelease, &program);
		mlx_loop_hook(program.window.mlx_ptr, draw_dot, &program);
		mlx_loop(program.window.mlx_ptr);
	}
	return (0);
}