/*
 * Copyright (C) 2022-2023 Valve Corporation
 * Copyright (C) 2022-2023 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Christophe Riccio <christophe@lunarg.com>
 */

#include "profiles_settings.h"
#include "profiles_util.h"

void WarnMissingFormatFeatures(ProfileLayerSettings *layer_settings, const char *device_name, const std::string &format_name,
                               const std::string &features,
                               VkFormatFeatureFlags profile_features, VkFormatFeatureFlags device_features) {
    if (!(layer_settings->log.debug_reports & DEBUG_REPORT_WARNING_BIT)) {
        return;
    }

    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
               "For %s `%s`,\nthe Profile requires:\n\t\"%s\"\nbut the Device (%s) %s.\nThe "
               "`%s` can't be simulated on this Device.\n",
               format_name.c_str(), features.c_str(), GetFormatFeatureString(profile_features).c_str(), device_name,
               format_device_support_string(device_features).c_str(), features.c_str());
}

void WarnMissingFormatFeatures2(ProfileLayerSettings *layer_settings, const char *device_name, const std::string &format_name,
                                const std::string &features,
                                VkFormatFeatureFlags2 profile_features, VkFormatFeatureFlags2 device_features) {
    if (!(layer_settings->log.debug_reports & DEBUG_REPORT_WARNING_BIT)) {
        return;
    }

    LogMessage(layer_settings, DEBUG_REPORT_WARNING_BIT,
               "For %s `%s`,\nthe Profile requires:\n\\t\"%s\"\nbut the Device (%s) %s.\nThe "
               "`%s` can't be simulated on this Device.\n",
               format_name.c_str(), features.c_str(), GetFormatFeature2String(profile_features).c_str(), device_name,
               format_device_support_string(device_features).c_str(), features.c_str());
}

std::string GetDebugActionsLog(DebugActionFlags flags) {
    std::string result = {};

    std::vector<std::string> tmp = GetDebugActionStrings(flags);

    for (std::size_t i = 0, n = tmp.size(); i < n; ++i) {
        if (!result.empty()) {
            result += ", ";
        }
        result += tmp[i];
    }

    return result;
}

#if defined(__ANDROID__)
void AndroidPrintf(DebugReportBits level, const std::string &message) {
    switch (level) {
        default:
        case DEBUG_REPORT_DEBUG_BIT:
        case DEBUG_REPORT_NOTIFICATION_BIT:
            __android_log_print(ANDROID_LOG_INFO, "Profiles", "%s", message.c_str());
            break;
        case DEBUG_REPORT_WARNING_BIT:
            __android_log_print(ANDROID_LOG_DEBUG, "Profiles", "%s", message.c_str());
            break;
        case DEBUG_REPORT_ERROR_BIT:
            __android_log_print(ANDROID_LOG_ERROR, "Profiles", "%s", message.c_str());
            break;
    }
}
#endif

const char *GetLogPrefix(DebugReportBits report) {
    static const char *table[] = {"PROFILES NOTIFICATION: ", "PROFILES WARNING: ", "PROFILES ERROR: ", "PROFILES DEBUG: "};

    switch (report) {
        case DEBUG_REPORT_NOTIFICATION_BIT:
            return table[0];
        default:
        case DEBUG_REPORT_WARNING_BIT:
            return table[1];
        case DEBUG_REPORT_ERROR_BIT:
            return table[2];
        case DEBUG_REPORT_DEBUG_BIT:
            return table[3];
    }
}

void LogMessage(ProfileLayerSettings *layer_settings, DebugReportBits report, const char *message, ...) {
#if defined(__ANDROID__)
    if (!layer_settings) return;
#else
    assert(layer_settings);
#endif

    if (!(layer_settings->log.debug_reports & report)) return;

    std::size_t const STRING_BUFFER(4096);

    assert(message != nullptr);
    assert(strlen(message) < STRING_BUFFER);

    char log[STRING_BUFFER];
    snprintf(log, STRING_BUFFER, "%s", GetLogPrefix(report));

    va_list list;

    va_start(list, message);
    vsnprintf(log, STRING_BUFFER, message, list);
    va_end(list);

    if (layer_settings->log.debug_actions & DEBUG_ACTION_STDOUT_BIT) {
#if defined(__ANDROID__)
        AndroidPrintf(report, message);
#else
        fprintf(stdout, "%s", log);
#endif
    }

    if (layer_settings->log.debug_actions & DEBUG_ACTION_FILE_BIT) {
        fprintf(layer_settings->log.profiles_log_file, "%s", log);
    }

#if _WIN32
    if (layer_settings->log.debug_actions & DEBUG_ACTION_OUTPUT_BIT) {
        OutputDebugString(log);
    }
#endif  //_WIN32

    if (layer_settings->log.debug_actions & DEBUG_ACTION_BREAKPOINT_BIT) {
#ifdef WIN32
        DebugBreak();
#else
        raise(SIGTRAP);
#endif
    }
}

void LogFlush(ProfileLayerSettings *layer_settings) {
#if defined(__ANDROID__)
    if (!layer_settings) return;
#else
    assert(layer_settings);
#endif

    if (layer_settings->log.debug_actions & DEBUG_ACTION_STDOUT_BIT) {
        std::fflush(stdout);
    }
    if (layer_settings->log.debug_actions & DEBUG_ACTION_FILE_BIT) {
        std::fflush(layer_settings->log.profiles_log_file);
    }
}

void InitProfilesLayerSettings(const VkInstanceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator,
                               ProfileLayerSettings *layer_settings) {
    assert(layer_settings != nullptr);

    const char *devsim_profile_file = std::getenv("VKSC_DEVSIM_PROFILE_FILE");

    if (devsim_profile_file) {
        layer_settings->simulate.profile_file = devsim_profile_file;
        layer_settings->simulate.capabilities =
            SIMULATE_API_VERSION_BIT |
            SIMULATE_FEATURES_BIT |
            SIMULATE_PROPERTIES_BIT |
            SIMULATE_EXTENSIONS_BIT |
            SIMULATE_FORMATS_BIT |
            SIMULATE_QUEUE_FAMILY_PROPERTIES_BIT;
        layer_settings->simulate.emulate_portability = false;
        layer_settings->log.debug_reports = DEBUG_REPORT_ERROR_BIT;
    }
}
