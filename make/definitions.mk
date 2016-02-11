# Definitions

# Application name
APP_NAME = onux

# Utility commands
RM      = rm -fr
MKDIR_P = mkdir -p

# Compiler options
CC           = clang++
STD          = -std=c++14
DEBUG        = -g
ALL_WARNINGS = -Wall
COMPILE_ONLY = -c
OUTPUT       = -o
GEN_DEPS     = -MM

ifeq ($(CC),clang++)

ERROR_LIMIT = -ferror-limit=5

else

ERROR_LIMIT =

endif

# Flags
CFLAGS = $(DEBUG) $(ALL_WARNINGS) $(ERROR_LIMIT) $(COMPILE_ONLY)
LFLAGS = $(DEBUG) $(ALL_WARNINGS) $(ERROR_LIMIT)

# Output target file
OUT = $(OUTPUT) $@

# Source file extension
SRC_EXT = .cpp

# Get source dependency for object
.SECONDEXPANSION:
OBJ_SRC_DEP = $$(subst $(BUILD_DIR),,$$*)$(SRC_EXT)

# Recipes
CLEAN                = $(RM) $(BIN_DIR)* $(BUILD_DIR)*
LINK_OBJECTS         = $(CC) $(STD) $(LFLAGS) $^ $(OUT) $(LIBS)
COMPILE_SOURCE       = $(CC) $(STD) $(CFLAGS) $(INCS) $< $(OUT)
COMPILE_DEPENDENCIES = $(CC) $(STD) $(CFLAGS) $(INCS) $< > $*.d $(GEN_DEPS)
FIX_DEPENDENCIES     = \
	mv -f $*.d $*.d.tmp \
	&& sed -e 's|.*:|$*.o:|' < $*.d.tmp > $*.d \
	&& sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $*.d \
	&& rm -f $*.d.tmp

# Messages
COMPILING_MSG = echo compiling $<
LINKING_MSG   = echo linking...
