cmake_minimum_required(VERSION 3.25)
project(logger)

set(CMAKE_CXX_STANDARD 17)


add_executable(logger
        main.cpp
        logger/logger.cpp
        logger/logger.h
        logger/logger_builder.cpp
        logger/logger_builder.h
        logger/logger_builder_concrete.cpp
        logger/logger_builder_concrete.h
        logger/logger_concrete.cpp
        logger/logger_concrete.h
        logger/logger_holder.cpp
        logger/logger_holder.h
        )
