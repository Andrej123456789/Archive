CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

OBJDIR = objects
OBJS = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(wildcard *.c)))

BINFOLDER = executable
BIN = $(BINFOLDER)/atomic

all : $(OBJDIR) $(BINFOLDER) $(BIN)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINFOLDER):
	mkdir $(BINFOLDER)

$(BIN) : $(OBJS)
	$(CC) $(OBJS) -o $(BIN) $(CFLAGS)

$(OBJDIR)/server.o : server.c
	$(CC) -c $< -o $@

$(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(BIN) settings/default.txt

clean:
	rm -rf $(wildcard *.o) objects

full_clean:
	rm -rf $(BIN) executable $(wildcard *.o) objects
