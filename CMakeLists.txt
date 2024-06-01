cmake_minimum_required(VERSION 3.10)
project(allocator)

# Додайте ваші виконувані файли тут
set(SOURCES 
    main.c
    allocator.c
    block.c
    kernel.c
)

# Додайте ваші заголовкові файли тут
set(HEADERS
    allocator.h
    block.h
    kernel.h
)

# Створення виконуваного файлу
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Додаткові конфігурації, якщо потрібно
# Наприклад, якщо ви використовуєте C99:
# set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 99)