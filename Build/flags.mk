# Add tools flags defines

ifeq ($(strip $(BUILD_CONFIG)),Debug)
OPTIMIZATION_OP := -O0
DEBUG_OP := -g3 -D_DEBUG
CPP_OPTIMIZATION_OP := -O0
CPP_DEBUG_OP := -g3 -D_DEBUG
LINK_OP :=
else
ifeq ($(strip $(BUILD_CONFIG)),Release)
OPTIMIZATION_OP := -O3
DEBUG_OP :=
CPP_OPTIMIZATION_OP := -O3
CPP_DEBUG_OP :=
LINK_OP := -s
endif
endif

COMPILE_FLAGS = $(DEBUG_OP) $(OPTIMIZATION_OP) -c -fmessage-length=0

CPP_COMPILE_FLAGS = $(CPP_DEBUG_OP) $(CPP_OPTIMIZATION_OP) -p -pg -c -fmessage-length=0

LINK_FLAGS = -L"$(PROJ_PATH)/lib" -Wl,--no-undefined $(LINK_OP)

AR_FLAGS = 

EDC_COMPILE_FLAGS = -id "$(PROJ_PATH)/edje/images"  -sd "$(PROJ_PATH)/edje/sounds" -fd "$(PROJ_PATH)/edje/fonts"