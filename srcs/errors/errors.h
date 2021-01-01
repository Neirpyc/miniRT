/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 22:09:41 by caugier           #+#    #+#             */
/*   Updated: 2020/12/29 11:42:24 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERRCODE_UNKNOWN_ERROR 0
# define ERRCODE_NO_MEM 1
# define ERRCODE_TOO_MANY_PTRS 2
# define ERRCODE_ILLEGAL_FREE 3
# define ERRCODE_NOT_ENOUGH_ARGS 4
# define ERRCODE_UNEX_ARG 5
# define ERRCODE_UNEX_ARGS 6
# define ERRCODE_NOT_RT 7
# define ERRCODE_NO_RES 8
# define ERRCODE_NO_AMB 9
# define ERRCODE_RD_UNTIL 10
# define ERRCODE_UNK_TYPE 11
# define ERRCODE_EXP_PINT 12
# define ERRCODE_EXP_EOL 13
# define ERRCODE_EXP_ARG 14
# define ERRCODE_EXP_DIG 15
# define ERRCODE_UNEX_CHR 16
# define ERRCODE_RES_RE 17
# define ERRCODE_AMB_RE 18
# define ERRCODE_EXP_FP01 19
# define ERRCODE_EXP_BYTE 20
# define ERRCODE_EXP_3BYTES 21
# define ERRCODE_EXP_3DBL_NP 22
# define ERRCODE_EXP_DBL_NP 23
# define ERRCODE_EXP_3DBL_11 24
# define ERRCODE_EXP_DBL_11 25
# define ERRCODE_EXP_DBL_180 26
# define ERRCODE_MAT_WDEF 27
# define ERRCODE_DUP_MATID 28
# define ERRCODE_UNK_MATID 29
# define ERRCODE_EXP_FP0INF 30
# define ERRCODE_CNT_IMLX 31
# define ERRCODE_CNT_OWIN 32
# define ERRCODE_ILLEGAL_CLOSE 33
# define ERRCODE_ILLEGAL_CBRM 34
# define ERRCODE_NO_CAM 35
# define ERRCODE_EXP_DBL_1INF 36
# define ERRCODE_EXP_DBL_0INC_INF 37
# define ERRCODE_CNT_ALLOC_FBUF 38
# define ERRCODE_UNK_WRT_F 39
# define ERRCODE_SINT_OVFL 40
# define ERRCODE_CRT_THRD 41
# define ERRCODE_COL_PTS_TRGL 42
# define ERRCODE_VEC_NNORM 43
# define ERRCODE_EXP_DBL_0180EX 44
# define ERRCODE_FI_RE 45
# define ERRCODE_EXP_RGB 46
# define ERRCODE_EXP_NSCR 47

const char	*ft_strerror(int error);
void		ft_put_strerror(int error);
void		ft_put_strerrno(void);
void		gc_exit_strerror(int error, int exit_code);

#endif
