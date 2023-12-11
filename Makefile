MAKEFLAGS += --always-make

image = fefas/aoc2023

tests:
	@docker build -q -t ${image} .
	@docker run --rm $(if ${CI},,-it) ${image}

sh:
	@docker run -it --entrypoint=sh ${image}
