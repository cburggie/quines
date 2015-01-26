all: quine

run:
	gcc -o quine quine.c
	@echo
	./quine
	@echo
	./quine quine.c

clean:
	rm -f builder quine.c quine

quine.c: quine
	./quine quine.c

quine: source.c
	gcc -o quine source.c






