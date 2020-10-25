/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saltarin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 03:04:02 by miki              #+#    #+#             */
/*   Updated: 2020/10/25 04:45:26 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./minilibx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_windowdata
{
	void	*mlx_ptr;
	void	*mlx_win;
	size_t	width;
	size_t	height;
}				t_windowdata;

typedef struct	s_imagedata
{
	void			*img_ptr;
	unsigned int	*bufaddr;
	int				bpp;
	int				size_line;
	int				endian;
}				t_imagedata;

typedef struct	s_key
{
	char	space : 1;
}				t_key;

typedef	struct	s_programdata
{
	t_windowdata	window;
	t_imagedata		buffer;
	t_key			key;
}				t_programdata;
