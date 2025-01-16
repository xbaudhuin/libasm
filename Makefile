NAME 			= 	libasm.a

TEST 			= 	test

COMPILE_FLAGS 	= 	compile_flags.txt

ASM 			= 	nasm

ASMFLAGS 		= 	-felf64

CC 				= 	gcc

DEPFLAG 		= 	-MMD -MP

AR 				= 	ar rcs

RM 				= 	rm -rf

HEADER 			= 	-I./includes/

HEADER_FILES 	= 	libasm.h

GREEN 			= 	\033[0;32m
RED 			= 	\033[0;31m
BLUE 			= 	\033[0;34m
YELLOW 			= 	\033[;33m
BWHITE 			= 	\033[1;37m
RESET 			= 	\033[0m
ITALIC 			= 	\e[3m
BOLD 			= 	\e[1m
NEW 			= 	\r\033[K

SRC_LIB_PATH 	= 	./srcs/lib/

SRC_TEST_PATH 	= 	./srcs/test/

OBJ_PATH 		= 	obj/

DEP_PATH 		= 	dep/

################################################################################
#                                    SOURCES                                   #
################################################################################

SRCS_LIB 		= 	ft_strlen.s

SRCS_TEST 		= 	main.c

OBJS_LIB 		= 	$(addprefix ${OBJ_PATH}, ${SRCS_LIB:.s=.o})

OBJS_TEST 		= 	$(addprefix ${OBJ_PATH}, ${SRCS_TEST:.c=.o})

################################################################################
#                                 RULES                                        #
################################################################################

all: 				${NAME}

${NAME}: 			${OBJS_LIB} ${COMPILE_FLAGS} Makefile
				@${AR} -o ${NAME} ${OBJS_LIB}
				@printf "${NEW}${YELLOW}${NAME}${RESET}${GREEN}${BOLD} Compiled\n${RESET}${GREEN}compiled with:${RESET} ${ASM} ${ASMFLAGS}\n"

${OBJ_PATH}%.o: 	${SRC_PATH}%.s
				@mkdir -p $(dir $@)
				@${ASM} ${ASMFLAGS} ${HEADER} $< -o $@

compile_flags: 		${COMPILE_FLAGS}

${COMPILE_FLAGS}:
				@echo "-I/includes/\n-Wall -Werror -Wextra" > compile_flags.txt

clean:
				${RM} ${OBJ_PATH}

fclean: 			clean
				${RM} ${NAME} ${TEST} ${COMPILE_FLAGS}

re: 				fclean all

.PHONY: 			all fclean clean re compile_flags
