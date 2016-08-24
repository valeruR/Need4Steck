##
## Makefile for Makefile in /home/blerio_h/Rendu/C_Elementary/CPE_2015_n4s
##
## Made by Harold Blériot
## Login   <blerio_h@epitech.net>
##
## Started on  Mon May  2 16:06:56 2016 Harold Blériot
## Last update Sun May 29 23:28:01 2016 Reever Valerus
##

GCC		=	gcc

RM		=	rm -rf

NAME		=	ia

DIR_SRCS	=	srcs

SRCS		=	$(DIR_SRCS)/get_next_line.c \
			$(DIR_SRCS)/main.c \
			$(DIR_SRCS)/get_lidar.c \
			$(DIR_SRCS)/get_float.c \
			$(DIR_SRCS)/lib.c

CFLAGS		+=	-Iinclude/
CFLAGS		+=	-lm

OBJS		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(GCC) $(OBJS) -o $(NAME) $(CFLAGS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
