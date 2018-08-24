COMPILER=g++
CFLAGS=-I/usr/include/opencv
LDFLAGS=-L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc

ALL=exemplo-opencv01 exemplo-opencv02 exemplo-opencv03 exemplo-opencv04 exemplo-opencv05

all: $(ALL)

exemplo-opencv01: exemplo-opencv01.c
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o $@ $^

exemplo-opencv02: exemplo-opencv02.c
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o $@ $^

exemplo-opencv03: exemplo-opencv03.c
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o $@ $^

exemplo-opencv04: exemplo-opencv04.c
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o $@ $^

exemplo-opencv05: exemplo-opencv05.c
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.*~ *~ $(ALL)
