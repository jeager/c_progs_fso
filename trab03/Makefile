#paths
SRC = src
OBJ = obj
BIN = bin
LIB = lib


CC = gcc
AR = ar
INC = -Iheader/
CFLAGS = -std=c99 -lm $(INC)
ARCHIVE = libprimo.a
SHAREDF = -Wl,-rpath,./lib -lm


Q01 = q01
Q02 = q02
Q03	= q03

all: mk_dirs $(Q01) $(Q02) $(Q03)

$(Q01):	mk_dirs_q01
	$(CC) -c $(SRC)/main.c -o q01/$(OBJ)/main.o $(CFLAGS)
	$(CC) -c $(SRC)/libprimo.c -o q01/$(OBJ)/libprimo.o $(CFLAGS)
	$(AR) rcs q01/$(LIB)/$(ARCHIVE) q01/$(OBJ)/main.o q01/$(OBJ)/libprimo.o
	$(CC) -static -o q01/$(BIN)/$(Q01) q01/$(OBJ)/main.o -L./q01/$(LIB) -lprimo $(CFLAGS)

$(Q02):	mk_dirs_q02
	$(CC) -shared -fPIC -c $(SRC)/libprimo.c -o q02/$(LIB)/libprimo.so $(CFLAGS)
	$(CC) -o q02/$(BIN)/$(Q02) $(SRC)/main.c -L./q02/$(LIB) -lprimo $(CFLAGS)

$(Q03):	mk_dirs_q03
	$(CC) -shared -fPIC $(SRC)/libprimo.c -o q03/$(LIB)/libprimo.so $(CFLAGS)
	$(CC) -c $(SRC)/main_ldl.c -o q03/$(OBJ)/main_ldl.o -ldl $(CFLAGS)
	$(CC) -o q03/$(BIN)/$(Q03) q03/$(OBJ)/main_ldl.o -L./q03/$(LIB) -lprimo $(SHAREDF) -ldl $(CFLAGS)


mk_dirs: mk_dirs_q01 mk_dirs_q02 mk_dirs_q03

mk_dirs_q01:
	@mkdir -p q01
	@mkdir -p q01/$(OBJ)
	@mkdir -p q01/$(BIN)
	@mkdir -p q01/$(LIB)

mk_dirs_q02:
	@mkdir -p q02
	@mkdir -p q02/$(OBJ)
	@mkdir -p q02/$(BIN)
	@mkdir -p q02/$(LIB)

mk_dirs_q03:
	@mkdir -p q03
	@mkdir -p q03/$(OBJ)
	@mkdir -p q03/$(BIN)
	@mkdir -p q03/$(LIB)

clean:
	rm -rf q01
	rm -rf q02
	rm -rf q03