LOCAL_PATH				:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE			:= libserver
LOCAL_MODULE_TAGS		:= tests
LOCAL_PRELINK_MODULE	:= false

LOCAL_SRC_FILES			:= libserver.cpp
LOCAL_C_INCLUDES		:= 

LOCAL_SHARED_LIBRARIES	:= libutils \
						   libbinder \

include $(BUILD_SHARED_LIBRARY)
