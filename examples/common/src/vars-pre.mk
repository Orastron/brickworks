CFLAGS_EXTRA := -I../../../include -I../../common/src -I../common/src
PLUGIN_DIR := ../src

ifeq ($(TEMPLATE), cmd)
	COMMON_DIR := ../../common/cmd
	TINYWAV_DIR := ../../../../tinywav
	MIDI_PARSER_DIR := ../../../../midi-parser
endif

ifeq ($(TEMPLATE), lv2)
	COMMON_DIR := ../../common/lv2
endif

ifeq ($(TEMPLATE), vst3)
	COMMON_DIR := ../../common/vst3
	CFLAGS_EXTRA := $(CFLAGS_EXTRA) -I../../../../vst3_c_api
endif

ifeq ($(TEMPLATE), web)
	COMMON_DIR := ../../common/web
	CFLAGS_EXTRA := $(CFLAGS_EXTRA) -DWASM
	CXXFLAGS_EXTRA := -DWASM -std=c++11
endif

ifeq ($(TEMPLATE), daisy-seed)
	COMMON_DIR := ../../common/daisy-seed
	LIBDAISY_DIR := ../../../../libDaisy
endif

ifeq ($(TEMPLATE), ios)
	COMMON_DIR := ../../common/ios
endif

ifeq ($(TEMPLATE), android)
	COMMON_DIR := ../../common/android
	CXXFLAGS_EXTRA := -I../../../include -I../../common/src -I../common/src -I../../../../miniaudio
	KEY_STORE := ../../common/src/keystore.jks
	KEY_ALIAS := androidkey
	STORE_PASS := android
	KEY_PASS := android
	SDK_DIR := $(HOME)/Android/Sdk
	ANDROIDX_DIR := $(HOME)/Android/androidx
	KOTLIN_DIR := $(HOME)/Android/kotlin
	NDK_VERSION := 27.2.12479018
	BUILD_TOOLS_VERSION := 35.0.0
	ANDROID_VERSION := 35
	ANDROIDX_CORE_VERSION := 1.15.0
	ANDROIDX_LIFECYCLE_COMMON_VERSION := 2.8.7
	ANDROIDX_VERSIONEDPARCELABLE_VERSION := 1.2.0
	KOTLIN_STDLIB_VERSION := 2.1.0
	KOTLINX_COROUTINES_CORE_VERSION := 1.9.0
	KOTLINX_COROUTINES_CORE_JVM_VERSION := 1.9.0
endif
