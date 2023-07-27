CXXFLAGS= -Wall -Werror -std=c++14
CXX= g++

###################
BUILDDIR=${PWD}/bin
OBJDIR=${BUILDDIR}/obj
$(shell mkdir -p $(OBJDIR))
###################
INCLUDEDIR=${PWD}/../include
THIRDPARTY_DIR=${PWD}/../thirdparty
###################
SRCDIR=${PWD}/../src
###################
TARGET=shubh_bin
GTEST_BIN=shubh_test_bin
GTEST_LIB_DIR=${PWD}/../thirdparty/googletest/build
###################
GTEST_DIR=${PWD}/../thirdparty/googletest/googletest/include
GTEST_LIB=${PWD}/../thirdparty/googletest/build/lib/ -lgtest
APP_SRC_DIR=${PWD}/../app
APPPOBJDIR=$(OBJDIR)/app
$(shell mkdir -p $(APPPOBJDIR))
APP_SRC=$(wildcard $(APP_SRC_DIR)/*.cpp)
$(info APP_SRC $(APP_SRC))
APP_OBJ=$(addprefix $(APPPOBJDIR)/, $(notdir $(patsubst $(APP_SRC_DIR)/%.cpp, %.o, $(APP_SRC))))
$(info APP_OBJ $(APP_OBJ))

#####################
SRCFILES=$(wildcard $(SRCDIR)/*.cpp)
OBJFILES=$(addprefix $(OBJDIR)/, $(notdir $(patsubst $(SRCDIR)/%.cpp, %.o, $(SRCFILES))))
####################
TEST_SRC_DIR=${PWD}/../test/
TEST_SRC_FILES=$(wildcard $(TEST_SRC_DIR)/*.cpp)
TEST_OBJ=${OBJDIR}/test_obj
$(shell mkdir -p $(TEST_OBJ))
#########################

TEST_OBJ_FILES=$(addprefix $(TEST_OBJ)/, $(notdir $(patsubst $(TEST_SRC_DIR)/%.cpp, %.o, $(TEST_SRC_FILES))))
$(info TEST_OBJ_FILES= $(TEST_OBJ_FILES))
OBJS=$(patsubst %src%, %obj%, $(OBJS_C))
$(shell mkdir -p  $(OBJDIR))
clean:
	rm -rf $(BUILDDIR)
	rm -rf $(TARGET)
	rm -rf $(GTEST_BIN)
	rm -rf $(GTEST_LIB_DIR)
	rm -rf $(THIRDPARTY_DIR)/googletest
build:
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) $(SRCDIR)/shubh.cpp -o $(OBJDIR)/shubh

$(OBJDIR)/%.o:$(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -ggdb3 -c  -o $@ $< 

$(APPPOBJDIR)/%.o: $(APP_SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -ggdb3 -c -o $@ $<

$(TARGET): $(OBJFILES) $(APP_OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -o $@ $^

$(TEST_OBJ)/%.o:$(TEST_SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -I$(GTEST_DIR)  -c -o $@ $<

GTEST_BUILD:
	mkdir -p $(THIRDPARTY_DIR)
	cd $(THIRDPARTY_DIR) &&\
	git clone git@github.com:google/googletest.git
	mkdir -p $(GTEST_LIB_DIR)
	cd 
	cd $(GTEST_LIB_DIR) && \
	cmake .. &&\
	make
	

app:$(TARGET)
	$(info "BINARY BUILD SUCCESSFULLY")
$(GTEST_BIN):$(OBJFILES) $(TEST_OBJ_FILES)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -I$(GTEST_DIR)  -o $@ $^ -L$(GTEST_LIB)
#	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -I$(GTEST_DIR) -L$(GTEST_LIB) $(SRCDIR)/../test/shubh_test.cpp $(SRCDIR)/../test/main.cpp -o shubh

test:GTEST_BUILD $(GTEST_BIN)
	$(info "GTEST Build SUCCESSFULLY")