#include <iostream>
#include "logger/logger_builder.h"
#include "logger/logger_builder_concrete.h"
#include "logger/logger_holder.h"

class some_object : private logger_holder {
private:
    logger *_logger;
public:
    explicit some_object(logger *logger) {
        this->_logger = logger;
    }

private:
    [[nodiscard]] logger *get_logger() const noexcept override {
        return _logger;
    }

public:
    void do_something_void() {
        this->critical_with_guard("something critical");
    }
};

int main() {
    logger_builder *log_builder_example = new logger_builder_concrete();
    logger *logger_ex = log_builder_example->add_stream("testFile.txt", logger::severity::trace)->construct();
    logger_ex->log("test input demo", logger::severity::trace);

    auto *someObject = new some_object(logger_ex);
    someObject->do_something_void();

    delete someObject;
    delete logger_ex;
    delete log_builder_example;
}
