MAKEFLAGS += --always-make

image = aoc2023

build:
	@docker build -q -t ${image} .

tests:
	@docker run $({CI},,-it) ${image} ./main

sh:
	@docker run $({CI},,-it) ${image} sh
