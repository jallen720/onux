# Tests

# App main object
APP_MAIN = $(BUILD_DIR)$(SRC_DIR)main.o

# File lists
TESTS_SRCS = $(shell find $(TESTS_DIR) -name "*$(SRC_EXT)")
TESTS_OBJS = $(addprefix $(BUILD_DIR),$(TESTS_SRCS:%$(SRC_EXT)=%.o))
TESTS_DEPS = $(TESTS_OBJS:%.o=%.d)
TESTABLE_APP_OBJS = $(filter-out $(APP_MAIN), $(APP_OBJS))

# Build directories
TESTS_BUILD_DIRS = $(sort $(dir $(TESTS_OBJS)))

# Binaries
TESTS = $(BIN_DIR)tests

# Build tests
tests: $(TESTS_BUILD_DIRS) $(APP_BUILD_DIRS) $(TESTS)

# Build and run tests
run-tests: tests
	@$(CLEAR) && $(TESTS)

$(TESTS_BUILD_DIRS):
	@$(MKDIR_P) $@

# Link test & testable app objects then compile tests binary
$(TESTS): $(TESTS_OBJS) $(TESTABLE_APP_OBJS)
	@$(LINKING_MSG)
	@$(LINK_OBJECTS)

# Compile tests into objects
$(TESTS_OBJS): $(OBJ_SRC_DEP)
	@$(COMPILING_MSG)
	@$(COMPILE_SOURCE)
	@$(COMPILE_DEPENDENCIES)
	@$(FIX_DEPENDENCIES)

# Include generated dependency targets
-include $(TESTS_DEPS)
