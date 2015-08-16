# Dependencies

# Include directories
APP_INCS    = -I$(INCLUDE_DIR)
MAGICK_INCS = `pkg-config Magick++ --cflags`
INCS        = $(APP_INCS) $(MAGICK_INCS)

# Libraries
APP_LIBS    =
GTEST_LIBS  = -lgtest -lpthread
GLEW_LIBS   = -lGLEW
GLFW3_LIBS  = `pkg-config --static --libs glfw3`
MAGICK_LIBS = `pkg-config --static --libs Magick++`
LIBS        = $(APP_LIBS) $(GTEST_LIBS) $(GLEW_LIBS) $(GLFW3_LIBS) $(MAGICK_LIBS)
