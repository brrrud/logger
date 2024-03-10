#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

class logger {

public:

    enum class severity {
        trace,
        debug,
        information,
        warning,
        error,
        critical
    };

public:

    virtual ~logger();

public:

    [[nodiscard]] virtual logger const *log(const std::string &, severity) const = 0;

};

#endif //LOGGER_H
