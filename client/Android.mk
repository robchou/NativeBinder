LOCAL_PATH				:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE			:= client
LOCAL_MODULE_TAGS		:= tests

LOCAL_SRC_FILES			:= main_client.cpp
LOCAL_C_INCLUDES		:= $(LOCAL_PATH)/.. \

LOCAL_SHARED_LIBRARIES	:= libutils \
						   libbinder

include $(BUILD_EXECUTABLE)
