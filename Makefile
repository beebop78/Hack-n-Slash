#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/07 13:21:20 by rcargou           #+#    #+#              #
#    Updated: 2015/07/10 23:51:02 by rcargou          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	= HacknSlash
SRC 	= Sources/main_dbg.cpp Sources/matrice.cpp
OBJ		= $(SRC:.cpp=.o)
INC 	= -I ./Includes
tmpFLAGS 	= -Wall -Wextra -Werror
LIB 	= -lX11 -lGL -lGLU

all : $(NAME)


$(NAME): $(OBJ) 
	g++ -o $(NAME) $(FLAGS) $(OBJ) $(LIB)

%.o: %.cpp
	g++ -o $@ -c $< $(FLAGS) $(INC) $(LIB)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
