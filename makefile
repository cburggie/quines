setup: quine_maker
	./quine_maker > quine.c

run: quine

clean:
	rm quine_maker
	rm quine.c
	rm quine

quine: quine.c
	gcc -o quine quine.c
	@echo
	./quine
	@echo
	./quine > quine.c

quine.c: setup

quine_maker: quine_maker.c
	gcc -o quine_maker quine_maker.c




