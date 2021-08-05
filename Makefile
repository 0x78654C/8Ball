CC = gcc
CFLAGS = -g -Wall -Wextra
LDFLAGS = 
EXEC = 8ball
VPATH = sources headers
OBJDIR = obj
OBJ_NAMES = 8ball.o
OBJS = $(addprefix $(OBJDIR)/,$(OBJ_NAMES))

all: mkndirs $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
$(OBJDIR)/%.o: %.c
	$(CC) -o $@ -c $(CFLAGS) $^

.PHONY: clean cleanest mkndirs

clean:
	rm $(EXEC)
	
cleanest:
	rm $(OBJDIR)/*.o
	
mkndirs:
	if [ ! -e obj ]; then mkdir obj; fi
	
