# compiler settings
CXXFLAGS:= $(INCLUDE) -Wall -O2
LDFLAGS	:= 

TARGET := doxyqml

# find sources and headers
SOURCES	:= $(wildcard *.cpp)

# objects go into current directory
OBJS 	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

build:	$(TARGET)

clean:
	rm -f $(TARGET) *.o .depend

$(TARGET):	.depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
