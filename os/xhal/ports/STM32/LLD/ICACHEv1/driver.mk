ifeq ($(USE_SMART_BUILD),yes)
PLATFORMSRC +=
else
PLATFORMSRC +=
endif

PLATFORMINC += $(CHIBIOS)/os/xhal/ports/STM32/LLD/ICACHEv1