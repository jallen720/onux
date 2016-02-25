#pragma once

#define ONUX_MOVE_ONLY_IMPLS(OBJECT) \
    OBJECT::OBJECT(OBJECT&& original) = default; \
    OBJECT::~OBJECT() = default; \
    OBJECT& OBJECT::operator =(OBJECT&& original) = default;
