#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define MAX_LOG_MESSAGE_SIZE 1024

enum LogLevel {
    LOG_LEVEL_TRACE,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_CRITICAL
};

const char* log_level_names[] = {
    "TRACE",
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR",
    "CRITICAL"
};

void log_message(enum LogLevel level, const char* format, ...) {
    char log_message_buffer[MAX_LOG_MESSAGE_SIZE];
    va_list args;

    va_start(args, format);
    vsnprintf(log_message_buffer, MAX_LOG_MESSAGE_SIZE, format, args);
    va_end(args);

    printf("[%s] %s: %s\n", log_level_names[level], __func__, log_message_buffer);
}

int main() {
    log_message(LOG_LEVEL_INFO, "This is an info message");
    log_message(LOG_LEVEL_WARNING, "This is a warning message");
    log_message(LOG_LEVEL_ERROR, "This is an error message");

    return 0;
}
