output := ./output
CC := clang
LOG := $(output)/warn.log

INC_DIRS := include ../include ../src/ ../src/lib/
INC_FLAGS := $(foreach dir,$(INC_DIRS),$(if $(wildcard $(dir)),-I$(dir)))
SRC_FILES := ../src/*.c

CFLAGS := -g -O0

ifeq ($(STRICT),1)
    CFLAGS += -Wall -Wextra -Wpedantic -Weverything -Werror
endif

.PHONY: clean all

all: output/main

clean:
	@rm -rf $(output)
	@echo "Build and log cleaned."

%: %.c
	@mkdir -p $(output)
	@if [ -f $< ]; then \
		printf "Compiling $< (STRICT=$(if $(STRICT),1,0))...\n"; \
		$(CC) $(CFLAGS) $(INC_FLAGS) $(SRC_FILES) $< -o $(output)/$@ 2>&1 | tee $(LOG); \
		if [ $${PIPESTATUS[0]} -eq 0 ]; then \
			printf "\033[0;32mBuild successful: $(output)/$@\033[0m\n"; \
		else \
			printf "\033[0;31mBuild failed. Check $(LOG) for details.\033[0m\n"; \
			exit 1; \
		fi \
	else \
		printf "\033[0;31mError: $< not found.\033[0m\n"; \
		exit 1; \
	fi
