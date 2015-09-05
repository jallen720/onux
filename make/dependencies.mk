# Dependencies

# Include directories
APP_INCS    = -I$(INCLUDE_DIR)
MAGICK_INCS = `pkg-config --cflags Magick++`
INCS        = $(APP_INCS) $(MAGICK_INCS)

# Testing include directories
ifneq ($(filter tests,$(MAKECMDGOALS)),)

TESTS_INCS = -I$(TESTS_DIR)$(INCLUDE_DIR)
INCS += $(TESTS_INCS)
$(info Building tests, adding $(TESTS_INCS) to additional include directories.)

endif

# Libraries
APP_LIBS    =
GTEST_LIBS  = -lgtest -lpthread
GLEW_LIBS   = `pkg-config --libs glew`
GLFW3_LIBS  = `pkg-config --static --libs glfw3`
MAGICK_LIBS = `pkg-config --static --libs Magick++`
ASSIMP_LIBS = `pkg-config --libs assimp`
LIBS        = \
	$(APP_LIBS) \
	$(GTEST_LIBS) \
	$(GLEW_LIBS) \
	$(GLFW3_LIBS) \
	$(MAGICK_LIBS) \
	$(ASSIMP_LIBS)
