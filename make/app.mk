# App

# File lists
APP_SRCS = $(shell find $(SRC_DIR) -name "*$(SRC_EXT)")
APP_OBJS = $(addprefix $(BUILD_DIR),$(APP_SRCS:%$(SRC_EXT)=%.o))
APP_DEPS = $(APP_OBJS:%.o=%.d)

# Build directories
APP_BUILD_DIRS = $(sort $(dir $(APP_OBJS))) $(BIN_DIR)

# App binary
APP = $(BIN_DIR)$(APP_NAME)

# Build app
$(APP_NAME): $(APP_BUILD_DIRS) $(APP)

# Build and run app
run-$(APP_NAME): $(APP_NAME)
	@$(CLEAR) && $(APP)

$(APP_BUILD_DIRS):
	@$(MKDIR_P) $@

# Link objects and compile app binary
$(APP): $(APP_OBJS)
	@$(LINKING_MSG)
	@$(LINK_OBJECTS)

# Compile sources into objects
$(APP_OBJS): $(OBJ_SRC_DEP)
	@$(COMPILING_MSG)
	@$(COMPILE_SOURCE)
	@$(COMPILE_DEPENDENCIES)
	@$(FIX_DEPENDENCIES)

# Include generated dependency targets
-include $(APP_DEPS)
