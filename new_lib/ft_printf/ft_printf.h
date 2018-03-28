/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:47:05 by ismus             #+#    #+#             */
/*   Updated: 2018/01/27 16:47:06 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft.h"

typedef struct		s_print
{
	char			*flag;
	int				wide;
	int				if_acc;
	int				accuracy;
	char			*spec;
	int				k_ret;
}					t_plist;

typedef struct		s_byte
{
	unsigned int	a0;
	unsigned int	a1;
	unsigned int	a2;
	unsigned int	a3;
}					t_byte;

int					ft_printf(char *format, ...);
int					type_defin(t_plist *par, va_list arg, char type, int k_ret);
char				*flags_mid(t_plist *par, char *s);
char				*flags_oux(t_plist *par, char type, char *s, int num);
char				*flags_id(t_plist *par, char *s);
int					modif_l(t_plist *par, va_list arg, char type);
int					modif_ll(t_plist *par, va_list arg, char type);
int					modif_j(t_plist *par, va_list arg, char type);
int					modif_z(t_plist *par, va_list arg, char type);
int					modif_h(t_plist *par, va_list arg, char type);
int					modif_hh(t_plist *par, va_list arg, char type);
int					modif_idoux(t_plist *par, va_list arg, char type);
int					modif_lc(t_plist *par, va_list arg);
int					modif_ls(t_plist *par, va_list arg);
int					modif_c(t_plist *par, va_list arg);
int					modif_p(t_plist *par, va_list arg);
int					modif_s(t_plist *par, va_list arg);
int					four_byte(char *s, t_plist *par);
int					three_byte(char *s, t_plist *par);
int					one_byte(unsigned int i, t_plist *par);
int					two_byte(char *s, t_plist *par);
void				str_unicode(unsigned int *s);
int					unicode(unsigned int i, t_plist *par);
unsigned int		two_to_ten(unsigned int k);
int					ac_n_bytes(unsigned int *s, int acc);
int					n_bytes(unsigned int *s);
int					n_byte(unsigned int i);
char				*ft_n_and_s(char c, int n, char *str, int i);
int					modif_s0(t_plist *par);
int					all_param(char *flag, int k, t_plist *param, va_list arg);
int					modif_t(t_plist *par, va_list arg, char type);
int					type_n(int k_ret, va_list arg);

#endif
