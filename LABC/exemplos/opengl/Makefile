COMPILER=g++
CFLAGS=
LDFLAGS=-L/usr/local/lib -lGL -lGLU -lglut -lGLEW

ALL=exemplo-opengl01 exemplo-opengl02 exemplo-opengl03 exemplo-opengl04 exemplo-opengl05

all: $(ALL)

exemplo-opengl01: exemplo-opengl01.c
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o $@ $^

exemplo-opengl02: exemplo-opengl02.c
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o $@ $^

exemplo-opengl03: exemplo-opengl03.c
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o $@ $^

exemplo-opengl04: exemplo-opengl04.c
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o $@ $^

exemplo-opengl05: exemplo-opengl05.c
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.*~ *~ $(ALL)
