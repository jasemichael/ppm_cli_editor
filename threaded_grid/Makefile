CXX := g++
CXXFLAGS := -g -O2 -Wall -std=c++11 -Werror
LDFLAGS := 
SRCS    := $(sort $(wildcard *.cpp))
OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))
TARGETS := threaded_grid

all: $(TARGETS)

threaded_grid: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

######################################
# automatic dependency generation
#
DEPDIR := .d
$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@

%.o : %.cpp
%.o : %.cpp $(DEPDIR)/%.d
	$(COMPILE.cc) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

include $(wildcard $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRCS))))
#
#
######################################

######################################
#
#
clean:
	-rm -f $(TARGETS)
	-rm -f *.o
	-rm -f *~
	-rm -rf $(DEPDIR)
#
#
######################################



# Local Variables:
# mode:makefile
# End: