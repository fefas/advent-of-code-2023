MAKEFLAGS += --always-make

image = aoc2023

build:
	@docker build -q -t ${image} .

tests:
	@docker run -it ${image} ./main

sh:
	@docker run -it ${image} sh
