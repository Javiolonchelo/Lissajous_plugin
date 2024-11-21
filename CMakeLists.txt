# dBob Studio 2024 - Lissajous Plugin
# Copyright (c) 2024 dBob Studio
# All rights reserved
# 
# Authors:
#   Hao Feng Chen Fu
#   Javier Rodrigo López

cmake_minimum_required(VERSION 3.15)

# Customize you plugin here
set(COMPANY_NAME "My company")
set(PROJECT_NAME MY_PLUGIN)
set(PLUGIN_TARGET_NAME "MyPlugin")
set(PLUGIN_FINAL_NAME "Fancy EQ")
set(PLUGIN_MANUFACTURER_CODE myCo)
set(PLUGIN_CODE myEq)
set(FORMATS AU VST3 Standalone)

# Paths
set(ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(MODULES_PATH "${ROOT_PATH}/modules")

project(${PROJECT_NAME} VERSION 0.0.1)

add_subdirectory(${MODULES_PATH}/JUCE)

# juce_set_vst2_sdk_path(...)
# juce_set_aax_sdk_path(...)
juce_add_plugin(${PLUGIN_TARGET_NAME}

    COMPANY_NAME ${COMPANY_NAME}
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    PLUGIN_MANUFACTURER_CODE ${PLUGIN_MANUFACTURER_CODE}
    PLUGIN_CODE ${PLUGIN_CODE}
    FORMATS ${FORMATS}
    PRODUCT_NAME ${PLUGIN_FINAL_NAME}
)

juce_generate_juce_header(${PLUGIN_TARGET_NAME})

set(SOURCE_PATH ${ROOT_PATH}/src)

target_sources(${PLUGIN_TARGET_NAME}
    PRIVATE

    # .cpp
    ${SOURCE_PATH}/PluginEditor.cpp
    ${SOURCE_PATH}/PluginProcessor.cpp

    # .h
    ${SOURCE_PATH}/PluginEditor.h
    ${SOURCE_PATH}/PluginProcessor.h
)

target_compile_definitions(${PLUGIN_TARGET_NAME}
    PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)
target_link_libraries(${PLUGIN_TARGET_NAME}
    PRIVATE
    juce::juce_audio_utils
    PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags
)
