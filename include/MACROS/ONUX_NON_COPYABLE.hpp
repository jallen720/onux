#pragma once

#define ONUX_NON_COPYABLE(OBJECT) \
    OBJECT(const OBJECT& original) = delete; \
    OBJECT& operator =(const OBJECT& original) = delete; \
    OBJECT(OBJECT&& original) = default; \
    OBJECT& operator =(OBJECT&& original) = default;
