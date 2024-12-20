CXX       = g++
CXXFLAGS  = -Wall -pedantic -O3 -std=c++17
LD        = g++
LIBS      = -lstdc++fs -lncurses -lcrypto
OBJDIR    = obj
SRCDIR    = src
DEPDIR    = dep

# recursive wildcard
rwildcard = $(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,$(SRCDIR),*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
HEADERS = $(call rwildcard,$(SRCDIR),*.h)
DEP = $(patsubst $(SRCDIR)/%.cpp,$(DEPDIR)/%.d,$(SRC))


all: compile docs

compile: $(OBJ)
	$(LD) -o midday-commander $^ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

docs: $(HEADERS) $(SRC) Doxyfile README.md
	doxygen

clean:
	rm -f midday-commander
	rm -rf docs
	rm -rf $(DEPDIR)
	rm -rf $(OBJDIR)

run: compile
	./midday-commander

$(DEPDIR)/%.d: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CXX) -MM $< -MT $(OBJDIR)/$*.o > $@

-include $(DEP)
