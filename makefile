target = a.out

SRCS = $(wildcard *.cpp)
SRCS += $(wildcard obj/*.cpp)
DS = $(SRCS:%.cpp=%.d)
OBJS = $(SRCS:%.cpp=%.o)

INC = -I/home/chenting/Desktop/1/obj

%.d : %.cpp
	g++ $(INC) -MM $< > $@
	echo \\tg++ $(INC) -c $($@:.d=.o) $< >> $@

$(target) : $(DS) $(OBJS)
	g++ -o a.out $(OBJS)


include $(DS)

clean:
	rm -f $(DS)
	rm -f $(OBJS)
	rm -f $(target)
