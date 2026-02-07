# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    os.mk                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 16:10:11 by fkruger           #+#    #+#              #
#    Updated: 2025/12/05 22:55:50 by fkruger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SECT_os = ft_execve.c ft_fatal.c ft_os_spawn.c ft_spawn_cmd.c

$(BIN_DIR)/os/ft_fatal.o: CFLAGS += -DFTLIB_F_PERROR
