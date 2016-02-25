#pragma once

#define ONUX_MOVE_ONLY(OBJECT) \
    OBJECT(const OBJECT& original) = delete; \
    OBJECT(OBJECT&& original) = default; \
    ~OBJECT() = default; \
    OBJECT& operator =(const OBJECT& original) = delete; \
    OBJECT& operator =(OBJECT&& original) = default;
