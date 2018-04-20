/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:14:33 by lpousse           #+#    #+#             */
/*   Updated: 2016/04/29 16:39:23 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

typedef struct	s_matrix
{
	double	**m;
	int		y;
	int		x;
}				t_matrix;

typedef struct	s_vector
{
	double	*v;
	int		n;
}				t_vector;

t_matrix		*ft_matnew(int y, int x);
t_matrix		*ft_matidentity(int n);
void			ft_matset(t_matrix *m, double **data);
void			ft_matclr(t_matrix *m);
void			ft_matdel(t_matrix **m);
t_matrix		*ft_matadd(t_matrix *a, t_matrix *b);
t_matrix		*ft_matsub(t_matrix *a, t_matrix *b);
t_matrix		*ft_matmulti(t_matrix *a, t_matrix *b);
t_matrix		*ft_matmultidel(t_matrix *a, t_matrix *b);
t_matrix		*ft_matmulti_scal(t_matrix *a, double b);
t_matrix		*ft_mattransp(t_matrix *m);
double			ft_matdet(t_matrix *m);
void			ft_matsetsub(t_matrix *subm, t_matrix *m, int y, int x);
t_matrix		*ft_matinvert(t_matrix *m);

t_vector		*ft_vectnew(int n);
void			ft_vectset(t_vector *v, double *data);
void			ft_vectclr(t_vector *v);
void			ft_vectdel(t_vector *v);
t_vector		*ft_vectadd(t_vector *a, t_vector *b);
t_vector		*ft_vectsub(t_vector *a, t_vector *b);
t_vector		*ft_vectmulti(t_vector *a, t_vector *b);
t_vector		*ft_vectmulti_scal(t_vector *a, double b);
double			ft_vectscal(t_vector *a, t_vector *b);

t_vector		*ft_matvectmulti(t_matrix *a, t_vector *b);

#endif
