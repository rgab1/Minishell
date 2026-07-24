/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassmou <hassmou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:06:52 by grivault          #+#    #+#             */
/*   Updated: 2026/07/24 11:07:41 by hassmou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

// minishell_error function messages
# define ERROR_HOME_NOT_SET "HOME not set"
# define ERROR_OLDPWD_NOT_SET "OLDPWD not set"
# define ERROR_CMD_NOT_FOUND "command not found"
# define ERROR_NO_FILE "No such file or directory"
# define ERROR_PERM_DENIED "Permission denied"
# define ERROR_IDENTIFIER "not a valid identifier"
# define ERROR_NUM_ARG "numeric argument required"
# define ERROR_MANY_ARGS "too many arguments"

// exit_error function messages
# define ERROR_MALLOC_FAILED_4 "Malloc failed\n"
# define ERROR_SHELL_NDEF_5 "Shell is not defined\n"
# define ERROR_CMD_NDEF_6 "Cmd is not defined\n"
# define ERROR_CMD_EMPTY_7 "Cmd char is NULL\n"
# define ERROR_EXP_NDEF_8 "Exp is not defined\n"

#endif
