# Port specification for the mcs51-medium port running with uCsim
#
# model medium

SDCCFLAGS +=--model-medium

include $(PORTS_DIR)/mcs51-common/spec.mk

LIBDIR = $(top_builddir)/device/lib/build/medium
