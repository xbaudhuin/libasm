NAME            = libasm.a
NAME_DEBUG 		= libasm_debug.a
TEST            = test.exe
TEST_DEBUG 		= test_debug.exe
COMPILE_FLAGS   = compile_flags.txt
ASM             = nasm
ASMFLAGS        = -felf64
ASMDEBUG 		= -g -F dwarf
CC              = gcc 
DEPFLAG         = -MMD -MP
AR              = ar rcs
RM              = rm -rf
HEADER          = -I./include/
HEADER_TEST     = -I./test/include/
CFLAGS          = -Wall -Werror -Wextra
CDEBUG 			= -g3
GREEN           = \033[0;32m
RED             = \033[0;31m
YELLOW          = \033[;33m
RESET           = \033[0m
NEW             = \r\033[K
SRC_LIB_PATH    = ./src/
SRC_TEST_PATH   = ./test/src/
OBJ_PATH        = obj/
OBJ_DEBUG_PATH 	= obj/debug/

SRCS_LIB        = ft_strlen.s \
				  ft_write.s \
				  ft_read.s \
				  ft_strcpy.s \
				  ft_strcmp.s \
				  ft_strdup.s

SRCS_LIB_FILES  = $(addprefix $(SRC_LIB_PATH), $(SRCS_LIB))
OBJS_LIB        = $(addprefix $(OBJ_PATH), $(SRCS_LIB:.s=.o))
OBJS_LIB_DEBUG  = $(addprefix $(OBJ_DEBUG_PATH), $(SRCS_LIB:.s=.o))

SRCS_TEST       = 	test_strlen.c \
				  	test_strcpy.c \
				  	test_strcmp.c \
				  	test_strdup.c \
				  	test_read.c \
					main.c \
					utils.c 

SRCS_TEST_FILES = $(addprefix $(SRC_TEST_PATH), $(SRCS_TEST))
OBJS_TEST       = $(addprefix $(OBJ_PATH), $(SRCS_TEST:.c=.o))
OBJS_TEST_DEBUG = $(addprefix $(OBJ_DEBUG_PATH), $(SRCS_TEST:.c=.o))

all: 			$(NAME)

$(NAME): 		${COMPILE_FLAGS} $(OBJS_LIB)
		@$(AR) $(NAME) $(OBJS_LIB)
		@printf "$(NEW)$(YELLOW)$(NAME)$(RESET)$(GREEN) Compiled\n$(RESET)compiled with: $(ASM) $(ASMFLAGS)\n"

$(OBJ_PATH)%.o: $(SRC_LIB_PATH)%.s
		@mkdir -p $(dir $@)
		@$(ASM) $(ASMFLAGS) $(HEADER) $< -o $@

test: 			$(NAME) $(TEST)

$(TEST): $(OBJS_TEST) ${NAME}
		@$(CC) $(CFLAGS) -o $(TEST) $(OBJS_TEST) $(HEADER_TEST) ${NAME}
		@printf "$(NEW)$(YELLOW)$(TEST)$(RESET)$(GREEN) Compiled\n$(RESET)compiled with: $(CC) $(CFLAGS)\n"

$(OBJ_PATH)%.o: $(SRC_TEST_PATH)%.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) $(HEADER_TEST) -c $< -o $@
		@printf "$(NEW)$(YELLOW)Building: $(RESET)$(CC) $(CFLAGS) $<\n"

debug: 			${COMPILE_FLAGS} ${NAME_DEBUG} $(TEST_DEBUG) Makefile

${NAME_DEBUG}: 	${OBJS_LIB_DEBUG} ${COMPILE_FLAGS}
		@${AR} ${NAME_DEBUG} ${OBJS_LIB_DEBUG}
		@printf "$(NEW)$(YELLOW)$(NAME_DEBUG)$(RESET)$(GREEN) Compiled\n$(RESET)compiled with: $(ASM) $(ASMFLAGS) ${ASMDEBUG}\n"

$(OBJ_DEBUG_PATH)%.o: $(SRC_LIB_PATH)%.s
		@mkdir -p ${OBJ_PATH}
		@mkdir -p $(dir $@)
		@$(ASM) $(ASMFLAGS) ${ASMDEBUG} $(HEADER) $< -o $@

$(TEST_DEBUG): $(NAME_DEBUG) $(OBJS_TEST_DEBUG)
		@$(CC) $(CFLAGS)  ${CDEBUG} -o $(TEST_DEBUG) $(OBJS_TEST_DEBUG) $(HEADER_TEST) ${NAME_DEBUG}
		@printf "$(NEW)$(YELLOW)$(TEST_DEBUG)$(RESET)$(GREEN) Compiled\n$(RESET)compiled with: $(CC) ${CFLAGS} ${CDEBUG} \n"

$(OBJ_DEBUG_PATH)%.o: $(SRC_TEST_PATH)%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) ${CDEBUG} $(HEADER_TEST) -c $< -o $@
		@printf "$(NEW)$(YELLOW)Debug Building: $(RESET)$(CC) $(CFLAGS) ${CDEBUG} \n"

compile_flags: $(COMPILE_FLAGS)

$(COMPILE_FLAGS):
		@echo "-I./include/\n-I./test/include/\n-Wall -Werror -Wextra" > $(COMPILE_FLAGS)

test_errno: ${TEST}
		(ulimit -v 2800; ./${TEST})

test_debug_errno: ${TEST_DEBUG}
		(ulimit -v 10000; ./${TEST_DEBUG})

clean_debug:
		${RM} ${OBJ_DEBUG_PATH}

clean: clean_debug
		$(RM) $(OBJ_PATH)

fclean_debug: clean_debug
		${RM} ${NAME_DEBUG} ${TEST_DEBUG}

fclean: clean fclean_debug
		$(RM) $(NAME) $(TEST) $(COMPILE_FLAGS)

redebug: fclean_debug debug

re: fclean all

.PHONY: all clean fclean re  redebug test debug fclean_debug compile_flags

