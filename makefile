all: quine

run:
	gcc -o quine quine.c
	@echo
	./quine
	@echo
	touch quine.c
	./quine > quine.c

clean:
	rm -f builder quine.c quine

quine: quine.c
	gcc -o quine quine.c

quine.c: builder
	./builder $@

builder: builder.c
	gcc -o $@ $<




