#pragma once

#define ONUX_MOVE_ONLY_DEFS(OBJECT) \
    OBJECT(const OBJECT& original) = delete; \
    OBJECT(OBJECT&& original); \
    ~OBJECT(); \
    OBJECT& operator =(const OBJECT& original) = delete; \
    OBJECT& operator =(OBJECT&& original);
