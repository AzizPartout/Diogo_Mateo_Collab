# Pour ne pas afficher les lignes de commande
.SILENT:

## ARGUMENTS
NAME = main
CFLAGS = -Wall -Werror -Wextra
CC = gcc

## FILES
SRC_FILES = src
INC_FILES = headers
TEST_FILES = test
INCTEST_FILES = test_headers
BIN_FILES = bin
OBJS_FILES = objs

SRCS = $(wildcard $(SRC_FILES)/*.c) # Recherche tous les fichiers se terminant par .c dans src et return une liste de ces fichiers
OBJS = $(patsubst $(SRC_FILES)/%.c,$(OBJS_FILES)/%.o,$(SRCS)) # Génère une liste de "string" de .o àpd'une liste de fichiers .c de src,
# nécessaire pour spécifier quels fichiers objets sont nécessaire pour l'executable

TEST_SRCS = $(wildcard $(TEST_FILES)/*.c)
TEST_OBJS = $(TEST_SRCS:$(TEST_FILES)/%.c=$(OBJS_FILES)/%.o)

all : $(NAME)

$(NAME): $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 
# $@ remplace le target, $< remplace les dépendances

$(OBJS_FILES)/%.o : $(SRC_FILES)/%.c
	$(CC) $(CFLAGS) -I$(INC_FILES) -c -o $@ $<


$(OBJS_FILES)/%.o: $(TEST_FILES)/%.c
	$(CC) $(CFLAGS) -I$(INCTEST_FILES) -c -o $@ $<

clean :
	rm -f $(OBJS_FILES)/* $(NAME)
