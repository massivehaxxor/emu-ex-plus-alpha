include $(IMAGINE_PATH)/make/config.mk

ifndef android_arch
 ifdef android_ouyaBuild
  android_arch := armv7
 else
  android_arch := armv7 x86
 endif
endif

android_minSDK ?= 9
android_buildPrefix := android

ifdef android_ouyaBuild
 android_minSDK := 16
 android_buildPrefix := android-ouya
endif

ifneq ($(filter arm, $(android_arch)),)
 armTarget := $(android_buildPrefix)-$(android_minSDK)-arm$(targetExt)
 targets += $(armTarget)
endif
ifneq ($(filter armv7, $(android_arch)),)
 armv7Target := $(android_buildPrefix)-$(android_minSDK)-armv7$(targetExt)
 targets += $(armv7Target)
endif
ifneq ($(filter arm64, $(android_arch)),)
 arm64Target := $(android_buildPrefix)-$(android_minSDK)-arm64$(targetExt)
 targets += $(arm64Target)
endif
ifneq ($(filter x86, $(android_arch)),)
 x86Target := $(android_buildPrefix)-$(android_minSDK)-x86$(targetExt)
 targets += $(x86Target)
endif

makefileOpts += projectPath=$(projectPath)

ifdef imagineLibExt
 makefileOpts += imagineLibExt=$(imagineLibExt)
endif

installTargets := $(targets:=-install)
installLinksTargets := $(targets:=-install-links)
commonBuildPath := $(buildSysPath)/shortcut/common-builds

.PHONY: all $(targets) $(installTargets) $(installLinksTargets)

all : $(targets)
install : $(installTargets)
install-links : $(installLinksTargets)

$(targets) :
	@echo "Performing target $@"
	$(PRINT_CMD)$(MAKE) -f $(commonBuildPath)/$@.mk $(makefileOpts)

$(installTargets) :
	@echo "Performing target $@"
	$(PRINT_CMD)$(MAKE) -f $(commonBuildPath)/$(@:-install=).mk $(makefileOpts) install

$(installLinksTargets) :
	@echo "Performing target $@"
	$(PRINT_CMD)$(MAKE) -f $(commonBuildPath)/$(@:-install-links=).mk $(makefileOpts) install-links
