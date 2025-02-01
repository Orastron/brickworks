API_DIR := ../api

ifeq ($(EXAMPLE_TYPE), c)
	PLUGIN_DIR := ../src
	CFLAGS_EXTRA := -I../../../include -I../../common/src
endif

ifeq ($(EXAMPLE_TYPE), cxx-fx)
	PLUGIN_DIR := ../../common/src/cxx-fx
	CXX_SRCS_EXTRA := ../src/impl.cpp
	CFLAGS_EXTRA := -I../../../include -I../../common/src -I../../common/src/cxx-fx
	CXXFLAGS_EXTRA := -I../../../include -I../../common/src -I../../common/src/cxx-fx -std=c++11
endif

ifeq ($(EXAMPLE_TYPE), cxx-synth)
	PLUGIN_DIR := ../../common/src/cxx-synth
	CXX_SRCS_EXTRA := ../src/impl.cpp
	CFLAGS_EXTRA := -I../../../include -I../../common/src -I../../common/src/cxx-synth
	CXXFLAGS_EXTRA := -I../../../include -I../../common/src -I../../common/src/cxx-synth -std=c++11
endif

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
	ifeq ($(EXAMPLE_TYPE), cxx-fx)
		C_SRCS_EXTRA := ../../common/src/cxx-fx/impl.h
	endif
	ifeq ($(EXAMPLE_TYPE), cxx-synth)
		C_SRCS_EXTRA := ../../common/src/cxx-synth/impl.h
	endif
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
	NDK_VERSION := 28.0.12674087
	BUILD_TOOLS_VERSION := 35.0.0
	ANDROID_VERSION := 35
	ANDROIDX_CORE_VERSION := 1.15.0
	ANDROIDX_LIFECYCLE_COMMON_VERSION := 2.8.7
	ANDROIDX_VERSIONEDPARCELABLE_VERSION := 1.2.1
	KOTLIN_STDLIB_VERSION := 2.1.10
	KOTLINX_COROUTINES_CORE_VERSION := 1.10.1
	KOTLINX_COROUTINES_CORE_JVM_VERSION := 1.10.1
endif
