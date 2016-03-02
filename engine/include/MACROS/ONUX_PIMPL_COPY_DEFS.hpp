#pragma once

#define ONUX_PIMPL_COPY_DEFS(OBJECT)\
OBJECT(const OBJECT& original);\
OBJECT(OBJECT&& original);\
~OBJECT();\
OBJECT& operator =(const OBJECT& original);\
OBJECT& operator =(OBJECT&& original);
