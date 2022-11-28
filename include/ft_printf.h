/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:07:26 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/28 10:32:32 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>

int		ft_putchar(const char character, int fd);
int		ft_putnbr(int nb, int fd);
int		ft_putunsignednbr(unsigned int nb, int fd);
int		ft_putstr(char *str, int fd);
int		ft_puthexa(unsigned long nb, int upper, int add, int fd);

#endif
