API_DIR := ../api

PLUGIN_DIR := ../src
CFLAGS_EXTRA := -I../../../include -I../../common/src
CXXFLAGS_EXTRA := -I../../../include -I../../common/src -std=c++11

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
	CXXFLAGS_EXTRA := $(CXXFLAGS_EXTRA) -DWASM -std=c++11
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
	CXXFLAGS_EXTRA := -I../../../include -I../../common/src -I../../../../miniaudio
	KEY_STORE := ../../common/src/keystore.jks
	KEY_ALIAS := androidkey
	STORE_PASS := android
	KEY_PASS := android
	SDK_DIR := $(HOME)/Android/Sdk
	ANDROIDX_DIR := $(HOME)/Android/androidx
	KOTLIN_DIR := $(HOME)/Android/kotlin
	NDK_VERSION := 29.0.14206865
	BUILD_TOOLS_VERSION := 36.1.0
	ANDROIDX_CORE_VERSION := 1.17.0
	ANDROIDX_LIFECYCLE_COMMON_VERSION := 2.9.4
	ANDROIDX_VERSIONEDPARCELABLE_VERSION := 1.2.1
	KOTLIN_STDLIB_VERSION := 2.2.20
	KOTLINX_COROUTINES_CORE_VERSION := 1.10.2
	KOTLINX_COROUTINES_CORE_JVM_VERSION := 1.10.2
endif
