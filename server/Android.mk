LOCAL_PATH				:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE			:= server
LOCAL_MODULE_TAGS		:= tests
LOCAL_PRELINK_MODULE	:= false

LOCAL_SRC_FILES			:= main_server.cpp
LOCAL_C_INCLUDES		:= $(LOCAL_PATH)/.. \

LOCAL_SHARED_LIBRARIES	:= libutils \
						   libbinder \
						   libserver

include $(BUILD_EXECUTABLE)
